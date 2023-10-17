//
//  main.m
//  Runtime-API 类
//
//  Created by WTW on 2019/8/23.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "Person.h"
#import "Son.h"

/*
    // 类相关：
    动态创建一个类（参数：父类，类名，额外的内存空间）
    Class objc_allocateClassPair(Class superclass, const char *name, size_t extraBytes)

    注册一个类（要在类注册之前添加成员变量）
    void objc_registerClassPair(Class cls)

    销毁一个类
    void objc_disposeClassPair(Class cls)

    获取isa指向的Class
    Class object_getClass(id obj)

    设置isa指向的Class
    Class object_setClass(id obj, Class cls)

    判断一个OC对象是否为Class
    BOOL object_isClass(id obj)

    判断一个Class是否为元类
    BOOL class_isMetaClass(Class cls)

    获取父类
    Class class_getSuperclass(Class cls)

 
    // 成员变量相关：
    获取一个实例变量信息
    Ivar class_getInstanceVariable(Class cls, const char *name)

    拷贝实例变量列表（最后需要调用free释放）
    Ivar *class_copyIvarList(Class cls, unsigned int *outCount)

    设置和获取成员变量的值
    void object_setIvar(id obj, Ivar ivar, id value)
    id object_getIvar(id obj, Ivar ivar)

    动态添加成员变量（已经注册的类是不能动态添加成员变量的）
    BOOL class_addIvar(Class cls, const char * name, size_t size, uint8_t alignment, const char * types)

    获取成员变量的相关信息
    const char *ivar_getName(Ivar v)
    const char *ivar_getTypeEncoding(Ivar v)
  
    // 属性相关：
    获取一个属性
    objc_property_t class_getProperty(Class cls, const char *name)

    拷贝属性列表（最后需要调用free释放）
    objc_property_t *class_copyPropertyList(Class cls, unsigned int *outCount)

    动态添加属性
    BOOL class_addProperty(Class cls, const char *name, const objc_property_attribute_t *attributes,
                      unsigned int attributeCount)

    动态替换属性
    void class_replaceProperty(Class cls, const char *name, const objc_property_attribute_t *attributes,
                          unsigned int attributeCount)

    获取属性的一些信息
    const char *property_getName(objc_property_t property)
    const char *property_getAttributes(objc_property_t property)

 
    // 方法相关
    获得一个实例方法、类方法
    Method class_getInstanceMethod(Class cls, SEL name)
    Method class_getClassMethod(Class cls, SEL name)

    方法实现相关操作
    IMP class_getMethodImplementation(Class cls, SEL name)
    IMP method_setImplementation(Method m, IMP imp)
    void method_exchangeImplementations(Method m1, Method m2)

    拷贝方法列表（最后需要调用free释放）
    Method *class_copyMethodList(Class cls, unsigned int *outCount)

    动态添加方法
    BOOL class_addMethod(Class cls, SEL name, IMP imp, const char *types)

    动态替换方法
    IMP class_replaceMethod(Class cls, SEL name, IMP imp, const char *types)

    获取方法的相关信息（带有copy的需要调用free去释放）
    SEL method_getName(Method m)
    IMP method_getImplementation(Method m)
    const char *method_getTypeEncoding(Method m)
    unsigned int method_getNumberOfArguments(Method m)
    char *method_copyReturnType(Method m)
    char *method_copyArgumentType(Method m, unsigned int index)
 
    //选择器相关
    const char *sel_getName(SEL sel)
    SEL sel_registerName(const char *str)

    // 用block作为方法实现
    IMP imp_implementationWithBlock(id block)
    id imp_getBlock(IMP anImp)
    BOOL imp_removeBlock(IMP anImp)
 */

//动态添加的方法必须是已经实现的
void RuntimeTestMethodIMP(id self,SEL _cmd,NSDictionary *dict) {
    NSLog(@"传递进来的 dict%@",dict);
    NSLog(@"打印成员变量name: %@",object_getIvar(self, class_getInstanceVariable([self class], "_name")));
}
//传递进来的 dict{ age = 25; name = xiaoli; }

