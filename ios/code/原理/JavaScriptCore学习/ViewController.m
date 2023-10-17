//
//  ViewController.m
//  JavaScriptCore学习
//
//  Created by WTW on 2020/3/22.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"
#import <JavaScriptCore/JavaScriptCore.h>
#import "MyPoint.h"

/**
 *
 * https://www.jianshu.com/p/3f5dc8042dfc
 * https://blog.csdn.net/longshihua/article/details/51645575
 *
 * iOS7 加入 JavaScriptCore 框架，该框架让 OC 和 JS 交互变的更加简单方便，允许在 swift 和 OC 中执行 JavaScript ，也可以插入到自定义对象到 JS 中
 * 对外一共暴露了5个类：JSContext/JSValue/JSManagedValue/JSVirtualMachine/JSExport  最为核心的是  JSContext 和 JSValue
 *
 * JSContext 是 JS 代码的执行环境，可以理解为作用域 (通过JSCore 执行的代码都是通过JSContext来执行的)，
 * 可以在 OC 或 swift 中创建和使用 JSContext 来执行 JS（evaluate），访问 JS 中定义的 values 甚至直接在 JS 中访问原生应用中的方法、函数等。
 * 对应于 JS 中的一个全局对象 (相当于浏览器中的window对象)
 * JSContext 用于管理 js 虚拟机中对象的生命周期，每一个 JSValue 实例都将于 JSContext 通过强引用关联，只要 JSValue 存在， JSContext 就会保持强引用，当 JSContext 中所有的 JSValue 被释放掉时，JSContext 也将被释放。
 *
 * JSValue 对 JS 值的包装 (JS的值拿到OC中不能直接使用，需要包装一下，一个JSValue对应一个JS值)，是 JS 和 OC 数据交换的桥梁
 * JSValue 可能是JS中的 number boolean 等基本类型，也可能是对象、函数、甚至 undefined 或者 null
 * JSValue 是不能独立存在的，必须存在某个 JSContext 中，一个 JSContext 中可以包含多个 JSValue
 * JSVaue 对其对应的 JS 值和其所属的 JSContext 对象都是强引用关系
 *
 *
 * JSVirtualMachine
 * JSContext 可以创建新的变量和获取已经存在的变量，在单一虚拟机（JSVirtualMachine）中能够拥有多个 JSContext ，在同一个虚拟机中的两个 JSContext 可以进行消息交换，但是不能在两个  JSVirtualMachine 中进行交换。
 *
 * JSExport 是一个协议而不是一个对象，可以使用这个协议暴露原生对象、实例方法、类方法、和属性 给 JS,这样 JS 就可以直接调用相关暴露的方法和属性。
 * 默认情况下，OC类的所有方法和属性都不会被暴露给JavaScript，所以必须要选择要暴露的方法和属性。对于类遵守的任意协议(protocol)，如果该协议包含了JSExport协议，
 * 则JavaScriptCore就会认为这个该协议中包含的方法和属性列表是暴露给JavaScript的。这个时候，我们才能在JavaScript调用OC类的exported的方法和属性。
 * 对于每一个暴露的实例方法，JavaScriptCore创建了一个与之对应的函数作为原型对象的属性。对于暴露的OC属性，JavaScriptCore将在原型上创建一个JavaScript的存储属性。
 * 对于每一个暴露的类方法，JavaScriptCore将在构造对象上创建一个JavaScript函数。
 *
 * // 需要注意 OC 中参数是 : 声明，JSCore 会用一下两个规则生成一个对应的 JS 函数:
 * 1、移除所有的冒号
 * 2、将跟在冒号后面的第一个小写字母大写
 *  还可以这样写 ：JSExportAs(makePoint, + (MyPoint *)makePointWithX:(double)x y:(double)y);  // makePoint 就是给 JS 中指定的名字，这个宏只对带有参数的OC 方法有效
 *
 *  JSManagedValue
 *  JSValue的封装，用它可以解决JS和原生代码之间循环引用的问题。添加一个“conditional retain”行为来为值(values)提供自动内存管理。
 *
 *
 */

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    JSContext *context = [[JSContext alloc] init];
//    JSValue *value = [context evaluateScript:@"2+2"];
//    NSLog(@"%d",[value toInt32]);  // 4
    
