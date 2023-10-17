//
//  main.m
//  内存管理-autorelease
//
//  Created by WTW on 2019/9/2.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

/*
 总结：置于 @autoreleasepool {} 中的代码实际上是被一个 push 和 pop 操作所包裹，当 push 时，会压栈一个 autoreleasepage，在 {} 中的所有 autorelease 对象都放到这个 page 中，当 pop 时，会出栈一个  autoreleasepage ，同时，所有存储在这个 page 的对象都会做 release 操作。这就是 autoreleasepool 的实现原理
 */

/*
 自动释放池的主要底层数据结构是：__AtAutoreleasePool、AutoreleasePoolPage
 调用了autorelease的对象最终都是通过AutoreleasePoolPage对象来管理的
 
 所有的AutoreleasePoolPage对象通过双向链表的形式连接在一起

 源码分析：
 @autoreleasepool {
        Person *person = [[[Person alloc] init] autorelease];
     }

clang 重写   @autoreleasepool

 {
     __AtAutoreleasePool __autoreleasepool;
     Person *person = ((Person *(*)(id, SEL))(void *)objc_msgSend)((id)((Person *(*)(id, SEL))(void *)objc_msgSend)((id)((Person *(*)(id, SEL))(void *)objc_msgSend)((id)objc_getClass("Person"), sel_registerName("alloc")), sel_registerName("init")), sel_registerName("autorelease"));
 }
 
 // __AtAutoreleasePool 的底层结构:
 struct __AtAutoreleasePool {
      __AtAutoreleasePool() {  //构造函数  在创建结构体变量的时候调用
             atautoreleasepoolobj = objc_autoreleasePoolPush();
     }
  
      ~__AtAutoreleasePool() {  //析构函数 在结构体变量销毁的时候调用
             objc_autoreleasePoolPop(atautoreleasepoolobj);
     }
     void * atautoreleasepoolobj;
 };
 可以看出 @autoreleasepool 本质就是在开始的时候调用 objc_autoreleasePoolPush 在完成的时候调用 objc_autoreleasePoolPop

 
 上面的代码等同于如下形式:
 atautoreleasepoolobj = objc_autoreleasePoolPush();
 Person *person = [[[Person alloc] init] autorelease];
 atautoreleasepoolobj = objc_autoreleasePoolPop();
 
 
 runtime 源码跟踪：
 void *
 objc_autoreleasePoolPush(void)
 {
     return AutoreleasePoolPage::push();
 }

 void
 objc_autoreleasePoolPop(void *ctxt)
 {
     AutoreleasePoolPage::pop(ctxt);
 }
 
 调用了autorelease的对象最终都是通过AutoreleasePoolPage对象来管理的
 每个AutoreleasePoolPage对象占用4096字节内存，除了用来存放它内部的成员变量，剩下的空间用来存放autorelease对象的地址
 autoreleasePoolPage在runtime中的定义如下：
 
 class AutoreleasePoolPage
 {
     magic_t const magic;                // 魔数，用于自身的完整性校验                                                         16字节
     id *next;                           // 指向autorelePool page中的下一个可用位置                                           8字节
     pthread_t const thread;             // 和autorelePool page中相关的线程                                                  8字节
     AutoreleasePoolPage * const parent; // autoreleasPool page双向链表的前向指针                                             8字节
     AutoreleasePoolPage *child;         // autoreleasPool page双向链表的后向指针                                             8字节
     uint32_t const depth;               // 当前autoreleasPool page在双向链表中的位置（深度）                                   4字节
     uint32_t hiwat;                     // high water mark. 最高水位，可用近似理解为autoreleasPool page双向链表中的元素个数       4字节

     // SIZE-sizeof(*this) bytes of contents follow
 }
 
 
 */

/*
 调用push方法会将一个POOL_BOUNDARY入栈，并且返回其存放的内存地址
 
 调用pop方法时传入一个POOL_BOUNDARY的内存地址，会从最后一个入栈的对象开始发送release消息，直到遇到这个POOL_BOUNDARY
 
 id *next指向了下一个能存放autorelease对象地址的区域
 */

/*
  @autoreleasepool(自动释放池) 的主要底层数据结构是： __AtAutoreleasePool 、 autoreleaseNewPage
 
 调用 autorelease 的对象最终都是通过 AutoreleasePoolPage 对象来管理的
  
 class AutoreleasePoolPage
 {
    ...
     magic_t const magic;
     id *next;
     pthread_t const thread;
     AutoreleasePoolPage * const parent;
     AutoreleasePoolPage *child;
     uint32_t const depth;
     uint32_t hiwat;
    ...
 }
 
 所有的 AutoreleasePoolPage 对象通过双向链表的形式连接在一起。
 
 可以通过私有函数查看自动释放池的情况：
 _objc_autoreleasePoolPrint
 
 */

