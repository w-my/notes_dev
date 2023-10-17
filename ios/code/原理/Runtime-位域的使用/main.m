//
//  main.m
//  Runtime-位域的使用
//
//  Created by WTW on 2019/8/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

/*
 在arm64架构之前，isa就是一个普通的指针，存储着Class、Meta-Class对象的内存地址
 从arm64架构开始，对isa进行了优化，变成了一个共用体（union）结构，使用位域来存储更多的信息
 */

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

