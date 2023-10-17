//
//  ViewController.m
//  内存管理-引用计数的存储
//
//  Created by WTW on 2020/2/18.
//  Copyright © 2020 wtw. All rights reserved.
//

/*  引用计数
 在64bit中，引用计数可以直接存储在优化过的isa指针中，也可能存储在SideTable类中
 
 extra_rc : 里面存储的值是引用计数器减 1
 has_sidetable_rc : 引用计数器是否过大无法存储在isa 中，如果为1，那么引用一个叫 SideTable 的类的属性中
 
 可以在objc源码 NSObject.mm 中 retainCount 等方法中证实
 
 union isa_t
 {
    Class cls;
    uintptr_t bits;
    struct  {
        uintptr_t nonpointer        : 1;                                       \
        uintptr_t has_assoc         : 1;                                       \
        uintptr_t has_cxx_dtor      : 1;                                       \
        uintptr_t shiftcls          : 33;                                      \
        uintptr_t magic             : 6;                                       \
        uintptr_t weakly_referenced : 1;                                       \
        uintptr_t deallocating      : 1;                                       \
        uintptr_t has_sidetable_rc  : 1;                                       \
        uintptr_t extra_rc          : 19
    };
 }
    
 struct SideTable {
     spinlock_t slock;
     RefcountMap refcnts;  //refcnts 是一个存放着对象引用计数的散列表
     weak_table_t weak_table;  // 弱引用散列表
     ......
 }
 
 */

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    __unsafe_unretained
}


@end
