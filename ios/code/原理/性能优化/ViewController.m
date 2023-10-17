//
//  ViewController.m
//  性能优化
//
//  Created by WTW on 2019/9/6.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "性能优化-Swift.h"

// 微信读书性能监测和性能优化：http://wereadteam.github.io/2016/05/03/WeRead-Performance/
// 老谭的笔记关于内存泄露检查：http://www.tanhao.me/code/160723.html/


/*
 // 打印 pre-main 阶段的启动时间
 Edit Scheme ->Run -> arguments -> Enviromment Variables  +  DYLD_PRINT_STATISTICS
 
 */

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) UITableView *tableView;

@property (nonatomic,strong) NSArray *dataSource;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setupUI];
    
#pragma mark - 网络请求的优化
    
    
#pragma mark - 图片加载优化
    
    /*
     1、对于大图而且是一次性使用的(不需要缓存的)比如 launchiamge 引导页 等
       [UIImage imageWithContentsOfFile:<#(nonnull NSString *)#>]
       加载图片的时候会缓存图片(反复使用，多次使用的)
       [UIImage imageNamed:<#(nonnull NSString *)#>]
     
     2、对于图片的裁剪
        尽量避免触发离屏渲染 (使用 Corgraphic 或者 CAShapLayer)
     
     3、尽量保证图片的大小和UIImageView的大小相等
        在运行中缩放图片也是很消耗资源的
        如果是从本地加载图片，尽量保证图片和ImageView的大小相同
        如果是远程图片可以尝试在子线程缩放一次在加载到imageView 上
     
     4、Cache 能缓存的尽量缓存(对于不经常改变但是需要经常读写的东西)
        
     5、权衡渲染方法
        对于一些漂亮的按钮是使用图片(浪费空间)还是自己绘制(消耗性能)
     
     6、处理内存警告
        在app delegate中使用applicationDidReceiveMemoryWarning: 的方法
        在你的自定义UIViewController的子类(subclass)中覆盖didReceiveMemoryWarning
        注册并接收 UIApplicationDidReceiveMemoryWarningNotification 的通知
        接收到内存警告，就去释放一些不必要的内存(移除一些暂时不用的 view ，清除图片缓存) 不然的话 app 就会被系统杀掉
     
     7、重用大开销对象
        比如 NSDateFormatter 和 NSCalendar 初始化会比较慢，然而有不可避免使用，所以就要重用(让他作为一个属性或者一个声明成静态变量)
     */
    
#pragma mark - 编码过程中的优化
    
    /*
     能用懒加载的尽量用懒加载
     尽量使用单例
     代码结构要清晰、编码要规范
     */
    
    /*
     尽量避免过于庞大的xib
     因为加载xib的时候所有的内容都加载进了内存(包括暂时不需要的)，浪费了内存开销
     sb 就是另外一码事了，sb 仅在需要的时候实例化一个 controller
     
     gzip 雅压缩 (对于依赖于远程的资源，比如配置文件，xml，json，html 等)
     
     假如说创建了很多临时对象，会发现会一直消耗内存，直到这些对象被销毁，可以自己创建一个 autoreleasepool 来避免这个行为
     */
    
#pragma mark - 不要阻塞主线程
    
    /*
     永远不要让主线程承担过多(因为 UIKit 在主线程上做所有的工作、渲染、触控等等)
     比如I/O操作、存储，网络、图片的加载尽量放在子线程(主线程回调)
     */
    
#pragma mark - tableview的优化
    
    /*
     正确使用 tableView 的 reuseIdentifier
     
     尽量把 Views 设置为完全不透明
        如果给 opaque(不透明)属性设置为yes，渲染系统会认为这个view 完全不透明，使得渲染系统优化一些渲染过程和提高性能
        如果设置为 NO 渲染系统要正常地考虑和其他内容组成这个View，默认是YES
     
     为什么 Blendin 会导致性能的损失？
     主要View 的不透明度设置小于1，就会导致 blending，这个操作时 GPU 中完成的，主要是混合像素颜色的计算。
        如果一个View 完全不透明，那么系统就直接显示该图层的颜色即可，如果是带透明效果的，则会引入更多的计算，需要把下层的图层也包括进来，进行混合颜色的计算
     
     尽量避免渐变，图片缩放
     缓存行高
     使用shadowPath 来绘制阴影
     减少 subViews 的数量
     
     cell的层级和数量尽可能的少，离屏渲染一定要控制住，另外就是手动计算 frame 要比 autolayout 的性能好的多
     
     */
    
    