#pragma mark - OC 中执行 JS 中的函数

//    NSString *path = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"js"];
//    NSString *factorialScript = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
//
//    JSContext *context = [[JSContext alloc] init];
//    [context evaluateScript:factorialScript];
//
//    // 获得函数
//    JSValue *function = context[@"factorial"];
//    // 调用函数，获得结果
//    JSValue *result = [function callWithArguments:@[@5]];
//
//    NSLog(@"%d",[result toInt32]);

#pragma mark - JavaScript 与 Objective-C 交互
    /*
     主要通过两种方式：
     Block ： 可以很方便的将 OC 中的方法暴露给 JS 调用
     JSExport 协议 ： 使用 JSEcport 协议，将OC中的某个对象直接暴露给 JS 使用，而且在JS中使用就像调用JS的对象一样自然
     */
    
    /*
    使用 Block 方式注意点：
    不要在 Block 中直接使用 JSValue
    不要在 Block 中直接使用 JSContext
    
    因为 block 内部会强引用它里面用到的的外部变量，直接在block 内部使用的话，JSValue 就会被 Block 强引用，而每个 JSValue 都是强引用着它属于的那个 JSContext ， 而 Blcok 又是注入到 Context 中，所以 Block 会被 Context 强引用，这样就照成了循环引用，不能使用 JSContext 是一样的道理
    解决办法：
       1、将JSValue 当做参数传到 Block 中，而不是直接在 Blcok 内部使用
       2、对于 JSContext 可以使用 [JSContext currentContext] 方法来获取当前的 Context
    
    */
    // JS 可以直接调用 makeNSColor 方法
    /*
     var colorForword = function(word) {
        if(!colorMap[word]) return;
        return makeNSColor(colorMap[word]);
     }
     */
//    JSContext *context = [[JSContext alloc] init];
//    context[@"makeNSColor"] = ^(NSDictionary *rgb){
//        float r = [rgb[@"red"] floatValue];
//        float g = [rgb[@"green"] floatValue];
//        float b = [rgb[@"blue"] floatValue];
//        return [UIColor colorWithRed:r green:g blue:b alpha:1.0];
//    };
    
    
    // JSExport 协议
    // 通过 JSExport 协议可以很方便的将 OC 中的对象暴露给 JS 使用，且在 JS 中使用起来就和 JS 对象一样
    // 例如将 OC 中一个 MyPoint 类，它有两个double类型的属性，x,y，一个实例方法description 和一个类方法 makePointWithX: Y:
    // 声明一个继承自JSExport的自定义协议时，就是在告诉JSCore，这个自定义协议中声明的属性，实例方法和类方法需要被暴露给JS使用。（不在这个协议中的方法不会被暴露出去。）
    /*
     @protocol MyPointExports <JSExport>

     @property double x;
     @property double y;

     - (NSString *)description;
     + (MyPoint *)makePointWithX:(double)x
                               y:(double)y;

     @end
     
     // JS 中调用
     point.x;
     point.y = 10;
     point.description();
     MyPoint.makePointWithXY(0,0);
     
     // 需要注意 OC 中参数是 : 声明，JSCore 会用一下两个规则生成一个对应的 JS 函数:
     1、移除所有的冒号
     2、将跟在冒号后面的第一个小写字母大写
     还可以这样写 ：JSExportAs(makePoint, + (MyPoint *)makePointWithX:(double)x y:(double)y);  // makePoint 就是给 JS 中指定的名字，这个宏只对带有参数的OC 方法有效
     
     */
}



@end
