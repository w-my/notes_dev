//
//  ViewController.m
//  内存管理-weak指针
//
//  Created by WTW on 2019/9/2.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"

/* 参考大神博客：
 * https://blog.csdn.net/u013378438/article/details/82767947  (反复多看几遍)
 * https://www.jianshu.com/p/13c4fb1cedea
 * https://www.jianshu.com/p/404d9c9baea9
 */

/*
 weak 的作用:
 1、不会添加引用计数
 2、当所引用的对象释放后，引用者的指针自动置为nil
*/
 
/*  源码地址 : objc4-NSObject.mm ->  objc_initWeak
    参考大神博客： https://blog.csdn.net/u013378438/article/details/82790332

 SideTables 是一个64个元素长度的hash数组，里面存储了SideTable。SideTables的hash 键值就是一个对象obj的address。因此可以说，一个obj，对应了一个SideTable。但是一个SideTable，会对应多个obj。因为SideTable的数量只有64个，所以会有很 多obj共用同一个SideTable
 
     struct SideTable {
         spinlock_t slock; // 自旋锁
         // 存放着对象引用计数的散列表 ,key obj 地址，value obj 对象的引用计数
         RefcountMap refcnts;
         // 全局弱引用表 ，key obj 地址，value weak_entry_t 结构体对象
         weak_table_t weak_table;
         ......
     }
 
    weak_table_t 存储了弱引用 obj 的指针的地址，本质是一个以 obj 地址为 key ，弱引用 obj 的指针的地址为 value 的 hash 表。hash 表的节点类型是 weak_entry_t
 
     SideTables 可以理解为一个全局的 hash 数组，存储了 SideTable 类型的数组，长度为 64
     // 可以看到 SideTabls 实质类型为模板类型 StripedMap
     static StripedMap<SideTable>& SideTables() {
         return *reinterpret_cast<StripedMap<SideTable>*>(SideTableBuf);
     }
    
    
 */

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
#pragma mark - 汇编查看代码入口
    
    // 对一个对象进行弱引用的时候，背后是通过runtime 来支持的
    // 下面代码根据查看汇编调用分析 (Debug -> Debug Workflow -> Always Show Disassembly)
    // __weak NSObject *weakP = p;   调用 objc_initWeak
    // weakP = p1;                   调用 objc_storeWeak
    // 出了 ViewDidLoad               调用 objc_destroyWeak
    NSObject *p = [[NSObject alloc] init];
    NSObject *p1 = [[NSObject alloc] init];
    __weak NSObject *weakP = p;  // weakP 弱引用 p
    weakP = p1; // objc_storeWeak
   
#pragma mark - 源码在 runtime 源码中 NSObject.mm
    
    // 阅读顺序 objc_initWeak -> objc_storeWeak -> objc_destroyWeak
    
    /*
     // location __weak 指针的地址 (&weakP) ，是一个指针的地址
     // 之所以要存储指针的地址，是为了后面把 __weak 指针指向的内容置为nil,如果仅存储指针，无法实现
     // newObj 所引用的对象 (p)
     objc_initWeak(id *location, id newObj)
     {
         if (!newObj) {  // 对象为空
             *location = nil;  // weak 指针置为 nil ,返回 nil
             return nil;
         }
         
         // 对象不为空
        // storeWeak weak 引用的核心
         return storeWeak<DontHaveOld, DoHaveNew, DoCrashIfDeallocating>
             (location, (objc_object*)newObj);
     }
     
     
     
     storeWeak 核心实现了两个功能：
     1、将 weak 指针的地址 location 存入到对应的 weak_entry_t 的数组(链表)中，用于在 obj 析构的时候，通过该数组(链表)找到其所有的 weak 指针引用，并将指针指向的地址(location)置为nil。
     2、如果是启用了isa 优化，则将obj 的 isa_t 的 weakly_referenced 置为1，标记 obj 被weak 引用了，当 delloc 时，runtime 会根据 weakly_referenced 标志位来判断是否需要查找 obj 对应的 weakly_entry_t 并将其置为 nil。
     
     前三个参数是通过模板枚举的方式传入:
        HaveOld haveOld, // weak ptr 之前时候已将指向一个弱引用 false
        HaveNew haveNew, // 是否需要指向一个新的引用  true
        CrashIfDeallocating crashIfDeallocating // 如果被弱引用的对象正在析构，此时再弱引用该对象，是否应该crash  true
     后面两个参数：
        location // 指针的地址
        newObj //  被 weak 引用的对象
     两个关键函数：
        weak_register_no_lock：将 weak ptr地址 注册到obj对应的weak_entry_t中
        weak_unregister_no_lock：将 weak ptr地址 从obj的weak_entry_t中移除
     template <HaveOld haveOld, HaveNew haveNew,
               CrashIfDeallocating crashIfDeallocating>
     static id
     storeWeak(id *location, objc_object *newObj){
        // 参考源码 NSObject.mm
     }
    
     
     // DoHaveOld true
     // DontHaveNew false
     // DontCrashIfDeallocating false
     objc_destroyWeak(id *location)
     {
         (void)storeWeak<DoHaveOld, DontHaveNew, DontCrashIfDeallocating>
             (location, nil);
     }
     */
 
    // 上面的所有就是当我们将一个obj作weak引用时，所发生的事情
  //当obj释放时，所有weak引用它的指针又是如何自动设置为nil的呢,接下来我们来看一下obj释放时，所发生的事情
    
