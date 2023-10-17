//
//  main.m
//  load
//
//  Created by WTW on 2019/7/22.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 面试题
 * 1、Category中有load方法吗？load方法是什么时候调用的？load 方法能继承吗？
 *      有load方法
 *      +load方法在 runtime 加载类、分类的时候调用
 *      +load方法可以继承，但是一般情况下不会主动去调用load方法，都是让系统自动调用，
 *      调用顺序： (先调用类的，再调用分类的)
 *          1、先调用类的+load
 *              按照编译先后顺序调用（先编译，先调用）
 *              调用子类的+load之前会先调用父类的+load
 *          2、再调用分类的+load
 *              按照编译先后顺序调用（先编译，先调用）
 */

/**
 * 每个类、分类的+load，在程序运行过程中只调用一次
 *
 * 源码解读： objc-os.mm
 * _objc_init
 *
 * load_images
 *
 * prepare_load_methods
 *      schedule_class_load
 *      add_class_to_loadable_list
 *      add_category_to_loadable_list
 *
 * call_load_methods
 *      call_class_loads
 *      call_category_loads
 *      (*load_method)(cls, SEL_load)
 *
 *  +load方法是根据方法地址直接调用，并不是经过objc_msgSend函数调用
 *  其他类方法是通过 objc_MsgSend() 来调用的，走的是分类的那个流程
 */


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
    }
    return 0;
}
