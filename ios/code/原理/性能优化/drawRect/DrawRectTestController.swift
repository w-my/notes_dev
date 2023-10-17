//
//  DrawRectTestController.swift
//  性能优化
//
//  Created by WTW on 2022/5/5.
//  Copyright © 2022 wtw. All rights reserved.
//
//  参考文章：https://www.jianshu.com/p/17eb5e095dd7

/***
 * 视图重绘机制
 *
 * 视图绘制相关方法：
 *
 *  /// 重写此方法，执行重绘任务
 *  func draw(_ rect: CGRect) { }
 *
 *  /// 将视图标记为需要重绘，异步调用drawRect
 *  func setNeedsDisplay() { }

 *  /// 将视图标记为需要局部重绘
 *  func setNeedsDisplay(_ rect: CGRect) { }
 *
 *
 *  drawRect 调用机制：
 *
 *  /// 调用时机
 *  1、如果初始化没有设置 rect，则 draw 方法不被自动调用
 *  2、设置contentMode为 redraw，那么每次设置和改变 frame 的时候自动调用 draw 方法
 *  3、直接调用 setNeedsDisplay() 或 setNeedsDisplay(<#T##rect: CGRect##CGRect#>)，且rect 不为 nil  会自动调用 draw 方法
 *  4、调用sizeThatFits后被调用，所以可以先调用sizeToFit计算出size,  会自动调用 draw 方法      ?? 待验证
 *
 *
 *  layoutSubviews 的作用：重新布局子控件
 *  默认不做任何事情，需要子类重写，在某个类的内部调整子视图的位置时，需要调用（外部设置 subviews的布局，不需要重写此方法）
 *
 *
 *  视图布局相关方法：
 *
 *  ///  对subview重新布局
 *  func layoutSubviews() { };
 *
 *  /// 将视图标记为需要重新布局
 *  /// 在系统runloop的下一个周期自动调用layoutSubviews
 *  func setNeedsDisplay() { }
 *
 *  /// 如果有需要刷新的标记，立即调用layoutSubviews进行布局（如果没有标记，不会调用layoutSubviews）
 *  /// 如果要立即刷新，要先调用[view setNeedsLayout]，把标记设为需要布局，然后马上调用[view layoutIfNeeded]，实现布局
 *  /// 在视图第一次显示之前，标记总是“需要刷新”的，可以直接调用[view layoutIfNeeded]
 *  func layoutIfNeeded() { }
 *
 *
 * layoutSubviews 调用时机：
 * 1、init 初始化不会触发
 * 2、addSubview 会触发 (连续添加多个只会执行一次，因为一次runloop结束后，如果有刷新，执行一次即可)
 * 3、修改 frame 会触发 （frame 发生变化）
 * 4、滚动一个UIScrollView引发UIView的重新布局会触发layoutSubviews。
 * 5、旋转屏幕会触发父view 上的layoutSubviews事件
 * 6、改变一个view 大小的时候也会触发父view 上的 layoutSubviews 事件
 * 7、直接调用 setLayoutSubviews （官方不建议这样调用）
 *
 *  layoutSubview是布局相关，而drawRect则是负责绘制，时序上来讲，layoutSubviews要早于drawRect；
 *
 *
 * iOS 显示系统：
 *  1、如何让App渲染的代码定时执行（例如：每秒执行60次）？
 *  iOS 的显示系统是由 VSync 信号驱动的，VSync 信号由硬件时钟生成，每秒钟发出 60 次（这个值取决设备硬件，比如 iPhone 真机上通常是 59.97）。
 *  iOS 图形服务接收到 VSync 信号后，会通过 IPC 通知到 App 内。
 *  App 的 Runloop 在启动后会注册基于端口的源也就是source1，Vsync信号则通过 mach_port 端口传递过来，同时唤醒runloop，随后 Source1 的回调会驱动整个 App 的动画与显示
 *
 *  2、通过mach_port端口发送消息，唤醒Runloop后，做了一些修改view和layer的工作，并提交到全局容器，等待渲染时机到来：
 *  Core Animation 在 RunLoop 中注册了一个 Observer，监听了 BeforeWaiting 和 Exit 事件。
 *  当一个触摸事件到来时（也可以理解成Vsync信号唤起），RunLoop 被唤醒，App 中的代码会执行一些操作，比如创建和调整视图层级、设置 UIView 的 frame、修改 CALayer 的透明度、为视图添加一个动画等；
 *  这些操作最终都会被 CALayer 标记，并通过 CATransaction 提交到一个中间状态去。
 *  当上面所有操作结束后，RunLoop 即将进入休眠（或者退出）时，关注该事件的 Observer 都会得到通知。
 *  这时 Core Animation 注册的那个 Observer 就会在回调中，把所有的中间状态合并提交到 GPU 去显示；
 *  如果此处有动画，通过 DisplayLink 稳定的刷新机制会不断的唤醒runloop，使得不断的有机会触发observer回调，从而根据时间来不断更新这个动画的属性值并 绘制出来；
 *
 *  回调函数内部调用栈大致如下：
    _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv()
     QuartzCore:CA::Transaction::observer_callback:
         CA::Transaction::commit();
             CA::Context::commit_transaction();
                 CA::Layer::layout_and_display_if_needed();
                     CA::Layer::layout_if_needed();
                           [CALayer layoutSublayers];
                           [UIView layoutSubviews];
                     CA::Layer::display_if_needed();
                           [CALayer display];
                           [UIView drawRect];
 *
 *
 */


import UIKit

@objcMembers
class DrawRectTestController: UIViewController {

    fileprivate lazy var redView: RedView = {
        let redView = RedView()
        redView.backgroundColor = .red
        return redView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        view.backgroundColor = .white
        
        redView.frame = CGRect(x: 100, y: 100, width: 100, height: 100)
                
        self.view.addSubview(redView)
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        
        /// 设置contentMode为 redraw，那么每次设置和改变 frame 的时候自动调用 draw 方法
//        redView.contentMode = .redraw
//        /// 再次修改frame
//        redView.frame = CGRect(x: 100, y: 100, width: 200, height: 200)
            
        
        /// 直接调用 setNeedsDisplay() 或 setNeedsDisplay(<#T##rect: CGRect##CGRect#>)，且rect 不为 nil  会自动调用 draw 方法
//        redView.setNeedsDisplay()
//        redView.setNeedsDisplay(<#T##rect: CGRect##CGRect#>)
                
        
        /// 调用sizeThatFits后被调用，所以可以先调用sizeToFit计算出size,  会自动调用 draw 方法
        /// sizeToFit: 会计算出最优的 size 而且会改变自己的size
        /// sizeThatFits:  会计算出最优的 size 但是不会改变 自己的 size
//        redView.sizeToFit()
//        redView.sizeThatFits(CGSize(width: 100, height: 100))
        
        
        /// addSubview会触发layoutSubviews
//        let v = UIView()
//        v.frame = CGRect(x: 0, y: 0, width: 20, height: 20)
//        v.backgroundColor = .yellow
//        redView.addSubview(v)
//
//        let b = UIView()
//        b.frame = CGRect(x: 30, y: 30, width: 20, height: 20)
//        b.backgroundColor = .blue
//        redView.addSubview(b)

    }

}
