//
//  ViewController.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

// 参考文章：https://www.jianshu.com/p/2f664e71c527

/*
 iOS 中的事件主要分为：触摸事件、加速计事件(例如摇一摇)、远程控制事件(例如耳机线控） 三类
 
 响应者对象：
    只有继承了 UIResponder 的对象才能接收并处理事件，称之为响应者对象(都能接收并处理事件)
    UIApplication/UIView/UIViewController都继承自UIResponder
 
    UIResponder 提供了四个方法来处理触摸事件:
    // 触摸结束前，某个系统事件(例如电话)会打断触摸过程，系统会自动调用如下方法
    -(void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
    // 一根或多跟手指在View 上一移动(随着手指的移动，会持续调用该方法)
    -(void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
    // 一根或多根手指离开View
    - (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
    // 一根或者多根手指开始触摸 View
    - (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
 
    /// 加速计事件
     - (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event
     - (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event
     - (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event
 
    /// 远程控制事件
    - (void)remoteControlReceivedWithEvent:(UIEvent *)event
 
 UITouch
    手指触摸屏幕时，会创建一个与手指相关联的 UITouch 对象，一根手指对应一个UITouch 对象
    作用：
        保存和手指相关的信息，比如触摸的位置、时间、阶段等
    对应方法：
        locationInView:
        previousLocationInView
 */

/**
 * UIEvent :
 *      每产生一个事件，就会产生一个 UIEvent 对象，UIEvent  也称事件对象，记录事件产生的时刻和类型
 *
 * 事件的产生和传递：
 *      发生触摸事件后，系统会将该事件加入到一个由 UIApplication 管理的事件队列中
 *      UIApplication 会从事件队列中取出最前面的事件，将事件分发下去，通常先发送事件给应用程序的主窗口(keyWindow)
 *      主窗口会在视图层次结构中找到一个最合适的视图来处理触摸事件，这也是整个事件处理的第一步
 *      找到合适的视图控件后，就会调用视图空间的touchs 方法来处理具体的事件
 *
 * 触摸事件的传递：
 *      从父控件传递到子控件 (如果父控件不能接收触摸事件，那么子控件也不可能接收到触摸事件)
 *      （比如demo 点击黄色：UIApplication -> Window -> 白色 -> 棕色 -> 蓝色 -> 黄色）
 *
 * 不能接收事件的三种情况：
 *      1、不能与用户进行交互 userInteractionEnabled = NO (UIImageView 的userInteractionEnabled 默认就是NO,因此子控件不能接收触摸事件)
 *      2、隐藏 hidden = YES
 *      3、透明 alpha = 0.0 ~ 0.01
 *
 * 如何寻找最适合的控件来处理事件？
 *      1、自己能否接收触摸事件？ (hitTest:withEvent: )
 *      2、触摸点是否在自己身上？ (pointInside:withEvent:)
 *      3、从后往前遍历子控件，重复前面的两个步骤
 *      4、如果没有符合条件的子控件，那么就自己最适合处理
 *
 * 事件传递的详细过程：
 *      keyWindow会在它的内容视图上调用hitTest:withEvent:（该方法返回的就是处理此触摸事件的最合适view）来完成这个找寻过程。
 *      hitTest:withEvent:在内部首先会判断该视图是否能响应触摸事件，如果不能响应，返回nil，表示该视图不响应此触摸事件。
 *      然后再调用pointInside:withEvent:（该方法用来判断点击事件发生的位置是否处于当前视图范围内）。
 *      如果pointInside:withEvent:返回NO，那么hiteTest:withEvent:也直接返回nil。
 *      如果pointInside:withEvent:返回YES，则向当前视图的所有子视图发送hitTest:withEvent:消息，
 *      所有子视图的遍历顺序是从最顶层视图一直到到最底层视图，即从subviews数组的末尾向前遍历。
 *      直到有子视图返回非空对象或者全部子视图遍历完毕；
 *      若第一次有子视图返回非空对象，则hitTest:withEvent:方法返回此对象，处理结束；
 *      如所有子视图都返回非，则hitTest:withEvent:方法返回该视图自身
 */

/**
 *  触摸事件处理的详细过程(事件传递的完整过程)：(1、事件传递 （父控件找子控件）2、响应者传递（子控件往父控件传递）)
 *  1、先将事件对象由上往下传递(由父控件传递给子控件)，会找到最合适的视图控件来处理这个事件
 *  2、找到最合适的视图控件后，就会调用控件的 touchs... 方法来作具体的事件处理
 *  3、如果调用了 [super touchs...] 方法，就会将事件顺着响应者链条往上传递，传递给上一个响应者(touchs 方法的默认做法是将事件顺着响应者链条向上传递，将事件交给上一个响应者进行处理)
 *  4、接着会调用 上一个响应者的touchs... 方法
 *
 *  如何判断上一个响应者：
 *  1、如果当前的View 是控制器的View，那么控制器就是上一个响应者
 *  2、如果当前这个View不是控制器的View，那么父控件就是上一个响应者
 */

/**
 * 响应者链条:
 *      由多个响应者对象连接起来的链条
 * 作用：
 *      能够清楚的看见每个响应者之间的联系，并且可以让一个事件多个对象处理
 * 响应者对象：
 *      能够处理事件的对象
 *
 * 每个能执行hitTest:方法的view都属于事件传递的一部分，但是，只有pointInside返回YES的view才属于响应者链条
 */


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"LaunchStartTime: %f %s", CACurrentMediaTime(),__func__);
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    NSLog(@"LaunchStartTime: %f %s", CACurrentMediaTime(),__func__);
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    NSLog(@"LaunchStartTime: %f %s", CACurrentMediaTime(),__func__);
}

@end
