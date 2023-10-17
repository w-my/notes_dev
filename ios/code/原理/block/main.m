//
//  main.m
//  block
//
//  Created by WTW on 2019/7/23.
//  Copyright © 2019 wtw. All rights reserved.
//

// xcrun -sdk iphoneos clang -arch arm64 -rewrite-objc main.m
// xcrun -sdk iphoneos clang -arch arm64 -rewrite-objc main.m -o xxxx路径
// xcrun -sdk iphoneos clang -arch arm64 -rewrite-objc -fobjc-arc -fobjc-runtime=ios-8.0.0 main.m

#import <Foundation/Foundation.h>
#import "Person.h"

/*
Block 的本质也是一个 OC 对象，内部也有一个isa指针
Block 是封装了函数调用以及函数调用环境的OC对象(带有自变量的匿名函数)
https://www.jianshu.com/p/d0a9eaebdd47
*/

// 定义全局变量
int age = 10;
static int  height = 10;

//void(^block3)(void);
//void test(){
//    int a = 20;
//    block3 = ^{
//        NSLog(@" testStackBlock === %d",a);
//    };
//    // 解决上面的在栈上被回收的问题的办法就是 copy 到堆上
////    block3 = [^{
////        NSLog(@" testStackBlock === %d",a);
////    } copy];
//};

typedef void(^Block)(void);

