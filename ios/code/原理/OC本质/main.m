//
//  main.m
//  OC本质
//
//  Created by wtw on 2019/3/23.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <malloc/malloc.h>
#import "Person.h"

// xcrun -sdk iphoneos(平台) clang -arch(架构) arm64 -rewrite-objc  OC源文件 - 0 输出的CPP文件
// xcrun -sdk iphoneos clang -arch arm64 -rewrite-objc main.m -o main_arm64.cpp

/*
 OC对象的本质：
 OC 代码的底层都是C/C++/汇编代码
 
 所以Objective-C的面向对象都是基于C\C++的数据结构实现的
 
 Objective-C的对象、类主要是基于C\C++的什么数据结构实现的？
 结构体
 
 @interface NSObject <NSObject> {
    Class isa  OBJC_ISA_AVAILABILITY;
 }
 
 // NSObject implementation
 struct NSObject_IMPL {
    Class isa;  // 8 个字节
 }
 */

/*
 占用16个字节也可以通过源码查看到：
 allocWithZone
 class_createInstance
 _class_createInstanceFromZone
 instanceSize
 
 size_t instanceSize(size_t extraBytes) {
       size_t size = alignedInstanceSize() + extraBytes;
       // CF requires all objects be at least 16 bytes.   // 所有的实例对象最少占用 16个字节
       if (size < 16) size = 16;
       return size;
 }
 */


int main(int argc, const char * argv[]) {
    @autoreleasepool {
       
        NSObject *obj = [[NSObject alloc] init];
 
#pragma mark 一个 NSObject 对象占用多少内存？ 16字节
        
        // 系统分配了16个字节给 NSObject 对象 (通过 alloc 创建出来的对象)
        // 但NSObject对象内部只使用了8个字节的空间 (64位环境下可以通过class_getInstanceSize函数获得)
        // 8个字节是用来存放 NSObject_IMPL 结构体
        
        //获得 NSObject 实例对象的成员变量所占用的大小
        NSLog(@"%zd",class_getInstanceSize([NSObject class]));   // 8
        
        //获得 obj 指针所指向内存的大小
        NSLog(@"%zd",malloc_size((__bridge const void *)obj));  // 16
        
#pragma mark   一个 Person  对象占用多少内存？ 32 个字节
        
        Person *person = [[Person alloc] init];
        
        person->_age = 10;
        person->_height = 20;
        
        NSLog(@"class_getInstanceSize == %zd",class_getInstanceSize([person class]));  // 24
        NSLog(@"malloc_size : %zd",malloc_size((__bridge const void *)(person)));  // 32
        
    }
    return 0;
}

# pragma mark - 常用LLDB 命令

// 常用LLDB 命令
/*
 print、p : 打印
 po : 打印对象
 读取内存：
    memory read/数量 格式 字节数 内存地址
    简写： x/数量 格式 字节数 内存地址   x/3xw 0x100010
 
    格式：
        x代表 16进制
        f 是浮点
        d 是十进制
    字节数：
        b byte 1字节
        h half word 2个字节
        w word 4个字节
        g gaint word 8个字节
 
修改内存中的值：
    memory write 内存地址 数值
    memory write 0x0000010 10
 */

/*
 (lldb) p obj
 (NSObject *) $0 = 0x0000000100540190
 (lldb) po obj
 <NSObject: 0x100540190>
 (lldb) x/4xw 0x100540190
 0x100540190: 0xa526d141 0x001dffff 0x00000000 0x00000000
 (lldb) x/3xw 0x100540190
 0x100540190: 0xa526d141 0x001dffff 0x00000000
 (lldb) x 0x100540190
 0x100540190: 41 d1 26 a5 ff ff 1d 00 00 00 00 00 00 00 00 00  A.&.............
 0x1005401a0: 70 02 54 00 01 00 00 00 b0 04 54 00 01 00 00 00  p.T.......T.....
 (lldb) 
 */