#pragma mark - 启动优化
    // 启动优化 二进制重排/dylib的加载流程在单独的工程中：
    /*
     app 的启动流程
     
    Launch Time
                user tapss app icon
                        |
                        |
                        \/
                      main()
                        |
                        |
                        \/
                UIApplicationMian()
                        |
                        |
                        \/
                Load main UI file
                        |
                        |
                        \/
                First initialization ------> willFinishLaunchingWithOptions
                        |
                        |
                        \/
                 Restore UI state ---------> Various methods
                        |
                        |
                        \/
                Final initialization -------> didFinishLaunchingWithOptions
                        |
        Running         |
                        \/
                Activete the app ----------> applicationDidBecomeActive
                        |
                        |
                        \/
                    Event Loop ------------> handle events
                        |
                        |
                        |
                        \/
            Switch to a different app
     */
    
    
    /*
    APP的启动可以分为2种
        冷启动（Cold Launch）：从零开始启动APP (优化主要是在冷启动阶段)
        热启动（Warm Launch）：APP已经在内存中，在后台存活着，再次点击图标启动APP

     启动时间可以分为两个阶段：main() 执行之前(t1) 和 main() 执行之后(t2)    t = t1 + t2
     
     t1: 系统的 dylib (动态链接库)和 App 可执行文件的加载时间
     t2: main()函数执行之后到AppDelegate类中的applicationDidFinishLaunching:withOptions:方法执行结束前这段时间
     
    main() 函数之前的耗时（t1）：
         通过添加环境变量可以打印出APP的启动时间分析（Edit scheme -> Run -> Arguments）
         DYLD_PRINT_STATISTICS设置为1；
         如果需要更详细的信息，那就将DYLD_PRINT_STATISTICS_DETAILS设置为1
    
    main() 函数之后到 applicationDidFinishLaunching 结束耗时（t2）：
        通过打点的方式进行统计
         // 1. 在 main.m 添加如下代码:
         CFAbsoluteTime AppStartLaunchTime;

         int main(int argc, char * argv[]) {
             AppStartLaunchTime = CFAbsoluteTimeGetCurrent();
           .....
         }

         // 2. 在 AppDelegate.m 的开头声明
         extern CFAbsoluteTime AppStartLaunchTime;

         // 3. 最后在AppDelegate.m 的 didFinishLaunchingWithOptions 中添加
         dispatch_async(dispatch_get_main_queue(), ^{
           NSLog(@"App启动时间--%f",(CFAbsoluteTimeGetCurrent()-AppStartLaunchTime));
         });
     
     系统级别的动态库链接库，苹果做了优化，耗时并不高，大多数时间 t1 的耗时在自身 app 中的代码和链接的三方库上；
     
     APP的(冷)启动可以概括为3大阶段
        dyld
        runtime
        main
    dyld（dynamic link editor），Apple的动态链接器，可以用来装载Mach-O文件（可执行文件、动态库等）
        启动APP时，dyld所做的事情有
            装载APP的可执行文件，同时会递归加载所有依赖的动态库
            dyld 加载 dyld 的过程为：
              1、分析 App 依赖的所有 dylib。
              2、找到 dylib 对应的 Mach-O 文件。
              3、打开、读取这些 Mach-O 文件，并验证其有效性。
              4、在系统内核中注册代码签名
              5、对 dylib 的每一个 segment 调用 mmap()。
            当dyld把可执行文件、动态库都装载完毕后，会通知Runtime进行下一步的处理
            
    启动APP时，runtime所做的事情有
            调用map_images进行可执行文件内容的解析和处理
            在load_images中调用call_load_methods，调用所有Class和Category的+load方法
            进行各种objc结构的初始化（注册Objc类 、初始化类对象等等）
            调用C++静态初始化器和__attribute__((constructor))修饰的函数
            到此为止，可执行文件和动态库中所有的符号(Class，Protocol，Selector，IMP，…)都已经按格式成功加载到内存中，被runtime 所管理
     总结一下
        APP的启动由dyld主导，将可执行文件加载到内存，顺便加载所有依赖的动态库
        并由runtime负责加载成objc定义的结构
        所有初始化工作结束后，dyld就会调用main函数
        接下来就是UIApplicationMain函数，AppDelegate的application:didFinishLaunchingWithOptions:方法
     
     // 启动的优化 按照不同的阶段
     pre-main 阶段：
         dyld
            减少(合并)动态库（定期清理不必要的动态库，特别是三方的动态库因为动态链接比较耗时）
            减少Objc类、分类的数量、减少Selector数量（定期清理不需要的类、分类）
            减少C++虚函数数量（创建虚函数表有开销）
            Swift尽量使用struct（内部做了优化，符号数量更少）
            压缩资源图片，删除无用的图片（IO操作）
            检查 framework 应当设为optional和required，如果该framework在当前App支持的所有iOS系统版本都存在，那么就设为required，否则就设为optional(因为optional会有额外的检查)

         runtime
            用+initialize方法和dispatch_once取代所有的__attribute__((constructor))、C++静态构造器、ObjC的+load
            少在类的 +load 方法里做事情，尽量把这些事情推迟到+initiailize(+initiailize + dipatch_once)
            减少构造器函数个数，在构造器函数里少做些事情
            减少C++静态全局变量的个数
     
     main() 函数到首屏阶段：
         main
            满足业务需要的前提下，尽可能将一些操作延迟，不要全部都放在finishLaunching方法中按需加载
            梳理各个二方/三方库，找到可以延迟加载的库，做延迟加载处理，比如放到首页控制器的 viewDidAppear 方法里,并且保证只执行一次（按项目结构，放在合适的地方）
            梳理业务逻辑，把可以延迟执行的逻辑，做延迟执行处理。比如检查新版本、注册推送通知等逻辑。
            避免复杂/多余的计算
            采用性能更好的API
            避免在首页控制器的viewDidLoad和viewWillAppear做太多事情，这2个方法执行完，首页控制器才能显示，部分可以延迟创建的视图应做延迟创建/懒加载处理/或者异步执行
            首页控制器或注册登录页面用纯代码方式来构建，尽量避免xib 和 sb的使用 （其他页面也是尽量使用纯代码）
            使用 instruments 的 Time Profiler 先分析启动时哪些地方比较耗时，是否可以做优化
            涉及活动需变更页面展示时(比如双十一)，提前下发数据缓存
            本地缓存首屏数据，待渲染完成后再去请求新的数据
            启动阶段的网络请求，能否放到异步请求中；
    */
    
    /*
         // pre-main 时间
         添加环境变量可以打印出APP的启动时间分析（Edit scheme -> Run -> Arguments）
         DYLD_PRINT_STATISTICS设置为1

        // rebase/binding time: 由于使用了ASLR 技术，在 dylib 加载过程中，需要计算指针偏移得到正确的资源地址。 Rebase 将镜像读入内存，修正镜像内部的指针，消耗 IO 性能；Bind 查询符号表，进行外部镜像的绑定，需要大量 CPU 计算
        // ObjC setup time: 进行 Objc 的初始化，包括注册 Objc 类、检测 selector 唯一性、插入分类方法等
        // initializer：往应用的堆栈中写入内容，包括执行 +load 方法、调用 C/C++ 中的构造器函数（用 attribute((constructor)) 修饰的函数）、创建非基本类型的 C++ 静态全局变量等
     
         Total pre-main time: 1.1 seconds (100.0%)
                  dylib loading time: 361.50 milliseconds (31.6%)
                 rebase/binding time: 141.95 milliseconds (12.4%)
                     ObjC setup time: 120.99 milliseconds (10.6%)
                    initializer time: 515.75 milliseconds (45.2%)
                    slowest intializers :
                      libSystem.B.dylib :  17.08 milliseconds (1.4%)
             libMainThreadChecker.dylib :  77.13 milliseconds (6.7%)
                                Flutter :  28.71 milliseconds (2.5%)
                             ImSDK_Plus :  25.94 milliseconds (2.2%)
                               NERtcSDK :  76.36 milliseconds (6.6%)
                               PocketCN : 359.78 milliseconds (31.5%)
         
  
         //如果需要更详细的信息，那就将DYLD_PRINT_STATISTICS_DETAILS设置为1
         Total pre-main time: 1.1 seconds (100.0%)
                  dylib loading time: 355.45 milliseconds (31.9%)
                 rebase/binding time: 132.45 milliseconds (11.8%)
                     ObjC setup time: 112.71 milliseconds (10.1%)
                    initializer time: 512.78 milliseconds (46.0%)
                    slowest intializers :
                      libSystem.B.dylib :  16.97 milliseconds (1.5%)
             libMainThreadChecker.dylib :  74.06 milliseconds (6.6%)
                                Flutter :  29.19 milliseconds (2.6%)
                             ImSDK_Plus :  25.80 milliseconds (2.3%)
                               NERtcSDK :  75.20 milliseconds (6.7%)
                               PocketCN : 360.88 milliseconds (32.4%)

           total time: 2.2 seconds (100.0%)
           total images loaded:  478 (464 from dyld shared cache)
           total segments mapped: 45, into 51316 pages with 1776 pages pre-fetched
           total images loading time: 1.0 seconds (45.9%)
           total load time in ObjC: 112.71 milliseconds (4.9%)
           total debugger pause time: 695.04 milliseconds (30.3%)
           total dtrace DOF registration time:   0.24 milliseconds (0.0%)
           total rebase fixups:  858,616
           total rebase fixups time: 126.91 milliseconds (5.5%)
           total binding fixups: 631,316
           total binding fixups time: 474.39 milliseconds (20.7%)
           total weak binding fixups time:  11.03 milliseconds (0.4%)
           total redo shared cached bindings time: 479.88 milliseconds (20.9%)
           total bindings lazily fixed up: 0 of 0
           total time in initializers and ObjC +load: 512.78 milliseconds (22.4%)
                                  libSystem.B.dylib :  16.97 milliseconds (0.7%)
                        libBacktraceRecording.dylib :  15.60 milliseconds (0.6%)
                         libMainThreadChecker.dylib :  74.06 milliseconds (3.2%)
                       libViewDebuggerSupport.dylib :  10.99 milliseconds (0.4%)
                                            Flutter :  29.19 milliseconds (1.2%)
                                         ImSDK_Plus :  25.80 milliseconds (1.1%)
                                           NERtcSDK :  75.20 milliseconds (3.2%)
                                             NIMSDK :  16.79 milliseconds (0.7%)
                                             nuisdk :  18.48 milliseconds (0.8%)
                                 libswiftCore.dylib :   2.75 milliseconds (0.1%)
                                           PocketCN : 360.88 milliseconds (15.7%)
         total symbol trie searches:    1450060
         total symbol table binary searches:    0
         total images defining weak symbols:  45
         total images using weak symbols:  115
         
         // main -> 主页的时间
         //main
         //NSLog(@"LaunchStartTime: %f", CACurrentMediaTime());
         //viewDidAppear
         //NSLog(@"LaunchEndTime: %f", CACurrentMediaTime());
     */
    
    
