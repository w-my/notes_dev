//
//  Animal.m
//  KVO本质
//
//  Created by WTW on 2020/4/17.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "OneViewController.h"

static void *OneViewControllerObserverContext = @"OneViewControllerContext";

@implementation OneViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = NSStringFromClass([self class]);
    
    [self.person addObserver:self forKeyPath:@"age" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:OneViewControllerObserverContext];
}

- (instancetype)initWithModel:(Person *)person {
    if (self = [super init]) {
        _person = person;
    }
    return  self;
}

// 修改模型数据
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    self.person.age = 100;
}

// 回调
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    
//    NSLog(@"keyPath == %@ object == %@  change == %@  context == %@ == %s",keyPath,object,change,context,__func__);

    if (context == OneViewControllerObserverContext) {
        NSLog(@"OneViewController 监听到age 属性的改变%d",self.person.age);
    }
}

// 移除监听
- (void)dealloc {
    [self.person removeObserver:self forKeyPath:@"age" context:OneViewControllerObserverContext];
}

@end
