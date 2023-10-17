//
//  main.m
//  内存管理-copy
//
//  Created by WTW on 2019/9/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

/*
 拷贝的目的 : 产生一个副本对象，跟源对象互不影响
 修改了源对象，不会影响副本对象
 修改了副本对象，不会影响源对象
 */

/*
 系统提供了两个 copy 方法：
 copy        不可变拷贝  产生不可变副本
 mutalecopy  可变拷贝    产生可变副本
 */

/*
 深拷贝 : 内容拷贝,产生新的对象
 
 浅拷贝 : 指针拷贝，没有产生新对象
 */

/* 总结如下：
                         copy              mutableCopy
NSString                 NSString          NSMutableString
                         浅拷贝             深拷贝
 
NSMutableString          NSString          NSMutableString
                         深拷贝             深拷贝

NSArray                  NSArray           NSMutableArray
                         浅拷贝             深拷贝

NSMutableArray           NSArray           NSMutableArray
                         深拷贝             深拷贝

NSDictionary             NSDictionary      NSMutableDictionary
                         浅拷贝             深拷贝

NSMutableDictionary      NSDictionary      NSMutableDictionary
                         深拷贝             深拷贝
*/

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
         // MRC 情况下
         // str1 str2 指向同一个地址(返回是的对象本身)
         // str3 是一个可变对象
        
        //NSString
//        NSString *str1 = [NSString stringWithFormat:@"test"];
//        NSString *str2 = [str1 copy];  // 浅拷贝  指针拷贝 未产生新对象
//        NSMutableString *str3 = [str1 mutableCopy]; // 深拷贝 内容拷贝 产生新对象
//        NSLog(@"%p %p %p",str1,str2,str3);  // 0x8bc3d7ad55331473 0x8bc3d7ad55331473 0x102801730
//        NSLog(@"%d  %d  %d",str1 == str3,str2 == str3,str1 == str2);  // 0 0 1

        
        // NSMutableString
//        NSString *str1 = [[NSMutableString alloc] initWithFormat:@"test"];
//        NSString *str2 = [str1 copy];  // 深拷贝
//        NSMutableString *str3 = [str1 mutableCopy]; // 深拷贝
//        NSLog(@"%p %p %p",str1,str2,str3);  // 0x100640a20 0x15cc1b77283eb063 0x100640b00
//        NSLog(@"%d  %d  %d",str1 == str3,str2 == str3,str1 == str2);  // 0  0  0
//
//        [str3 release];
//        [str2 release];
//        [str1 release];
        
        
        // NSArray
//        NSArray *arr1 = [[NSArray alloc] initWithObjects:@"a",@"b", nil];
//        NSArray *arr2 = [arr1 copy];  // 浅拷贝
//        NSMutableArray *arr3 = [arr1 mutableCopy];  // 深拷贝
//        NSLog(@"%p %p %p",arr1,arr2,arr3);  // 0x100721dc0 0x100721dc0 0x100722620
        
        // NSMutableArray
//        NSMutableArray *arr1 = [[NSMutableArray alloc] initWithObjects:@"a",@"b", nil];
//        NSArray *arr2 = [arr1 copy];  // 深拷贝
//        NSMutableArray *arr3 = [arr1 mutableCopy];  // 深拷贝
//        NSLog(@"%p %p %p",arr1,arr2,arr3);  // 0x100506b00 0x100505080 0x100508040
//
//        [arr1 release];
//        [arr2 release];
//        [arr3 release];
        
        
        Person *person = [[Person alloc] init];
        //当是 NSArray copy 的时候没有问题 是浅拷贝 还是指向同一个地址
//        person.data = [NSArray arrayWithObjects:@"a",@"b", nil];
//        NSLog(@"%@",person.data);
        
        // 当是 NSMutableArray copy 的时候会产生一个新的不可变数组 所以会崩溃
//        person.data = [NSMutableArray array];
//        [person.data addObject:@"1"];  // unrecognized selector sent to instance
//
//        [person release];
    }
    return 0;
}
