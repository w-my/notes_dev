//
//  ViewController.swift
//  二进制重排
//
//  Created by WTW on 2022/2/18.
//  Copyright © 2022 wtw. All rights reserved.
//

// https://juejin.cn/post/6844904130406793224

import UIKit

/*
 虚拟内存解决的问题：
     1、安全问题 一个进程(app)可以通过地址偏移访问到其他进程的内存地址；
     2、效率问题 整个APP都装载到内存，可能只用了其中很少的一部分，导致内存使用效率很低；

 虚拟内存原理:
    使用虚拟内存的概念以后就是说在进程中可以认为0x000000 ~ 0xffffff 地址是连续的且都是可以使用的，而虚拟内存需要通过映射才能访问到真正的物理内存（解决了安全问题）；
 CPU 寻址过程：
    1、通过虚拟内存地址找到对应进程的映射表。
    2、通过映射表找到真实的物理地址，进而找到数据；这个过程由操作系统和cpu上集成的 mmu 单元协同来完成；
 虚拟内存解决效率问题：
     虚拟内存和物理内存通过映射表来进行映射的，但是映射并不可能是一一对应的，那样就太浪费了。为了解决效率问题，物理内存是分页的，而映射表同样是以页为单位的。
     换句话说，映射表只会映射到一页，并不会映射到每一个地址；
     Linux 和 macOX 一页是4K ，iOS 一页是16K (可以直接通过pagesize 在终端中查看 4096 和 16384)
 内存分页原理：
    1、当应用被加载到内存中时,不会将整个应用加载到内存中，只会放用到的那一部分，换句话说就是应用使用多少,实际物理内存就实际存储多少。
    2、当应用访问到某个地址,映射表中为0,也就是说并没有被加载到物理内存中时,系统就会立刻阻塞整个进程,触发一个我们所熟知的缺页中断 - Page Fault。
    3、当一个缺页中断被触发,操作系统会从磁盘中重新读取这页数据到物理内存上,然后将映射表中虚拟内存指向对应(如果当前内存已满,操作系统会通过置换页算法找一页数据进行覆盖,
        这也是为什么开再多的应用也不会崩掉,但是之前开的应用再打开时,就重新启动了的根本原因)；
 但是应用开发完成以后由于采用了虚拟内存,那么其中一个函数无论如何运行,运行多少次,都会是虚拟内存中的固定地址，为了解决这个问题,ASLR 应运而生 .
 其原理就是每次虚拟地址在映射真实地址之前,增加一个随机偏移值,以此来解决我们刚刚所提到的这个问题.
*/

