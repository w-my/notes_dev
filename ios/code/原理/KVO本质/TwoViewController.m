//
//  Cat.m
//  KVO本质
//
//  Created by WTW on 2020/4/17.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "TwoViewController.h"

static void *TwoViewControllerObserverContext = @"TwoViewControllerContext";

@implementation TwoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = NSStringFromClass([self class]);
}

- (instancetype)initWithModel:(Person *)person {
    if (self = [super initWithModel:person]) {
        [self.person addObserver:self forKeyPath:@"age" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:TwoViewControllerObserverContext];
    }
    return  self;
}

// 修改模型数据
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    // 默认情况下，就会自动触发 KVO
    // automaticallyNotifiesObserversOfAge 为 NO 时，就必须要手动触发 KVO了
//    self.person.age = 100;
    
    // 如果在某些条件下，比如满足某些条件才触发 KVO ,就需要手动去触发KVO
    // 首先在间监听属性中添加 + (BOOL)automaticallyNotifiesObserversOfAge 默认返回 yes，改为返回 no 就是手动触发 KVO
    // 然后当满足条件时调用以下方法
    [self.person willChangeValueForKey:@"age"];
    self.person.age = 100;
    [self.person didChangeValueForKey:@"age"];
    
}

// 回调
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    
//    NSLog(@"keyPath == %@ object == %@  change == %@  context == %@ == %s",keyPath,object,change,context,__func__);
    if (context == TwoViewControllerObserverContext) {
        NSLog(@"TwoViewController 监听到age 属性的改变%d",self.person.age);
    }else{  // 保证的父类的监听器也得到执行
        [super observeValueForKeyPath:keyPath ofObject:object change:change context: context];
    }
}

// 移除监听
- (void)dealloc {
    [self.person removeObserver:self forKeyPath:@"age" context:TwoViewControllerObserverContext];
}

@end