/**
 动态创建 类
 */
void dynamicCreatClass () {
    
    //在运行时动态生成一个类
    Class newClass = objc_allocateClassPair([NSObject class], "RuntimeClass", 0);
    
    // 为类添加成员变量
    // 给指定的类添加成员变量 ，只能在objc_allocateClassPair() 和 objc_registerClassPair() 之间调用，并且不能为一个已经存在的类添加成员变量
    class_addIvar(newClass, "_name", sizeof(NSString *), log2(sizeof(NSString *)), @encode(NSString *));
    class_addIvar(newClass, "_age", sizeof(int), sizeof(int), @encode(int));
    
    // 为类添加方法
    SEL sel = sel_registerName("RuntimeTestMethod");
    class_addMethod(newClass, sel, (IMP)RuntimeTestMethodIMP, "i@:@");
    
    // 注册类到Runtime (必须要注册)
    objc_registerClassPair(newClass);
    
    // 使用已经创建的类
    id person = [[newClass alloc] init];
    
    // 可以这样设置值
    //        [person setValue:@"小花" forKey:@"_name"];
    //        NSLog(@" name :%@",[person valueForKey:@"_name"]);
    
    // 设置成员变量的值
    Ivar nameIvar = class_getInstanceVariable(newClass, "_name");
    object_setIvar(person, nameIvar, @"xiaohua");
    
    Ivar ageIvar = class_getInstanceVariable(newClass, "_age");
    object_setIvar(person, ageIvar, @18);
    
    NSDictionary *dic = [NSDictionary dictionaryWithObjectsAndKeys:@"xiaoli",@"name",@"25",@"age", nil];
    [person performSelector:@selector(RuntimeTestMethod) withObject:dic];
    
    // 获取成员变量的值
    NSLog(@"实例变量Person的值%@  %@",object_getIvar(person, nameIvar),object_getIvar(person, ageIvar));
    // 实例变量Person的值xiaohua  18
    NSLog(@"实例所属的类: %@ ,实例所属的父类: %@",object_getClass(person),class_getSuperclass(object_getClass(person)));
    //实例所属的类: RuntimeClass ,实例所属的父类: NSObject
    
    // 在不需要这个类的时候释放
    //objc_disposeClassPair(newClass);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
//        Person *person = [[Person alloc] init];
//        [person run]; // [Person run]
//
//        //object_setClass  设置isa指向的Class
//        object_setClass(person, [Son class]);   // 可以动态修改 isa 指向
//        [person run]; // [Son run]
        
  
        //object_isClass 判断一个OC对象是否为Class
//        NSLog(@"%d  %d  %d",
//              object_isClass(person),
//              object_isClass([Person class]),
//              object_isClass(object_getClass([Person class])));  // 0 1 1
        
        
        //object_getClass 获取isa指向的 Class (获取类对象)
        // object_getClass(person) = [person class]
//        NSLog(@"%p == %p",object_getClass(person),[person class]);
        
//        NSLog(@"%s",class_getName(nil));
        
        
        //动态创建一个类 并为类添加 成员变量
//        dynamicCreatClass();
        
        
        // 获取成员变量信息
//        Ivar ivar = class_getInstanceVariable([Person class],"_height");
//        NSLog(@"%s == %s",ivar_getName(ivar),ivar_getTypeEncoding(ivar));  //  _height == i
        
        
//        unsigned int count = 0;
//        //获取类中的所有成员变量
//        Ivar *ivarList = class_copyIvarList([Person class], &count);
//        //遍历所有成员变量
//        for (int i = 0; i < count; i ++) {
//            //根据角标，从数组中取出对应的成员变量
//            Ivar ivar = ivarList[i];
//            //获取成员变量的名字
//            NSString *ivarName = [NSString stringWithUTF8String:ivar_getName(ivar)];
//
//            NSLog(@"%@",ivarName);
//        }
//        free(ivarList);
     
    }
    return 0;
}

