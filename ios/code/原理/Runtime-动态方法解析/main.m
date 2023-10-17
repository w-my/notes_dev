//
//  main.m
//  Runtime-动态方法解析
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "PersonC.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
       
        // 动态方法解析
//        Person *person = [[Person alloc] init];
//        [person test];
        
        PersonC *personC = [[PersonC alloc] init];
        [personC performSelector:@selector(run:) withObject:@10];
        
        //类方法
        //[PersonC test1];
        
    }
    return 0;
}
