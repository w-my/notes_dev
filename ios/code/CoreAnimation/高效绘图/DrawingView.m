//
//  DrawingView.m
//  高效绘图
//
//  Created by wtw on 2019/3/1.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "DrawingView.h"

@interface DrawingView()

@property (nonatomic,strong) UIBezierPath *path;

@end

@implementation DrawingView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        
        self.path = [UIBezierPath bezierPath];
        self.path.lineJoinStyle = kCGLineJoinRound;
        self.path.lineCapStyle = kCGLineCapRound;
        self.path.lineWidth = 5;
    }
    return self;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    CGPoint point = [[touches anyObject] locationInView:self];
    [self.path moveToPoint:point];
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    CGPoint point = [[touches anyObject] locationInView:self];
    [self.path addLineToPoint:point];
    [self setNeedsDisplay];
}

- (void)drawRect:(CGRect)rect {
    [[UIColor clearColor] setFill];
    [[UIColor redColor] setStroke];
    [self.path stroke];
}

@end
