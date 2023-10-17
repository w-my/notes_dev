//
//  Person.h
//  Category 原理
//
//  Created by WTW on 2019/7/23.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
//{
//    int _age;
//}
//
//- (void)setAge:(int)age;
//-(int)age;

@property (nonatomic,assign) int age;
/*
 以上代码
 1、会自动生成成员变量 _age 
 2、生成 setter 和 getter 方法的声明
 3、生成 setter 和 getter 方法的实现
 */

@end

NS_ASSUME_NONNULL_END
