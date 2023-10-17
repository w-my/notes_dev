//
//  Person.h
//  Runtime-动态方法解析
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

// @dynamic  提醒编译器不自动生成 setter getter 方法 和 _name成员变量
// @synthesize 会帮助自动生成成员变量_name 和 setter getter 方法 (现在不需要写了，编译器会自动生成)
// 会自动生成 成员变量 _name setter getter 方法
@property (nonatomic,copy) NSString *name;

- (void)test;

@end

NS_ASSUME_NONNULL_END
