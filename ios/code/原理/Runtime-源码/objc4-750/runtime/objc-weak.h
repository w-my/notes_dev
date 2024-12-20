/*
 * Copyright (c) 2010-2011 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _OBJC_WEAK_H_
#define _OBJC_WEAK_H_

#include <objc/objc.h>
#include "objc-config.h"

__BEGIN_DECLS

/*
The weak table is a hash table governed by a single spin lock.
An allocated blob of memory, most often an object, but under GC any such 
allocation, may have its address stored in a __weak marked storage location 
through use of compiler generated write-barriers or hand coded uses of the 
register weak primitive. Associated with the registration can be a callback 
block for the case when one of the allocated chunks of memory is reclaimed. 
The table is hashed on the address of the allocated memory.  When __weak 
marked memory changes its reference, we count on the fact that we can still 
see its previous reference.

So, in the hash table, indexed by the weakly referenced item, is a list of 
all locations where this address is currently being stored.
 
For ARC, we also keep track of whether an arbitrary object is being 
deallocated by briefly placing it in the table just prior to invoking 
dealloc, and removing it via objc_clear_deallocating just prior to memory 
reclamation.

*/

// The address of a __weak variable.
// These pointers are stored disguised so memory analysis tools
// don't see lots of interior pointers from the weak table into objects.
typedef DisguisedPtr<objc_object *> weak_referrer_t;

#if __LP64__
#define PTR_MINUS_2 62
#else
#define PTR_MINUS_2 30
#endif

/** 存储在弱引用表的内部结构
 *  维护和存储指向对象的弱引用的哈希表。
 * The internal structure stored in the weak references table. 
 * It maintains and stores
 * a hash set of weak references pointing to an object.
 * If out_of_line_ness != REFERRERS_OUT_OF_LINE then the set
 * is instead a small inline array.
 */
#define WEAK_INLINE_COUNT 4

// out_of_line_ness field overlaps with the low two bits of inline_referrers[1].
// inline_referrers[1] is a DisguisedPtr of a pointer-aligned address.
// The low two bits of a pointer-aligned DisguisedPtr will always be 0b00
// (disguised nil or 0x80..00) or 0b11 (any other address).
// Therefore out_of_line_ness == 0b10 is used to mark the out-of-line state.
#define REFERRERS_OUT_OF_LINE 2

// 负责维护和存储指向一个对象的所有弱引用hash 表
// 每个 weak_entry_t 对应一个 OC 对象的弱引用信息
// 也是一个 hash 表，存储的元素是 weak_referrer_t 实质上是弱引用该对象的指针的指针
// objc_object **newReferrer 通过操作指针的指针，可以使得 weak 引用的指针在对象析构后 指向nil
struct weak_entry_t {
    
    // 将一个对象的指针地址进行特殊处理，这里是取负值
    DisguisedPtr<objc_object> referent;
    
    // 引用该对象的对象列表，联合。 引用个数小于4，用inline_referrers数组。 引用个数大于4，用动态数组weak_referrer_t *referrers
    // 动态数组 和 定长数组 用来存储弱引用该对象的指针的指针，同样也是对地址进行了特殊处理
    // 当弱引用该对象的指针数据小于 4（WEAK_INLINE_COUNT）使用定长数组
    // 当操作 WEAK_INLINE_COUNT 会将定长数组中的元素转移到动态数组中，并之后都使用动态数组储存
    union {
        struct { // 动态数组
            weak_referrer_t *referrers;  // 弱引用该对象的对象指针地址的hash数组
            uintptr_t        out_of_line_ness : 2;  // 是否使用动态hash数组标记位
            uintptr_t        num_refs : PTR_MINUS_2;  // hash数组中的元素个数
            uintptr_t        mask; // hash数组长度-1，会参与hash计算。（注意，这里是hash数组的长度，而不是元素个数。比如，数组长度可能是64，而元素个数仅存了2个）素个数）。
            uintptr_t        max_hash_displacement; // 可能会发生的hash冲突的最大次数，用于判断是否出现了逻辑错误（hash表中的冲突次数绝不会超过改值）
            };
        };
        struct { // 定长数组
            // out_of_line_ness field is low bits of inline_referrers[1]
            weak_referrer_t  inline_referrers[WEAK_INLINE_COUNT];
        };
    };

    // 判断 weak_entry_t  使用的是 定长数组还是动态数组
    // 实质是测试定长数组第二个元素值的2进制位第2位是否等于01。
    // 因为根据苹果的注释，inline_referrers[1] 中存储的是pointer-aligned DisguisedPtr ，
    // 即指针对齐的指针摘要，其最低位一定是0b00或0b11，因此可以用0b10 表示使用了动态数组
    bool out_of_line() {
        return (out_of_line_ness == REFERRERS_OUT_OF_LINE);
    }

    // 赋值方法
    weak_entry_t& operator=(const weak_entry_t& other) {
        memcpy(this, &other, sizeof(other));
        return *this;
    }

    // 构造方法 初始化了静态数组
    weak_entry_t(objc_object *newReferent, objc_object **newReferrer)
        : referent(newReferent)
    {
        inline_referrers[0] = newReferrer;
        for (int i = 1; i < WEAK_INLINE_COUNT; i++) {
            inline_referrers[i] = nil;
        }
    }
};

/**
 * 全局弱引用表，将对象的地址作为key  weak_entry_t 结构体对象作为 value
 * The global weak references table. Stores object ids as keys,
 * weak_entry_t结构存储为它们的值
 * and weak_entry_t structs as their values.
 */
struct weak_table_t {
    // hash数组，是一个动态数组，用来存储 weak_table_t 的数据元素 weak_entry_t
    // 其他三个元素将会用于 hash 表的相关操作
    weak_entry_t *weak_entries;
    // hash 数组中的元素个数
    size_t    num_entries;
    // 参hash 计算判断引用计数辅助量
    // hash数组长度-1，会参与hash计算。（注意，这里是hash数组的长度，而不是元素个数。比如，数组长度可能是64，而元素个数仅存了2个）
    uintptr_t mask;
   // 可能会发生的hash冲突的最大次数，用于判断是否出现了逻辑错误（hash表中的冲突次数绝不会超过改值）
    uintptr_t max_hash_displacement;
};

// 将 weak ptr地址 注册到obj对应的weak_entry_t中
/// Adds an (object, weak pointer) pair to the weak table.
id weak_register_no_lock(weak_table_t *weak_table, id referent, 
                         id *referrer, bool crashIfDeallocating);

/// Removes an (object, weak pointer) pair from the weak table.
void weak_unregister_no_lock(weak_table_t *weak_table, id referent, id *referrer);

#if DEBUG
/// Returns true if an object is weakly referenced somewhere.
bool weak_is_registered_no_lock(weak_table_t *weak_table, id referent);
#endif

/// Called on object destruction. Sets all remaining weak pointers to nil.
void weak_clear_no_lock(weak_table_t *weak_table, id referent);

__END_DECLS

#endif /* _OBJC_WEAK_H_ */
