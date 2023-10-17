//
//  CoverView.m
//  画板
//
//  Created by WTW on 2020/1/14.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "CoverView.h"

@implementation CoverView

- (UIImageView *)imageView {
    if (!_imageView) {
        _imageView = [[UIImageView alloc] initWithFrame:self.bounds];
        _imageView.userInteractionEnabled  = YES;
        [self addSubview:_imageView];
        
        UIPanGestureRecognizer *pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(pan:)];
        [self.imageView addGestureRecognizer:pan];

        // 捏合
        UIPinchGestureRecognizer *pinch = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinch:)];
        [self.imageView addGestureRecognizer:pinch];
        
        // 旋转
        UIRotationGestureRecognizer *rota = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(rota:)];
        [self.imageView addGestureRecognizer:rota];

        //长按
        UILongPressGestureRecognizer *longPress = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(longPress:)];
        [self.imageView addGestureRecognizer:longPress];
    }
    return _imageView;
}

- (void)setImage:(UIImage *)image {
    _image = image;
    self.imageView.image = image;
}

// 拖拽手势
- (void)pan:(UIPanGestureRecognizer *)pan {
    CGPoint transP = [pan translationInView:pan.view];
    pan.view.transform = CGAffineTransformTranslate(pan.view.transform, transP.x, transP.y);
    // 每次拖拽完毕后，让平移的值不要累加
    [pan setTranslation:CGPointZero inView:pan.view];
}

// 捏合手势
- (void)pinch:(UIPinchGestureRecognizer *)pinch {
    pinch.view.transform = CGAffineTransformScale(pinch.view.transform, pinch.scale,pinch.scale);
    [pinch setScale:1];
}

// 旋转手势
- (void)rota:(UIRotationGestureRecognizer *)rota {
    rota.view.transform = CGAffineTransformRotate(rota.view.transform, rota.rotation);
    // 每次旋转完毕后将 rotation 的值恢复到0的z位置
    rota.rotation = 0;
}

// 长按手势
- (void)longPress:(UILongPressGestureRecognizer *)longPress {
    if (longPress.state == UIGestureRecognizerStateBegan) {
        [UIView animateWithDuration:0.5 animations:^{
            self.alpha = 0;
        } completion:^(BOOL finished) {
            [UIView animateWithDuration:0.5
                             animations:^{
                self.alpha = 1.0;
            } completion:^(BOOL finished) {
                
                // 把图片绘制到画板中
                UIGraphicsBeginImageContextWithOptions(self.bounds.size, NO, 0);
          
                CGContextRef ctx = UIGraphicsGetCurrentContext();
                [self.layer renderInContext:ctx];
                
                UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
                UIGraphicsEndImageContext();
                
                if (self.handleImageBlcok) {
                    self.handleImageBlcok(newImage);
                }
                    
                [self removeFromSuperview];
            }];
        }];
    }else {
        
    }
}

@end
