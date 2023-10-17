//
//  main.m
//  OC本质-Class对象
//
//  Created by WTW on 2019/9/25.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

/*
 Objective-C中的对象，简称OC对象，主要可以分为3种
     instance对象（实例对象）
     class对象（类对象）
     meta-class对象（元类对象）
 
 instance对象就是通过类alloc出来的对象，每次调用alloc都会产生新的instance对象
 instance对象在内存中存储的信息包括 (不包括方法)
    isa指针 (isa地址其实也是instance对象的地址，底层是结构体的首地址)
    其他成员变量

 Class objectClass1 = [object1 class];
 Class objectClass2 = [object2 class];
 Class objectClass3 = object_getClass(object1);
 Class objectClass4 = object_getClass(object2);
 Class objectClass5 = [NSObject class];
 以上都是NSObject的class对象（类对象）
 它们是同一个对象。每个类在内存中有且只有一个class对象
 class对象(类对象)在内存中存储的信息主要包括
    isa指针
    superclass指针
    类的属性信息（@property）、类的对象方法信息（instance method）
    类的协议信息（protocol）、类的成员变量信息（ivar）
    ......
 
 Class objectMetaClass = object_getClass([NSObject class]);
 objectMetaClass是NSObject的meta-class对象（元类对象）
 每个类在内存中有且只有一个meta-class对象
 meta-class对象和class对象的内存结构是一样的，但是用途不一样，在内存中存储的信息主要包括
    isa指针
    superclass指针
    类的类方法信息（class method）
    ......

 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        // instance 对象 实例对象
        NSObject *object1 = [[NSObject alloc] init];
        NSObject *object2 = [[NSObject alloc] init];
        
        // class 对象 类对象
        Class objectClass1 = [object1 class];
        Class objectClass2 = [object2 class];
        Class objectClass3 = object_getClass(object1);
        Class objectClass4 = object_getClass(object2);
        Class objectClass5 = [NSObject class];
        
        NSLog(@"%p %p",object1,object2);
        // 0x10056baf0 0x10056b900
        NSLog(@"%p %p %p %p %p",objectClass1,objectClass2,objectClass3,objectClass4,objectClass5);
        // 0x7fff93411140 0x7fff93411140 0x7fff93411140 0x7fff93411140 0x7fff93411140
        
        // meta-class 将 类对象 当做参数传入 获得元类对象
        Class objectMetaClass = object_getClass([NSObject class]);
        NSLog(@"%@ %p",objectMetaClass,objectMetaClass);

    }
    return 0;
}
