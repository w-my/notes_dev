//
//  main.m
//  LLVM 中间代码
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
    
        Person *p = [[Person alloc] init];
        [p run];
        
    }
    return 0;
}
