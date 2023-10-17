//
//  RCProxy.h
//  NSTimer使用注意事项
//
//  Created by wtw on 2018/8/30.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

// NSProxy 对象不需要调用 init 方法，因为 NSProxy 没有init 方法
// 主要就是用来做消息转发
// 先从自己类中搜索，如果搜索不到直接走消息转发，不去父类中搜索

@interface RCProxy : NSProxy
// 必须声明为weak 以解除循环引用
@property (nonatomic, weak, readonly) id target;
-(instancetype)initWithTarget:(id)target;
+(instancetype)proxyWithTarget:(id)target;
@end
