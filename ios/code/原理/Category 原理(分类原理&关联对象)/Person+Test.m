//
//  Person+Test.m
//  Category 原理
//
//  Created by WTW on 2019/7/23.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person+Test.h"
#import <objc/runtime.h>

//#define weights_Key [NSString stringWithFormat:@"weight_%p",self]
//#define names_Key [NSString stringWithFormat:@"name_%p",self]
//NSMutableDictionary *weights_;
//NSMutableDictionary *names_;

@implementation Person (Test)

//+ (void)load {
//    weights_ = [NSMutableDictionary dictionary];
//    names_ = [NSMutableDictionary dictionary];
//}
//
//- (void)setWeight:(int)weight {
//    weights_[weights_Key] = @(weight);
//}
//
//- (int)weight {
//    return [weights_[weights_Key] intValue];
//}
//
//- (void)setName:(NSString *)name {
//    names_[names_Key] = name;
//}
//
//- (NSString *)name {
//    return names_[names_Key];
//}
/** 分类中添加属性的方案一：
 *      例如上面可以通过一个全局字典来实现 ： (这样做弊端比较多)
 *      1、但是可能会存在内存泄露问题 (全局的字典可能不会销毁)
 *      2、也会存在线程安全的问题 (多个属性同时访问字典,需要加锁)
 *      3、书写起来比较麻烦
 *  分类添加属性的方式二：
 *      关联对象的方式添加属性
 */

/**
 * 关联对象的理解：
 * 默认情况下，因为分类底层结构的限制，不能添加成员变量到分类中。但可以通过关联对象来间接实现
 *
 *  关联对象提供了以下API：
 *      添加关联对象
 *          void objc_setAssociatedObject(id object, const void * key,
                                id value, objc_AssociationPolicy policy)
 *      获得关联对象
 *          id objc_getAssociatedObject(id object, const void * key)
 *      移除所有的关联对象
 *          void objc_removeAssociatedObjects(id object)
 *
 * objc_AssociationPolicy    对应的修饰符:
 *      OBJC_ASSOCIATION_ASSIGN                              assign
 *      OBJC_ASSOCIATION_RETAIN_NONATOMIC       strong, nonatomic
 *      OBJC_ASSOCIATION_COPY_NONATOMIC         copy, nonatomic
 *      OBJC_ASSOCIATION_RETAIN                              strong, atomic
 *      OBJC_ASSOCIATION_COPY                                 copy, atomic
 */

/**
 * 面试题：如何使用runtime 给分类添加 weak 属性  (https://www.jianshu.com/p/ed65d71554d8)
 *
 *
 */

/**
 * 实现关联对象技术的核心对象有:
 * AssociationsManager
 * AssociationsHashMap
 * ObjectAssociationMap
 * ObjcAssociation
 *
 *  源码解读：objc-references.mm
 *  objc_setAssociatedObject
 *  _object_get_associative_reference
 *  _object_set_associative_reference
 *  _object_remove_assocations
 *

 class AssociationsManager {
    static AssociationsHashMap *_map;
 };
 
 //  key ： disguised_ptr_t       value ： ObjectAssociationMap *
 class AssociationsHashMap : public unordered_map<disguised_ptr_t, ObjectAssociationMap *, DisguisedPointerHash, DisguisedPointerEqual, AssociationsHashMapAllocator>{};
 
 class _LIBCPP_TEMPLATE_VIS unordered_map
 {
 public:
     // types
     typedef _Key                                           key_type;
     typedef _Tp                                            mapped_type;
     typedef pair<const key_type, mapped_type>              value_type;
 };
 
 // key : ObjcAssociation   value : ObjectPointerLess
class ObjectAssociationMap : public std::map<void *, ObjcAssociation, ObjectPointerLess,     ObjectAssociationMapAllocator>{};

 class ObjcAssociation {
      uintptr_t _policy;
      id _value;
}
 */

/* key 的方式可以写成多种形式
 static void *MyKey = &MyKey;
 objc_setAssociatedObject(obj, MyKey, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC)
 objc_getAssociatedObject(obj, MyKey)
 
 static char MyKey;
 objc_setAssociatedObject(obj, &MyKey, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC)
 objc_getAssociatedObject(obj, &MyKey)
 
 使用属性名作为key
 objc_setAssociatedObject(obj, @"property", value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
 objc_getAssociatedObject(obj, @"property");
 
 使用get方法的@selecor作为key (常用的方式)
 objc_setAssociatedObject(obj, @selector(getter), value, OBJC_ASSOCIATION_RETAIN_NONATOMIC)
 objc_getAssociatedObject(obj, @selector(getter))
 
 */

- (void)setName:(NSString *)name {
    objc_setAssociatedObject(self, @"name", name, OBJC_ASSOCIATION_COPY);
}

- (NSString *)name {
    return objc_getAssociatedObject(self, @"name");
}

// 推荐使用方式
- (void)setWeight:(int)weight {
    objc_setAssociatedObject(self, @selector(weight), @(weight), OBJC_ASSOCIATION_ASSIGN);
}

- (int)weight {
    //_cmd = @selector(weight)
    return [objc_getAssociatedObject(self, _cmd) intValue];
}

- (void)test1 {
    NSLog(@"%s",__func__);
}

+ (void)test2 {
    NSLog(@"%s",__func__);
}
@end
