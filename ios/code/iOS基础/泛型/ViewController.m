//
//  ViewController.m
//  泛型
//
//  Created by WTW on 2020/2/1.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "Java.h"
#import "Swift.h"
#import "Person.h"

/**
 * 泛型(ios9)：限制类型
 * 为什么推出泛型？迎合 swift
 *
 * 泛型作用：
 * 1、限制类型
 * 2、提高代码规范，减少沟通成本
 *
 * 泛型用法：
 * 类型< 限制类型 *>
 *
 * 泛型的好处：
 * 1、从数组中取元素，可以使用点语法
 * 2、给数组添加元素，有类型提示等
 *
 * 泛型在开发中的使用场景：
 * 1、用于限制集合类型
 *
 * 什么时候使用泛型？
 * 在不确定某些属性或者方法类型，在使用的时候才确定，就可以使用泛型
 * 如果没有定义泛型，默认就是id
 *
 * 自定义 Person 会一些编程语言(iOS，Java)，在声明 Person 时不确定这个人会什么，在使用Person 的时候才知道会什么语言
 *
 *
 *  // __covariant 协变  ： 子类转父类
 *  // __contravariant 逆变 ： 父类转子类
 *  // 用于父子类型转换 (了解即可)
 *
 */

@interface ViewController ()

@property (nonatomic,strong) NSMutableArray<NSString *> *arr;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    _arr[0].length
//    [_arr addObject:<#(nonnull NSString *)#>]
    
    
//    Java *java = [[Java alloc] init];
//
//    Swift *swift = [[Swift alloc] init];
//
//    Person<Swift *> *p1 = [[Person alloc] init];
//    p1.language = swift;
//
//    Person<Java *> *p2 = [[Person alloc] init];
//    p2.language = java;
    
    
    // __covariant 协变  ： 子类转父类
//    Java *java = [[Java alloc] init];
//    Language *language = [[Language alloc] init];
//
//    Person<Java *> *p1 = [[Person alloc] init];
//    p1.language = java;
//
//    Person<Language *> *p2;
//    p2 = p1;
    
    // __contravariant 逆变 ： 父类转子类
    Java *java = [[Java alloc] init];
    Language *language = [[Language alloc] init];
    
    Person<Language *> *p1 = [[Person alloc] init];
    p1.language = language;
    
    Person<Java *> *p2;
    p2 = p1;
}


@end
