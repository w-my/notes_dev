//
//  MyPoint.h
//  JavaScriptCore学习
//
//  Created by WTW on 2020/3/22.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

NS_ASSUME_NONNULL_BEGIN

@class MyPoint;

@protocol MyPointExports <JSExport>

@property double x;
@property double y;

- (NSString *)description;
+ (MyPoint *)makePointWithX:(double)x
                          y:(double)y;

@end

@interface MyPoint : NSObject<MyPointExports>

// Not in the MyPointExports protocol,so not visible to JavaScript code
- (void)myPrivateMethod;

@end

NS_ASSUME_NONNULL_END
