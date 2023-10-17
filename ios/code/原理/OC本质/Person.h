//
//  Person.h
//  OC本质
//
//  Created by WTW on 2019/9/24.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
Person 对象的底层实现：
 
struct NSObject_IMPL{
    Class isa;
}; // 8个字节

struct Person_IMPL{
    struct NSObject_IMPL NSObject_IVARS; // 8
    int _age; // 4
    int _height; // 4
    int _no; // 4
}; // 20   字节对齐需要24个字节
*/
 
@interface Person : NSObject
{
    @public // 方便在外部可以调用,不写外部调用报错 Instance variable '_age' is protected
    int _age;
    int _height;
    int _no;
}
@end

NS_ASSUME_NONNULL_END
