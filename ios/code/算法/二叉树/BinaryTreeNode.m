//
//  BinaryTreeNode.m
//  二叉树
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "BinaryTreeNode.h"

@implementation BinaryTreeNode

+ (instancetype)nodeWithValue:(NSInteger)value {
    BinaryTreeNode *node = [[super alloc] init];
    node.value = value;
    return node;
}

@end
