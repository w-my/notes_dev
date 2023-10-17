//
//  main.m
//  Runtime-cache
//
//  Created by WTW on 2019/9/16.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MJGoodStudent.h"
#import "MJClassInfo.h"

/*
 Class内部结构中有个方法缓存（cache_t），用散列表（哈希表）来缓存曾经调用过的方法，可以提高方法的查找速度
 objc-cache.mm
 bucket_t * cache_t::find(cache_key_t k, id receiver)
 
 cache 查找过程：（以对象方法为例） 先找cache 没有就遍历方法列表找到就缓存，没有就向上找(父类cache 父类方法列表，找到就缓存在自己的class中，找不到继续向上找)
     1、通过isa查找到指定 class
     2、从 cache 中查找，若存在缓存，则直接调用
     3、若缓存中不存在方法，则在自己的 class 里 bits 的 rw 中(遍历methods)查找方法
     4、若找到该方法则调用，并将方法缓存至cache中
     5、若没有找到，则通过 superclass 找到父类，继续从父类class里 bits 的 rw 中(遍历methods)查找方法
     6、若在父类中找到，则直接调用，并将方法缓存至自己 class 中；若找不到，则一直向上查找
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        MJGoodStudent *goodStudent = [[MJGoodStudent alloc] init];
        mj_objc_class *goodStudentClass = (__bridge mj_objc_class *)[MJGoodStudent class];
        
        // 通过断点观察goodStudentClass 的cache, 一开始  _mask 的长度是 4  当不够用的时候 乘以2 清空之前的缓存 _mask 变成了8
        // 可以通过单步调试根据 _occupied(已占用的) 和 _mask(hash 表的长度) 的值进行验证
        [goodStudent goodStudentTest];  // _mask = 3  _occupied = 2  init / goodStudentTest
        [goodStudent studentTest];      // _mask = 3  _occupied = 3  init / goodStudentTest / studentTest
        // 到此缓存了4个方法，由于一开始的长度是4，所以就会在这里进行扩容，_mask = 7 (hash表长度为8)
        // _occupied = 1 证明了清空了之前的缓存
        [goodStudent personTest];       // _mask = 7  _occupied = 1  personTest
        [goodStudent goodStudentTest];  // _mask = 7  _occupied = 2  personTest / goodStudentTest
        [goodStudent studentTest];      // _mask = 7  _occupied = 3  personTest / goodStudentTest / studentTest
        
        NSLog(@"--------------------------");
        
        
        cache_t cache = goodStudentClass->cache;
        
        NSLog(@"%s %p", @selector(personTest), cache.imp(@selector(personTest)));
        NSLog(@"%s %p", @selector(studentTest), cache.imp(@selector(studentTest)));
        NSLog(@"%s %p", @selector(goodStudentTest), cache.imp(@selector(goodStudentTest)));
        
        bucket_t *buckets = cache._buckets;

        // 根据方法名SEL & _mask   计算对应的 key  根据key 获取对应的 bucket
        bucket_t bucket = buckets[(long long)@selector(studentTest) & cache._mask];
        NSLog(@"key(SEL):%s IMP:%p", bucket._key, bucket._imp);
        
        /*
         2020-02-26 00:02:56.097352+0800 Runtime-cache[38710:7014904] personTest 0x100001970
         2020-02-26 00:02:56.097400+0800 Runtime-cache[38710:7014904] studentTest 0x100001940
         2020-02-26 00:02:56.097490+0800 Runtime-cache[38710:7014904] goodStudentTest 0x100001db0
         
         2020-02-26 00:02:56.097597+0800 Runtime-cache[38710:7014904] key(SEL):studentTest IMP:0x100001940
         */
        
        NSLog(@"----------遍历散列表----------------");
        
        // 遍历获取所有缓存中方法
        for (int i = 0; i <= cache._mask; i++) {
            bucket_t bucket = buckets[i];
            NSLog(@"%s ==  %p", bucket._key, bucket._imp);
        }
        
        /* 通过遍历验证了删列表长度为 8 只有3个位置缓存了对应的方法
         2020-02-26 00:02:56.097775+0800 Runtime-cache[38710:7014904] (null) ==  0x0
         2020-02-26 00:02:56.097825+0800 Runtime-cache[38710:7014904] (null) ==  0x0
         2020-02-26 00:02:56.097872+0800 Runtime-cache[38710:7014904] (null) ==  0x0
         2020-02-26 00:02:56.097941+0800 Runtime-cache[38710:7014904] studentTest ==  0x100001940
         2020-02-26 00:02:56.098102+0800 Runtime-cache[38710:7014904] (null) ==  0x0
         2020-02-26 00:02:56.098152+0800 Runtime-cache[38710:7014904] goodStudentTest ==  0x100001db0
         2020-02-26 00:02:56.098200+0800 Runtime-cache[38710:7014904] (null) ==  0x0
         2020-02-26 00:02:56.098293+0800 Runtime-cache[38710:7014904] personTest ==  0x100001970
         */
    }
    return 0;
}
