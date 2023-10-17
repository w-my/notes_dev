//
//  ViewController.swift
//  UIView 的异步绘制
//
//  Created by WTW on 2020/3/25.
//  Copyright © 2020 wtw. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    
        /*
         UIView 的绘制流程：
             1、当UIView调用setNeedDisplay之后,系统会调用view对应layer的 setNeedsDisplay（实际上在显式调用了drawRect 方法之后才会走）
             2、在当前runloop即将结束或者休眠的时候调用CALayer的display方法.
             3、CALayer的display方法的内部实现
                首先会判断layer的delegete是否响应display方法,如果代理不响应就会进入到系统的绘制流程当中,
                如果响应,实际上就为我们提供了异步绘制的接口,这样就构成了UIView的绘制原理
         系统绘制流程：
             CALayer会在内部创建一个backing store(CGContextRef),一般在drawRect中可以通过上下文堆栈当中拿到当前栈顶的context
             然后layer判断是否有代理,如果没有代理会调用layer的drawInContext方法
             如果实现了代理就会调用delegete的drawLayer:inContext方法
             这是在发生在系统内部当中的,然后在合适的时机给予回调方法,也就是View的drawRect方法.
             可以通过drawRect方法做一些其他的绘制工作.然后无论哪两个分支,都有calayer上传backing store(最终的位图)到CPU.然后结束系统的绘制流程.
         异步绘制流程：
            借用系统给开的这个口子，即[layer.delegate displayLayer:]
            在这个异步绘制过程中就需要代理商负责生成对应的bitmap(位图)
            同时设置bitmap作为layer.contents属性的值
         */
        
        let label = AsyncLabel(frame: CGRect(x: 100, y: 100, width: 100, height: 100))
        label.backgroundColor = UIColor.green
        label.asyncBGColor = UIColor.yellow
        label.asyncText = "学习异步绘制相关知识点, 学习异步绘制相关知识点"
        label.asyncFont = UIFont.systemFont(ofSize: 16, weight: UIFont.Weight.black)
        view.addSubview(label)
        
        // 不调用的话不会触发 displayLayer方法
        label.layer.setNeedsDisplay()
    
    }


}

