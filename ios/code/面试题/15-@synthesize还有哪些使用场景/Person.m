//
//  Person.m
//  15-@synthesize还有哪些使用场景
//
//  Created by WTW on 2020/3/11.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "Person.h"

@interface Person ()
{
    NSString *_name;
}
@end

@implementation Person

//@synthesize name = _name;

- (void)setName:(NSString *)name {
    _name = name;
}

- (NSString *)name {
    return  [_name copy];
}

@end
