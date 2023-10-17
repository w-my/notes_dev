//
//  ViewController.swift
//  集合类型
//
//  Created by WTW on 2020/1/19.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MARK: - 数组、字典(也叫映射表或散列表)、Set
        // Swift 中的数组 、字典、Set 都是以泛型集合实现的
        
        // MARK: - 数组
        // 一串有序的相同类型的元素构成的集合，数组关心的是是否有序，而不关心是否重复
        
        // 声明 和 初始化
        // Swift 的 Array类型被桥接到了基础框架的 NSArray类上
        // Array 是结构体类型，NSArray 是类
        
        // 声明数组
        // Array<String> 是泛型写法 说明这个数组中只能存放字符串类型的数据
        // [String] 和上面是等价的
        var studentList1: Array<String>
        var studentList2: [String]   // 推荐写法
        
        studentList1 = ["张三","李四","王五","董六"]
        studentList2 = ["张三","李四","王五","董六"]
        let studentList3 = ["张三","李四","王五","董六"]  //声明不可变数组
        var studnetList4 = [String]()  // 初始化一个空数组 [String] 仅仅是声明 ,[String]()进行初始化 ，只不过没有任何元素
        
        // 可变数组
        // var 可变
        // let 不可变
        // 不可变在访问效率上比可变数组要高 ，可变数组牺牲访问效率换区可变性(需要重新改变大小，然后重排他们的索引下标)
        // 追加元素 append 方法 、+ 和 += 操作符实现
        // + 和 +=  能将两个数组合并在一起
        // 插入元素 insert(插入到特定位置)
        // 删除元素 remove
        // 是否为空 isEmpty
        
        print("原始数据 \(studentList1)",studentList1.isEmpty)
        studentList1.append("刘备")   // 不能追加多个元素
        print("append \(studentList1)")
        studentList1 += ["关于","张飞"]
        print("+= \(studentList1)")
        studentList1.insert("悟空", at: studentList1.count)
        print("insert \(studentList1)")
        studentList1.remove(at: 0)
        print("remove \(studentList1)")
//        studentList1.removeLast(3)  // 从后面开始删除 k 个元素
//        studentList1.removeFirst(<#T##k: Int##Int#>)  // 从前面开始删除 k 个元素
//        studentList1.removeLast()  // 删除最后一个元素
//        studentList1.removeFirst()  // 删除第一个元素
//        studentList1.removeAll()   // 清空数组
//        studentList1.removeSubrange(Range.init(NSRange(location: 0, length: 3))!)
        
        // 数组遍历
        for item in studentList1 {
            print(item)
        }
        
        // 数组的 enumerated 方法取出数组的索引和元素
        for (index,value) in studentList1.enumerated() {
            print("Item \(index) : value :\(value)")
        }
        
        // 迭代除第一个元素外的其余元素
        for item in studentList1.dropFirst() {
            print("===dropFirst== \(item) === ")
        }
        
        //迭代除最后几个元素的别的元素
        for item in studentList1.dropLast(3) {
            print("==dropLast(3) ==\(item)")
        }
        
        // MARK: 数组高级用法
        // https://www.cnblogs.com/strengthen/p/10297316.html
        // 转字符串 array.joined
        // 遍历 array.forearch
        // 排序 array.sort
        // 过滤 array.filter 元素是否应该包含在结果中
        // 映射 array.map 可以改变数组存储的数据类型
        // 其他映射 array.flatMap 过滤nil值；将多维素组变成一维数组，强制解析可选值
        // 其他映射 array.compactMap 过滤 nil 和 可选值
        // array.reduce   将元素合并到一个总和的值中 ,序列元素的累加
        
        
        // 遍历数组
        studentList1.forEach { (string) in
            print("映射",string)
        }
        
        // 序列元素的累加
        // 初始值为 0 对元素做相加，每次相加后的结果作为下次必报的参数
        let fibs = [1,1,2,3,5,8,13]
        let sum = fibs.reduce(0) { (x, y) in
            return x + y
        }
        print(sum)  // 33
        
        // 排序
        print("排序前",studentList1)
        studentList1.sort { (str1, str2) -> Bool in
            return str1 > str2
        }
        print("排序后",studentList1)
        
        // 过滤
        let arr = studentList1.filter { (str) -> Bool in
            return str == "李四"
        }
        print("过滤",arr)
     
        let result = fibs.filter { (item) -> Bool in
            item % 2 == 0
        }
        print("过滤的结果为\(result)")
        
