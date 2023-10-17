//
//  ViewController.m
//  48-多用块枚举,少用for 循环
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSArray *arr = [NSArray arrayWithObjects:@1,@2,@3,@4,@5, nil];
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:@"obj1",@"key1",@"obj2",@"key2",@"obj3",@"key3",@"obj4",@"key4", nil];
    
    // for 循环
    for (int i = 0; i < arr.count; i ++) {
        NSLog(@"%@",arr[i]);
    }
    
    NSArray *keys = [dict allKeys];
    for (int i = 0; i < keys.count; i ++) {
        id key = keys[i];
        id value = dict[key];
        NSLog(@"key: %@ == value : %@",key,value);
    }
    
    // OC 1.0  NSEnumerator
    NSEnumerator *enumerator = [arr objectEnumerator];
    id object;
    while ((object = [enumerator nextObject]) != nil) {
        NSLog(@"%@",object);
    }
    
    NSEnumerator *dictEnumerator = [dict keyEnumerator];
    id key;
    while ((key = [dictEnumerator nextObject]) != nil) {
        NSLog(@"%@ == %@",key,dict[key]);
    }
    
    // OC 2.0 快速遍历
    for (id object in arr) {
        NSLog(@"%@",object);
    }
    
    for (id key in dict) {
        id value = dict[key];
        NSLog(@"key : %@  == value : %@",key,value);
    }
    
    // 基于块的遍历方式
    [arr enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
       NSLog(@"obj: %@ == idx : %zd",obj,idx);
    }];
    
    [dict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        NSLog(@"key: %@ == value : %@",key,obj);
    }];
    
    
    
    
    
}


@end
