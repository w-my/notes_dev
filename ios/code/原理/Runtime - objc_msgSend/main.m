//
//  main.m
//  Runtime - objc_msgSend
//
//  Created by WTW on 2019/8/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import <objc/message.h>

/*
 OC中的方法调用，其实都是转换为objc_msgSend函数的调用
 objc_msgSend的执行流程可以分为3大阶段
    消息发送
    动态方法解析
    消息转发
 */

/*
 源码跟读：
 objc-msg-arm64.s
    ENTRY _objc_msgSend
    b.le    LNilOrTagged
    CacheLookup NORMAL
    .macro CacheLookup
    .macro CheckMiss
    STATIC_ENTRY __objc_msgSend_uncached
    .macro MethodTableLookup
    __class_lookupMethodAndLoadCache3
 
 objc-runtime-new.mm
    _class_lookupMethodAndLoadCache3
    lookUpImpOrForward
    getMethodNoSuper_nolock、search_method_list、log_and_fill_cache
    cache_getImp、log_and_fill_cache、getMethodNoSuper_nolock、log_and_fill_cache
    _class_resolveInstanceMethod // 动态方法解析
    _objc_msgForward_impcache  // 消息转发

 objc-msg-arm64.s
    STATIC_ENTRY __objc_msgForward_impcache
    ENTRY __objc_msgForward

 Core Foundation
    __forwarding__（不开源
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
       
        // 消息机制的作用：可以调用私有方法
        
        /*
         Person *person = ((Person *(*)(id, SEL))(void *)objc_msgSend)((id)((Person *(*)(id, SEL))(void *)objc_msgSend)((id)objc_getClass("Person"), sel_registerName("alloc")), sel_registerName("init"));
         ((void (*)(id, SEL))(void *)objc_msgSend)((id)person, sel_registerName("personTest"));
         
         // OC 的方法调用： 消息机制 给方法调用者发送消息
         // 消息接收者(receiver)：person
         // 消息名称:personTest
         // objc_msgSend(person, sel_registerName("personTest"))
        */
        
        //sel_registerName("personTest") == @selector(personTest);
//        NSLog(@"%p %p",sel_registerName("personTest"),@selector(personTest));  // 0x100000f96 0x100000f96
        
        Person *person = [[Person alloc] init];
//        [person personTest];
        
        // build Settings 修改： Enable Strict Checking of objc_msgSend Calls  NO 即可如下调用
//        objc_msgSend(person,sel_registerName("personTest"));
        
//        objc_msgSend(person, @selector(personTest));
        
        // 带有参数的调用方式
//        objc_msgSend(person, @selector(personTest:),20);
        
    }
    return 0;
}
