//
//  HomeCellViewModel.m
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/6.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "HomeCellViewModel.h"
#import "HomeTableViewCell.h"
#import "HomeModel.h"

@implementation HomeCellViewModel

- (void)bindViewModel:(id)bindView {
    HomeTableViewCell *cell = (HomeTableViewCell *)bindView;
    cell.imageView.image = [UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:_item.img]]];
    cell.digest.text = _item.digest;
}

@end
