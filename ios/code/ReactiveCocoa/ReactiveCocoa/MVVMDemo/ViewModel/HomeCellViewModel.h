//
//  HomeCellViewModel.h
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/6.
//  Copyright © 2018 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ViewModelProtocol.h"

@class HomeModel;
//处理cell的显示和业务逻辑
@interface HomeCellViewModel : NSObject<ViewModelProtocol>

@property (nonatomic,strong) HomeModel *item;

@end
