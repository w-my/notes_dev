//
//  main.m
//  内存管理-MRC
//
//  Created by WTW on 2019/8/27.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 在iOS中，使用 引用计数 来管理OC对象的内存

 一个新创建的OC对象引用计数默认是1，当引用计数减为0，OC对象就会销毁，释放其占用的内存空间

 调用retain会让OC对象的引用计数+1，调用release会让OC对象的引用计数-1

 内存管理的经验总结
    当调用alloc、new、copy、mutableCopy方法返回了一个对象，在不需要这个对象时，要调用release或者autorelease来释放它
    想拥有某个对象，就让它的引用计数+1；不想再拥有某个对象，就让它的引用计数-1

 可以通过以下私有函数来查看自动释放池的情况
    extern void _objc_autoreleasePoolPrint(void);
 */

#import <Foundation/Foundation.h>
#import "MJPerson.h"
#import "MJDog.h"

// Manual Reference Counting ： MRC

// 测试 autorelease
void test()
{
    // 内存泄漏：该释放的对象没有释放
    
    // autorelease 会在 @autoreleasepool {} 大括号结束的时候自动调用 release
    /* 打印结果证实是在 大括号结束的时候自动调用 release
     2020-02-18 11:58:33.989804+0800 内存管理-MRC[56588:3982824] 1
     2020-02-18 11:58:33.990623+0800 内存管理-MRC[56588:3982824] -[MJPerson dealloc]
     2020-02-18 11:58:33.990813+0800 内存管理-MRC[56588:3982824] -[MJPerson dealloc]
     2020-02-18 11:58:33.991008+0800 内存管理-MRC[56588:3982824] 2
     */
     MJPerson *person1 = [[[MJPerson alloc] init] autorelease];
     MJPerson *person2 = [[[MJPerson alloc] init] autorelease];
    NSLog(@"1");
}

// 测试 引用计数
void test2()
{
    MJDog *dog = [[MJDog alloc] init]; // 1
    
    MJPerson *person1 = [[MJPerson alloc] init];
    [person1 setDog:dog]; // 2
    
    MJPerson *person2 = [[MJPerson alloc] init];
    [person2 setDog:dog]; // 3
    
    [dog release]; // 2
    
    [person1 release]; // 1
    
    [[person2 dog] run];
    
    [person2 release]; // 0
}

void test3()
{
    MJDog *dog1 = [[MJDog alloc] init]; // dog1 : 1
    MJDog *dog2 = [[MJDog alloc] init]; // dog2 : 1
    
    MJPerson *person = [[MJPerson alloc] init];
    [person setDog:dog1]; // dog1 : 2
    [person setDog:dog2]; // dog2 : 2, dog1 : 1
    
    [dog1 release]; // dog1 : 0
    [dog2 release]; // dog2 : 1
    [person release]; // dog2 : 0
}

void test4()
{
    MJDog *dog = [[MJDog alloc] init]; // dog:1
    
    MJPerson *person = [[MJPerson alloc] init];
    [person setDog:dog]; // dog:2
    
    [dog release]; // dog:1
    
    [person setDog:dog];
    [person setDog:dog];
    [person setDog:dog];
    [person setDog:dog];
    [person setDog:dog];
    
    [person release]; // dog:0
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        MJPerson *person = [MJPerson person];
        //        MJPerson *person = [[MJPerson alloc] init];
        //
        //        [person release];
        
        
//        test(); // autorelease
        
        test2();
    }
    
    NSLog(@"2");
    return 0;
}
