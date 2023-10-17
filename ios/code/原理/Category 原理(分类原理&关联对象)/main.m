//
//  main.m
//  Category 原理
//
//  Created by WTW on 2019/7/19.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Person+Test.h"

/** 常见面试题：
 *  1、Category能否添加成员变量？如果可以，如何给Category添加成员变量？
 *      不能直接给Category添加成员变量，但是可以间接实现Category有成员变量的效果
 *
 * 2、Category 的实现原理：
        Category编译之后的底层结构是struct category_t，里面存储着分类的对象方法、类方法、属性、协议信息
        在程序 运行 的时候，runtime会将Category的数据，合并到类信息中（类对象、元类对象中）
 *
 * 3、Category和Class Extension的区别是什么？
        Class Extension在编译的时候，它的数据就已经包含在类信息中
        Category是在运行时，才会将数据合并到类信息中
 *
 * 分类之所以覆盖类的方法原因：
        分类最后参与编译，分类的方法列表会追加到原来类的方法列表中，并且是在前面，所以调用类的方法时去方法列表中找的时候先找到前面分类的实现，类似被覆盖的效果
 *       （ memmove  memcpy，先把原来的方法往后移动，再把分类的方法列表拷贝到原来的位置）
 */

/**
 * Category 的加载处理过程
 *      通过Runtime加载某个类的所有Category数据
 *      把所有Category的方法、属性、协议数据，分别合并到一个大数组中
 *      后面参与编译的Category数据，会在数组的前面
 *      将合并后的分类数据（方法、属性、协议），插入到类原来数据的前面
 *
 * 源码的阅读顺序：
 * objc-os.mm
 *      _objc_init
 *      map_images
 *      map_images_nolock
 *
 *  objc-runtime-new.mm
 *      _read_images
 *       remethodizeClass
 *       attachCategories
 *       attachLists
 *       realloc、memmove、 memcpy
 */

/*
 Category 的底层结构:（objc-runtime-new.h）
 struct category_t {
     const char *name; // 类名
     classref_t cls;
     struct method_list_t *instanceMethods;  // 实例方法列表
     struct method_list_t *classMethods;     // 类方法列表
     struct protocol_list_t *protocols;      // 协议列表
     struct property_list_t *instanceProperties; // 属性列表
     // Fields below this point are not always present on disk.
     struct property_list_t *_classProperties;

     method_list_t *methodsForMeta(bool isMeta) {
         if (isMeta) return classMethods;
         else return instanceMethods;
     }

     property_list_t *propertiesForMeta(bool isMeta, struct header_info *hi);
 };
 */


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Person *person = [[Person alloc] init];
        person.age = 10;
        person.weight = 20;
        person.name = @"哈哈";
        
        NSLog(@"age:%d weight:%d name:%@",person.age,person.weight,person.name);
    }
    return 0;
}
