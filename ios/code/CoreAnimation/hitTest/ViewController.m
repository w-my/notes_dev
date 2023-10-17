//
//  ViewController.m
//  hitTest
//
//  Created by wtw on 2019/3/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "hitTestView.h"
#import "CustomButton.h"


@interface ViewController (){
    CustomButton *customBtn;
}

@end

@implementation ViewController

/*
 (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event
 point : 在接收器的局部坐标系(界)中指定的点。
 event : 系统保证调用此方法的事件。如果从事件处理代码外部调用此方法，则可以指定nil。
 returnValue : 视图对象是当前视图或包含点的最远的后代。如果点完全位于接收方的视图层次结构之外，则返回nil。
 
 递归调用 -pointInside:withEvent: 在视图的层次结构中寻找一个最适合的 view 来响应触摸事件
 
 触摸事件的传递顺序：
 1、当用户点击屏幕，会产生一个触摸事件，系统会将该事件加入到UIApplication管理的队列中
 2、UIApplication 会从事件队列中取出最早的事件进行分发处理，先发送事件给应用程序的主窗口UIWindow
 3、主窗口会调用hitTest:withEvent: 方法在视图层次结构中找到一个合适的View来处理触摸事件
 touch -> UIApplication -> UIWindow -> UIViewController.view -> subViews -> ....-> 合适的view ->touchs方法处理事件
 
 事件传递顺序：
 view -> superView ...- > UIViewController.view -> UIViewController -> UIWindow -> UIApplication -> 事件丢弃
 
 
 hitTest 底层实现：
 当控件接收到触摸事件的时候，不管能不能处理事件，都会先调用hitTest 方法。此方法的底层实现是：
 1、先看自己能否能接受触摸事件 （self.userInteractionEnabled == NO || self.alpha <=0.01 || self.hidden == YES）
 2、在看触摸点是否在自己身上  [self pointInside:point withEvent:event]
 3、从后往前遍历子控件，拿到子控件后，再次重复 1，2 步骤，要把父控件的坐标点转换位子控件坐标系下的点，再次执行hittest 方法
 4、钥匙没有找到合适的view 就返回self ，自己就是合适的view。
 */
//    [self.view hitTest:<#(CGPoint)#> withEvent:<#(nullable UIEvent *)#>]
//    [self.view.layer hitTest:<#(CGPoint)#>]

- (void)viewDidLoad {
    [super viewDidLoad];

    
    //圆外的区域不能交互
    customBtn = [[CustomButton alloc] initWithFrame:CGRectMake(100, 100, 120, 120)];
    customBtn.backgroundColor = [UIColor blueColor];
    [customBtn addTarget:self action:@selector(click) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:customBtn];
    
    
    
    
    
//    hitTestView *hitestView = [[hitTestView alloc] initWithFrame:CGRectMake(0, 50, [UIScreen mainScreen].bounds.size.width, 600)];
//    hitestView.backgroundColor = [UIColor lightGrayColor];
//    [self.view addSubview:hitestView];
    
}

- (void)click {
    NSLog(@"click");
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
//    CGPoint point = [[touches anyObject] locationInView:self.view];
//    UIView *view =  [self.view hitTest:point withEvent:event];
//    NSLog(@"%@",view);
}

@end
