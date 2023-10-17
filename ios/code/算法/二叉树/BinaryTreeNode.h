//
//  BinaryTreeNode.h
//  二叉树
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BinaryTreeNode : NSObject

//值
@property (nonatomic,assign) NSInteger value;

// 左子树
@property (nonatomic,strong) BinaryTreeNode *leftNode;

// 右子树
@property (nonatomic,strong) BinaryTreeNode *rightNode;

// 父结点
@property (nonatomic,strong) BinaryTreeNode *parentNode;

// 便利构造器
+ (instancetype)nodeWithValue:(NSInteger)value;

@end

NS_ASSUME_NONNULL_END
