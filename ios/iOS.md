## UI 视图

#### 事件传递机制

当我们触摸屏幕的时候,系统会生成一个Event和point信息传递给当前的应用, 并通过以下两个方法传递并找到合适的响应者

```objc
// 返回接收响应事件的视图
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event
// 判断触摸点是否在视图内
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event;
```

点击屏幕，系统传给当前应用 application 的 window 对象。window 递归+倒序 遍历子视图，通过 hitTest 和 pointInside 方法判断是否符合条件，如果找到就返回对应的视图去处理触摸事件，找不到就忽略。

#### UI 绘制原理

##### UIView 绘制流程

- 当我们调用[UIView setNeedsDisplay]方法时，并没有执行立即执行绘制工作。
- 调用`setNeedDisplay`之后,系统会调用`view`对应`layer`的 `setNeedsDisplay`
- 在当前RunLoop快要结束的时候调用layer 的display方法，来进入到当前视图的真正绘制当中。
- 在layer的display方法内部，系统会判断layer的layer.delegate是否实现了displayLayer:方法，a.如果没有实现，则执行**系统的绘制流程**;b.如果实现了则会进入**异步绘制的入口**。
- 最后把绘制完的backing store（可以理解为位图）提交给GPU。

##### 系统绘制流程

- 在layer内部会创建一个backing store，我们可以理解为CGContextRef上下文。

- 判断layer是否有delegate:
  - 如果有delegate，则会执行[layer.delegate drawLayer:inContext]（这个方法的执行是在系统内部执行的），然后在这个方法中会调用view的drawRect:方法，也就是我们重写view的drawRect:方法才会被调用到。
  - 如果没有delegate，会调用layer的drawInContext方法，也就是我们可以重写的layer的该方法，此刻会被调用到。

- 最后把绘制完的backing store（可以理解为位图）提交给GPU。

#### 异步绘制原理

#### 流式页面的性能优化

#### 离屏渲染

On-Screen Rendering:当前屏幕渲染，指的是 GPU 的渲染操作是在当前用于显示的屏幕缓冲区中进行
Off-Screen Rendering:离屏渲染，分为 CPU 离屏渲染和 GPU 离屏渲染两种形式。GPU 离屏渲染指的是 GPU 在当前屏幕缓冲区外新开辟一个缓冲区进行渲染操作

##### 触发离屏渲染

当使用圆角，阴影，遮罩的时候，图层属性的混合体被指定为在未预合成之前不能直接在屏幕中绘制，所以就需要屏幕外渲染被唤起。

离屏渲染之所以会特别消耗性能，是因为要创建一个屏幕外的缓冲区，然后从当屏缓冲区切换到屏幕外的缓冲区，然后再完成渲染；其中，创建缓冲区和切换上下文最消耗性能，而绘制其实不是性能损耗的主要原因。

上下文之间的切换这个过程的消耗会比较昂贵，涉及到 OpenGL的 pipeline 跟 barrier，而且 offscreen-render 在每一帧都会涉及到，因此处理不当肯定会对性能产生一定的影响。另外由于离屏渲染会增加 GPU 的工作量，可能会导致 CPU+GPU 的处理时间超出 16.7ms，导致掉帧卡顿。

##### 离屏渲染的场景和优化

圆角优化

**方法一：**
一般情况下我们会用这个方法去设置圆角：

```objc
iv.layer.cornerRadius = 30;
iv.layer.masksToBounds = YES;
```

使用cornerRadius进行切圆角，在iOS9之前会产生离屏渲染，比较消耗性能，而之后系统做了优化，则不会产生离屏渲染，但是操作最简单

**方法二：**

利用mask设置圆角，利用的是UIBezierPath和CAShapeLayer来完成

```objc
CAShapeLayer *mask = [[CAShapeLayer alloc] init];
mask1.opacity = 0.3;
mask1.path = [UIBezierPath bezierPathWithOvalInRect:iv.bounds].CGPath;
iv.layer.mask = mask;
```

**方法三：**

利用CoreGraphics画一个圆形上下文，然后把图片绘制上去，得到一个圆形的图片

```objc
- (UIImage *)drawCircleImage:(UIImage*)image
{
  CGFloat side = MIN(image.size.width, image.size.height);

  UIGraphicsBeginImageContextWithOptions(CGSizeMake(side, side), false, [UIScreen mainScreen].scale);
  CGContextAddPath(UIGraphicsGetCurrentContext(), [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, side, side)].CGPath);
  CGContextClip(UIGraphicsGetCurrentContext());

  CGFloat marginX = -(image.size.width - side) * 0.5;
  CGFloat marginY = -(image.size.height - side) * 0.5;
  [image drawInRect:CGRectMake(marginX, marginY, image.size.width, image.size.height)];

  CGContextDrawPath(UIGraphicsGetCurrentContext(), kCGPathFillStroke);

  UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
  UIGraphicsEndImageContext();

  return newImage;
}
```

