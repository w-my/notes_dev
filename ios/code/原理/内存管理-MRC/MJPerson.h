//
//  MJPerson.h
//  Interview01-内存管理
//
//  Created by MJ Lee on 2018/6/27.
//  Copyright © 2018年 MJ Lee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MJDog.h"
#import "MJCar.h"

@interface MJPerson : NSObject
//{
//    MJDog *_dog;
//    MJCar *_car;
//    int _age;
//}
//
//- (void)setAge:(int)age;
//- (int)age;
//
//- (void)setDog:(MJDog *)dog;
//- (MJDog *)dog;
//
//- (void)setCar:(MJCar *)car;
//- (MJCar *)car;

// 也可以不手动去实现 setter getter 只要用 retain 即可
@property (nonatomic, assign) int age;
@property (nonatomic, retain) MJDog *dog;
@property (nonatomic, retain) MJCar *car;

+ (instancetype)person;

@end