#pragma mark - 内存优化
    /*
     如果内存过高会导致如下几个问题：
     1、被操作系的守护进程杀掉，无论是前台还是后台
     2、耗电增加，手机会发热
     3、系统会运行卡顿
     
     技术方案： http://www.zoomfeng.com/blog/memory.html
     1、优化长期的内存占用
        内存泄露问题：
            1、使用 instruments (比较麻烦，可能无法检测到循环引用导致的内存泄露)
            2、使用 MLeaksFinder (只能检查到 VC 和 对应的 View 是否有内存泄露，方便开发时发现问题)
            3、集成 FBMemoryProfiler 可视化工具
        不必要的单例：
            是否可以改造成懒加载，用的时候才去初始化，用完可以释放掉，主要是排查代码
        图片的加载(大图的使用方式)
            对于大图使用 imageWithContentsOfFile 可以避免使用缓存，用完即释放，但是需要把图片放在 bundle 目录下
        APP监听到内存警告或者App退到后台的通知时，释放一些可重建的非必要对象
     
     2、优化峰值内存占用
        在合适的地方添加 AutoreleasePool 来及时释放内存
        尽量使用缓存
        缓存的释放时机，在App 退到后台或者收到内存警告时及时清理内存缓存
        控制网络单张图片的size大小，以及网络图片的总内存大小限制
     */
    
