//
//  Person.h
//  atomic
//
//  Created by WTW on 2019/8/5.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

@property (nonatomic,assign) int age;
@property (nonatomic,copy) NSString *name;

// 不写默认是 atomic 的
@property (copy) NSString *address;

/*
 nonatomic 和 atomic
 
 atom : 原子 线程安全，需要消耗大量的资源
 nonatomic : 原子性 非线程安全的  适合内存小的移动设备
 
 给属性加上 atomic 修饰，可以保证属性 setter 和 getter 都是原子性操作，
 也就是保证 setter 和 getter 内部是线程同步(加锁)的 (objc-accessors.mm 可以跟源码证实)
 - setter {
    lock
    ...
    unlock
 }
 它并不能保证是绝对的线程安全的(仅仅 setter 和 getter 读写是线程安全的),因为属性除了读写还有其他操作，比如一个线程对其进行读写操作，另一个线程对其进行 realease 操作，也是会导致崩溃的
 
 为什么还用nonatomic ？
 atomic  太消耗性能，因为 setter 和 getter 调用的次数比较多
 对同一个对象进行多线程操作的时候才会出现多线程资源抢占的问题 （在iOS中一般很少出现）
 
 iOS 开发建议：
 所有的属性都声明为 nonatomic
 尽量避免多线程抢夺同一块资源
 尽量将加锁、资源抢夺的业务逻辑交给服务器处理，减少移动端的压力
 
 总结：
 atomic 只能保证 getter 和 setter 存取方法的线程安全，并不能保证整个对象是线程安全的，因此在多线程编程时，线程安全还是需要开发者自己来处理
 atomic 系统生成的 getter 和 setter 会保证 set 和 get 操作的安全性，相对 noatomic 来说，atomic 更消耗资源，速度慢，因此在iPhone小型设备上，如果没有多线程之间的通讯，使用 noatomic 是最好的选择
 */


@end

NS_ASSUME_NONNULL_END
