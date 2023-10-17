//
//  Person.m
//  swift调用OC
//
//  Created by WTW on 2020/3/27.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "Person.h"

@implementation Person

- (instancetype)initWithName:(NSString *)name age:(NSInteger)age {
    if (self = [super init]) {
        
        self.name = name;
        self.age = age;
    }
    return  self;
}

- (NSString *)write:(NSString *)fileName error:(NSError * __autoreleasing *)error {
    if (error) {
       *error = [NSError errorWithDomain:@"ObjcObject Error" code:0 userInfo:nil];
    }
    return nil;
}

@end
