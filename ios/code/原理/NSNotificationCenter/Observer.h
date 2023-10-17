//
//  Observer.h
//  NSNotificationCenter
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Observer : NSObject

@property (nonatomic, assign) NSInteger i;
@property (nonatomic, weak) id<NSObject> observer;

@end

NS_ASSUME_NONNULL_END
