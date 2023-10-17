//
//  main.m
//  位运算-取值和设值
//
//  Created by WTW on 2019/8/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

//xcrun -sdk iphoneos clang -arch arm64 -rewrite-objc main.m

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Person *person = [[Person alloc] init];
        [person setTall:NO];
        [person setHandSome:YES];
        //取值
        NSLog(@" tall %d == rich %d  == handsome %d ",person.isTall,person.isRich,person.isHandSome);
        
    }
    return 0;
}
