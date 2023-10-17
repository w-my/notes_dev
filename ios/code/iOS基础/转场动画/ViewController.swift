//
//  ViewController.swift
//  转场动画
//
//  Created by WTW on 2021/11/12.
//  Copyright © 2021 WTW. All rights reserved.
//

// https://blog.devtang.com/2016/03/13/iOS-transition-guide/
// https://github.com/seedante/iOS-ViewController-Transition-Demo

/**
 *  作为容器的父VC 维护着多个子VC, 但在视图结构上，只保留一个子VC的视图
 *  转场的本质是下一个子VC的视图替换当前子VC的视图以及相应的控制器子VC的替换，表现为当前视图消失下一视图出现，基于此进行动画，动画的方式非常多
 *  目前官方支持几种方式的自定义转场：
 *  1、在UINavigationController 中 push 和 pop
 *  2、在 UITabBarComtroller 中切换 Tab
 *  3、Modal 转场：presentation 和 dismissal （模态显示和消失）
 *  4、UICollectionViewController 的布局转场：UICollectionViewController 与 UINavigationController 结合的转场方式，实现很简单。
 *  5、iOS7 以协议的方式开放了自定义转场的API，只要准守该协议的对象都能参与转场，转场协议由5种协议组成，实际中只需要提供其中的两个或者三个便能实现绝大部分的转场动画
 *      1、转场代理
 *          自定义转场的第一步是提供转场代理，告诉系统使用我们提供的代理而不是系统的默认代理来实现来执行转场，有如下三种转场代理，对应上面三种类型的转场：
 *              <UINavigationControllerDelegate> //UINavigationController 的 delegate 属性遵守该协议。
 *              <UITabBarControllerDelegate> //UITabBarController 的 delegate 属性遵守该协议。
 *              <UIViewControllerTransitioningDelegate> //UIViewController 的 transitioningDelegate 属性遵守该协议
 *          转场发生时，需要转场代理提供转场动画的核心构件：动画控制器和交互控制器(可选)；由我们实现
 *      2、动画控制器
 *          最重要的部分，负责添加视图以及执行动画；遵守 UIViewControllerAnimatedTransitioning 协议，由我们实现
 *      3、交互控制器
 *          通过交互手段，通常是手势来驱动动画控制器实现的动画，使得用户能够控制整个过程；遵守 UIViewControllerInteractiveTransitioning 协议,系统已经打包好现成的类供我们使用。
 *      4、转场环境
 *          提供转场中需要的数据，遵守 UIViewControllerContextTransitioning 协议，由UIKit 在转场开始前生成并提供给我们提交的动画控制器和交互控制器使用。
 *      5、 转场协调器
 *          可在转场动画发生时并执行其他的动画，与其说协调不如说辅助，主要在Modal 转场和交互转场取消时使用，其他时间很少用到。遵守 UIViewControllerTranstionCoordinator 协议，由UIKit 在转场时生成，
 *          UIViewController 在iOS 7 新增的方法 transitionCoordinor() 返回一个准守协议的对象，且该方法只在该控制器处于转场过程中才返回一个此类对象，不参与转场时返回nil；
 *   5个协议只需要操心3个，只需要提供转场代理和动画控制器即可实现最低限度的转场动画，还有一个转场环境是必须的，不过这由系统提供；当进一步实现交互转场时，还需要提供交互控制器，也有现成的类供使用；
 */

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
    
    }


}