/**
 * 二进制重排背景：
 * 在 iOS 系统中 , 对于生产环境的应用 , 当产生缺页中断进行重新加载时 , iOS 系统还会对其做一次签名验证 . 因此 iOS 生产环境的应用 page fault 所产生的耗时要更多
 * 当用户使用应用时 , 第一个直接印象就是启动 app 耗时 , 而恰巧由于启动时期有大量的类 , 分类 , 三方 等等需要加载和执行 , 多个 page fault 所产生的的耗时往往是不能小觑的 . 这也是二进制重排进行启动优化的必要性
 * 函数编译在 mach-o 中的位置是根据 ld ( Xcode 的链接器) 的编译顺序并非调用顺序来的 . 因此很可能这两个函数分布在不同的内存页上，那么启动时 , page1 与 page2 则都需要从无到有加载到物理内存中 , 从而触发两次 page fault
 * 而二进制重排的做法就是将 method1 与 method4 放到一个内存页中 , 那么启动时则只需要加载 page1 即可 , 也就是只触发一次 page fault , 达到优化目的 .
 *
 * 二进制重排 启动优化的原理：
 *      在应用启动过程中，调用到的方法处在不同的内存分页上，那么在启动过程中就会不停地触发缺页中断，导致进程阻塞，从而引起启动时间变长。
 *      而如果可以尝试将启动过程所需要的方法尽可能集中在较少的分页上，通过减少缺页中断的触发次数，就可以将启动时间缩短。这就二进制重排优化启动的基本原理
 *
 *如何定位缺页中断的耗时：
 *  如果想查看真实 page fault 次数 , 应该将应用卸载 , 查看第一次应用安装后的效果 , 或者先打开很多个其他应用 (之前运行过 app , 一部分已经被加载到物理内存并做好映射表映射 , 再启动会少触发一部分缺页中断 , 杀掉应用再打开也是如此)。
 *      1、使用Instruments工具
 *          使用Instruments工具中的System Trace工具来查看在应用启动阶段中缺页中断的触发次数
 *          1、打开 Instruments , 选择 System Trace；
 *          2、选择真机 , 选择工程 , 点击启动 , 当首个页面加载出来点击停止 ；
 *          3、等待分析完成 ,在virtual Memory Trace (Operation/Process/Thread) 查看第一次安装缺页次数,File Backed Page in ,Count 代表 page fault 次数和时长（Duration）
 *
 *      2、设置Xcode调试参数
 *          1、Edit Scheme->Arguments(或者快捷键组合cmd+shift+,)，设置打印加载数据分析参数来查看启动参数，以在启动之后查看到启动加载相关操作的耗时；
 *
 * 如何检测启动时调用的所有方法？
 *  1、hook objc_MsgSend ( 只能拿到 oc 以及 swift 加上 @objc dynamic 修饰后的方法 )
 *  2、静态扫描 macho 特定段和节里面所存储的符号以及函数数据 . (静态扫描 , 主要用来获取 load 方法 , c++ 构造（https://juejin.cn/post/6844904040149729294）
 *  3、clang 插桩 ( 完美版本 , 完全拿到 swift , oc , c , block 全部函数 )   clang 插桩官方文档  https://clang.llvm.org/docs/SanitizerCoverage.html
 *
 *  查看工程的符号顺序：
 *      Build Settings 中 Write Link Map File 改为yes （Link Map 是编译期间产生的产物，记录了二进制文件的布局）
 *      然后运行项目，就会在Products的同级目录中找到关于项目的一个.txt文件，这里就保存了在编译期间的二进制分布信息（ 这个符号顺序明显是按照Xcode 中 Compile Sources 的文件顺序来排列的 .）
 # Symbols:
 # Address    Size        File  Name
 0x100001EE0    0x00000087    [  2] _main
 0x100001F70    0x00000039    [  3] -[ViewController viewDidLoad]
 0x100001FB0    0x00000070    [  4] -[AppDelegate application:didFinishLaunchingWithOptions:]
 0x100002020    0x00000110    [  4] -[AppDelegate application:configurationForConnectingSceneSession:options:]
 0x100002130    0x00000065    [  4] -[AppDelegate application:didDiscardSceneSessions:]
 0x1000021A0    0x00000090    [  5] -[SceneDelegate scene:willConnectToSession:options:]
 0x100002230    0x00000040    [  5] -[SceneDelegate sceneDidDisconnect:]
 0x100002270    0x00000040    [  5] -[SceneDelegate sceneDidBecomeActive:]
 0x1000022B0    0x00000040    [  5] -[SceneDelegate sceneWillResignActive:]
 0x1000022F0    0x00000040    [  5] -[SceneDelegate sceneWillEnterForeground:]
 0x100002330    0x00000040    [  5] -[SceneDelegate sceneDidEnterBackground:]
 0x100002370    0x00000020    [  5] -[SceneDelegate window]
 0x100002390    0x00000040    [  5] -[SceneDelegate setWindow:]
 0x1000023D0    0x00000030    [  5] -[SceneDelegate .cxx_destruct]
 0x100002400    0x00000006    [  6] _NSStringFromClass
 0x100002406    0x00000006    [  8] _UIApplicationMain
 *
 * 最左侧是实际代码地址而并非符号地址，二进制重排并非只是修改符号地址，而是利用符号顺序，重新排列整个代码在文件的偏移地址，
 * 将启动需要加载的方法地址放到前面内存页中 , 以此达到减少 page fault 的次数从而实现时间上的优化
 *
 *
 *  如何改变二进制符号的加载顺序
 *      Xcode中可以通过设置Order File来人为干预编译期间的符号加载顺序。随便定义一个symbols.order文件,在Xcode编译配置中设置symbols.order的路径;
 *      清理项目编译，重新编译，然后查看编译生成的.txt文件，就会发现设置的order文件确实改变了文件的编译顺序。
 *      当工程 build 的时候 , Xcode 会读取这个文件 , 打的二进制包就会按照这个文件中的符号顺序进行生成对应的 mach-O 。
 *
 *         order 文件里 符号写错了或者这个符号不存在会不会有问题 ?
 *         ld 会忽略这些符号 , 实际上如果提供了 link 选项 -order_file_statistics，会以 warning 的形式把这些没找到的符号打印在日志里。
 *         会不会影响上架 ?
 *         首先 , objc 源码自己也在用这种方式 .二进制重排只是重新排列了所生成的 macho 中函数表与符号表的顺序
 *
 *  clang 插桩:
 *   两个思路：
 *   1、编写clang 插件（llvm 介绍）
 *   2、clang 本身提供的工具
 *       1、添加编译设置  Other C Flags 来到 Apple Clang - Custom Compiler Flags 中 , 添加 -fsanitize-coverage=trace-pc-guard
 *       2、添加 hook 代码 .
            void __sanitizer_cov_trace_pc_guard_init(uint32_t *start,
             uint32_t *stop) {
            static uint64_t N;  // Counter for the guards.
            if (start == stop || *start) return;  // Initialize only once.
            printf("INIT: %p %p\n", start, stop);
            for (uint32_t *x = start; x < stop; x++)
            *x = ++N;  // Guards should start from 1.
            }

            void __sanitizer_cov_trace_pc_guard(uint32_t *guard) {
            if (!*guard) return;  // Duplicate the guard check.

            void *PC = __builtin_return_address(0);
            char PcDescr[1024];
            //__sanitizer_symbolize_pc(PC, "%p %F %L", PcDescr, sizeof(PcDescr));
            printf("guard: %p %x PC %s\n", guard, *guard, PcDescr);
            }
 
 打印结果如下： （OC 项目才行）
 INIT: 0x10ec2b4f0 0x10ec2b528
 guard: 0x10ec2b4f4 2 PC
 guard: 0x10ec2b4f8 3 PC \367El\377
 guard: 0x10ec2b51c c PC
 guard: 0x10ec2b520 d PC \300\302>\375\377\237\377\377 \304>\375\377\237\377\377p
 guard: 0x10ec2b51c c PC `\236\375\340\376
 guard: 0x10ec2b51c c PC 0\237\375\340\376
 guard: 0x10ec2b504 6 PC @\340
 guard: 0x10ec2b51c c PC
 guard: 0x10ec2b51c c PC \240\245\375\340\376
 guard: 0x10ec2b51c c PC P\242\375\340\376
 guard: 0x10ec2b4f0 1 PC 
 guard: 0x10ec2b514 a PC 
 guard: 0x10ec2b50c 8 PC
 (lldb) x 0x10ec2b4f0
 0x10ec2b4f0: 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00  ................
 0x10ec2b500: 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00  ................
 (lldb) x 0x10ec2b524
 0x10ec2b524: 0e 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
 0x10ec2b534: 00 00 00 00 bc 52 c2 0e 01 00 00 00 00 00 00 00  .....R..........
 (lldb)

 INIT 后面打印的两个指针地址叫 start 和 stop, 通过 lldb 查看 start 到 stop 这个内存地址里面所存储的是 1 到 14 这个序号，添加一个OC方法以后如下：0e -> 0f
 
 INIT: 0x10ca69508 0x10ca69544
 guard: 0x10ca69510 3 PC
 guard: 0x10ca69514 4 PC \367El\377
 guard: 0x10ca69538 d PC
 guard: 0x10ca6953c e PC `!\374\377\237\377\377\300!\374\377\237\377\377\260
 guard: 0x10ca69538 d PC `\276\343\376
 guard: 0x10ca69538 d PC 0\277\343\376
 guard: 0x10ca69520 7 PC \360\374
 guard: 0x10ca69538 d PC
 guard: 0x10ca69538 d PC \240\305\343\376
 guard: 0x10ca69538 d PC P\302\343\376
 guard: 0x10ca69508 1 PC 
 guard: 0x10ca69530 b PC 
 guard: 0x10ca69528 9 PC
 (lldb) x 0x10ca69508
 0x10ca69508: 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00  ................
 0x10ca69518: 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00  ................
 (lldb) x 0x10ca69540
 0x10ca69540: 0f 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
 0x10ca69550: 00 00 00 00 00 00 00 00 c1 32 a6 0c 01 00 00 00  .........2......
 
 再添加一个C 函数和block 以后：0f -> 11   17
 那么我们得到一个猜想 , 这个内存区间保存的就是工程所有符号的个数
 
 INIT: 0x10659e698 0x10659e6dc
 guard: 0x10659e6a8 5 PC
 guard: 0x10659e6ac 6 PC \367El\377
 guard: 0x10659e6d0 f PC
 guard: 0x10659e6d4 10 PC  ]\374\377\237\377\377\200^\374\377\237\377\377`?&
 guard: 0x10659e6d0 f PC `nf\351\376
 guard: 0x10659e6d0 f PC 0of\351\376
 guard: 0x10659e6b8 9 PC \260\202\306
 guard: 0x10659e6d0 f PC
 guard: 0x10659e6d0 f PC \240uf\351\376
 guard: 0x10659e6d0 f PC Prf\351\376
 guard: 0x10659e698 1 PC 
 guard: 0x10659e6c8 d PC 
 guard: 0x10659e6c0 b PC
 (lldb) x 0x10659e698
 0x10659e698: 01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00  ................
 0x10659e6a8: 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00  ................
 (lldb) x 0x10659e6d8        // 减4的原因是获取结束指针的开始地址
 0x10659e6d8: 11 00 00 00 00 00 00 00 11 00 00 00 00 00 00 00  ................
 0x10659e6e8: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
 *
 *  通过点击事件 touchesBegan 的汇编可以看到，每个函数调用的第一句实际代码 ( 栈平衡与寄存器数据准备除外 ) , 被添加进去了一个 bl 调用到 __sanitizer_cov_trace_pc_guard 这个函数中
 *  这也是静态插桩的原理和名称由来
 *  总结：静态插桩实际上编译期就在每一个函数内部二进制源数据添加 hook 代码 ( 我们添加的 __sanitizer_cov_trace_pc_guard 函数 ) 来实现全局的方法 hook 的效果
 *
 * __sanitizer_cov_trace_pc_guard 函数中的这一句代码 : void *PC = __builtin_return_address(0);
 * 作用其实就是去读取 x30 中所存储的要返回时下一条指令的地址 . 所以他名称叫做 __builtin_return_address . 换句话说 , 这个地址就是我当前这个函数执行完毕后 , 要返回到哪里去
 *
 *  根据内存地址获取函数名称：
 *      逆向中防止某些特定的方法被别人使用 fishhook hook 掉 , 会利用 dlopen 打开动态库 , 拿到一个句柄 , 进而拿到函数的内存地址直接调用 .
 *      根据内存地址获取函数名称就是反过来
 *      与 dlopen 相同 , 在 dlfcn.h 中有一个方法如下
    /*
     // typedef struct dl_info {
     //         const char      *dli_fname;     /* Pathname of shared object（所在文件） */
     //         void            *dli_fbase;     /* Base address of shared object (文件地址) */
     //         const char      *dli_sname;     /* Name of nearest symbol (函数名称)*/
     //         void            *dli_saddr;     /* Address of nearest symbol (函数起始地址)*/
     // } Dl_info;
     //
     // //这个函数能通过函数内部地址找到函数符号
     // extern int dladdr(const void *, Dl_info *);
     // */
 
 INIT: 0x10b1fb6b8 0x10b1fb700
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=main
 saddr=0x10b1f3ec0
 guard: 0x10b1fb6d8 9 PC
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[AppDelegate application:didFinishLaunchingWithOptions:]
 saddr=0x10b1f3c60
 guard: 0x10b1fb6cc 6 PC \367El\377
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate window]
 saddr=0x10b1f4220
 guard: 0x10b1fb6f4 10 PC
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate setWindow:]
 saddr=0x10b1f4270
 guard: 0x10b1fb6f8 11 PC \340"\314\375\377\237\377\377\300&\314\375\377\237\377\377\320\361
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate window]
 saddr=0x10b1f4220
 guard: 0x10b1fb6f4 10 PC \236\240\344\376
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate window]
 saddr=0x10b1f4220
 guard: 0x10b1fb6f4 10 PC \340\236\240\344\376
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate scene:willConnectToSession:options:]
 saddr=0x10b1f3f90
 guard: 0x10b1fb6dc a PC \320
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate window]
 saddr=0x10b1f4220
 guard: 0x10b1fb6f4 10 PC `\203\220(\234
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate window]
 saddr=0x10b1f4220
 guard: 0x10b1fb6f4 10 PC \223\373
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate window]
 saddr=0x10b1f4220
 guard: 0x10b1fb6f4 10 PC
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[ViewController viewDidLoad]
 saddr=0x10b1f3ac0
 guard: 0x10b1fb6b8 1 PC 
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate sceneWillEnterForeground:]
 saddr=0x10b1f4160
 guard: 0x10b1fb6ec e PC 
 fname=/Users/wtw/Library/Developer/CoreSimulator/Devices/33370059-E56C-4670-A28E-57198D376C7C/data/Containers/Bundle/Application/9FA5F044-D033-4198-B744-E8311D595698/二进制重排_OC.app/二进制重排_OC
 fbase=0x10b1f2000
 sname=-[SceneDelegate sceneDidBecomeActive:]
 saddr=0x10b1f40a0
 guard: 0x10b1fb6e4 c PC

    
 *  目前所有的符号都获取到了 , 写到 order 文件里不就完事了吗 ?
 *
 * 多线程问题：
 * __sanitizer_cov_trace_pc_guard 这个函数也有可能受多线程影响 , 所以不可能简简单单用一个数组来接收所有的符号就搞定了
 * 考虑到这个方法会来特别多次，使用锁会影响性能，这里使用苹果底层的原子队列（底层是一个栈的结构，利用队列结构+原子性保证顺序）来实现
 
     // 原子队列
     static OSQueueHead symboList = OS_ATOMIC_QUEUE_INIT;

     // 定义符号结构体
     typedef struct {
         void * pc;
         void * next;
     }SymbolNode;

 - (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
     
     while (true) {
         //offsetof 就是针对某个结构体找到某个属性相对这个结构体的偏移量
         SymbolNode * node = OSAtomicDequeue(&symboList, offsetof(SymbolNode, next));
         if (node == NULL) { break; }
         
         Dl_info info;
         dladdr(node->pc, &info);
         
         printf("%s \n",info.dli_sname);
     }
     
 }
 
 void __sanitizer_cov_trace_pc_guard(uint32_t *guard) {
 //  if (!*guard) return;  // Duplicate the guard check.
   
     void *PC = __builtin_return_address(0);
    
     SymbolNode *node = malloc(sizeof(SymbolNode));
     *node = (SymbolNode){PC,NULL};
     
     // 入队
     // offsetof 用在这里是为了入队添加下一个节点找到 前一个节点next指针的位置
     OSAtomicEnqueue(&symboList, node, offsetof(SymbolNode, next));
 }
 *
 *
 * 上面的写法会导致死循环，原因是while 循环方法会多次加入 __sanitizer_cov_trace_pc_guard 调用，导致死循环
 * 解决办法：
 * Other C Flags 修改为如下 : -fsanitize-coverage=func,trace-pc-guard   只是针对 func 进行 hook
 *
 *  load 方法时，__sanitizer_cov_trace_pc_guard 函数的参数 guard 是 0，没有打印，
   解决办法： __sanitizer_cov_trace_pc_guard 中屏蔽掉 if (!*guard) return;
 
    由于先进后出原因, 需要倒叙一下，还需要做去重
    order 文件格式要求c 函数 , block 调用前面还需要加 _ , 下划线
    写入order文件即可 .
 *
 *swift工程/混编工程
 上面的方式适合纯的OC工程获取符号方式，由于swift 的编译器其阿奴单是自己的 swift 编译前端程序，因此配置稍有不同：
 Other Swift Flags  添加两条配置即可 :
 -sanitize-coverage=func
 -sanitize=undefined
 *
 * cocoapod 工程问题
 * 对于 cocoapod 工程引入的库 , 由于针对不同的 target . 那么我们在主程序中的 target 添加的编译设置 Write Link Map File , -fsanitize-coverage=func,trace-pc-guard 以及 order file 等设置肯定是不会生效的 .
 * 解决方法就是针对需要的 target 去做对应的设置即可
 *
 * 对于直接手动导入到工程里的 sdk , 不管是 静态库 .a 还是 动态库 , 默认主工程的设置就可以了 , 是可以拿到符号的 .
 * 最后提示一下 , 手动导入的三方库如果没有导入并且使用的话 , 是不会加载的 . 添加了 load 方法也是如此 .
 *
 *  优化方案：
 *  获取启动期间加载的所有符号（可以使用clang插桩(https://juejin.cn/post/6844904130406793224)  来获得启动时期需要加载的所有 函数/方法 , block , swift 方法以及 c++构造方法的符号 .符号）
 *  编写order文件，获取到启动期间的所有符号之后对符号进行调整顺序去重之后，写入.order文件用以改变编译期间的二进制布局，达到减少触发缺页中断，缩短启动时间的目的.
 *
 */

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
    }

    func test1(){
        
    }
    
    func test2(){
        
    }
    
}