#pragma mark - 崩溃优化
    
    /*
     不能识别的方法，可以动态去添加
     数组越界或者字典为空则可以 method swizzle 拦截掉
     其他异常可以从 BSD 层和 Mach 层都可以处理，一般从 Mach 层捕获异常信号
     http://www.zoomfeng.com/blog/plcrashreporter-1.html
     防崩溃的第三方: http://www.zoomfeng.com/blog/ffextension.html
     
     NSSetUncaughtExceptionHandler 
     */
    
#pragma mark - 卡顿优化
    /*
     CPU: 负责对象的创建和销毁、对象属性的调整、布局计算、文本的计算和排版、图片的格式转换和解码、图像的绘制（Core Graphics）
     GPU: 负责纹理的渲染(将数据渲染到屏幕)
     
     尽量不要在主线层做耗时操作，比如解析数据、高度计算、解压缩文件和IO操作
     耗时的计算结果，应该缓存起来，比如 cell的高度
     尽量少去做同步操作，尽量避免死锁
     能在子线程做的操作，就不要放到主线程，比如说打点等
     对于tableview 尽量避免离屏渲染，cell的层级尽量少，另外就是手机计算 frame 比 autolayout 要好得多
     
     CPU:
         尽量用轻量级的对象，比如用不到事件处理的地方，可以考虑使用CALayer取代UIView
         不要频繁地调用UIView的相关属性，比如frame、bounds、transform等属性，尽量减少不必要的修改
         尽量提前计算好布局，在有需要时一次性调整对应的属性，不要多次修改属性
         Autolayout会比直接设置frame消耗更多的CPU资源
         图片的size最好刚好跟UIImageView的size保持一致
         控制一下线程的最大并发数量
         尽量把耗时的操作放到子线程
            文本处理（尺寸计算、绘制）
            图片处理（解码、绘制）
     
     GPU:
         尽量避免短时间内大量图片的显示，尽可能将多张图片合成一张进行显示
         GPU能处理的最大纹理尺寸是4096x4096，一旦超过这个尺寸，就会占用CPU资源进行处理，所以纹理尽量不要超过这个尺寸
         尽量减少视图数量和层次
         减少透明的视图（alpha<1），不透明的就设置opaque为YES
         尽量避免出现离屏渲染

     iOS 的双缓冲技术：
        前帧缓存和后帧缓存，CPU 计算完，GPU 渲染后放入帧缓冲区，当GPU下一帧已经渲染完放入帧缓冲区，且视频控制器已经读完前帧，GPU 会等待 Vsync 同步信号发出后，瞬间切换前后帧缓存，并让CPU 准备下一帧数据；
     
     */
    
