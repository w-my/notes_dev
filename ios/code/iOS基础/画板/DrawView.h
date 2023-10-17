//
//  DrawView.h
//  画板
//
//  Created by WTW on 2020/1/14.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DrawView : UIView

@property (nonatomic,strong) UIImage *image;

- (void)cls;
- (void)undo;
- (void)erase;
- (void)setLineWidth:(CGFloat)lineWidth;
- (void)setLineColor:(UIColor *)LineColor;

@end

NS_ASSUME_NONNULL_END
