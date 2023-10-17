//
//  Person.m
//  Runtime-动态方法解析
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"
#import <objc/runtime.h>

@implementation Person

// 提醒编译器不自动生成 setter getter 方法 和 _name成员变量
//@dynamic name;

// @synthesize 会帮助自动生成成员变量_name 和 setter getter 方法
// 现在不需要了，可以省略 编译器会自动生成
//@synthesize name = _name;

- (void)otherTest {
    NSLog(@"%s",__func__);
}

+ (BOOL)resolveInstanceMethod:(SEL)sel {

    if (sel == @selector(test)) {

        //获取需要动态添加的方法
        Method method = class_getInstanceMethod(self, @selector(otherTest));

        //动态添加方法实现
        class_addMethod(self, sel, method_getImplementation(method), method_getTypeEncoding(method));

        // 返回 YES 代表有动态添加的方法
        return YES;
    }
  return [super resolveInstanceMethod:sel];
}

// 如果是C语言函数实现
//void testC(id self,SEL _cmd){
//    NSLog(@"%@ == %@",self,NSStringFromSelector(_cmd));;
//}
//
//+ (BOOL)resolveInstanceMethod:(SEL)sel {
//    if (sel == @selector(test)) {
//        class_addMethod(self, sel, (IMP)testC, "v@:");
//        return YES;
//    }
//
//    return [super resolveInstanceMethod:sel];
//}

@end
