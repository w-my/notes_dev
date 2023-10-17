//
//  main.m
//  Runtime-共用体
//
//  Created by WTW on 2019/8/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Person *person = [[Person alloc] init];
        [person setTall:YES];
        [person setHandSome:YES];
        [person setRich:NO];
        //取值
        NSLog(@" tall %d == rich %d  == handsome %d ",person.isTall,person.isRich,person.isHandSome);
   
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
