//
//  Son.m
//  Runtime - super面试题
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Son.h"

@implementation Son

/*
 static void _I_Son_run(Son * self, SEL _cmd) {
    ((void (*)(__rw_objc_super *, SEL))(void *)objc_msgSendSuper)((__rw_objc_super){(id)self, (id)class_getSuperclass(objc_getClass("Son"))}, sel_registerName("run"));
     NSLog((NSString *)&__NSConstantStringImpl__var_folders_5y_yjd90h1x3_l05zb_76wpthp40000gn_T_Son_0574b2_mi_0,__func__);
 }
 */

struct objc_super {
    /// Specifies an instance of a class.
    __unsafe_unretained _Nonnull id receiver; // 消息接受者
    /// Specifies the particular superclass of the instance to message.
    __unsafe_unretained _Nonnull Class super_class;  // 消息接受者父类
};

/**
 * Sends a message with a simple return value to the superclass of an instance of a class.
 *
 * @param super A pointer to an \c objc_super data structure. Pass values identifying the
 *  context the message was sent to, including the instance of the class that is to receive the
 *  message and the superclass at which to start searching for the method implementation.
 * @param op A pointer of type SEL. Pass the selector of the method that will handle the message.
 * @param ...
 *   A variable argument list containing the arguments to the method.
 *
 * @return The return value of the method identified by \e op.
 *
 * @see objc_msgSend
 */
//objc_msgSendSuper(struct objc_super * _Nonnull super, SEL _Nonnull op, ...)

- (void)run {
    
    /*
    objc_msgSendSuper(
       {
           self,
           class_getSuperclass(objc_getClass("Son"))
       }, sel_registerName("run"));
    */
    
    // super 的 reciver 依然是 self (Son)
    // super 的 superclass 表示是从当前类的父类中查找方法
    // Son 从父类中找到 run 方法进行调用
    [super run];
    NSLog(@"%s",__func__);
}


/*
 [super message] 的底层实现：
 1、消息接受者依然是子类对象
 2、从父类的方法列表中查找方法实现
 */


/*
 class 获取当前方法的调用者的类
 superClass获取当前方法的调用者的父类
 
 super 仅仅是一个编译器指示器，就是给编译器看的，不是一个指针
 只要编译器看到super 这个标志，就会让当前对象去调用父类方法，本质还是当前对象在调用。
 self是类的隐藏参数，指向当前调用方法的这个类的实例。而super本质是一个编译器标识符，和self是指向的同一个消息接受者。
 当使用self调用方法时，会从当前类的方法列表中开始查找，如果没有就从父类中再找。
 而当使用super时，则从父类的方法列表中开始找。然后调用父类的这个方法。
 调用 [self class]时，会转化成objc_msgSend函数。
 id objc_msgSend(id self, SEL op, ...)
 调用 [super class]时，会转化成 objc_msgSendSuper 函数。
 id objc_msgSendSuper(struct objc_super *super, SEL op, ...)
 */

- (instancetype)init {
    if (self = [super init]) {
        
        NSLog(@"[self class] == %@",[self class]);  // Son
        NSLog(@"[self superclass] ==%@",[self superclass]);  //Person
        
        NSLog(@"==================");
        
        // [super class] 表示去当前类(Son)的父类(Person)中去找 class 方法，
        // 最终找到NSObject，由于 class 方法最终的实现是在NSObject 中
        // class 方法的返回值取决于消息接收者是谁，由于 reciver 是 Son 所以返回是 Son
        // 结论：super 的消息接收者依然是 self(子类对象) ，只不过调用方法是去父类的方法列表中去找
        NSLog(@"[super class] == %@",[super class]); // Son
        NSLog(@"[super superclass] == %@",[super superclass]); // Person
    }
    return self;
}



@end

// NSObject 的class 的伪代码如下
// class 最终返回的是什么取决于消息接收者
//@implementation NSObject
//
//- (Class)class {
//    return object_getClassName(self);
//}
//- (Class)superclass {
//    return  class_getSuperClass(object_getClass(self));
//}
//
//@end