#pragma mark - 耗电优化
    /*
     尽可能降低 CPU 和 GPU 的功耗
     少用定时器(尽量用其他方案替代)
     优化 I/O 操作：
        尽量不要频繁的写入小数据，最好是一次性写入
        读写大量的重要数据时，考虑使用 dispatch_io 其提供了基于 GCD 的异步操作文件的 I/O的API.dispatch_io 系统会优化磁盘
        数据量比较大的，建议使用 SQLite 和 CoreData
     网络优化：
        减少、压缩网络数据
        如果多次请求的结果相同，尽量使用缓存
        使用断点续传，否则网络不稳定时可能多次传输相同的内容
        网络不可用时，不要尝试执行网络请求
        让用户可以取消长时间运行或者速度很慢的网络操作，设置合适的超时时间
        批量传输，比如下载视频时，不要传输很小的数据包，直接下载整个文件或者一大块一大块地下载。如果下载广告，一次性多下载一些，然后再慢慢展示。如果下载电子邮件，一次下载多封，不要一封一封地下载。
     
    定位优化：
        如果是需要快速定位，定位完成以后让自动定位关闭
        如果不是导航应用，尽量不要实时定位，定位完毕就关掉定位服务
        尽量降低定位的精准度，比如尽量不要使用精度最高的 Best
        如果需要后台定位时，尽量设置 pauseLocationUpdatesAutomatically 为YES,如果用户不太可能移动的时候系统会自动暂停位置更新
        尽量不要使用startMonitoringSignificantLocationChanges，优先考虑startMonitoringForRegion:

    硬件检测优化
        用户移动、摇晃、倾斜设备时，会产生动作(motion)事件，这些事件由加速度计、陀螺仪、磁力计等硬件检测。在不需要检测的场合，应该及时关闭这些硬件
     */
    