//        // 切片 第二个元素到最后一个元素的数据 
//        let slice = fibs[1..<fibs.endIndex]   // [1, 2, 3, 5, 8, 13]
//        print(slice)
        
        
        // 映射
        let array = studentList1.map { (str) -> String in
            return "我是" + str
        }
        print("map 映射:",array)
        
        
        //MARK: - 字典
        // 键和值是成对出现的 键不能重复
        // Dictionary 是结构体类型 ，也是一个泛型集合
        
        // 声明 和 初始化
        // <Int,String> 是泛型，表明键集合元素类型是 Int 值集合元素类型是 String
        // [Int:String] 是等价的
        var studentDic1 : Dictionary<Int,String>
        var studentDic2 : [Int:String]
        
        studentDic1 = [102:"张三",103:"李四",104:"王五"]
        studentDic2 = [102:"张三",103:"李四",104:"王五"]
        let studentDic3 = [102:"张三",103:"李四",104:"王五"]  //不可变字典
        var studentDic4 = Dictionary<Int,String>()
        var studentDic5 = [Int:String]()
        
        // 可变字典
        // var 声明可变字典
        // let 声明不可变字典
        
        // 字典删除元素两种方式：
        // 一种是：给一个键赋值为nil 这样就可以删除元素
        // 另外一种是: 通过 removeValue(forKey):方式删除元素，方法返回值是要删除的值
        
        // 元素替换也有两种方式：
        // 一种是： 直接给一个存在的键赋值，这样新值就会替换旧值
        // 另一种是：通过updateValue(_:forKey)方法替换 ，方法返回值是要替换的值
        
        print("元素数据：\(studentDic1) 字典长度 :\(studentDic1.count)")
        
        studentDic1[110] = "李逵" // 追加元素
        print("追加后数据：\(studentDic1)")
        
        studentDic1[102] = nil  // 删除元素
        print("删除元素后数据：\(studentDic1)")
        
        let removeStudent = studentDic1.removeValue(forKey: 104)  // 删除元素
        print("删除的元素 \(removeStudent!)")
        print("removeValue 删除元素后数据：\(studentDic1)")
        
        studentDic1[110] = "关羽"  // 更新元素
        print("更新元素后的数据 : \(studentDic1)")
        
        let replaceStudent = studentDic1.updateValue("刘备", forKey: 110)
        print("被替换的studnet \(replaceStudent!)")
        print("updateValue 更新元素后的数据 : \(studentDic1)")
        
        
        // 字典的遍历
        // 只遍历值集合
        // 只遍历键集合
        // 同时遍历
        // 这些遍历过程都是可以通过 for 循环来实现的
        for studentId in studentDic2.keys {
            print("studentId:\(studentId)")
        }
        
        for studentName in studentDic2.values {
            print("studentName:\(studentName)")
        }
        
        for (key,value) in studentDic2 {
            print("syudentId:\(key) studentName:\(value)")
        }
        
        //MARK: 高级用法
        // merge 合并
        print("merge前" ,studentDic2)
        studentDic2.merge([102 : "我是王五"]) { (value1, value2) -> String in
          return value2  // 返回 value2 是合并之后的字典  返回  value1 还是合并之前的字典
        }
        print("merge后" ,studentDic2)
        
        // 字典排序
        print("排序前" ,studentDic2)
        let dict = studentDic2.sorted { (arg1,arg2) -> Bool in
            return arg1.key > arg2.key
        }
        print("排序后" ,dict)
        
        // MARK:- swift 中的 Set 集合
        // 无序的，不能重复的相同类型元素构成的集合
        // 强调的是不能重复
        // 数组强调的是有序
        
        // Set 的声明和初始化
        // Set 也是结构体类型 也是一个一维泛型集合
        // 没有像数组那样的简化写法
        var studentSetList1 : Set<String>
        var studentSetList2 = Set<String>()
        
        studentSetList1 = ["张三","李四","王五","董六"]
        studentSetList2 = ["张三","李四","王五","董六"]
        
        // 可变 Set 集合
        // 不可变 Set 集合与可变 Set 集合之间的关系，类似不可变素组和可变数组之间的关系
        // var 声明可变  let 声明不可变
        
        print("原始数据:\(studentSetList1) 数据长度:\(studentSetList1.count)");
        
        // insert 插入元素
        studentSetList1.insert("李逵")
        print("插入数据:\(studentSetList1)");
        
        // remove 删除元素
        let removeSetStudent = studentSetList1.removeFirst()
        let student = "张三"
        studentSetList1.remove(student)  // 删除特定元素
        print("删除的元素:\(removeSetStudent)");
        print("删除后数据:\(studentSetList1)");
        
        // contains 是否包含特定元素
        print(studentSetList1.contains(student))
        
        // Set 集合遍历
        for item in studentSetList2 {
            print(item)
        }
        
        for (index,value) in studentSetList2.enumerated() {
            print("item \(index) : value:\(value)")
        }
        
        // Set 集合运算
        // 交集 intersection
        // 并集 union
        // 异或集合 symmetricDifference
        // 差集 subtracting
        
        // MARK：元组
        // 元组一般应用到函数的返回值
        let tuple = (404,"Not Found")
        print(tuple.0)  // 404
        print(tuple.1)  // Not Found
        
        let tuple1 = (name:"huangjiang",age:"20")
        
        // 取值
        print(tuple1.0,tuple1.name)  // huangjiang huangjiang
        print(tuple1.1,tuple1.age)   // 20 20
        
        // 解构
        let (width,_) = (width:100,height:200)
        print(width)  // 100
    }


}