// 声明函数
extern void _objc_autoreleasePoolPrint(void);

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        _objc_autoreleasePoolPrint();
        NSLog(@"\n===================\n");
        
        // hot 指当前页
        /*
         objc[64560]: ##############
         objc[64560]: AUTORELEASE POOLS for thread 0x1000aa5c0
         objc[64560]: 1 releases pending.
         objc[64560]: [0x103001000]  ................  PAGE  (hot) (cold)
         objc[64560]: [0x103001038]  ################  POOL 0x103001038
         objc[64560]: ##############
         */
        
        Person *person = [[[Person alloc] init] autorelease];
        
        _objc_autoreleasePoolPrint();
        /*
         objc[24164]: ##############
         objc[24164]: AUTORELEASE POOLS for thread 0x1000aa5c0
         objc[24164]: 2 releases pending.
         objc[24164]: [0x101000000]  ................  PAGE  (hot) (cold)
         objc[24164]: [0x101000038]  ################  POOL 0x101000038
         objc[24164]: [0x101000040]       0x10072d5a0  Person
         objc[24164]: ##############
         */
        
        //@autoreleasepool 本质就是在开始的时候调用 objc_autoreleasePoolPush 在完成的时候调用 objc_autoreleasePoolPop
        
        @autoreleasepool {
            //atautoreleasepoolobj = objc_autoreleasePoolPush()
            
            Person *person = [[[Person alloc] init] autorelease];
            Person *person1 = [[[Person alloc] init] autorelease];
            
            //objc_autoreleasePoolPop(atautoreleasepoolobj)
            
            NSLog(@"\n===================\n");
            
            _objc_autoreleasePoolPrint();
            /*
             objc[24164]: ##############
             objc[24164]: AUTORELEASE POOLS for thread 0x1000aa5c0
             objc[24164]: 5 releases pending.
             objc[24164]: [0x101000000]  ................  PAGE  (hot) (cold)
             objc[24164]: [0x101000038]  ################  POOL 0x101000038     1
             objc[24164]: [0x101000040]       0x10072d5a0  Person               2
             objc[24164]: [0x101000048]  ################  POOL 0x101000048     3
             objc[24164]: [0x101000050]       0x100500560  Person               4
             objc[24164]: [0x101000058]       0x100500050  Person               5
             objc[24164]: ##############
             */
        }
        
        NSLog(@"\n===================\n");
        _objc_autoreleasePoolPrint();
        /*
         objc[64612]: ##############
         objc[64612]: AUTORELEASE POOLS for thread 0x1000aa5c0
         objc[64612]: 2 releases pending.
         objc[64612]: [0x100806000]  ................  PAGE  (hot) (cold)
         objc[64612]: [0x100806038]  ################  POOL 0x100806038
         objc[64612]: [0x100806040]       0x1007466c0  Person
         objc[64612]: ##############
         */
        
//        NSAutoreleasePool *autorelease = [[NSAutoreleasePool alloc] init];
//        // 相当于调用构造函数也就是 objc_autoreleasePoolPush();
//        [autorelease drain];
//        // 相当于调用构造函数也就是 objc_autoreleasePoolPush();
        
    }
    
    _objc_autoreleasePoolPrint();
    /*
     objc[64623]: ##############
     objc[64623]: AUTORELEASE POOLS for thread 0x1000aa5c0
     objc[64623]: 0 releases pending.
     objc[64623]: [0x100803000]  ................  PAGE  (hot) (cold)
     objc[64623]: ##############
     */
    
    return 0;
    }

/*
 在ARC环境下，何时需要 autoreleasePool？
 一般两种情况：
 1、创建子线程。
    当创建子线程的时候，需要将子线程的 runloop 用@autoreleasePool 包裹起来，进而达到释放内存的效果。因为系统并不会为子线程自动包裹一个@autoreleasePool，这样加入到autoreleasepage中的元素就得不到释放
 2、在大循环中创建 autorelease 对象
  当在一个循环中创建autorelease对象(不是用alloc创建的对象)，该对象会加入到autoreleasepage中，而这个page中的对象，会等到外部池子结束才会释放。在主线程的runloop中，会将所有的对象的释放权都交给了RunLoop 的释放池，而RunLoop的释放池会等待这个事件处理之后才会释放，因此就会使对象无法及时释放，堆积在内存造成内存泄露。https://www.cnblogs.com/Mike-zh/p/4445174.html
  
 */
