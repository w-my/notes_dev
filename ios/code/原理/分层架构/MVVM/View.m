//
//  View.m
//  分层架构
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "View.h"
#import "NSObject+FBKVOController.h"

@interface View ()
@property (nonatomic,strong) UILabel *nameLabel;
@property (nonatomic,strong) UIImageView *iconImage;
@end

@implementation View

- (void)setViewModle:(ViewModel *)viewModle {
    _viewModle = viewModle;
    
    __weak typeof(self) weakSelf = self;
    
    // 通过 KVO 实现数据的双向绑定
    [self.KVOController observe:viewModle keyPath:@"name" options:NSKeyValueObservingOptionNew block:^(id  _Nullable observer, id  _Nonnull object, NSDictionary<NSKeyValueChangeKey,id> * _Nonnull change) {
        weakSelf.nameLabel.text = change[NSKeyValueChangeNewKey];
    }];
    
    [self.KVOController observe:viewModle keyPath:@"image" options:NSKeyValueObservingOptionNew block:^(id  _Nullable observer, id  _Nonnull object, NSDictionary<NSKeyValueChangeKey,id> * _Nonnull change) {
           weakSelf.iconImage.image = [UIImage imageNamed:change[NSKeyValueChangeNewKey]];
    }];
}


@end