int main(int argc, const char * argv[]) {
    @autoreleasepool {

#pragma mark - block 底层数据结构 main-01.cpp
        
    /*
    struct __block_impl {
        void *isa;
        int Flags;
        int Reserved;
        void *FuncPtr;
    };

     static struct __main_block_desc_0 {
         size_t reserved;
         size_t Block_size;  // block 占用的内存大小 sizeof(struct __main_block_impl_0)
     } __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};

    struct __main_block_impl_0 {
        struct __block_impl impl;
        struct __main_block_desc_0* Desc;
        //构造函数 返回结构体对象
        __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) {
            impl.isa = &_NSConcreteStackBlock;
            impl.Flags = flags;
            impl.FuncPtr = fp;      // FuncPtr 指向要执行的函数的地址
            Desc = desc;
        }
    };

    //封装了 block 执行逻辑的代码(把block内部代码封装到此函数的内部)
    static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
        NSLog((NSString *)&__NSConstantStringImpl__var_folders_5y_yjd90h1x3_l05zb_76wpthp40000gn_T_main_97ec57_mi_0);
    }

    //定义block 变量
    void(*block)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA));
    //执行 block 内部代码
    ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);
     
     
     去掉强转上面代码转换为如下：
     void(*block)(void) = &__main_block_impl_0(__main_block_func_0, &__main_block_desc_0_DATA));
     //执行 block 内部代码
     block->FuncPtr(block);
    */
       
//    void(^block)(void) = ^{
//       NSLog(@"hello block");
//    };
//    block();  //底层 block->FuncPtr(block);
        
#pragma mark - 变量捕获 main-02.cpp

        /*
         static struct __main_block_desc_0 {
                   size_t reserved;
                   size_t Block_size;
                 } __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};
         
         struct __main_block_impl_0 {
           struct __block_impl impl;
           struct __main_block_desc_0* Desc;
           __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) {
             impl.isa = &_NSConcreteStackBlock;
             impl.Flags = flags;
             impl.FuncPtr = fp;
             Desc = desc;
           }
         };
         
         static void __main_block_func_0(struct __main_block_impl_0 *__cself, int a, int b) {
                     NSLog((NSString *)&__NSConstantStringImpl__var_folders_5y_yjd90h1x3_l05zb_76wpthp40000gn_T_main_a153eb_mi_0,a + b);
                 }
         
         void(*block)(int,int) = ((void (*)(int, int))&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA));
         ((void (*)(__block_impl *, int, int))((__block_impl *)block)->FuncPtr)((__block_impl *)block, 10, 20);
         
         简化以后如下：
         void(*block)(int,int) = &__main_block_impl_0(__main_block_func_0, &__main_block_desc_0_DATA));
         block->FuncPtr(block, 10, 20);
         */
        
//        void(^block)(int,int) = ^(int a,int b) {
//            NSLog(@"a + b = %d",a + b);
//        };
//        block(10,20);    // 10 20
        
#pragma mark - 捕获静态局部变量(指针传递) 和 auto变量(值传递)  main-03.cpp
        
        //捕获静态局部变量 和 auto 变量
        /*
         * auto 局部变量 变量是值传递 自动变量,离开作用域就会被销毁 一般 auto 不写 (auto 变量就是局部变量)
         * static 局部变量 是指针传递
         */
        
        /*
         struct __main_block_impl_0 {
           struct __block_impl impl;
           struct __main_block_desc_0* Desc;
           int age;  // 变量捕获
           int *height;
            // age(_age)  的意思外面传进来的_age 赋值给 age
           __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int _age, int *_height, int flags=0) : age(_age), height(_height) {
             impl.isa = &_NSConcreteStackBlock;
             impl.Flags = flags;
             impl.FuncPtr = fp;
             Desc = desc;
           }
         };
         static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
           int age = __cself->age; // bound by copy
           int *height = __cself->height; // bound by copy

                     NSLog((NSString *)&__NSConstantStringImpl__var_folders_5y_yjd90h1x3_l05zb_76wpthp40000gn_T_main_3d1d33_mi_0,age,(*height));
                 }

         static struct __main_block_desc_0 {
           size_t reserved;
           size_t Block_size;
         } __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};
         
         
         auto int age = 10;
         static int height = 10;
         void(*block)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, age, &height)); // &height 传递过来的是地址
         age = 20;
         height = 20;
         ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);
         
         简写如下：
         auto int age = 10;
         static int height = 10;
         void(*block)(void) = &__main_block_impl_0(__main_block_func_0, &__main_block_desc_0_DATA, age, &height));
         age = 20;
         height = 20;
         block->FuncPtr(block);
         */
        
//        auto int age = 10;      //auto 局部变量 变量是值传递
//        static int height = 10; //static 局部变量 是指针传递(引用传递)
//        void(^block)(void) = ^{
//            NSLog(@"age:%d  height:%d",age,height);  // age:10  height:20
//        };
//        age = 20;
//        height = 20;
//        block();
        
#pragma mark - 不会捕获全局变量 main-04.cpp
        
        /*
         // age 和 height 声明为全局变量
         int age = 10;
         static int height = 10;

         struct __main_block_impl_0 {
           struct __block_impl impl;
           struct __main_block_desc_0* Desc;
           __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) {
             impl.isa = &_NSConcreteStackBlock;
             impl.Flags = flags;
             impl.FuncPtr = fp;
             Desc = desc;
           }
         };
         static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
                    // 直接以全局变量的形式来打印
                     NSLog((NSString *)&__NSConstantStringImpl__var_folders_5y_yjd90h1x3_l05zb_76wpthp40000gn_T_main_ead607_mi_0,age,height);
                 }

         static struct __main_block_desc_0 {
           size_t reserved;
           size_t Block_size;
         } __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};
         
         void(*block)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA));
         age = 20;
         height = 20;
         ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);
         */
        
        //不会去捕获 因为可以直接访问
//        void(^block)(void) = ^{
//            NSLog(@"age:%d  height:%d",age,height);  // age:20  height:20
//        };
//        age = 20;
//        height = 20;
//        block();
        
#pragma mark - block 类型 main-05.cpp

        // block 继承关系 (最终是继承自 NSObject 也是为什么有 isa 的原因)
        /**
         * __NSGlobalBlock__ :  __NSGlobalBlock : NSBlock : NSObject
         */
        
//        void (^block)(void) = ^{
//            NSLog(@"hello");
//        };
//
//        NSLog(@"%@",[block class]);  // __NSGlobalBlock__
//        NSLog(@"%@",[[block class] superclass]);  //__NSGlobalBlock
//        NSLog(@"%@",[[[block class] superclass] superclass]);  //NSBlock
//        NSLog(@"%@",[[[[block class] superclass] superclass] superclass]); //NSObject
        
        
        // Block 的三种类型
        /**
         * __NSGlobalBlock__  存放在数据区
         * __NSMallocBlock__  存放在堆区 (堆区的内存是需要程序员申请和释放的)
         * __NSStackBlock__   存放在栈区
         */
        
//        void (^block1)(void) = ^{
//            NSLog(@"hello");  //__NSGlobalBlock__
//        };
//
//        int age = 10;
//        void(^block2)(void) = ^{
//            NSLog(@"hello %d",age);   //__NSMallocBlock__
//        };
//
//        NSLog(@"%@   %@   %@",[block1 class],[block2 class],[^{
//            NSLog(@"%d",age);
//        } class] );   //__NSGlobalBlock__   __NSMallocBlock__   __NSStackBlock__
    
        
        /**
         * 没有访问 auto 变量的都是      __NSGlobalBlock__
         * 访问了 auto 变量的都是        __NSStackBlock__
         * __NSStackBlock__调用了copy  __NSMallocBlock__
         *
         * 无论是 静态局部变量 全局变量 都是 __NSGlobalBlock__
         */
        
        // __NSGlobalBlock__  没有访问 auto 变量
//        void(^block)(void) = ^{
//            NSLog(@"没有访问auto变量");
//        };
//        NSLog(@"%@",[block class]);  //__NSGlobalBlock__
        
        //__NSStackBlock__  访问了 auto 变量都是 (ARC 环境下__NSMallocBlock__)
//        int b = 10;
//        void (^block1)(void) = ^{
//            NSLog(@" ===== %d ",b);
//        };
//        NSLog(@"%@",[block1 class]);  //__NSMallocBlock__
        //因为是ARC 环境 所以被转换了 手动把 ARC 关了(Objective-C Automatic Reference Counting 置为 NO )后是 __NSStackBlock__
        
        // __NSGlobalBlock__  访问了 静态局部变量  静态全局变量 或者 全局变量
//        static int a = 10;
//        void (^block2)(void) = ^{
//            NSLog(@" ===== %d == %d == %d",a,age,height);
//        };
//        NSLog(@"%@",[block2 class]);   //__NSGlobalBlock__   无论是 静态 局部变量/全局变量 都是 __NSGlobalBlock__

        // 栈上的内存会被系统回收自动销毁
        // 解决这种被系统回收的问题的办法就是 copy 到堆上
//        test();
//        block3();  // 非ARC 环境下打印结果 testStackBlock === -272632616 不等于 20  因为栈上的内存被系统销毁了
        
        
        // 栈上的内存会被系统回收自动销毁 (避免回收的办法一般是 copy到堆上)
        // 堆上的内存需要程序员处理
        // 所以开发中 一般都是用copy 需要把 block 保存下来
        
        /**
         * 每一种 block copy 后的结果
         * __NSStackBlock__     栈 -> 从栈复制到堆
         * __NSGlobalBlock__    程序的数据区域 -> 什么也不做
         * __NSMallocBlock__    堆  -> 引用计数加1
         */
         
#pragma mark - 对象类型的 auto 变量 main-06.cpp
        
//        Person *person = [[Person alloc] init];
//        person.age = 10;
//        Block block = ^{
//            NSLog(@"---------- %d",person.age);
//        };
//        block();
        
        // block() 执行结果 
        // ---------- 10
        //Person === delloc
        
        //ARC 环境下 block 释放以后 person 才销毁  因为 blcok 在堆空间内(系统做了copy操作)，且block 内部用到了 person 对 person 进行强引用，这样就会到 block 销毁 person 才会被销毁
        //在 MRC 环境下，即使 block 没有销毁，person 也会销毁 ，因为在 MRC 下 block 在栈空间，不会对 person 进行强引用，如果对 block 进行copy 则会变成堆block ，这样就会对 person 进行强引用，直到 block 销毁 person 才会销毁
        // 结论 ：栈空间的 block 是不会对外部对象类型 auto 变量进行强引用的
        
        /**
         * 对象类型的 auto 变量总结：
         * 当 Block 内部访问了对象类型的auto变量时：
         *    如果block 在栈上，将不会对auto 变量产生强引用
         *    如果block被拷贝到堆上(会对auto变量产生强引用)：
         *         会调用block 内部的copy 函数
         *         copy函数内部会调用 _Block_object_assign 函数
         *         _Block_object_assign函数会根据 auto 变量的修饰符(__strong/__weak/__unsafe_unretained)做出相应的操作，类似于 retain (形成强引用、弱引用)
         *    如果block 从堆上移除：
         *      会调用block内部的dispose函数
         *      dispose函数内部会调用_Block_object_dispose 函数
         *      _Block_object_dispose 函数会自动释放引用的 auto变量，类似于release
         *  总结：
         *      copy 函数         调用时机：栈上的 block 复制到堆时
         *      dispose函数      调用时机：堆上的block被废弃时
         */
        
        
#pragma mark - __block 修改变量 main-07.cpp main-08.cpp
       
        
        // 想要在 blcok 内部修改外部变量
        // 可以声明为 static 类型局部变量（因为是指针传递所以可以改） 或者 全局变量（全局变量随便改）
        // static 和 全局变量 弊端 会一直存在于内存中
        /**
         * __block 修饰符
         * __block 可以用于解决block 内部无法修改 auto 变量值的问题
         * __block 不能修饰全局变量、静态变量(static)
         * 编译器会将 __block 变量包装成一个对象
         */
        
        // 对应 c++ 代码 main-07.cpp
        /*
        struct __Block_byref_age_0 {
          void *__isa;
        __Block_byref_age_0 *__forwarding;  // __forwarding 指针指向自己
         int __flags;
         int __size;
         int age;
        };

        struct __main_block_impl_0 {
          struct __block_impl impl;
          struct __main_block_desc_0* Desc;
          __Block_byref_age_0 *age; // by ref
          __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, __Block_byref_age_0 *_age, int flags=0) : age(_age->__forwarding) {
            impl.isa = &_NSConcreteStackBlock;
            impl.Flags = flags;
            impl.FuncPtr = fp;
            Desc = desc;
          }
        };
        */
        
//        struct __block_impl {
//          void *isa;
//          int Flags;
//          int Reserved;
//          void *FuncPtr;
//        };
//
//        //  (__Block_byref_age_0 *) age = 0x00000001007439b0
//        //  po &age  0x1007439c8
//        struct __Block_byref_age_0 {
//         void *__isa;  //8  0x00000001007439b0  结构体的地址就是结构体第一个成员的地址
//         struct __Block_byref_age_0 *__forwarding;  //__forwarding 指针指向自己  // 8  0x00000001007439b8
//         int __flags;  //4 0x00000001007439c0
//         int __size;  //4  0x00000001007439c4
//         int age;     //4  0x00000001007439c8  0x1007439c8  所以block内部修改 age 实际上修改的是 __Block_byref_age_0 内部的age
//        };
//
//        struct __main_block_desc_0 {
//          size_t reserved;
//          size_t Block_size;
//          void (*copy)(void);
//          void (*dispose)(void);
//        };
//
//        struct __main_block_impl_0 {
//          struct __block_impl impl;
//          struct __main_block_desc_0* Desc;
//          struct __Block_byref_age_0 *age; // by ref
//        };
//
//        __block int age = 10;
//       Block block = ^{
//            age = 20;
//            NSLog(@"%d",age);
//        };
//        block();
        
        //查看 block 内部结构验证地址
//        struct __main_block_impl_0  *blockImpl = (__bridge struct __main_block_impl_0 *)block;
//        NSLog(@"%p",&age);  // 0x1007439c8

        // 另外一种终端地址验证方式
//        p/x blockImpl->age
//        (__Block_byref_age_0 *) $1 = 0x0000000100728b80
//        p/x &(blockImpl->age->age)
//        (int *) $0 = 0x0000000100728b98
        
        
        // 对应 c++ 代码 main-08.cpp
//        __block id obj = [[NSObject alloc] init];
//        void(^block)(void) = ^{
//            NSLog(@"%@",obj);
//        };
//        block();
        
        /*
         struct __Block_byref_obj_0 {
           void *__isa;
         __Block_byref_obj_0 *__forwarding;
          int __flags;
          int __size;
          void (*__Block_byref_id_object_copy)(void*, void*);
          void (*__Block_byref_id_object_dispose)(void*);
          id obj;
         };

         struct __main_block_impl_0 {
           struct __block_impl impl;
           struct __main_block_desc_0* Desc;
           __Block_byref_obj_0 *obj; // by ref
           __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, __Block_byref_obj_0 *_obj, int flags=0) : obj(_obj->__forwarding) {
             impl.isa = &_NSConcreteStackBlock;
             impl.Flags = flags;
             impl.FuncPtr = fp;
             Desc = desc;
           }
         };
         */

        
#pragma mark - __block 内存管理 __weak
        
        /**
         * 当 block 在栈上时，并不会对 __block 变量产生强引用
         * 当 block 被拷贝到堆上时：
         *     会调用block 内部的copy 函数
         *     copy函数内部会调用_Block_object_assign函数
         *     _Block_object_assign函数会对__block变量形成强引用（retain）
         * 当 block 从堆上移除时：
         *      会调用block内部的dispose函数
         *      dispose函数内部会调用_Block_object_dispose函数
         *      _Block_object_dispose函数会自动释放引用的__block变量（release）
         */
        
        // xcrun -sdk iphoneos clang -arch arm64 -rewrite-objc -fobjc-arc -fobjc-runtime=ios-8.0.0 main.m
        
        /**
         * 对象类型的auto 变量 、__block 变量  (main-09.cpp)
         * 当block 在栈上时，对他们都不会产生强引用
         * 当block 拷贝到堆上时，都会通过 copy 函数来处理他们
         *    __block 变量(假设变量名都叫a)
         *       _Block_object_assign((void*)&dst->a, (void*)src->a, 8 /BLOCK_FIELD_IS_BYREF /);
         *    对象类型的auto变量（假设变量名叫做p）
         *       _Block_object_assign((void*)&dst->p, (void*)src->p, 3/BLOCK_FIELD_IS_OBJECT/);
         * 当block从堆上移除时，都会通过dispose函数来释放它们
         *    __block变量（假设变量名叫做a）
         *       _Block_object_dispose((void*)src->a, 8/BLOCK_FIELD_IS_BYREF/);
         *    对象类型的auto变量（假设变量名叫做p）
         *       _Block_object_dispose((void*)src->p, 3/BLOCK_FIELD_IS_OBJECT/);
        */

//        int no = 20;
//        __block int age = 30;
//        NSObject *object = [[NSObject alloc] init];
//        __weak NSObject *weakObject = object;
//        Block block = ^{
//            NSLog(@"%d",no);
//            NSLog(@"%d",age);
//            NSLog(@"%@",weakObject);
//        };
 
#pragma mark - __block的 __forwarding指针
        /**
         * 在栈上的时候，__forwarding 指向栈上的__block 变量结构体本身
         * 复制到堆上之后，栈上的 __forwarding  指针指向堆上的备份的__block 结构体变量，堆上的 __forwarding 指向堆上备份的自己
         * 这样就能保证不管是在栈上还是堆上都可以通过 __forwarding 来访问堆上的 __blcok 结构体中的变量
         */

#pragma mark - __block 修饰的对象类型  main-10.cpp
        
        /**
         * 当__block变量在栈上时，不会对指向的对象产生强引用
         * 当__block变量被copy到堆时
         *      会调用__block变量内部的copy函数
         *      copy函数内部会调用_Block_object_assign函数
         *      _Block_object_assign函数会根据所指向对象的修饰符（__strong、__weak、__unsafe_unretained）做出相应的操作，形成强引用（retain）或者弱引用（注意：这里仅限于ARC时会retain，MRC时不会retain）
         * 如果__block变量从堆上移除
         *      会调用__block变量内部的dispose函数
         *      dispose函数内部会调用_Block_object_dispose函数
         *      _Block_object_dispose函数会自动释放指向的对象（release）
         */
        
//        __block Person *person = [[Person alloc] init];
//        Block block = ^{
//            NSLog(@"%@",person);
//        };
        
#pragma mark - 循环引用
    
        /**
         * ARC 的情况下
         * 1、__unsafe_unretained（不常用，因为不安全）: 不会产生强引用，不安全，指向的对象销毁时，指针存储的地址不变（指向一块被回收的内存）
         * 2、__weak（常用） : 不会产生强引用，指向的对象销毁时，会自动让指针置为nil
         * 3、__block 解决 （必须要调用block,且做清空操作(置为nil)）
         *
         * MRC 的情况下
         * MRC 不支持 __weak
         * 1、用 __unsafe_unretained 解决
         * 2、用 __block 解决
         */
      
        // 会出现循环引用  main-11.cpp
//        Person *person = [[Person alloc] init];
//        person.age = 20;
//        person.block = ^{
//           NSLog(@"age is : %d",person.age);
//        };
//        NSLog(@"========");
        
        //这样会不安全，一般不会使用
        // ARC 通过 __unsafe_unretained 解除循环引用
//        Person *person = [[Person alloc] init];
//        person.age = 20;
//        __unsafe_unretained typeof(person) weakPerson = person;
//        person.block = ^{
//            NSLog(@"age is : %d",weakPerson.age);
//        };
//        NSLog(@"==============");
        
        // ARC 通过 __weak 解除循环引用
//        Person *person = [[Person alloc] init];
//        person.age = 20;
//        __weak typeof(person) weakPerson = person;
//        person.block = ^{
//            NSLog(@"age is : %d",weakPerson.age);
//        };
//        NSLog(@"==============");
        
        // ARC 通过 __blcok 解除循环引用
//        __block Person *person = [[Person alloc] init];
//        person.age = 20;
//        person.block = ^{
//            NSLog(@"age is : %d",person.age);
//            person = nil;
//        };
//        person.block(); //必须调用才行
//        //缺点：如果不手动执行blcok 就会一直存在 也存在内存泄露
//        NSLog(@"==============");
     
        // main-12.cpp  参考链接：https://www.jianshu.com/p/fe772a3536ca
        /*
         只有单个线程的时候只用 __weak 是没有问题的，但是在多线程的情况下就可能造成在执行上半部分代码的时候，对象还在，而在执行下半部分的时候对象已经被释放的情况，比如下面的情况
         
         TestObj *obj = [[TestObj alloc] init];
         __weak TestObj *weakObj = obj;
         NSLog(@"before block retainCount:%zd",[obj arcDebugRetainCount]);
         block = ^(){
             NSLog(@"TestObj对象地址:%@",weakObj);
             dispatch_async(dispatch_queue_create(DISPATCH_QUEUE_PRIORITY_DEFAULT, NULL), ^{
                 
                 for (int i = 0; i < 1000000; i++) {
                     // 模拟一个耗时的任务
                 }

                 NSLog(@"耗时的任务 结束 TestObj对象地址:%@",weakObj);
             });
         };
         NSLog(@"after block retainCount:%zd",[obj arcDebugRetainCount]);
         block();
         
         //执行结果：
         DemoWeek[19247:6816518] before block retainCount:1
         DemoWeek[19247:6816518] after block retainCount:1
         DemoWeek[19247:6816518] TestObj对象地址:<TestObj: 0x602000006af0>
         DemoWeek[19247:6816518] TestObj 对象已释放
         DemoWeek[19247:6816544] 耗时的任务 结束 TestObj对象地址:(null)
         
         处理办法：
         block = ^(){
         __strong  TestObj *strongObj = weakObj;
             if(! strongObj) return;
         NSLog(@"TestObj对象地址:%@",strongObj);
         dispatch_async(dispatch_queue_create(DISPATCH_QUEUE_PRIORITY_DEFAULT, NULL), ^{
             
             for (int i = 0; i < 1000000; i++) {
                 // 模拟一个耗时的任务
             }

             NSLog(@"耗时的任务 结束 TestObj对象地址:%@",strongObj);
         });
         
         // 执行结果:
         DemoWeek[19280:6819437] before block retainCount:1
         DemoWeek[19280:6819437] after block retainCount:1
         DemoWeek[19280:6819437] TestObj对象地址:<TestObj: 0x602000006b30>
         DemoWeek[19280:6819464] 耗时的任务 结束 TestObj对象地址:<TestObj: 0x602000006b30>
         DemoWeek[19280:6819464] TestObj 对象已释放
         */
        
//        Person *person = [[Person alloc] init];
//        __weak typeof(person) weakPerson = person;
//        person.block = ^{
//          __strong typeof(weakPerson) strongPerson = weakPerson;
//          NSLog(@"age is : %d",strongPerson.age);
//        };
        
        
    }
    return 0;
}