三种方法里面，方法三是性能最好的。

##### shadow优化

我们可以通过设置shadowPath来优化性能，能大幅提高性能

```objc
imageView.layer.shadowColor=[UIColorgrayColor].CGColor;
imageView.layer.shadowOpacity=1.0;
imageView.layer.shadowRadius=2.0;
UIBezierPath *path=[UIBezierPathbezierPathWithRect:imageView.frame];
imageView.layer.shadowPath=path.CGPath;
```

##### 组不透明

开启CALayer的 allowsGroupOpacity 属性后，子 layer 在视觉上的透明度的上限是其父 layer 的 opacity (对应UIView的 alpha )，并且从 iOS 7 以后默认全局开启了这个功能，这样做是为了让子视图与其容器视图保持同样的透明度。

所以，可以关闭 allowsGroupOpacity 属性，按产品需求自己控制layer透明度。

##### 抗锯齿

不设置 allowsEdgeAntialiasing属性为YES(默认为NO)

##### 标题离屏渲染的检测

Instruments的Core Animation工具中有几个和离屏渲染相关的检查选项：
Color Offscreen-Rendered Yellow
开启后会把那些需要离屏渲染的图层高亮成黄色，这就意味着黄色图层可能存在性能问题。

Color Hits Green and Misses Red
如果shouldRasterize被设置成YES，对应的渲染结果会被缓存，如果图层是绿色，就表示这些缓存被复用；如果是红色就表示缓存会被重复创建，这就表示该处存在性能问题了。

##### iOS版本上的优化

iOS 9.0 之前UIimageView跟UIButton设置圆角都会触发离屏渲染

iOS 9.0 之后UIButton设置圆角会触发离屏渲染，而UIImageView里png图片设置圆角不会触发离屏渲染了，如果设置其他阴影效果之类的还是会触发离屏渲染的。

##### 善用离屏渲染

尽管离屏渲染开销很大，但是当我们无法避免它的时候，可以想办法把性能影响降到最低。优化思路也很简单：既然已经花了不少精力把图片裁出了圆角，如果我能把结果缓存下来，那么下一帧渲染就可以复用这个成果，不需要再重新画一遍了。

CALayer为这个方案提供了对应的解法：shouldRasterize。一旦被设置为true，Render Server就会强制把layer的渲染结果（包括其子layer，以及圆角、阴影、group opacity等等）保存在一块内存中，这样一来在下一帧仍然可以被复用，而不会再次触发离屏渲染。有几个需要注意的点：

- shouldRasterize的主旨在于降低性能损失，但总是至少会触发一次离屏渲染。如果你的layer本来并不复杂，也没有圆角阴影等等，打开这个开关反而会增加一次不必要的离屏渲染
- 离屏渲染缓存有空间上限，最多不超过屏幕总像素的2.5倍大小
- 一旦缓存超过100ms没有被使用，会自动被丢弃
  layer的内容（包括子layer）必须是静态的，因为一旦发生变化（如resize，动画），之前辛苦处理得到的缓存就失效了。如果这件事频繁发生，我们就又回到了“每一帧都需要离屏渲染”的情景，而这正是开发者需要极力避免的。针对这种情况，Xcode提供了“Color Hits Green and Misses Red”的选项，帮助我们查看缓存的使用是否符合预期
- 其实除了解决多次离屏渲染的开销，shouldRasterize在另一个场景中也可以使用：如果layer的子结构非常复杂，渲染一次所需时间较长，同样可以打开这个开关，把layer绘制到一块缓存，然后在接下来复用这个结果，这样就不需要每次都重新绘制整个layer树了
  



## OC 语言

#### KVO

#### KVC

#### 分类

#### 关联对象





## Runtime

#### 对象、类对象、元类对象

#### 消息传递机制

#### 消息转发流程

#### Method-Swizzling





## 内存

#### 引用计数表

#### 弱引用表

#### ARC、MRC

#### 循环引用

#### 内存管理



## Block

#### Block 本质

#### 截获变量特性

#### 内存管理

#### 循环引用



## 多线程

#### GCD、NSOperation

#### 资源共享

#### 线程同步

#### SpinLock等



## RunLoop

#### 事件循环

#### 用户态

#### 核心态

#### 常驻线程



## 网络

#### HTTPS

#### 对称加密算法

#### 非对称加密算法

#### DNS解析

#### HTTP、TCP



## 设计模式

#### 桥接、适配器、命令

#### 责任链、单利

#### 六大设计原则



## 架构/框架

#### MVVM、时长统计框架

#### 图片缓存框架

#### PV量级10亿级业务框架



## 算法

#### 字符串反转

#### 单链表反转

#### 有序数组归并

#### 无序数组找中位数



## 第三方

#### AFNetworking

#### ReactCocoa 响应式编程



