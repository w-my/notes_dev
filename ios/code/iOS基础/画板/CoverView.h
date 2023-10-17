//
//  CoverView.h
//  画板
//
//  Created by WTW on 2020/1/14.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CoverView : UIView

@property (nonatomic,strong) UIImage *image;

@property (nonatomic,strong) UIImageView *imageView;

@property (nonatomic,copy) void(^handleImageBlcok)(UIImage *image);

@end

NS_ASSUME_NONNULL_END
