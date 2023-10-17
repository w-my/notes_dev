//
//  main.m
//  Clang学习
//
//  Created by WTW on 2022/3/9.
//  Copyright © 2022 wtw. All rights reserved.
//

/*
 什么是LLVM?
    LLVM 项目是 模块化、可重用 的编译器以及工具链技术的集合
 
    传统的编译器架构：
        Source Code -> Front end -> Optimizer -> Back end -> Machine Code
     
        Frontend 前端：词法分析 、语法分析、语义分析、生成中间代码
        Optimizer 优化器： 中间代码优化
        Backend 后端：生成机器码
 
    LLVM 架构：
      C->  Clang C/C++/Objc Frontend ------                           ------- LLVM X86 Backend  --> X86
                                          |                         |
      Fortran ->  llvm-gcc Frontend  ------ ----> LLVM Optimizer ------------ LLVM PowerPC Backend  --> PowerPC
                                          |                         |
      Haskell ->  GHC Frontend       ------  LLVM IR         LLVM IR  ------- LLVM ARM Backend  -->ARM
 
    不同的前端后端使用统一的中间代码 (LLVM IR)
    如果需要支持一种新的编程语言，那么只需要实现一个新的前端
    如果需要支持一种新的硬件设备，那么只需要实现一个新的后端
    优化阶段是一个通用阶段，针对的是统一的LLVM IR，不管是支持新的编程语言还是支持新的硬件设备，都不需要对优化阶段做修改
    相比之下，GCC 的前端和后端分的太开，前端和后端耦合在一起了，所以GCC 为了支持一种新的语言，就会变得比较困难
    LLVM 现在被作为各种静态和运行时编译语言的通用基础架构（GCC 家族，Java、.NET 、Python 、Ruby、Haskell 、D 等）
 
 什么是Clang?
    Clang 是 LLVM 项目的一个子项目，C++ 编写，基于 LLVM 的C/C++/Objc 编译器前端，目标之一就是超过 GCC；
                                      
    C/C++/Objc --->Front end ---IR---> Pass ---IR---> Pass --IR-->Pass --IR---> Back end ---> Machine Code
                      Clang
 
    相比于 GCC，Clang 优点：
    编译速度快：在某些平台上，Clang 编译速度显著快过GCC(DEBUG 模式下编译OC的速度比GCC 快三倍)
    占用内存小：Clang 生成的AST 所占用的内存是 GCC 的五分之一左右
    模块化设计：Clang 是采用基于库的模块化设计，便于IDE 集成及其他用途的重用；
    诊断信息可读性强：在编译过程中，Clang 保存了大量的详细的元数据，有利于调试和错误报告；
    设计清晰简单，容易理解、易于扩展增强；
 */


#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
