//
//  PthreadMutexDemo2.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/2.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "PthreadMutexDemo2.h"
#import <pthread.h>

// pthreadMutex 条件的使用
/*
 使用情况 ：线程等待（线程依赖） 比如 1 等2 完成后再执行1
 
 类似生产者 消费者模式，必须生产完才能消费
 
 */
@interface PthreadMutexDemo2 ()
@property (nonatomic,assign) pthread_mutex_t mutex;

@property (assign,nonatomic) pthread_cond_t condt;
@property (nonatomic,strong) NSMutableArray *data;  // 数组先添加元素 再删除元素
@end

@implementation PthreadMutexDemo2

- (instancetype)init {
    if (self = [super init]) {
        //初始化属性
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_DEFAULT);
        //初始化锁
        pthread_mutex_init(&_mutex, &attr);
        //销毁属性
        pthread_mutexattr_destroy(&attr);
        
        //初始化条件
        pthread_cond_init(&_condt, NULL);
        
        self.data = [NSMutableArray array];
    }
    return self;
}

/*
 有数据才删
 没有数据就不去删
 删除和添加在不同的线程中
 */
- (void)otherTest {
    
    [[[NSThread alloc] initWithTarget:self selector:@selector(__remove) object:nil] start];
    sleep(1);
    [[[NSThread alloc] initWithTarget:self selector:@selector(__add) object:nil] start];

}

//删除数组中的元素
- (void)__remove {
    
    pthread_mutex_lock(&_mutex);
    
    if (self.data.count == 0) {
        //等待 等待的同时会把锁放开
        pthread_cond_wait(&_condt, &_mutex);
    }
    
    [self.data removeLastObject];
    NSLog(@"删除元素");
    
    pthread_mutex_unlock(&_mutex);
}

//往数组中添加元素
- (void)__add {
    
    pthread_mutex_lock(&_mutex);
    
    [self.data addObject:@"Test"];
    NSLog(@"添加元素");
    
    //唤醒等待线程
    pthread_cond_signal(&_condt);
    //广播 唤醒所有等待条件的线程
    //pthread_cond_broadcast(&_condt);
    
    pthread_mutex_unlock(&_mutex);
    
}

- (void)dealloc {
    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_condt);
}



















@end
