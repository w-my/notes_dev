//
//  Person.h
//  内存管理-copy
//
//  Created by WTW on 2019/9/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

// NSArray 因为是 浅拷贝 所以是没问题的
// NSMutableArray 是深拷贝 所以会出现问题 被拷贝成不可变
// 一般开发中对于数组使用 strong 而不用 copy

// 对于字符串一般是使用 copy 为了防止被修改 （copy 成不可变）
@property (nonatomic,copy) NSString *name;

//@property (nonatomic,copy) NSArray *data;

// 不存在 mutableCopy
@property (nonatomic,copy) NSMutableArray *data;

@end

NS_ASSUME_NONNULL_END
