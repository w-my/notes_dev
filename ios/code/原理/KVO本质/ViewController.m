//
//  ViewController.m
//  KVO本质
//
//  Created by WTW on 2019/7/17.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 https://www.jianshu.com/p/e8313f007210
 */

#import "ViewController.h"
#import "Person.h"
#import <objc/Runtime.h>
#import "TwoViewController.h"

@interface ViewController ()

@property (nonatomic,strong) Person *person1;
@property (nonatomic,strong) Person *person2;

@end

@implementation ViewController

- (void)printMethodNamesOfClass:(Class)cls {
    unsigned int count;
    //获得方法数组
    Method *methodList = class_copyMethodList(cls, &count);
    
    //存储方法名
    NSMutableString *methodNames = [NSMutableString string];
    
    //遍历数组
    for (int i = 0; i < count; i ++) {
        //获得方法
        Method method = methodList[i];
        //获取方法名
        NSString *methodName = NSStringFromSelector(method_getName(method));
        //拼接方法名
        [methodNames appendString:methodName];
        [methodNames appendString:@","];
        
    }
    
    //释放
    free(methodList);
    //打印方法名
    NSLog(@"%@ %@",cls,methodNames);
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.person1 = [[Person alloc] init];
    self.person1.age = 10;
    
    self.person2 = [[Person alloc] init];
    self.person2.age = 20;
    
    //验证方式一
    //NSLog(@"person1 添加KVO监听之前 - %@ %@",object_getClass(self.person1),object_getClass(self.person2));
    //person1 添加KVO监听之前 - Person Person
    
    //验证方式二
    //NSLog(@"person1 添加KVO监听之前 - %p %p",[self.person1 methodForSelector:@selector(setAge:)],[self.person2 methodForSelector:@selector(setAge:)]);
    // person1 添加KVO监听之前 - 0x10ab2d4f0 0x10ab2d4f0
    // p (IMP)0x108d2c4f0
    // (IMP) $0 = 0x0000000108d2c4f0 (KVO本质`-[Person setAge:] at Person.m:13)
    
    NSKeyValueObservingOptions option =NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld;
    [self.person1 addObserver:self forKeyPath:@"age" options:option context:@"123"];
    
    [self printMethodNamesOfClass:object_getClass(self.person1)];
    //NSKVONotifying_Person setAge:,class,dealloc,_isKVOA,
    [self printMethodNamesOfClass:object_getClass(self.person2)];
    //Person setAge:,age,
    
//    NSLog(@"%@  %@",object_getClass(self.person1),object_getClass(self.person2));
//    //结果为：NSKVONotifying_Person  Person
//    NSLog(@"%@  %@",[self.person1 class],[self.person2 class]);
//    //结果为：Person  Person （这种方式获取的不准确，因为被系统被屏蔽了）
    
    
    //验证方式一
    //NSLog(@"person1 添加KVO监听之后 - %@ %@",object_getClass(self.person1),object_getClass(self.person2));
    // person1 添加KVO监听之后 - NSKVONotifying_Person Person
    
    //验证方式二
     //NSLog(@"person1 添加KVO监听之后 - %p %p",[self.person1 methodForSelector:@selector(setAge:)],[self.person2 methodForSelector:@selector(setAge:)]);
    // person1 添加KVO监听之后 - 0x10ae883d2 0x10ab2d4f0
    // p (IMP)0x1090873d2
    // (IMP) $1 = 0x00000001090873d2 (Foundation`_NSSetIntValueAndNotify)
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    //    self.person1.isa  NSKVONotifying_Person
    //    self.person2.isa  Person
    //    isa 不一样 会导致类对象不一样 类对象不一样会导致类对象的实现方法不一样
    
    [self.person1 setAge:20];
    [self.person2 setAge:30];
    
    
//    //手动触发KVO的方法
//    [self.person1 willChangeValueForKey:@"age"];
//    [self.person1 didChangeValueForKey:@"age"];
    
    
    TwoViewController *two = [[TwoViewController alloc] initWithModel:self.person2];
    [self.navigationController pushViewController:two animated:YES];
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    NSLog(@"keyPath == %@ object == %@  change == %@  context == %@ ",keyPath,object,change,context);
}

/* 打印结果：
 keyPath == age object == <Person: 0x600003a1eb50>  change == {
 kind = 1;
 new = 20;
 old = 10;
 }  context == 123
 context ： 传入的是什么 接收到的就是什么
 */


// 注意点：
// 需要移除监听 iOS10 以下会崩溃，iOS 11以上不会崩溃
// 观察者的添加和移除必须成对出现，移除一个已经销毁的观察者也会崩溃
// 可以多次对同一个属性添加相同的观察者，当属性更改的时候，会多次调用接收方法，不过移除的时候也需要移除多次
// 当同一个控制器中添加了多个KVO的时候，需要对想要的监听属性进行区分，以便指定不同的逻辑
// 父子继承的情况时，父子都监听同一个属性的时候，子类需要调用super 根据 context 去区别父类还是子类
// 尽量使用静态变量作为 context ，尽量不要用 keypath 作为区分(存在继承的时候就无法区分)
// 如果有继承关系，在监听器回调函数中将 不是当前类处理的context 调用父类的监听器回调函数进行处理
// 删除监听器时需要注意不要重复删除，尽量使用context删除
-(void)dealloc {
    [self.person1 removeObserver:self forKeyPath:@"age"];
}


@end
