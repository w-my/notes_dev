//
//  Animal.h
//  KVO本质
//
//  Created by WTW on 2020/4/17.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Person.h"

NS_ASSUME_NONNULL_BEGIN

@interface OneViewController : UIViewController

@property (nonatomic,strong) Person *person;

- (instancetype)initWithModel:(Person *)person;

@end

NS_ASSUME_NONNULL_END
