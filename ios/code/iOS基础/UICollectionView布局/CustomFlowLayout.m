//
//  CustomFlowLayout.m
//  UICollectionView布局
//
//  Created by WTW on 2020/1/29.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "CustomFlowLayout.h"

/*
 自定义布局： 只需要了解 5 个方法
 重写方法，扩展功能
 */

@implementation CustomFlowLayout

// 作用：计算cell的布局，
// 条件:cell的位置是固定不变
// 什么时候调用: collectionView 第一次布局，collectionView 刷新的时候也会调用
//- (void)prepareLayout {
//    [super prepareLayout];
//
//    NSLog(@"%s",__func__);
//}

// 计算 collectionview的滚动范围
- (CGSize)collectionViewContentSize {
    return [super collectionViewContentSize];
}

/*
 UICollectionViewLayoutAttributes 确定cell的尺寸
 一个 UICollectionViewLayoutAttributes 对象对应一个cell
 拿到UICollectionViewLayoutAttributes 就相当于拿到cell
 */
// 返回cell的尺寸
- (NSArray<UICollectionViewLayoutAttributes *> *)layoutAttributesForElementsInRect:(CGRect)rect {
  
    // 1、获取当前显示的cell的布局
    NSArray *attrs = [super layoutAttributesForElementsInRect:self.collectionView.bounds];
    
    // 越靠近中心点,距离越小，缩放越大
    // 求cell与中心点距离
    for (UICollectionViewLayoutAttributes *attr in attrs) {
        // 2、计算中心点距离
        CGFloat delta = fabs((attr.center.x - self.collectionView.contentOffset.x)- self.collectionView.bounds.size.width * 0.5);
        // 3、计算比例
        CGFloat scale = 1 - delta / (self.collectionView.bounds.size.width * 0.5) * 0.25;
        attr.transform = CGAffineTransformMakeScale(scale, scale);
    }
    
    return attrs;
}

// 在滚动的时候是否允许刷新布局
- (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)newBounds {
    return YES;
}

// 确定最终的偏移量
// 什么时候调用：用户手指松开就会调用
// 定位：距离中心点越近，这个cell最终展示在中心点
- (CGPoint)targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset withScrollingVelocity:(CGPoint)velocity {
    
    // 最终的偏移量
    // 拖动比较快的时候 最终的偏移量不等于手指离开时的偏移量
    CGPoint targetPoint = [super targetContentOffsetForProposedContentOffset:proposedContentOffset withScrollingVelocity:velocity];
    
    // 0、获取最终显示的区域
    CGRect targetRect = CGRectMake(targetPoint.x, 0, self.collectionView.bounds.size.width, MAXFLOAT);
    
    // 1、获取最终显示的cell
    NSArray *attrs = [super layoutAttributesForElementsInRect:targetRect];
    
    CGFloat minDelta = MAXFLOAT;
    for (UICollectionViewLayoutAttributes *attr in attrs) {
        // 获取中心点距离
        CGFloat delta = (attr.center.x - self.collectionView.contentOffset.x)- self.collectionView.bounds.size.width * 0.5;
        if (fabs(delta) < fabs(minDelta)) {
            minDelta = delta;
        }
    }
    
    targetPoint.x += minDelta;
    
    if (targetPoint.x < 0) {
        targetPoint.x = 0;
    }
    
    return targetPoint;
}

@end
