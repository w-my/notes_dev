//
//  HomeViewModel.h
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/6.
//  Copyright © 2018 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveObjC.h>
#import "ViewModelProtocol.h"

@interface HomeViewModel : NSObject<ViewModelProtocol>

@property (nonatomic,strong) RACCommand *loadHomeDataCommand;

@end
