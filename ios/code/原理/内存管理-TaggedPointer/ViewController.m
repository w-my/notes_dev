//
//  ViewController.m
//  内存管理-TaggedPointer
//
//  Created by WTW on 2019/8/26.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 主要是用来存储小对象，NSNumber NSDate NSString 等
 不在是一个简单的地址值，而是一个类型+长度(tag + value)
 读取速度非常快，读取是 3倍，创建是106倍 相比以前
 */


/*
  未使用 Tagged Pointer 时存在的问题：
 1、内存浪费
    由于OC中的内存对齐，在 64位中，创建一个对象至少需要16个字节，再加上一个指针8个字节，总共需要24个字节，为了存储一个数值，占用了24个字节，造成了内存极大的浪费
 2、性能浪费
    为了存储和访问一个NSNumber 对象，需要在堆上分配内存，还需要维护引用计数，管理其生命周期，这些都增加了额外的逻辑，造成了运行效率的损失。
 */

/*
 从64bit(5s)开始，iOS引入了Tagged Pointer技术，用于优化NSNumber、NSDate、NSString等小对象的存储

 在没有使用Tagged Pointer之前， NSNumber等对象需要动态分配内存、维护引用计数等，NSNumber指针存储的是堆中NSNumber对象的地址值

 使用Tagged Pointer之后，NSNumber指针里面存储的数据变成了：Tag + Data，也就是将数据直接存储在了指针中(也就是指针不再是地址，而是真正的值，实际上它不再是一个对象，而是一个普通变量而已。所以它的内存并不存储在堆中，也不需要 malloc 和 free，在内存的读取上)

 当指针不够存储数据时，才会使用动态分配内存的方式来存储数据

 objc_msgSend能识别Tagged Pointer，比如NSNumber的intValue方法，直接从指针提取数据，节省了以前的调用开销

 如何判断一个指针是否为Tagged Pointer？
    iOS平台，最高有效位是1（第64bit）
    Mac平台，最低有效位是1
 */

/* 源码：
 #if (TARGET_OS_OSX || TARGET_OS_IOSMAC) && __x86_64__
     // 64-bit Mac - tag bit is LSB
 #   define OBJC_MSB_TAGGED_POINTERS 0
 #else
     // Everything else - tag bit is MSB
 #   define OBJC_MSB_TAGGED_POINTERS 1
 #endif


 #if OBJC_MSB_TAGGED_POINTERS
 #   define _OBJC_TAG_MASK (1UL<<63)
 #else
 #   define _OBJC_TAG_MASK 1UL
 #endif

_objc_makeTaggedPointer(objc_tag_index_t tag, uintptr_t value)
 
 static inline bool
 _objc_isTaggedPointer(const void * _Nullable ptr)
 {
     return ((uintptr_t)ptr & _OBJC_TAG_MASK) == _OBJC_TAG_MASK;
 }
 */

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,copy) NSString *name;  // 解决问题可以使用 atomic 或者 加锁
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 面试题 思考以下2段代码能发生什么事？有什么区别？
    // 主要还是 考察 TaggedPointer 的问题
    /* 当指针不够存储数据的时候，才会动态分配内存的方式来存储数据，因为异步 调用 setter(先释放旧值然后copy新值，由于是异步并发可能会多次释放导致坏内存访问) 方法会导致调用 已经回收的对象 （可以通过加锁来解决）
     
        而 TaggedPointer(不是OC对象) 是不存在 retain 和 release 操作的(或者copy 操作)，所以不会存在上面的问题
     
     objc_retain(id obj)
     {
         if (!obj) return obj;
         if (obj->isTaggedPointer()) return obj;
         return obj->retain();
     }

     objc_release(id obj)
     {
         if (!obj) return;
         if (obj->isTaggedPointer()) return;
         return obj->release();
     }
     */
    
    // EXC_BAD_ACCES 通过加锁 可以处理奔溃
