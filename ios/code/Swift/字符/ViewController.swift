//
//  ViewController.swift
//  字符
//
//  Created by WTW on 2020/1/19.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

/**
 * swift 中字符串不能使用单引号，必须使用双引号括起来
 * Character 字符类型 String 字符串类型 如果不指定，编译器默认是 String 类型
 *
 */

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        let str = "123456"
        
        print(str.prefix(3))
        
//        var userName = "1"
//        
//        if userName.count >= 2 {
//            let sIndex = userName.index(userName.startIndex, offsetBy: 1)
//            let eIndex = userName.index(userName.endIndex, offsetBy: -1)
//            let range = sIndex..<eIndex
//            userName.replaceSubrange(range, with:"**")
//        }
//        
//        print(userName)
        
        
        // MARK:- 概念
        ///swift 中字符不能使用单引号，必须使用双引号括起来 字符串也是使用双引号括起来
//        let str1 = 'str1'
//        print(str1)
        
        /// Character 字符类型 String 字符串类型 如果不指定，编译器默认是 String 类型
//        let cha1 : Character = "A" // Character
        let cha1 = "A"
        let cha2 = "&A"
        print(type(of: cha1)) // String
        print(type(of: cha2)) // String
        
        
        // MARK: 空字符串
        var emptyStr1 = ""
        var emptyStr2 = String()
        print(emptyStr1,emptyStr1.isEmpty) // true
        print(emptyStr2,emptyStr2.isEmpty)  // true
        
        // MARK: - 转义符  \
        // \t  水平制表符   \n 换行   \r 回车   \" 双引号  \' 单引号   \\ 反斜线
        
        // MARK:- 创建字符串
        // 在swift 中实际上 String 是一个结构体  在 OC 中 NSString 在Foundation 中是一个类，而不是结构体
        let 熊 = "🐻"
        let emptyString1 = ""
        let emotyString2 = String()
        print(熊 + emptyString1 + emotyString2)
        
        //MARK: - 可变字符串  var 声明可变字符串  字符串拼接 可以使用 +  、 += 、 append
        // 字符串拼接
        var 🌎 = "地球"
        🌎.append("123") // append
        🌎 = 🌎 + "_5"  // +
        🌎 += "_6"  // +=
        print(🌎)  // 地球123_5_6
        
        // 将不同类型的变量、常量和表达式运算的结果转换成字符串拼接起来 \()
        let muStr1 = "小明"
        let age = 20
        print(muStr1 + "\(age)" + "岁了")
     
        //MARK: - hasPrefix hasSuffix
        let hasStr = "123456"
        print(hasStr.hasPrefix("123"))  // true
        print(hasStr.hasSuffix("456"))  // true
        
        // MARK: - prefix suffix 截取子串，子串的类型不是 String ，而是 Substring
        var cutStr = "1_2_3_4_5"
        var substr1 = cutStr.prefix(3)
        var substr2 = cutStr.suffix(3)
        var cutRange = cutStr.startIndex..<cutStr.index(str.startIndex, offsetBy: 3)
        var substr3 = cutStr[cutRange]
        print(substr3.base)
        
        // Substring -> String
        var substr4 = String(substr3)
        
        // Substring 和 它的base 共享字符串数据
        // Substring 发生修改或者转为String 时，会分配新的内存存储字符串数据
        
        // MARK: - String 转换成 NSString 后截取
        // 另外一种方式是先把 String 转化为 NSString 后再进行截取
        let urlString = "1234hello5678"
        let header = (urlString as NSString).substring(to: 4)
        let middle = (urlString as NSString).substring(with: NSMakeRange(4, 9))
        let footer = (urlString as NSString).substring(from: 9)
        print(header,middle,footer)  // 1234 hello5678 5678
        
        // MARK: - 字符串的插入、删除 和 替换
        // 插入字符
        //str.insert(<#T##newElement: Character##Character#>, at: <#T##String.Index#>)
        // str.insert(contentsOf: <#T##Collection#>, at: <#T##String.Index#>)
        // str.insert(<#T##newElement: Character##Character#>, at: <#T##String.Index#>)
        // 删除字符
        //str.remove(at: <#T##String.Index#>)
        // 替换字符
        //str.replaceSubrange(<#T##bounds: Range<String.Index>##Range<String.Index>#>, with: <#T##Collection#>)
   
        var str2 = "Objecte-C and Swift"
        print("原始字符串 : \(str2)")
        
        // 插入字符
        str2.insert(".", at: str2.endIndex)
        print("插入,字符后 : \(str2)")
        
        str2.insert(contentsOf: "666", at: str2.index(after: str2.startIndex))
        print("插入,字符后 : \(str2)")
        
        str2.insert(contentsOf: "hello", at: str2.index(str2.startIndex, offsetBy: 4))
         print("插入,字符后 : \(str2)")
        
        // 删除字符
        str2.remove(at: str2.index(before: str2.endIndex))
        print("删除之后 : \(str2)")
        
        var removeRange = str.index(str2.endIndex, offsetBy: -4)..<str.index(before: str2.endIndex)
        str2.removeSubrange(removeRange)
        print("删除之后 : \(str2)")
        
