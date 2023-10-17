//
//  AOPProxy.h
//  NSProxy
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^proxyBlock)(id target,SEL selector);

@interface AOPProxy : NSProxy

@property(nonatomic,strong)id target;

+(instancetype)proxyWithTarget:(id)target;

/// <#Description#>
/// @param selector 需要 hook 的方法名
/// @param preTask  hook 方法后执行前执行的block
/// @param endTask hook 方法后执行后执行的block 
-(void)inspectSelector:(SEL)selector preSelTask:(proxyBlock)preTask endSelTask:(proxyBlock)endTask;
@end

NS_ASSUME_NONNULL_END
