//
//  Person.m
//  atomic
//
//  Created by WTW on 2019/8/5.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

// atomic 修饰的属性的内部实现 
//- (void)setName:(NSString *)name {
//     //atomic 下就会经历加锁和解锁的过程
//    //加锁
//    _name = name;
//    //解锁
//}
//
//- (NSString *)name {
//    //atomic 下就会经历加锁和解锁的过程
//    //加锁
//    //解锁
//    return _name;
//}


//MARK: noatomic (未加锁)
//@synthesize name = _name;
//
//- (void)setName:(NSString *)name{
//    if (_name != name){
//        [_name release];
//        _name = [name retain];
//    }
//}
//
//- (NSString *)name {
//    return  _name;
//}

//MARK: atomic  (加有同步锁)
//@synthesize _name;
//
// set
//- (void)setName:(NSString *)name {
//    @synchronized (self) {
//        if (_name != name){
//            [_name release];
//            _name = [name retain];
//        }
//    }
//}
//
////get
//-(UIImage *)name
//{
//    NSString *name = nil;
//    @synchronized (self) {
//
//        name = [[_name retain] autorelease];
//    }
//    return name;
//}

@end
