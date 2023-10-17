//
//  main.m
//  斐波那契数列
//
//  Created by WTW on 2020/3/15.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

// 斐波那契数列  0 1 1 2 3 5 8 13 .....
// 求第 n 个斐波那契数

/// 递归方式 (效率比较低)
int fib(int n){
    if (n <= 1)  return n;
    return fib(n-1) + fib(n-2);
}

/// 非递归方式 (推荐使用，效率比较高)
int fib2(int n){
    if (n<=1) return n;
    int first = 0;
    int second = 1;
    
//    while (n--) {
//        second += first;
//        first = second - first;
//    }
    
    // n-1 是因为只需要加 n-1次就可以得到第n个数的值
    for (int i = 0; i < n -1; i ++) {
        int sum = first + second;
        first = second;
        second = sum;
    }
    
    return second;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        NSLog(@"递归方式 - 第%d个斐波那契数是%d",6,fib2(6));
        NSLog(@"非递归方式 - 第%d个斐波那契数是%d",6,fib(50));
    }
    return 0;
}

