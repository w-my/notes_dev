//
//  ViewController.m
//  layout机制
//
//  Created by WTW on 2020/10/24.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "TestLayoutView.h"

/**
 * https://blog.csdn.net/wanghongios/article/details/39965651
 * https://blog.csdn.net/qq_36557133/article/details/98411856?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param
 *
 * layout 机制相关的几个方法：
 *
 * - (CGSize)sizeThatFits:(CGSize)size
 * - (void)sizeToFit
 *
 * - (void)layoutIfNeeded
 * - (void)setNeedsLayout
 *
 * - (void)layoutSubviews
 *
 * - (void)setNeedsDisplay
 * - (void)setNeedsDisplayInRect:(CGRect)rect;
 *
 * - (void)drawRect
 *
 * 修改 uiview 的frame bounds 等属性后并不是马上就重新绘制，而是用runloop 把多次绘制聚集在一个 cycle 里一起绘制，这样更加高效
 *
 *  刷新子控件布局：
 *
 * -layoutSubviews方法：
 *      这个方法是对子控件进行重新布局，默认没有做任何事情，需要子类进行重写，不会直接调用。
 *      如果想要强制更新布局，应在下次runloop 来之前调用 setNeedsLayout
 *      如果不想等待下一次runloop，要立即更新视图的布局，调用 layoutIfNeeded
 *
 * -setNeedsLayout方法：
 *      标记为需要重新布局，异步调用layoutIfNeeded刷新布局，不立即刷新，但layoutSubviews一定会被调用
 *
 * -layoutIfNeeded方法：  （如果布局更新处于待处理状态，则立即布置子视图，一般需要立即更新约束来显示过渡动画的效果的时候才会使用这个方法）
 *      如果，有需要刷新的标记，立即调用layoutSubviews进行布局（如果没有标记，不会调用layoutSubviews）
 *      self.margin.constant = 100;
 *      [UIView animateWithDuration:0.25 animations:^{
 *         [self.view layoutIfNeeded];
 *      }];
 *
 * 如果要立即刷新，要先调用[view setNeedsLayout]，把标记设为需要布局，然后马上调用[view layoutIfNeeded]，实现布局
 * 在视图第一次显示之前，标记总是“需要刷新”的，可以直接调用[view layoutIfNeeded]
 *
 * setNeedsLayout( 用于数据计算布局子控件) 和 setNeedsDisplay (用于视图绘制)   两个方法都是异步执行的
 * setNeedsDisplay 会自动调用 drawRect 方法，这样就可以拿到 UIGraphicsGetCurrentContext 就可以开始自定义绘制了
 * setNeedsLayout 会默认调用 layoutSubviews 可以用来处理一些子视图的数据
 *
 *
 * layoutSubviews 什么情况下会被调用
 * 1、init 初始化不会触发 layoutSubviews
 * 2、addSubview 会触发layoutSubviews
 * 3、设置 view 的 Frame 会触发layoutSubviews，当然前提是frame的值设置前后发生了变化
 * 4、滚动一个 UIScrollView 会触发 layoutSubviews
 * 5、旋转Screen会触发父UIView上的layoutSubviews事件
 * 6、改变一个子view大小的时候也会触发父UIView上的layoutSubviews事件
 * 7、直接调用setLayoutSubviews 的时候
 * 8、直接调用setNeedsLayout 的时候
 *
 */

@interface ViewController ()

@property (nonatomic,strong) TestLayoutView *testView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.testView = [[TestLayoutView alloc] init];
    self.testView.backgroundColor = [UIColor redColor];
    self.testView.frame = CGRectMake(0, 0, 200, 200);
    [self.view addSubview:self.testView];
    
//    [self.testView layoutIfNeeded];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    // 设置和修改frame 会触发 layoutSubviews
//    self.testView.frame = CGRectMake(0, 0, 200, 100);
        
//    [self.testView layoutIfNeeded];
//
//    [self.testView setNeedsLayout];  // 不会调用 drawRect 方法，会调用  layoutSubviews
    
//    [self.testView setNeedsDisplay];  // 会调用 drawRect 方法        
}


@end
