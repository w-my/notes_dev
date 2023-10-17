//
//  BinaryTree.h
//  二叉树
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BinaryTreeNode;

NS_ASSUME_NONNULL_BEGIN

@interface BinaryTree : NSObject

//结点的个数
- (NSInteger)size;

//是否为空
-(BOOL)isEmpty;

- (void)addNode;

/// 创建二叉树
/// @param values 值数组
+ (BinaryTreeNode *)createTreeWithValues:(NSArray *)values;

///  向二叉树结点添加一个结点
/// @param treeNode 根结点
/// @param value 结点值
+ (BinaryTreeNode *)addTreeNode:(BinaryTreeNode *)treeNode value:(NSInteger)value;

/// 反转二叉树 （非递归）。又叫二叉树的镜像
/// @param rootNode 根结点
+ (BinaryTreeNode *)invertBinaryTreeWithoutRecursion:(BinaryTreeNode *)rootNode;

/// 递归方式翻转二叉树 (二叉树镜像)
/// @param rootNode 根结点
+ (BinaryTreeNode *)invertBinaryTree:(BinaryTreeNode *)rootNode;


@end

NS_ASSUME_NONNULL_END
