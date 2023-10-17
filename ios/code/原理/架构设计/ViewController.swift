//
//  ViewController.swift
//  架构设计
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        
        // 苹果版本的 MVC
        /*
        mode        Controller     View
        M   <-----    C   ----->    V
            ------>       <------
            
        M 和 V 是解耦合的(View 和 Model 也是可以复用的)，都是可独立使用的，是通过 C 来进行通信的 (C 创建View 创建 model 然后根据model 给view 赋值)
        缺点是：所有的逻辑代码都是在 C 中，导致 C 中的代码比较臃肿
         
         
         
         // 苹果版本的 MVC 的变种
         // 让 View 拥有 model，view 子控件的赋值都在 view 内部实现 (View 对外是封装的)
         // 这样可以让 Controller 进行瘦身,将View 内部的细节封装起来，外界不知道View 内部的具体实现
         // 缺点： View 依赖 Model
         
         C       ------->      V
                <-------
           \                  /
            \                /
             \              /
              \/          \/
                    M
        */
        
        /*
         MVP  Mode View Presenter
        
         mode        Presenter     View
         M   <-----    P   ----->    V
             ------>       <------
         
         相当于 Presenter 把 Controller 做的事情都拿走了，一个View 对应一个 Presenter
         这样 Controller 会拥有好几个 Presenter
         View 和  Model 的交互都是和基于 Presenter  进行交互
         */
        
        
        /*
         MVVM
         
         mode          ViewModel     View
         M   <-----    ViewModel   ----->    V
             ------>              <------
         
         */
        
        
        /*
         分层架构
         数据层
         业务层
         View层
        */
        
        
        // 设计模式
        /*
         创建型模式：对象实例化的模式，用于解耦对象的实例化过程
            单例模式、工厂模式等
         结构型模式：把类或对象结合在一起形成一个更大的结构
            代理模式、适配器模式、组合模式、修饰模式等
         行为型模式：类或对象之间如何交互，及划分责任和算法
            观察者模式，命令模式，责任链模式等等
         
         */
        
    }


}

