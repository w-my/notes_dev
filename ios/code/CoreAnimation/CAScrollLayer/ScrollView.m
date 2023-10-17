//
//  ScrollView.m
//  CAScrollLayer
//
//  Created by wtw on 2019/1/29.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ScrollView.h"

@implementation ScrollView

+ (Class)layerClass {
    return [CAScrollLayer class];
}

- (void)setup {
    self.layer.masksToBounds = YES;
    
    UIPanGestureRecognizer *recognizer = nil;
    recognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(pan:)];
    [self addGestureRecognizer:recognizer];
}

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self setup];
    }
    return self;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    [self setup];
}

- (void)pan:(UIPanGestureRecognizer *)recognizer {
    CGPoint offset = self.bounds.origin;
    offset.x -= [recognizer translationInView:self].x;
    offset.y -= [recognizer translationInView:self].y;
    
    [(CAScrollLayer *)self.layer scrollPoint:offset];
    
    [recognizer setTranslation:CGPointZero inView:self];
}

@end