//    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
//    for (int i = 0; i < 1000; i++) {
//        dispatch_async(queue, ^{
//            // 加锁
//            // 实际是在频繁调用 setter 方法，内部在频繁的释放旧值copy新值，由于是异步可能会导致坏内存访问
//           self.name = [NSString stringWithFormat:@"abcdefghijklmnopqrst"];
//           // 解锁
//        });
//    }
//
//    // 如下代码不会崩溃 因为是 TaggedPointer 不是OC 对象，不会调用 setter 方法
//    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
//    for (int i = 0 ; i < 1000; i ++) {
//        dispatch_async(queue, ^{
//            self.name = [NSString stringWithFormat:@"abc"];
//        });
//    }
//
//    NSLog(@"end");

    /*
     怎么判断一个指针是否为 Tagged Pointer
         iOS平台，最高有效位是1（第64bit）
         Mac平台，最低有效位是1
     */
    NSString *str1 = [NSString stringWithFormat:@"abcdefghijklmnopqrst"];
    NSString *str2 = [NSString stringWithFormat:@"abc"];

    // str1 0x 6000 0330 c5c0       iOS 平台首位 0110
    // str2 0x 98b6 dc69 4c52 2fef  iOS 平台首位 1001 所谓 str2 为使用了 TaggedPointer
    /*
    str1 : 0x60000330c5c0
    str1class :__NSCFString
    str2: 0x98b6dc694c522fef
    str2class:NSTaggedPointerString
     */
    NSLog(@"\n str1 : %p \n str1class :%@ \n str2: %p \n str2class:%@",str1,[str1 class],str2,[str2 class]);
    
    NSNumber *number1 = @(1);
    NSNumber *number2 = @(2);
    NSNumber *number3 = @(0xFFFFFFFFFFFFFFF);
    // 在 objc4-750之后 苹果对这个指针做了一些编码处理，不能通过地址直接看出来是Tagged Pointer，只能根据首位是否为1来判断(iOS平台)
    /*
     number1: 0x8cb71b2bf3cb4bcd
     number2: 0x8cb71b2bf3cb4bfd
     number3: 0x600001e8fc00
     */
    NSLog(@"\nnumber1: %p\nnumber2: %p\nnumber3: %p",number1,number2,number3);
    
    
    /*
     // 编码解码的目的就是为了简单的加密 ，不想让看到底层是怎么实现的
     // 编码
     _objc_encodeTaggedPointer(uintptr_t ptr)
     {
         return (void *)(objc_debug_taggedpointer_obfuscator ^ ptr);
     }
     // 解码
     _objc_decodeTaggedPointer(const void * _Nullable ptr)
     {
         return (uintptr_t)ptr ^ objc_debug_taggedpointer_obfuscator;
     }
     */
    
    // 解码处理之后的结果
    
    NSString *str3 = [NSString stringWithFormat:@"a"];
    NSString *str4 = [NSString stringWithFormat:@"b"];
    
    int num1 = 1;
    float num2 = 2.0;
    long num3 = 3;
    double num4 = 4.0;
    
    NSNumber *n1 = @(num1);
    NSNumber *n2 = @(num2);
    NSNumber *n3 = @(num3);
    NSNumber *n4 = @(num4);
    
    NSLog(@"\n 0x%lx \n 0x%lx ",_objc_decodeTaggedPointer_(str3),_objc_decodeTaggedPointer_(str4));
    NSLog(@"\n 0x%lx \n 0x%lx \n 0x%lx \n 0x%lx ",_objc_decodeTaggedPointer_(n1),_objc_decodeTaggedPointer_(n2),_objc_decodeTaggedPointer_(n3),_objc_decodeTaggedPointer_(n4));

    /*
     0xa000000000000611  // 最后一位代表类型
     0xa000000000000621
     
     0xb000000000000012    // 最后一位代表类型  2 int  float 4 long 3 double 5
     0xb000000000000024
     0xb000000000000033
     0xb000000000000045
     */
    
}

OBJC_EXPORT uintptr_t objc_debug_taggedpointer_obfuscator;

uintptr_t _objc_decodeTaggedPointer_(id ptr)
{
    return (uintptr_t)ptr ^ objc_debug_taggedpointer_obfuscator;
}

@end