#pragma mark -  Dealloc NSObject.mm -> _objc_rootDealloc
    
     /*
     当引用计数为 0 时，runtime 会调用 _objc_rootDealloc 方法来析构对象
      
     源码位置：objc-object.h
     
     rootDealloc的实现逻辑如下：
     1、判断object是否采用了Tagged Pointer计数，如果是，则不进行任何析构操作。关于这一点，我们可以看出，用Tagged Pointer计数的对象，是不会析构的。TaggedPointer计数的对象在内存中应该是类似于字符串常量的存在，多个对象指针其实会指向同一块内存地址。虽然官方文档中并没有提及，但可以推测，Tagged Pointer计数的对象的内存位置很有可以就位于字符串常量区。
     
    2、接下来判断对象是否采用了优化的isa计数方式（isa.nonpointer）。如果是，则判断是否能够进行快速释放（free(this) 用C函数释放内存）。可以进行快速释放的前提是：对象没有被weak引用!isa.weakly_referenced，没有关联对象!isa.has_assoc，没有自定义的C++析构方法!isa.has_cxx_dtor，没有用到sideTable来做引用计数 !isa.has_sidetable_rc。
    3、其余的，则进入object_dispose((id)this)慢释放分支 (objc-runtime-new.mm)
     
      源码调用流程：
        object_dispose((id)this)
        void *objc_destructInstance(id obj)
        objc_object::clearDeallocating()
            sidetable_clearDeallocating(); // 已不用
            clearDeallocating_slow(); // 优化过的isa指针
      objc_object::clearDeallocating_slow()
      weak_clear_no_lock()
      
      这就是为什么当对象析构时，所有弱引用该对象的指针都会被设置为nil的原因。
     */
    
    /*
  纵观weak引用的底层实现，其实原理很简单。就是将所有弱引用obj的指针地址都保存在obj对应的weak_entry_t中。当obj要析构时，会遍历weak_entry_t中保存的弱引用指针地址，并将弱引用指针指向nil，同时，将weak_entry_t移除出weak_table
     */
    
    
    /*
     __weak 、__unsafe_unretained 都是弱引用
     共同点：
            都不会产生强引用
     不同点：
            weak 在对象销毁的时候指针会自动清空 (person = nil)
            __unsafe_unretained 不会清空，会出现坏内存访问 (EXC_BAD_ACCESS)
     */
    
//    __strong Person *person1;
//    __weak Person *person2;
//    __unsafe_unretained Person *person3;
//    
//    NSLog(@"====1====");
//    
//    {
//        Person *person = [[Person alloc] init];
//        
////        person1 = person;
////        person2 = person;       // 出了大括号 person 就销毁了 perosn2 = nil
////        person3 = person;  // 出了大括号 person 就销毁了 但是 perosn3 还是有值的（值就是之前对象的地址值，这样再去访问就报野指针）
//    }
//    
//    NSLog(@"====2==== %@ == %@ == %@",person1,person2,person3);
    // ====2==== <Person: 0x6000015743a0> == (null) == (null)
    // ====2==== (null) == (null) == (null)
    // EXC_BAD_ACCESS
}


@end
