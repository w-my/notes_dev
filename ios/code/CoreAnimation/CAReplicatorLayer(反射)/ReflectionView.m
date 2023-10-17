//
//  ReflectionView.m
//  CAReplicatorLayer
//
//  Created by wtw on 2019/1/28.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ReflectionView.h"

@implementation ReflectionView

+ (Class)layerClass {
    return [CAReplicatorLayer class];
}

- (void)setup {
    CAReplicatorLayer *layer = (CAReplicatorLayer *)self.layer;
    layer.instanceCount = 2;
    
    CATransform3D transform = CATransform3DIdentity;
    CGFloat verticalOffset = self.bounds.size.height + 2;
    transform = CATransform3DTranslate(transform, 0, verticalOffset, 0);
    transform = CATransform3DScale(transform, 1, -1, 0);
    layer.instanceTransform = transform;
    
    layer.instanceAlphaOffset = - 0.6;
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

@end
