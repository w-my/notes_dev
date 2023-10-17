//
//  ViewController.swift
//  CustomDrawing
//
//  Created by WTW on 2021/1/26.
//  Copyright © 2021 wtw. All rights reserved.
//

/**
 Custom Drawing
 
    给 contents 赋 CGImage 的值不是唯一的设置寄宿图的方法，还可以通过 Core Graphics 直接绘制寄宿图。通过继承UIView  实现 drawRect: 方法来自定义绘制
 
    drawRect 方法没有默认实现，对于 UIView 来说寄宿图不是必须的，如果UIView 检测到 drawRect 方法被调用了，他就会为视图分配一个寄宿图，这个寄宿图的像素尺寸等于视图大小乘以 contentScale 的值。（故如果不需要寄宿图就不要在子类中写一个空的 drawRect 方法，这样会照成 CPU 资源和内存的浪费）
        
    当视图在屏幕上出现的时候， drawRect 方法就会被自动调用，drawRect 方法里面的代码利用 Core Graphics 去绘制一个寄宿图，然后内容就会被缓存起来直到它需要被更新(通常是开发者调用了 - setNeedDisplay 方法) ，尽管影响到表现效果的属性值被更改时，一些视图类型会被自动重绘，比如 bounds属性。
 
    虽然 drawRect 是UIView 的方法，事实上都是底层的 CALayer 安排了重绘工作和保存了因此产生的图片
 
    CALayer 有一个可选的 delegate 属性，实现了 CALayerDelegate 协议，当 CALayer 需要一个内容特定的信息时，就会从协议中请求。 (CALayerDelegate 是一个非正式的协议，就是说没有CALayerDelegate @protocol可以让你在类里面引用啦。你只需要调用你想调用的方法，CALayer会帮你做剩下的)
 
    当需要被重绘时，CALayer 会请求它的代理给他一个寄宿图来显示。  -(void)displayLayer:(CALayerCALayer *)layer;
    
    如果代理想直接设置 contents 属性的话就可以这么做，不然没有别的办法，如果代理不实现 displayLayer 方法，CALayer 就会尝试调用
    - (void)drawLayer:(CALayer *)layer inContext:(CGContextRef)ctx;
    在调用这个方法之前，CALayer创建了一个合适尺寸的空寄宿图（尺寸由bounds和contentsScale决定）和一个Core Graphics的绘制上下文环境，为绘制寄宿图做准备，他作为ctx参数传入

 
    当使用寄宿了视图的图层的时候，你也不必实现-displayLayer:和-drawLayer:inContext:方法来绘制你的寄宿图。
    通常做法是实现UIView的-drawRect:方法，UIView就会帮你做完剩下的工作，包括在需要重绘的时候调用-display方法。
 */


import UIKit

class ViewController: UIViewController, CALayerDelegate {

    lazy var layerView: UIView = {
        
        let layerView = UIView()
        layerView.backgroundColor = .green
        layerView.frame = CGRect(x: 0, y: 100, width: UIScreen.main.bounds.size.width, height: 400)
        return layerView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        view.addSubview(layerView)
        
        let blueLayer = CALayer()
        blueLayer.frame = CGRect(x: 50, y: 50, width: 100, height: 100)
        blueLayer.backgroundColor = UIColor.blue.cgColor
        
        blueLayer.delegate = self
        
        // ensure that layer backing image uses correct scale
        blueLayer.contentsScale = UIScreen.main.scale
        
        layerView.layer.addSublayer(blueLayer)
        
        // force layer to redraw
        blueLayer.display()
    }

    func draw(_ layer: CALayer, in ctx: CGContext) {
        
        ctx.setLineWidth(10.0);
        ctx.setStrokeColor(UIColor.red.cgColor);
        ctx.strokeEllipse(in: layer.bounds);
    }

}

