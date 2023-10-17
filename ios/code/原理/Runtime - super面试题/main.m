//
//  main.m
//  Runtime - super面试题
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "Person.h"
#import "Son.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
#pragma mark - 面试题 super的本质
        /*
         面试题一
         Son *son = [[Son alloc] init];
         [son run];
         */
        
#pragma mark - 面试题 isMemberOfClass  isMemberOfClass
        // 结论：
        // 如果是实例对象调用，右边应该是类对象
        // 如果是类对象调用，右边应该传元类对象
        
        /* 源码如下：
         // 类方法
         
         // 是否等于当前类 cls
         + (BOOL)isMemberOfClass:(Class)cls {
            return object_getClass((id)self) == cls;
         }
         
         // 是否是 当前类 或者 当前类的子类
         + (BOOL)isKindOfClass:(Class)cls {
             for (Class tcls = object_getClass((id)self); tcls; tcls = tcls->superclass) {
                if (tcls == cls) return YES;
             }
             return NO;
         }
         
         // 对象方法
         
         // 是否正好等于当前类
         - (BOOL)isMemberOfClass:(Class)cls {
            return [self class] == cls;
         }
         
         // 是否是当前类 或者 是cls的子类
         - (BOOL)isKindOfClass:(Class)cls {
             for (Class tcls = [self class]; tcls; tcls = tcls->superclass) {
                if (tcls == cls) return YES;
             }
             return NO;
         }
        */
        
        
//        id person = [[Person alloc] init];
//        // person 是否是 [Person class] 或者 [Person class] 的子类
//        NSLog(@"%d",[person isKindOfClass:[Person class]]);  // 1
//        // person 是否是 [Person class]
//        NSLog(@"%d",[person isMemberOfClass:[Person class]]); // 1
        
        // 元类对象父类最终是 NSObject 所以第一个是1
        // 调用者不管是哪个类(只要是继承自NSObject)，都返回 YES
        BOOL res1 = [[NSObject class] isKindOfClass:[NSObject class]];  // 1
        // 应该是元类 不是类对象
        BOOL res2 = [[NSObject class] isMemberOfClass:[NSObject class]];  // 0
        BOOL res21 = [[NSObject class] isMemberOfClass:object_getClass([NSObject class])];  // 1

        BOOL res3 = [[Person class] isKindOfClass:[Person class]];  // 0
        BOOL res31 = [[Person class] isKindOfClass:object_getClass([Person class])];  // 1

        
        BOOL res4 = [[Person class] isMemberOfClass:[Person class]];  // 0
        BOOL res41 = [[Person class] isMemberOfClass:object_getClass([Person class])];  // 1
        
        // NSObject  == Person
        NSLog(@"%@  == %@ ",object_getClass([NSObject class]),object_getClass([Person class]));
        
        NSLog(@"\n res1 : %d \n res2 : %d \n res21 : %d \n res3 : %d \n res31 : %d \n res4 : %d \n res41 : %d ",res1,res2,res21,res3,res31,res4,res41);  // 1 0 0 0

    }
    return 0;
}
