//
//  MyOperation.h
//  自定义NSOperation
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyOperation : NSOperation

@property (nonatomic,assign,getter=isExecuting) BOOL executing;
@property (nonatomic,assign,getter=isFinished)  BOOL finished;

@end

NS_ASSUME_NONNULL_END
