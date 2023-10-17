//
//  PersonC.m
//  Runtime-动态方法解析
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "PersonC.h"
#import <objc/runtime.h>

@implementation PersonC


// 任何方法都默认的两个参数 self , _cmd (当前方法的方法编号)
void otherRun(id self,SEL _cmd,NSNumber *meter){
    NSLog(@"跑了%@米",meter);
}

+ (BOOL)resolveInstanceMethod:(SEL)sel {

    if (sel == NSSelectorFromString(@"run:")) {

        // class_addMethod(Class _Nullable cls, SEL _Nonnull name, IMP _Nonnull imp, const char * _Nullable types)
        // cls ： 给哪个类动态添加方法
        // name : 添加方法的方法名
        // imp : 方法实现
        // types :  方法类型 (返回值 + 参数类型)
        // v: void
        // @ : 对象 -> self
        // :  表示SEL->_cmd
        class_addMethod(self, sel, (IMP)otherRun, "v@:@");

        return YES;
    }

    // 返回父类的默认调用
    return [super resolveInstanceMethod:sel];
}

//+ (BOOL)resolveClassMethod:(SEL)sel {
//    if (sel == NSSelectorFromString(@"test1")) {
//        
//        class_addMethod(object_getClass(self), sel, (IMP)otherRun, "v@:@");
//
//        return YES;
//    }
//    return [super resolveClassMethod:sel];
//}

@end
