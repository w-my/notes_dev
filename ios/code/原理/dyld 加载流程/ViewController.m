//
//  ViewController.m
//  dyld 加载流程
//
//  Created by WTW on 2022/2/28.
//  Copyright © 2022 wtw. All rights reserved.

//  https://www.jianshu.com/p/bb181f0c3c1c

#import "ViewController.h"

/*
 (lldb) bt
 * thread #1, queue = 'com.apple.main-thread', stop reason = breakpoint 9.1
   * frame #0: 0x000000010cfbcea1 dyld 加载流程`+[ViewController load](self=ViewController, _cmd="load") at ViewController.m:22:1
     frame #1: 0x00007fff2018cf26 libobjc.A.dylib`load_images + 1419
     frame #2: 0x000000010cfd89da dyld_sim`dyld4::RuntimeState::notifyObjCInit(dyld4::Loader const*) + 170
     frame #3: 0x000000010cfdd94d dyld_sim`dyld4::Loader::runInitializersBottomUp(dyld4::RuntimeState&, dyld3::Array<dyld4::Loader const*>&) const + 167
     frame #4: 0x000000010cfdd9f6 dyld_sim`dyld4::Loader::runInitializersBottomUpPlusUpwardLinks(dyld4::RuntimeState&) const + 102
     frame #5: 0x000000010cfec2d8 dyld_sim`dyld4::APIs::runAllInitializersForMain() + 222
     frame #6: 0x000000010cfd0920 dyld_sim`dyld4::prepare(dyld4::APIs&, dyld3::MachOAnalyzer const*) + 2306
     frame #7: 0x000000010cfd0d3f dyld_sim`_dyld_sim_prepare + 379
     frame #8: 0x000000011b2b5a88 dyld`dyld::useSimulatorDyld(int, macho_header const*, char const*, int, char const**, char const**, char const**, unsigned long*, unsigned long*) + 2093
     frame #9: 0x000000011b2b3162 dyld`dyld::_main(macho_header const*, unsigned long, int, char const**, char const**, char const**, unsigned long*) + 1198
     frame #10: 0x000000011b2ad224 dyld`dyldbootstrap::start(dyld3::MachOLoaded const*, int, char const**, dyld3::MachOLoaded const*, unsigned long*) + 450
     frame #11: 0x000000011b2ad025 dyld`_dyld_start + 37

 
 源码搜索 dyldbootstrap 找到 start 函数
 /// macho_header*  appsMachHeader : Mach-O 的 header
 /// intptr_t slide : 这个其实就是ALSR
 ///
 /// 首先 , 根据计算出来的 ASLR 的 slide 来重定向 macho .
 /// 初始化 , 允许 dyld 使用 mach 消息传递 .
 /// 栈溢出保护 .
 /// 初始化完成后调用 dyld 的 main 函数 ,dyld::_main .
 uintptr_t start(const struct macho_header* appsMachHeader, int argc, const char* argv[],
                 intptr_t slide, const struct macho_header* dyldsMachHeader,
                 uintptr_t* startGlue)
 
 
 
 总结：
 dyld 加载所有的库和执行文件
 dyld 加载流程：
 程序从_dyld_start 开始
 进入到 dyldbootstrap::start ->  dyld::_main 函数
    配置一些环境变量
    加载共享缓存库（一开始就判断是否是禁用，iOS无法被禁用)
    实例化主程序
    加载动态库
    链接主程序
    最关键的地方：初始化方法
        经过一系列初始化调用 notifySingle 函数
            该函数会执行一个回调
            通过断点调试：该回调是_objc_init 初始化的时候赋值的一个函数load_images
                load_images 里面执行 call_load_methods 函数
                    call_load_methods 函数循环调用各个类的load 方法
        doModInitFunctions 函数
            内部会调用带 __attribute__((constructor)) 的c函数
        返回主程序的入口函数，开始进入主程序的 main 函数
 */


@interface ViewController ()

@end

@implementation ViewController

+ (void)load {
    
    NSLog(@"==== load ====");
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}



@end
