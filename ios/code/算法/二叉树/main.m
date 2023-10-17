//
//  main.m
//  二叉树
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BinaryTree.h"
#import "BinaryTreeNode.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        // 创建结点
        BinaryTreeNode *node1 = [BinaryTreeNode nodeWithValue:10];
        BinaryTreeNode *node2 = [BinaryTreeNode nodeWithValue:11];
        BinaryTreeNode *node3 = [BinaryTreeNode nodeWithValue:12];
        BinaryTreeNode *node4 = [BinaryTreeNode nodeWithValue:13];
        BinaryTreeNode *node5 = [BinaryTreeNode nodeWithValue:14];

        
        BinaryTreeNode *b = [BinaryTree createTreeWithValues:@[@11,@12]];
        
        
        
    }
    return 0;
}
