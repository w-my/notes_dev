//
//  ViewController.m
//  Mach-O 文件
//
//  Created by WTW on 2022/2/28.
//  Copyright © 2022 wtw. All rights reserved.
//

#import "ViewController.h"

/*
 
 Mach-O 文件：
 
 Mach Object 文件格式 的缩写 ，是iOS 和 mac 上可执行文件的格式。是一种用于可执行文件、目标代码、动态库的文件格式。
 
 属于 Mach-O 格式的常见文件(是一种文件格式，并非一定是可执行文件)：
     1、目标文件 .o
     2、库文件：
        .a
        .dylib
        .framwork
     3、可执行文件
     4、dyld 动态链接器
     5、.dsym  符号表
 
 
 共享缓存：
    由于 iOS系统中UIKit/Foundation等库每个应用都会通过 dyld 加载到内存中,因此,为了节约空间，苹果将这些系统库放在了一个地方:动态库共享缓存区 (dyld shared cache).(Mac OS 一样有)
    类似NSLog的函数实现地址,并不会也不可能会在我们自己的工程的 Mach-O 中,那么我们的工程想要调用NSLog方法
 
    流程如下：
        在工程编译时,所产生的 Mach-O 可执行文件中会预留出一段空间,这个空间其实就是符号表,存放在_DATA数据段中(因为_DATA 段在运行时是可读可写的)
        编译时 : 工程中所有引用了共享缓存区中的系统库方法,其指向的地址设置成符号地址,(例如工程中有一个NSLog,那么编译时就会在Mach-O中创建一个NSLog的符号,工程中的 NSLog 就指向这个符号 )
        运行时 : 当 dyld将应用进程加载到内存中时,根据 load commands 中列出的需要加载哪些库文件,去做绑定的操作(以 NSLog 为例,dyld 就会去找到 Foundation 中NSLog的真实地址写到_DATA 段的符号表中NSLog 的符号上面)

    这个过程被称为 PIC 技术(位置代码独立)；
    fishhook 原理是：
        将编译后系统库函数所指向的符号,在运行时重绑定到用户指定的函数地址,然后将原系统函数的真实地址赋值到用户指定的指针上.
 */


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


@end
