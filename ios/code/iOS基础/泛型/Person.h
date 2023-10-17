//
//  Person.h
//  泛型
//
//  Created by WTW on 2020/2/2.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// __covariant 协变  ： 子类转父类
//@interface Person<__covariant ObjectType> : NSObject

// __contravariant 逆变 ： 父类转子类
@interface Person<__contravariant ObjectType> : NSObject

// 泛型基本使用
//@interface Person<ObjectType> : NSObject

@property (nonatomic,strong) ObjectType language;

@end

NS_ASSUME_NONNULL_END
