//
//  Student.m
//  Runtime-super的本质
//
//  Created by WTW on 2019/9/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Student.h"

@implementation Student

- (void)print {
    [super print];
    
    
    // 转换为C++ 代码后如下：
//      ((void (*)(__rw_objc_super *, SEL))(void *)objc_msgSendSuper)((__rw_objc_super){(id)self, (id)class_getSuperclass(objc_getClass("Student"))}, sel_registerName("print"));
    
//    struct objc_super = {
//        self,
//        [Person class];
//    }
//     objc_msgSendSuper(objc_super, sel_registerName("print"));
    
    
    // 可以看到调用super 的底层实质是转换为 objc_msgSendSuper2，而不是 objc_msgSendSuper
    /*
     struct objc_super2 {
        id receiver; // 消息接收者
        Class current_class;  // receiver 的 Class 对象
     }
     */
    
//    struct objc_super2 = {
//                self,
//                [Student class];  //实际调用的时候还是会去调用 [Student class]->superClass 
//            }
//    objc_msgSendSuper2(objc_super2, sel_registerName("print"));
    
   
    
    // 调试技巧
    /*
     方式一、直接打断点 Debug -> Debug Workflow -> Always Show Disassembly
     方式二、Product -> Perform Action -> Assemble xxx 直接就能把当前文件转换成汇编代码
     方式三、通过 clang 指令转换为C++ 代码
     */
    
    int a = 10;
}

@end
