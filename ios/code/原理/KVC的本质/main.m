//
//  main.m
//  KVC的本质
//
//  Created by WTW on 2019/7/18.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Observer.h"

/*
 KVC 的原理：
 
 setValue:forKey: 原理：
 首先按照 setKey: _setKey 顺序查找方法，找到了就传递参数调用方法
 如果没找到 就会查看 accessInstanceVariablesDirectly(默认返回值是YES) 方法的返回值，
 如果是NO 调用setValue:forUndefinedKey: 并抛出异常NSUnknownKeyException;
 如果是YES 按照 _key _isKey key isKey 顺序查找成员变量，找到了就直接赋值，找不到就报错

 通过 KVC 设置 age 属性内部的的本质就是先调用 willChangeValueForKey 再调用 didChangeValueForKey，
 [person willChangeValueForKey:@"age"];
 person->_age = 20;
 [person didChangeValueForKey:@"age"];
 
 valueForKey:的原理
 先按照 getKey key isKey _key 顺序查找方法，如果找到了就直接调用方法
 如果没有找到方法，查看 accessInstanceVariablesDirectly(默认返回值是YES) 方法的返回值
 如果返回 YES 按照 _key _isKey key isKey 顺序查找成员变量，找到了就直接取值，找不到就报错
 如果没有找到 调用valueForUndefinedKey: 并抛出异常NSUnknownKeyException
 */


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Observer *observer = [[Observer alloc] init];
        Person *person = [[Person alloc] init];
        
        //添加KVO 监听
        [person addObserver:observer forKeyPath:@"age" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:nil];
       
        [person setValue:@20 forKey:@"age"];
        
         // 通过 KVC 设置 age 属性内部的的本质就是先 调用willChangeValueForKey 再调用 didChangeValueForKey
//        [person willChangeValueForKey:@"age"];
//        person->_age = 20;
//        [person didChangeValueForKey:@"age"];
        
        
        
        [person valueForKey:@"age"];
        
    }
    return 0;
}
