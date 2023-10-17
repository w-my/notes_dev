//
//  main.m
//  指针的宽度
//
//  Created by WTW on 2021/4/20.
//  Copyright © 2021 WTW. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
// 指针64位 占8个字节(64bit)

/**
 * 指针自增 自减的结果，其实是指针指向的数据类型 宽度 决定的
 * 指针加上或减去一个整数的结果，其实是指针指向的数据类型 宽度 决定的
 * 指针求差，得到的结果是整形，其结果和指针指向的数据类型 宽度 有关
 * 指针的运算单位，其实就是数据类型的宽度
 */

void func() {
    
    // 编译器决定了指针不能做乘法和除法
    // 指针 运算结果由所指向的数据类型的宽度决定的
    int* a;
    a = (int *)100;
//    a++;
//    printf("%d",a); // 104
    
    int* b;
    b = (int *)200;
    int x = a - b;
    printf("%d",x);// -25      -100/4
    
}



int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
