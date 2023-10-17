//
//  ViewController.m
//  const static extern define使用
//
//  Created by WTW on 2020/2/4.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "GlobalConst.h"

/**
 * 宏
 *    通常是把常用的字符串、变量定义成宏
 * const
 *     苹果推荐使用 const
 *     常用来修饰右边的 基本变量 或 者指针变量
 *     被 const 修饰的变量只能 只读(不能修改)
 *     用法：
 *      用于修饰全局变量
 *      修饰方法中的参数
 *
 *  const  和 宏的区别：
 *      1、编译时刻：
 *          宏 预编译阶段
 *          const 编译阶段
 *      2、编译检查：
 *          宏没有编译检查
 *          const 有编译检查
 *      3、宏的好处
 *          宏可以定义函数、方法
 *          const 可以定义函数方法
 *      宏的坏处：
 *          大量使用宏，会导致编译时间过长
 */

// 宏定义
#define XX_K_NAME_KEY @"name"
#define XX_K_DEFAULT [NSUserDefaults standardUserDefaults]

// const 修饰全局只读变量 (常用，代替宏)
NSString *const name = @"name";

/**
 * static :
 * 1、修饰局部变量，被 static 修饰的局部变量，延长生命周期，跟整个应用程序有关
 *    * 被 static 修饰的局部变量，只会分配一次内存
 *    * 被 static 修饰的局部变量什么时候分配内存？程序一运行就会给 static 修饰的变量分配内存
 * 2、修饰全局变量， 被 static 修饰的全局变量，只能在当前文件下使用
 *
 * extern ：
 *  声明外部全局变量，注意：extern 只能用于声明，不能用于定义
 *  工作原理：会先去当前文件下查找有没有对应的全局变量，没有才会去其他文件查找
 *
 *  static 和 const 联合使用：
 *      static 保证全局变量自能在当前文件中使用
 *      const  保证全变量不能被修改(只读)
 *
 *  extern 和 const 联合使用 (常用)
 *      一般默认的规定，全局变量不定义在自己的类中，一般是定义在一个独立的全局文件中
 */

// static 和 const 联合使用
// static 保证全局变量自能在当前文件中使用
// const  保证全变量不能被修改
static NSString * const userName = @"userName";

@interface ViewController ()

@end

@implementation ViewController

// 定义一个全局变量 在别的文件下通过 extern 声明
int i = 20;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"%@ %@",XX_K_NAME_KEY,XX_K_DEFAULT);
    
    // const 修饰的变量 只能读 不能修改
    // 修饰基本变量
    int const a = 20;
    // a = 15;  // Cannot assign to variable 'a' with const-qualified type 'const int'

    // 修饰指针变量
    int b = 3;
//    int *p = &b;
//    p = &a;
    
//    int * const p = &b;
    // p = &a; // 报错 不能修改
    
//    int const *p = &b;
//    p = &a;  // 可以修改
    
    // 面试题
    int * const p; // p : 只读，不能修改  *p : 可以修改
    int const * p1; // p1 : 变量  *p1: 只读
    const int * p2; // p2 : 变量  * p2 : 只读
    const int * const p3;  // p3 : 只读  * p3 : 只读
    int const * const p4;  // p4 : 只读  * p4 : 只读
    
    // extern & const
    NSLog(@"%@ %@",xx_name,xx_userName);
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    // 使用 static 就能保证每次都是累加1
    static int a = 0;
    a ++;
    NSLog(@"%d",a);
}

@end
