//
//  Person.h
//  swift调用OC
//
//  Created by WTW on 2020/3/27.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

@property (nonatomic,copy) NSString *name;
@property (nonatomic,assign) NSInteger age;

- (instancetype)initWithName:(NSString *)name age:(NSInteger)age;

- (NSString *)write:(NSString *)fileName error:(NSError * __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
