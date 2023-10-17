//
//  Person.h
//  __kindof
//
//  Created by WTW on 2020/2/2.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

// Xcode5 以后才可以使用 instancetype
// Xcode5 以前使用 id

// instancetype 能够识别当前类的对象
// id 可以调用任何对象方法，不能进行编译检查
//+ (instancetype)person;

// __kindof 表示当前类或者它的子类
+ (__kindof Person *)person;

@end

NS_ASSUME_NONNULL_END
