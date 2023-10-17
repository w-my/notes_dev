//
//  TestLayoutView.m
//  layout机制
//
//  Created by WTW on 2020/10/24.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "TestLayoutView.h"
#import "TestLayoutSubView.h"

@interface TestLayoutView ()

@property (nonatomic,strong) TestLayoutSubView *subView;

@end

@implementation TestLayoutView

- (void)layoutSubviews {

    NSLog(@"%s",__func__);
    
}


- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        
        self.subView.frame = CGRectMake(10, 10, 100, 100);
        
        [self addSubview:_subView];
        
    }
    return self;
}

- (TestLayoutSubView *)subView {
    if (!_subView) {
        _subView = [[TestLayoutSubView alloc] init];
        _subView.backgroundColor = [UIColor greenColor];
    }
    return  _subView;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    self.subView.frame = CGRectMake(10, 10, 90, 90);
    
}

- (void)drawRect:(CGRect)rect {
    NSLog(@"%s",__func__);
}




@end
