//
//  DrawView.m
//  画板
//
//  Created by WTW on 2020/1/14.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "DrawView.h"
#import "MyBezierPath.h"

@interface DrawView ()

// 当前绘制的路径
@property (nonatomic,strong) MyBezierPath *path;
// 保存当前绘制的所有路径
@property (nonatomic,strong) NSMutableArray *allPathsArray;

@property (nonatomic,strong) UIColor *lColor;
@property (nonatomic,assign) CGFloat lWidth;

@end

@implementation DrawView

- (void)awakeFromNib {
   
    [super awakeFromNib];
    
    [self addGestureRecognizer:[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(pan:)]];

    self.lWidth = 10;
    self.lColor = [UIColor blackColor];
}

- (void)setImage:(UIImage *)image {
    _image = image;
    
    // 把图片添加到数组中
    [self.allPathsArray addObject:image];
    [self setNeedsDisplay];
}

- (void)cls {
    [self.allPathsArray removeAllObjects];
    [self setNeedsDisplay];
}
- (void)undo {
    [self.allPathsArray removeLastObject];
    [self setNeedsDisplay];
}
- (void)erase {
    [self setLineColor:[UIColor whiteColor]];
}
- (void)setLineWidth:(CGFloat)lineWidth {
    self.lWidth = lineWidth * 10;
}
- (void)setLineColor:(UIColor *)LineColor {
    self.lColor = LineColor;
}
 
- (void)pan:(UIPanGestureRecognizer *)pan {
    // 获取当前手指的点
    CGPoint curP = [pan locationInView:self];
    
    // 判断寿手势的状态
    if (pan.state == UIGestureRecognizerStateBegan) {
        // 创建路径
        MyBezierPath *path = [MyBezierPath bezierPath];
        self.path = path;
        // 设置起点
        [path moveToPoint:curP];
        
        // 设置线宽
       self.lWidth = self.lWidth == 0 ? 10 : self.lWidth;
        [path setLineWidth:self.lWidth];
        
        // 设置颜色
        path.color = self.lColor;
        
        //保存当前路径
        [self.allPathsArray addObject:path];
        
    }else if(pan.state == UIGestureRecognizerStateChanged) {
        // 绘制线
        [self.path addLineToPoint:curP];
        // 重绘
        [self setNeedsDisplay];
    }
}

- (void)drawRect:(CGRect)rect {
    // 绘制保存的所有路径
    for (MyBezierPath *path in self.allPathsArray) {
        if ([path isKindOfClass:[UIImage class]]) {
            UIImage *image = (UIImage *)path;
            [image drawInRect:rect];
        }else {
            [path.color set];
            [path stroke];
        }
    }
}

- (NSMutableArray *)allPathsArray {
    if (!_allPathsArray) {
        _allPathsArray = [NSMutableArray array];
    }
    return _allPathsArray;
}

@end
