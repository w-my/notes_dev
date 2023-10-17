//
//  Person+Test.h
//  Category 原理
//
//  Created by WTW on 2019/7/23.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

NS_ASSUME_NONNULL_BEGIN

@interface Person (Test)
//{
//    int _age;
//}
//
//- (void)setAge:(int)age;
//-(int)age;

//@property (nonatomic,assign) int age;
/*
 * 分类中添加属性只会生成成员变量和setter getter方法的声明
   不会生成实现
 *
 * 如果添加属性需要自己去实现 getter 和 setter 方法
 */

@property (nonatomic,assign) int weight;
@property (nonatomic,copy) NSString *name;

// 直接设置会报错 unrecognized selector sent to instance 0x100502b60

- (void)test1;

+ (void)test2;

@end

NS_ASSUME_NONNULL_END
