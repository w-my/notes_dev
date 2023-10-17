//
//  AOPProxy.m
//  NSProxy
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "AOPProxy.h"

@interface AOPProxy ()

@property(nonatomic,strong)NSMutableDictionary *preSelTaskDic;
@property(nonatomic,strong)NSMutableDictionary *endSelTaskDic;

@end

@implementation AOPProxy

-(instancetype)initWithTarget:(id)target{
    self.target = target;
    return self;
}

+(instancetype)proxyWithTarget:(id)target{
    return [[self alloc] initWithTarget:target];
}

-(void)inspectSelector:(SEL)selector preSelTask:(proxyBlock)preTask endSelTask:(proxyBlock)endTask{
    NSString *selKey = NSStringFromSelector(selector);
    if (preTask) {
        self.preSelTaskDic[selKey] = preTask;
    }
    if (endTask) {
        self.endSelTaskDic[selKey] = endTask;
    }
}
-(NSMethodSignature *)methodSignatureForSelector:(SEL)sel
{
    return [self.target methodSignatureForSelector:sel];
}
-(void)forwardInvocation:(NSInvocation *)invocation{
    NSString *selKey = NSStringFromSelector(invocation.selector);
    proxyBlock pretask =self.preSelTaskDic[selKey];
    proxyBlock endtask = self.endSelTaskDic[selKey];
    if (pretask) {
        pretask(self.target,invocation.selector);
    }
    
    [invocation invokeWithTarget:self.target];
    
    if (endtask) {
        endtask(self.target,invocation.selector);
    }
    
}

-(NSMutableDictionary *)preSelTaskDic{
    if (!_preSelTaskDic) {
        _preSelTaskDic = [NSMutableDictionary dictionaryWithCapacity:1];
    }
    return _preSelTaskDic;
}
-(NSMutableDictionary *)endSelTaskDic{
    if (!_endSelTaskDic) {
        _endSelTaskDic = [NSMutableDictionary dictionaryWithCapacity:1];
    }
    return _endSelTaskDic;
}

@end
