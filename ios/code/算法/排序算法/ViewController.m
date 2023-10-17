//
//  ViewController.m
//  排序算法
//
//  Created by WTW on 2020/3/20.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSMutableArray *dataArr = [NSMutableArray arrayWithObjects:@10,@12,@9,@0,@5,@19,@13,@7,@6,@1, nil];
    
    // 测试冒泡排序
    NSMutableArray *arr =  [self bubblingSortWithArray:dataArr];
    NSLog(@"%@",arr);
}

#pragma mark - 冒泡排序

/// 冒泡排序
/// @param dataArr 待排序数组
- (NSMutableArray *)bubblingSortWithArray:(NSMutableArray *)dataArr {
    
    for (int i = 0; i < dataArr.count -1; i ++) {
        for (int j = 0; j < dataArr.count - i -1; j ++) {
            if ([dataArr[j] intValue] > [dataArr[j+1] intValue]) {
                [dataArr exchangeObjectAtIndex:j withObjectAtIndex:j+1];
            }
        }
    }
    return dataArr;
}


@end