#pragma mark - 安装包瘦身
    /*
    安装包（IPA）主要由可执行文件、资源组成

    资源（图片、音频、视频等）
     采取无损压缩
     去除没有用到的资源： https://github.com/tinymind/LSUnusedResources

    可执行文件瘦身
     编译器优化
     Strip Linked Product、Make Strings Read-Only、Symbols Hidden by Default设置为YES
     去掉异常支持，Enable C++ Exceptions、Enable Objective-C Exceptions设置为NO， Other C Flags添加-fno-exceptions

    利用AppCode（https://www.jetbrains.com/objc/）检测未使用的代码：菜单栏 -> Code -> Inspect Code

    编写LLVM插件检测出重复代码、未被调用的代码
    */
    
#pragma mark - 编译优化
    /*
     1、退出 xcode
     终端执行 defaults write com.apple.dt.Xcode ShowBuildOperationDuration YES
     command + B 可以在导航中查看编译时间

    
     2、提高XCode编译时使用的线程数
     defaults write com.apple.Xcode PBXNumberOfParallelBuildSubtasks 4

     
     3、将Debug Information Format改为DWARF
     
     在工程对应Target的Build Settings中，找到Debug Information Format这一项，将Debug时的DWARF with dSYM file改为DWARF。
     这一项设置的是是否将调试信息加入到可执行文件中，改为DWARF后，如果程序崩溃，将无法输出崩溃位置对应的函数堆栈，但由于Debug模式下可以在XCode中查看调试信息，所以改为DWARF影响并不大。这一项更改完之后，可以大幅提升编译速度
     
     4、将Build Active Architecture Only改为Yes
     
        在工程对应Target的Build Settings中，找到Build Active Architecture Only这一项，将Debug时的No改为Yes。

     这一项设置的是是否仅编译当前架构的版本，如果为No，会编译所有架构的版本。需要注意的是，此选项在Release模式下必须为Yes，否则发布的ipa在部分设备上将不能运行。这一项更改完之后，可以显著提高编译速度
     
     */
    
    

}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    NSLog(@"LaunchEndTime: %f", CACurrentMediaTime());
    
}


- (void)setupUI {
    

    [self.view addSubview:self.tableView];
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:self.view.bounds];
        _tableView.delegate = _tableView.dataSource = self;
    }
    return  _tableView;
}

- (NSArray *)dataSource {
    return [NSArray arrayWithObjects:@"drawRect", nil];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    NSLog(@"%d",self.dataSource.count);
    return  self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    }
    
    cell.textLabel.text = self.dataSource[indexPath.row];
    return  cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UIViewController *vc = nil;
    
    if (indexPath.row == 0) {
     
       vc = [[DrawRectTestController alloc] init];
        
        [self.navigationController pushViewController:vc animated:YES];
    }
    
}

@end
