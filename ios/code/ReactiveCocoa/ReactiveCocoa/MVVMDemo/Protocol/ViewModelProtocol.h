//
//  ViewModelProtocol.h
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/6.
//  Copyright © 2018 wtw. All rights reserved.
//

@protocol ViewModelProtocol <NSObject>

@optional
- (void)bindViewModel:(UIView *)bindView;

@end
