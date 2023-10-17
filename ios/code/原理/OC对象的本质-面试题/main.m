//
//  main.m
//  OC对象的本质-面试题
//
//  Created by WTW on 2019/9/24.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <malloc/malloc.h>

/*
 一个Person对象、一个Student对象占用多少内存空间？ 都是 16 个字节

 struct NSObject_IMPL {
     Class isa;
 };
 
 struct Person_IMPL {
     struct NSObject_IMPL NSObject_IVARS;  // 8 字节
     int _age; // 4 字节
 };  // 内存对齐(结构体的最终大小必须是最大成员大小的倍数) 8*2 = 16字节  (且OC 有对象最少占用16个字节也可以确定是16个字节)
 
 struct Student_IMPL {
     struct Person_IMPL Person_IVARS;  // 16字节
     int _no;  // 4 字节
 };  // 16个字节  16字节的原因是父类有正好4个字节的空余 子类正好占用，所以是16 * 1 = 16个字节
 
 
 还可以看出 实例对象只包含了成员变量没有包含方法 ，方法是不会在成员变量的内存中的 （放到了类对象的方法列表中）
 */

/* 两个容易混淆的函数
 创建一个实例对象，至少需要多少内存？
 #import <objc/runtime.h>
 class_getInstanceSize([NSObject class]);

 创建一个实例对象，实际上分配了多少内存？ (实例对象一般是16的倍数，考虑的内存对齐的问题，有个内存对齐的概念，bucket 一般为 16  32  64 。。。 256可以参考 libmalloc 源码)
 #import <malloc/malloc.h>
 malloc_size((__bridge const void *)obj);
 */

@interface Person : NSObject
{
    int _age;
}
@end

@implementation Person

@end

@interface Student : Person
{
    int _no;
    //int _height;  加上以后就是 24  32
}
@end

@implementation Student

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Person *person = [[Person alloc] init];
        
        NSLog(@"class_getInstanceSize == %zd",class_getInstanceSize([person class]));  // 16
        NSLog(@"malloc_size : %zd",malloc_size((__bridge const void *)(person)));  // 16
        
        Student *student = [[Student alloc] init];
        
        NSLog(@"class_getInstanceSize == %zd",class_getInstanceSize([student class]));  // 16
        NSLog(@"malloc_size : %zd",malloc_size((__bridge const void *)(student)));  // 16
        
    }
    return 0;
}
