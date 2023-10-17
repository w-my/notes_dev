//
//  Person.h
//  KVC的本质
//
//  Created by WTW on 2019/7/18.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject{
    int age;
    int isAge;
    int _isAge;
    int _age;
    
    //_age _isAge age isAge
}

//@property (nonatomic,assign) int age;

@end

NS_ASSUME_NONNULL_END
