//
//  main.m
//  OC对象的本质-Class 的结构
//
//  Created by WTW on 2019/9/27.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "MJClassInfo.h"

// MJPerson
@interface MJPerson : NSObject <NSCopying>
{
@public
    int _age;
}
@property (nonatomic, assign) int no;
- (void)personInstanceMethod;
+ (void)personClassMethod;
@end

@implementation MJPerson

- (void)test
{
    
}

- (void)personInstanceMethod
{
    
}
+ (void)personClassMethod
{
    
}
- (id)copyWithZone:(NSZone *)zone
{
    return nil;
}
@end

// MJStudent
@interface MJStudent : MJPerson <NSCoding>
{
@public
    int _weight;
}
@property (nonatomic, assign) int height;
- (void)studentInstanceMethod;
+ (void)studentClassMethod;
@end

@implementation MJStudent
- (void)test
{
    
}
- (void)studentInstanceMethod
{
    
}
+ (void)studentClassMethod
{
    
}
- (id)initWithCoder:(NSCoder *)aDecoder
{
    return nil;
}

- (void)encodeWithCoder:(NSCoder *)aCoder
{
    
}
@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        MJStudent *stu = [[MJStudent alloc] init];
        stu->_weight = 10;
        
        mj_objc_class *studentClass = (__bridge mj_objc_class *)([MJStudent class]);
        mj_objc_class *personClass = (__bridge mj_objc_class *)([MJPerson class]);
        
        //类对象结构
        class_rw_t *studentClassData = studentClass->data();
        class_rw_t *personClassData = personClass->data();
        
        //元类对象的结构
        class_rw_t *studentMetaClassData = studentClass->metaClass()->data();
        class_rw_t *personMetaClassData = personClass->metaClass()->data();

        NSLog(@"1111");
    }
    return 0;
}
