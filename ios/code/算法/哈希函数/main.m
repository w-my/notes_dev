//
//  main.m
//  哈希函数
//
//  Created by WTW on 2022/3/2.
//  Copyright © 2022 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 哈希表(也叫散列表)：
    哈希表是 空间换时间 的典型应用
    哈希函数，也叫散列函数
    哈希表内部的数据元素，很多地方也叫Bucket(桶)，整个数组叫 Buckets 或者 Bucket Array
    
    key -> 哈希函数_hash(key) -> 哈希表的索引(其实就是一个数组，索引就是数组的下标)
 
 哈希冲突(哈希碰撞)：
    两个不同的key,经过哈希函数计算出相同的结果
    key1 != key2   hash(key1) = hash(key2)
    
    解决hash 冲突的常见方法：
        1、开放定址法： 按照一定规则向其他地址探测，直到遇到空桶
        2、再哈希法： 设计多个hash 函数
        3、链地址法： 通过链表将同一个index 的元素串起来
 
    jdk 1.8 中解决hash 冲突的办法：
        默认使用单向链表将元素串起来
        在添加元素的时候，可能会由单向链表转为红黑树来存储元素
            比如当哈希表的容量>=64且单向链表节点数大于8时
        当红黑树结点少到一定程度的时候，又会转为单向链表
        jdk1.8 中是使用单向链表+红黑树来解决hash冲突的
 
 哈希函数
    哈希表中哈希函数的实现步骤大致如下：
        1、先生成key的哈希值（必须是整数）
        2、再让key的哈希值跟数组的大小进行相关的运算，生成一个索引值
            int hash(Object key){
                return hash_code(key) % table.length
            }
        为了提高效率可以使用&位运算代替%运算（前提是把table的长度设计为2的n次幂）
             int hash(Object key){
                 return hash_code(key) & (table.length -1 )
             }
    良好的哈希函数:
        让哈希值更加均匀分布 -> 减少 hash 冲突次数 -> 提升哈希表的性能
 
 如何生成 key 的哈希值？
    key 的常见类型可能有：
        整数、浮点数、字符串、自定义对象
        不同类型的key，哈希值的生成方式不一样，但是目标是一致的
            尽量让每个key 的哈希值是唯一的
            尽量让key的所有信息参与运算
    整数 int：
        整数值当做哈希值
        比如10的哈希值就是10
 
    浮点数 float：
        将存储的二进制格式转为整数值
 
    Long 和 Double：
         static int hashCode(long value){
             return (int)(value ^ (value >>> 32))
         }
         static int hashCode(double value){
             long bits = doubleToLongBits(value)
             return (int)(bits ^ (bits >>> 32))
         }
        >>> 和 ^ 的作用：
            高32bit 位和低32bit 位混合计算出32bit的哈希值
            充分利用所有信息计算出哈希值
 
    字符串的哈希值:
       字符串是有若干个字符组成
            比如jack 由 j a c k 四个字符组成(字符的本质就是一个整数)
            因此 jack 的哈希值可以表示为 j * n^3 + a * n^2 + c * n^1 + k * n^0 ,等价于 [(j * n + a) * n + c] * n + k
            在JDK 中，乘数n 为 31(31 是一个奇素数，JVM会将31*i 优化成 (i<<5) -i ),仅仅 java 中是31 ，其他不一样
 
    对象的哈希值：
        根据属性计算 类似字符串
        自定义对象的 hash 值需要实现 hashcode 和 equals 方法
 */

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
