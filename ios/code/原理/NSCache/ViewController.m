//
//  ViewController.m
//  NSCache
//
//  Created by WTW on 2019/10/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

/*
 苹果官方提供的一个缓存类，具体使用和 NSDictionary 类似，在 AFN 和 SD 中用来管理缓存
 在系统内存很低时会自动释放对象 (模拟器不会,建议收到内存警告时主动调用 removeAllObjects 方法释放对象)
 NSCahce 是线程安全的，在多线程操作中，不需要对 NSCache 加锁
 NSCache 只是对对象进行Strong 引用，不是拷贝
 */

@interface ViewController ()<NSCacheDelegate>

@property (nonatomic,strong) NSCache *cache;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 创建 Cache 缓存对象
    _cache = [[NSCache alloc] init];
    
    //设置缓存中对象的最大个数是5
    _cache.countLimit = 5;
    
    //设置代理
    _cache.delegate = self;
    
    //创建字符串类型对象添加进缓存,Test 作为key
    NSString *test = @"hello world";
    [_cache setObject:test forKey:@"Test"];
    
    for (int i = 0; i < 10; i ++) {
        NSString *key = [NSString stringWithFormat:@"key %d",i];
        NSString *object = [NSString stringWithFormat:@"object %d",i];
        [_cache setObject:object forKey:key];
        NSLog(@"Add key:%@  object:%@ to Cache", key, object);
    }
    
    for (int i = 0; i < 10; i++)
    {
        NSLog(@"Get object:%@ for key:%@", [_cache objectForKey:[NSString stringWithFormat:@"key %d", i]], [NSString stringWithFormat:@"object %d", i]);
    }
    
    //删除所有的缓存
    [_cache removeAllObjects];
    
    for (int i = 0; i < 10; i++)
    {
         NSLog(@"Get object:%@ for key:%@", [_cache objectForKey:[NSString stringWithFormat:@"key %d", i]], [NSString stringWithFormat:@"object %d", i]);
    }
}

#pragma mark - NSCacheDelegate
// 缓存中的任一个对象即将被删除时被回调
- (void)cache:(NSCache *)cache willEvictObject:(id)obj {
    NSLog(@"NSCacheDelegate ==> cache %@  obj ==> %@",cache,obj);
}

@end

/*
 //第一个for 循环
  23:17:56.610234  Add key:key 0  object:object 0 to Cache
  23:17:56.610520  Add key:key 1  object:object 1 to Cache
  23:17:56.610668  Add key:key 2  object:object 2 to Cache
  23:17:56.610982  Add key:key 3  object:object 3 to Cache
  23:17:56.611201  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> hello world
  23:17:56.611523  Add key:key 4  object:object 4 to Cache
  23:17:56.611789  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 0
  23:17:56.612210  Add key:key 5  object:object 5 to Cache
  23:17:56.612647  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 1
  23:17:56.613002  Add key:key 6  object:object 6 to Cache
  23:17:56.613430  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 2
  23:17:56.613812  Add key:key 7  object:object 7 to Cache
  23:17:56.614232  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 3
  23:17:56.614624  Add key:key 8  object:object 8 to Cache
  23:17:56.615054  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 4
  23:17:56.615379  Add key:key 9  object:object 9 to Cache
 
 // 第二个 for 循环
  23:17:56.615743  Get object:(null) for key:object 0
  23:17:56.616073  Get object:(null) for key:object 1
  23:17:56.649675  Get object:(null) for key:object 2
  23:17:56.649830  Get object:(null) for key:object 3
  23:17:56.649979  Get object:(null) for key:object 4
  23:17:56.650102  Get object:object 5 for key:object 5
  23:17:56.650222  Get object:object 6 for key:object 6
  23:17:56.650365  Get object:object 7 for key:object 7
  23:17:56.650499  Get object:object 8 for key:object 8
  23:17:56.650733  Get object:object 9 for key:object 9
 
 // removeAllObjects
  23:17:56.651233  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 5
  23:17:56.651690  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 6
  23:17:56.652250  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 7
  23:17:56.652551  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 8
  23:17:56.653095  NSCacheDelegate ==> cache <NSCache: 0x600003df6380>  obj ==> object 9
 
 // 最后一个 for 循环
  23:17:56.653673  Get object:(null) for key:object 0
  23:17:56.654057  Get object:(null) for key:object 1
  23:17:56.654333  Get object:(null) for key:object 2
  23:17:56.654739  Get object:(null) for key:object 3
  23:17:56.655359  Get object:(null) for key:object 4
  23:17:56.655793  Get object:(null) for key:object 5
  23:17:56.693196  Get object:(null) for key:object 6
  23:17:56.693382  Get object:(null) for key:object 7
  23:17:56.693529  Get object:(null) for key:object 8
  23:17:56.693649  Get object:(null) for key:object 9

 */
