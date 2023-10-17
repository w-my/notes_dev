//
//  main.m
//  block-copy
//
//  Created by WTW on 2019/7/26.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 每一种 block copy 后的结果:
 * __NSStackBlock__     栈 -> 从栈复制到堆
 * __NSGlobalBlock__    程序的数据区域 -> 什么也不做
 * __NSMallocBlock__    堆  -> 引用计数加1
 *
 * 所以开发中 一般都是用copy 需要把 block 保存下来
 */

#pragma mark - Block 的 copy

/* block 的 copy 
 在ARC环境下，编译器会根据情况自动将栈上的block复制到堆上，比如以下情况
    block作为函数返回值时
    将block赋值给__strong指针时
    block作为Cocoa API中方法名含有usingBlock的方法参数时
    block作为GCD API的方法参数时
 
 MRC下block属性的建议写法
    @property (copy, nonatomic) void (^block)(void);
 
 ARC下block属性的建议写法
     @property (strong, nonatomic) void (^block)(void);
     @property (copy, nonatomic) void (^block)(void);
 */


typedef void(^Block)(void);
//
//Block myBlock(){
//    // 在 ARC 环境下自动将栈上的 block 拷贝到堆上
//    int age = 10;
//    return ^{
//        NSLog(@"======= %d",age);
//    };
//}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
#pragma mark - Block 作为函数的返回值
       
//        Block block = myBlock();
//        block();  // ======= 10
//        NSLog(@"%@",[block class]); // __NSMallocBlock__
       
#pragma mark - 将 Block 赋值给 __strong 指针时
        
//        int age = 10;
//        Block block = ^{
//            NSLog(@"======= %d",age);
//        };
//        NSLog(@"%@",[block class]); // __NSMallocBlock__
        
#pragma mark - Block作为 Cocoa API 中方法名含有 usingBlock 的方法参数时
        
//        NSArray *arr = [NSArray array];
//        [arr enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//
//        }];
        
#pragma mark - Block作为 GCD API的方法参数时
        
//        dispatch_async(dispatch_get_main_queue(), ^{
//
//        });
    }
    return 0;
}
