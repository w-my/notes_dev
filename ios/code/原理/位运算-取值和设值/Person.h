//
//  Person.h
//  位运算-取值和设值
//
//  Created by WTW on 2019/4/24.
//  Copyright © 2019 rocedar. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

- (BOOL)isTall;
- (BOOL)isRich;
- (BOOL)isHandSome;

- (void)setTall:(BOOL)tall;
- (void)setRich:(BOOL)rich;
- (void)setHandSome:(BOOL)handsome;

@end

NS_ASSUME_NONNULL_END
