//
//  main.m
//  initialize
//
//  Created by WTW on 2019/7/22.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Student.h"
#import "Teacher.h"

/**
 *  +initialize方法会在类第一次接收到消息时调用
 *  有以下特点：
 *  如果子类没有实现+initialize，会调用父类的+initialize（所以父类的+initialize可能会被调用多次）
 *  如果子类实现了 +initialize ，父类的 +initialize 就只会调用一次(原因是因为子类没有实现会去调用父类的initialize方法)
 *  如果分类实现了+initialize，就覆盖类本身的+initialize调用
*/

/**
 子类没有实现，多次调用父类的原因分析： 实际上还是 objc_MsgSend() 的原理的理解
 子类没有初始化会先初始化父类再初始化子类，如果父类初始化过了就直接初始化子类，由于子类没有实现对应的方法，所以会调用父类的+initialize方法，所以就会多次调用父类的 +initialize 方法
 */

/**
 * 面试题：
 * 1、load、initialize方法的区别什么？它们在category中的调用的顺序？以及出现继承时他们之间的调用过程？
 *      +initialize和+load的很大区别是：
 *          调用方式的区别：
 *              +load方法是根据方法(函数)地址直接调用，并不是经过objc_msgSend函数调用
 *              +initialize是通过objc_msgSend进行调用的
 *           调用时刻的区别：
 *               + load 在 runtime 加载类 分类时调用(只调用一次)
 *               + initialize 是类第一次接收到消息的时候调用，每个类只会 + initialize 一次，(如果子类没有实现+ initialize,父类的+initialize可能会被调用多次)
    *                                  if (Student没有初始化) {
                         if (Person 父类没有初始化) {  // 先调用父类的  initialize
                             objc_msgSend([Person class],@selector(initialize));
                         }
                         // 在调用自己的 initialize
                         objc_msgSend([Student class],@selector(initialize));
                   }
 *
 *            调用顺序的区别：
 *               + load 是先调用类的load(先编译，优先调用，调用子类的load 方法之前，会先调用父类的load)，再调用分类的 load(先编译的分类，优先调用)
 *               + initialize 先初始化父类，再初始化子类(最终可能调用的是父类的 + initialize 方法)
 *
 *
 *      +initialize调用顺序
 *          先调用父类的+initialize，再调用子类的+initialize
 *          (先初始化父类，再初始化子类，每个类只会初始化1次)
 *      load 方法调用顺序：
 *          1、先调用类的+load
 *              按照编译先后顺序调用（先编译，先调用）
 *              调用子类的+load之前会先调用父类的+load
 *          2、再调用分类的+load
 *              按照编译先后顺序调用（先编译，先调用）
 */

/**
 * 源码解读过程:
 * objc-msg-arm64.s
 *      objc_msgSend
 * objc-runtime-new.mm
 *      class_getInstanceMethod
 *      lookUpImpOrNil
 *      lookUpImpOrForward
 *      _class_initialize
 *      callInitialize
 *      objc_msgSend(cls, SEL_initialize)
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
//        Person *p = [[Person alloc] init];
        
        Student *s = [[Student alloc] init];
        Teacher *t = [[Teacher alloc] init];
    }
    return 0;
}
