//
//  main.m
//  Runtime- 消息转发
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
       
        Person *person = [[Person alloc] init];
        [person test:10];
    }
    return 0;
}
