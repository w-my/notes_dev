//
//  BinaryTree.m
//  二叉树
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "BinaryTree.h"
#import "BinaryTreeNode.h"

@interface BinaryTree ()

// 二叉树结点的个数
@property (nonatomic,assign) NSInteger size;

// 根结点
@property (nonatomic,strong) BinaryTreeNode *root;

@end

@implementation BinaryTree

//结点的个数
- (NSInteger)size{
    return self.size;
}

//是否为空
-(BOOL)isEmpty {
    return self.size == 0;
}




/// 创建二叉排序树 (左结点值全部小于根结点，右结点全部大于根结点值)
/// @param values 数组
+ (BinaryTreeNode *)createTreeWithValues:(NSArray *)values {
    BinaryTreeNode *root = nil;
    for (NSInteger i = 0; i < values.count; i++) {
        NSInteger value = [(NSNumber *)[values objectAtIndex:i] integerValue];
        root = [[self class] addTreeNode:root value:value];
    }
    return root;
}


///  向二叉树结点添加一个结点
/// @param treeNode 根结点
/// @param value 结点值
+ (BinaryTreeNode *)addTreeNode:(BinaryTreeNode *)treeNode value:(NSInteger)value {
    if (!treeNode) {  // 根结点不存在，创建节点
        treeNode = [[BinaryTreeNode alloc] init];
        treeNode.value = value;
        NSLog(@"node value:%@",value);
    }else if(value <= treeNode.value) { // 值小于根结点，插入到左子树
        treeNode.leftNode = [[self class] addTreeNode:treeNode.leftNode value:value];
        NSLog(@"to left %@:",value);
    }else { // 值大于根结点，插入到右子树
        treeNode.rightNode = [[self class] addTreeNode:treeNode.rightNode value:value];
        NSLog(@"to right %@:",value);
    }
    return treeNode;
}


/// 反转二叉树 （非递归）。又叫二叉树的镜像
/// @param rootNode 根结点
/*
 反转前：
      4
    /   \
   2     7
  / \   / \
 1   3 6   9
 
 反转后：
      4
    /   \
   7     2
  / \   / \
 9   6 3   1
 */

+ (BinaryTreeNode *)invertBinaryTreeWithoutRecursion:(BinaryTreeNode *)rootNode {
    if (!rootNode) return nil;
    if (!rootNode.leftNode && !rootNode.rightNode) return rootNode;
    
    NSMutableArray *queueArray = [NSMutableArray array]; // 数组当做队列
    [queueArray addObject:rootNode]; // 压入根结点
    while (queueArray.count > 0) {
        BinaryTreeNode *node = queueArray.firstObject;
        [queueArray removeObjectAtIndex:0];  // 弹出最前面的结点，仿照队列先进先出原则
       
        BinaryTreeNode *pleft = node.leftNode;
        node.leftNode = node.rightNode;
        node.rightNode = pleft;
       
        if (node.leftNode) {
            [queueArray addObject:node.leftNode];
        }
        
        if (node.rightNode) {
            [queueArray addObject:node.rightNode];
        }
    }
    return rootNode;
}

/// 递归方式翻转二叉树 (二叉树镜像)
/// @param rootNode 根结点
+ (BinaryTreeNode *)invertBinaryTree:(BinaryTreeNode *)rootNode {
    if (!rootNode)  return nil;
    if (!rootNode.leftNode && !rootNode.rightNode) return nil;
    
    [self invertBinaryTree:rootNode.leftNode];
    [self invertBinaryTree:rootNode.rightNode];
    
    BinaryTreeNode *tempNode = rootNode.leftNode;
    rootNode.leftNode = rootNode.rightNode;
    rootNode.rightNode = tempNode;
    
    return rootNode;
}

#pragma mark - 遍历二叉树 

@end
