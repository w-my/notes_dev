//
//  Person.h
//  KVO的本质
//
//  Created by wtw on 2019/3/29.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

- (void)personTest;

@property (nonatomic,assign) int age;

@end

NS_ASSUME_NONNULL_END
