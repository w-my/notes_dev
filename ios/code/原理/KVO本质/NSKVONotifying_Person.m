//
//  NSKVONotifying_Person.m
//  原理
//
//  Created by WTW on 2019/7/17.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "NSKVONotifying_Person.h"

// KVO failed to allocate class pair for name NSKVONotifying_Person, automatic key-value observing will not work for this class
//一旦手动实现这个类 KVO 就失效了 证实了的确是动态生成了这个类
// 手动移除编译 便于调试

@implementation NSKVONotifying_Person

//- (void)setAge:(int)age {
//    _NSSetIntValueAndNotify();
//}
// 
////伪代码
//void _NSSetIntValueAndNotify(){
//    [self willChangeValueForKey:@"age"];
//    [super setAge:age];
//    [self didChangeValueForKey:@"age"];
//}
//
//- (void)didChangeValueForKey:(NSString *)key {
//    //通知监听器 某某属性值发生了改变
//    [observer observeValueForKeyPath:key ofObject:self change:nil context:nil];
//}

- (Class)class {
    //为了屏蔽 NSKVONotifying_Person 内部实现 隐藏此类的存在 给开发者的感觉就是 Person 而不是 NSKVONotifying_Person
    //重写了父类方法
    
    //验证如下：
    NSLog(@"%@  %@",object_getClass(self.person1),object_getClass(self.person2));
    //结果为：NSKVONotifying_Person  Person
    NSLog(@"%@  %@",[self.person1 class],[self.person2 class]);
    //结果为：Person  Person （这种方式获取的不准确，因为被屏蔽了）
    
}

- (void)delloc {

    
}

- (BOOL)_isKVOA{
    return YES;
}

@end
