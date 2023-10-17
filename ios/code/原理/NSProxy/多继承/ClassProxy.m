//
//  ClassProxy.m
//  NSProxy
//
//  Created by WTW on 2020/3/9.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ClassProxy.h"
#import <objc/runtime.h>

@interface ClassProxy()

@property(nonatomic,strong) NSMutableArray *targetArray;//多个targets皆可代理
@property(nonatomic,strong) NSMutableDictionary *methodDic;

@end

@implementation ClassProxy

-(void)handleTargets:(NSArray *)targets
{
    if (targets && targets.count) {
        [self.targetArray addObjectsFromArray:targets];
        [self regist];
    }
}
-(void)regist{
    [self.targetArray enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [self registMethodWithTarget:obj];
    }];
}

-(void)registMethodWithTarget:(id)target {
    unsigned int countOfMethods = 0;
    Method *method_list = class_copyMethodList([target class], &countOfMethods);
    for (int i = 0; i<countOfMethods; i++) {
        Method method = method_list[i];
        //得到方法的符号
        SEL sel = method_getName(method);
        //得到方法的符号字符串
        const char *sel_name = sel_getName(sel);
        //得到方法的名字
        NSString *method_name = [NSString stringWithUTF8String:sel_name];
        self.methodDic[method_name] = target;
    }
    free(method_list);
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel {

    NSMethodSignature *signature;
    
    NSString *methodName = NSStringFromSelector(sel);
    id target = self.methodDic[methodName];
    if (target) {
        signature = [target methodSignatureForSelector:sel];
    }else {
        signature = [super methodSignatureForSelector:sel];
    }
    
    return  signature;
}

- (void)forwardInvocation:(NSInvocation *)invocation {
    
    SEL sel = invocation.selector;
    NSString *methodName = NSStringFromSelector(sel);
    id target = self.methodDic[methodName];
    if (target) {
        [invocation invokeWithTarget:target];
    }
}

-(NSMutableArray *)targetArray{
    if (!_targetArray) {
        _targetArray = [[NSMutableArray alloc] initWithCapacity:2];
    }
    return _targetArray;
}
-(NSMutableDictionary *)methodDic{
    if (!_methodDic) {
        _methodDic = [NSMutableDictionary dictionaryWithCapacity:2];
    }
    return _methodDic;
}

@end