//        str2.removeAll()
        
        // 替换字符
        // ... 闭区间  ..< 半开区间
        var startIndex = str2.startIndex
        var endIndex = str2.index(startIndex, offsetBy: 9)
        var range = startIndex...endIndex
        
        // 删除范围
        str2.removeSubrange(range)
        print("删除范围后：\(str2)")
        
        startIndex = str2.startIndex
        endIndex = str2.index(startIndex, offsetBy: 0)
        range = startIndex...endIndex
    
        //替换范围
        str2.replaceSubrange(range, with: "C++")
        print("替换范围后 : \(str2)")
        
        // MARK: - 字符串比较
       
        // 大小 比较
        let 小熊 = "🐻"
        let 小猫 = "🐱"
        
        if 小熊 > 小猫 {
            print("🐻大于🐱")
        }else {
            print("🐻小于🐱")
        }
        
        //相等比较
        //Character 和 String 都是结构体类型 只能使用 == 或者 != 比较是否相等
        // Foundation 中的 NSString 字符串比较是否相等需要使用 === 和 !== 运算符
        
        // MARK: - 前缀 和 后缀 比较
//        str2.hasPrefix(<#T##prefix: String##String#>)  // 比较前缀
//        str2.hasSuffix(<#T##suffix: String##String#>)  // 比较后缀
        
        let docFolder = [
        "java.docx",
        "javascript.docx",
        "Objective-C.xlsx",
        "swift.docx"
        ]
        
        var wordDocument = 0
        for doc in docFolder {
            if doc.hasSuffix(".docx") {
                wordDocument += 1
            }
        }
        print("文件中word 文档的个数为 : \(wordDocument)")
        
        var javaDocument = 0;
        for doc in docFolder  {
            let lowercaseDoc = doc.lowercased()
            if lowercaseDoc.hasPrefix("java") {
                javaDocument += 1
            }
        }
        print("文件中与 java 相关的文档有 : \(javaDocument)个")
     
        
        //MARK: 带间隔的区间值
        let hours = 11
        let hourInterval = 2
        // 从4 开始，间隔为 2 不超过 11
        for tickMark in stride(from: 4, through: hours, by: hourInterval) {
            print(tickMark)  // 4 6 8 10
        }
        
        //MARK: String 相关的协议
        /*
         BidirectionalCollection 协议包含的部分内容
            startIndex 、 endIndex 属性、index 方法
            String、Array 都遵守了这个协议
         RangeReplaceableCollection 协议包含的部分内容
            append、insert、remove 方法
            String、Array 都遵守了这个协议
         Dictionary、Set 也有实现上述协议中声明的一些方法，只是并没有遵守上述协议
         */
      
        
        
    }

}

