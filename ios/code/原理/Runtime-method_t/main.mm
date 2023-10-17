//
//  main.m
//  Runtime-method_t
//
//  Created by WTW on 2019/8/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MJClassInfo.h"
#import "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
       
        Person *person = [[Person alloc] init];
        
        struct mj_objc_class *cls = (__bridge struct mj_objc_class *)[person class];
        class_rw_t *data = cls->data();
        
        [person test];
        
        // method_t  是对方法、函数的封装
        /*
        struct method_t {
            SEL name; // 函数、方法名（选择器）
            const char *types; // 编码(返回值类型、参数类型)
            IMP imp; // 指向函数的指针(函数首地址 方法的实现)
        }
        */
        
        // IMP 代表方法、函数的具体实现
        // typedef id _Nullable (*IMP)(id _Nonnull,SEL _Nonnull,...)
//        data->methods->first.imp:
//        (IMP) imp = 0x0000000100000d20 (Runtime-method_t`-[Person test] at Person.m:13)
        
        // SEL 代表方法\函数名，一般叫做选择器，底层结构跟char *类似
        // 获取 SEL 两种方式 @selector 或者 sel_registerName()
        // 可以通过sel_getName()和NSStringFromSelector()转成字符串
        // 不同类中相同名字的方法，所对应的方法选择器是相同的
        // 123 == init == init
        NSLog(@"%s == %s == %s","123",@selector(init),sel_registerName("init")); 
        
        // types 包含了函数返回值、参数编码的字符串
        
//        - (void)test;  其实有两个隐藏参数  -(void)test:(id)self _cmd:(SEL)_cmd;
        // v16@0:8   v: void  @:id   : :SEL     16 = id 8 + SEL 8
//        data->methods->first.types:
//        (const char *) types = 0x0000000100000f83 "v16@0:8"
        
        // - (NSString *)testMethodt:(int)a;
//        data->methods->first.types:
//        (const char *) types = 0x0000000100000f6a "@ 20 @ 0 : 8 i 16"
        // 20 所有参数大小的总和 id 8 SEL 8 int 4    8 + 8 + 4 = 20
        NSLog(@"%s == %s == %s  == %s",@encode(id),@encode(SEL),@encode(void),@encode(NSString *));  // @ == : == v == @
        
    }
    return 0;
}
