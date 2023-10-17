//
//  ViewController.m
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/4.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "ViewController.h"
#import <ReactiveObjC.h>
#import <Masonry.h>
#import "CalculatorManager.h"
#import "RACSubjectTestView.h"
#import "HomeViewController.h"
#import "LoginViewController.h"
#import <RACReturnSignal.h>

@interface ViewController ()
@property (nonatomic,strong) RACCommand *command;
@property (nonatomic,assign) int age;
@property (weak, nonatomic) IBOutlet UITextField *textField;
@end

//响应式编程 代表 KVO KVO原理： 监听set 方法有没有调用
//函数式编程  让操作写成一系列嵌套的函数或者方法调用，特点是每个方法必须有返回值(对象本身)，把函数或者block 当做参数，block 参数(需要操作的值)   block 返回值（操作结果）；

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
/**
    //测试Masonry
    UIView *redView = [[UIView alloc] init];
    redView.backgroundColor = [UIColor redColor];
    [self.view addSubview:redView];
    
   [redView mas_makeConstraints:^(MASConstraintMaker *make) {
       make.left.equalTo(self.view);
       make.top.equalTo(self.view.mas_top).offset(100);
       make.width.height.mas_equalTo(200);
    }];
**/
    

//    //测试链式编程
//    CalculatorManager *manager = [[CalculatorManager alloc] init];
//    manager.add(5).add(5).add(5);
//    NSLog(@"result == %ld",manager.result);
//
//    //函数式编程
//    CalculatorManager *mgr = [[CalculatorManager alloc] init];
//    BOOL isqule = [[[[mgr jisuan:^NSInteger(NSInteger result) {
//        result += 15;
//        result -= 5;
//        return result;
//    }] log] equle:^BOOL(NSInteger result) {
//        return result == 10;
//    }] isEqule];
//
//    NSLog(@"isqule == %d ",isqule);
    
    
/**
    //RACSignal 基本使用
     底层实现：
     1.创建信号，首先把didSubscribe保存到信号中，还不会触发。
     2.当信号被订阅，也就是调用signal的subscribeNext:nextBlock
     2.1 subscribeNext内部会创建订阅者subscriber，并且把nextBlock保存到subscriber中。
     2.2 subscribeNext内部会调用siganl的didSubscribe
     3.siganl的didSubscribe中调用[subscriber sendNext:@1];
     3.1 sendNext底层其实就是执行subscriber的nextBlock
 
    //1、创建信号
    // block 执行时机 当有订阅者订阅了信号，就会调用block
    RACSignal *signal = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        //2、发送信号
        [subscriber sendNext:@"123"];
        
        //如果不再发送数据 ，最好发送信号完成，内部会自动调用 [RACDisposable disposable] 取消订阅信号
        //[subscriber sendCompleted];
        
        //block 调用时刻 ：当信号发送完成或者发送失败就会调用这个block，取消订阅信号
        //执行完block 后，当前信号就不在被订阅了
        return [RACDisposable disposableWithBlock:^{
            //当订阅者销毁的时候就会被调用
            NSLog(@"信号销毁了");
        }];
    }];
    //3、订阅信号，信号才会被激活 订阅信号传的值
    [signal subscribeNext:^(id  _Nullable x) {
        NSLog(@"接收到的数据 %@",x);
    }];
//    //订阅信号的错误信息
//    [signal subscribeError:^(NSError * _Nullable error) {
//        NSLog(@"%@",error);
//    }];
//    //订阅完成
//    [signal subscribeCompleted:^{
//
//    }];
**/
  
/**
    //RACSubject 基本使用：
    //先订阅 在发送信号
    //1、创建信号
    RACSubject *subject = [RACSubject subject];

    //2、订阅信号
    //内部创建 RACSubscriber，并且保存起来
    //block 调用时机：当信号发出新值，就会调用
    [subject subscribeNext:^(id  _Nullable x) {
        NSLog(@"第一个订阅者%@",x);
    }];
    [subject subscribeNext:^(id  _Nullable x) {
        NSLog(@"第二个订阅者%@",x);
    }];
    //3、发送信号
    //遍历所有的订阅者 执行 nextBlock
    [subject sendNext:@"123"];
    
    //RACReplaySubject 基本使用：
    //先发送，再订阅
    //1、创建信号
    RACReplaySubject *replaySubject = [RACReplaySubject subject];
    //2、发送信号
    [replaySubject sendNext:@"1"];
    [replaySubject sendNext:@"2"];
    //3、订阅信号
    [replaySubject subscribeNext:^(id  _Nullable x) {
        NSLog(@"第一个订阅者接收到的数据%@",x);
    }];
    [replaySubject subscribeNext:^(id x) {
        NSLog(@"第二个订阅者接收到的数据%@",x);
    }];
**/
/**
     RACSignal 信号 ：
 
     订阅RACSignal,自动创建RACSubscriber，RACSubscriber 发送信号消息
     RACSignal : 只能订阅，不能发送;
     RACSignal : 只有一个订阅者
 
    先发送信号，再订阅：
     RACSubject:(开发的时候使用的比较多)
        有多个订阅者
        信号提供者，自己可以充当信号，又能充当订阅者。
        使用场景:通常用来代替代理，有了它，就不必要定义代理了。
     
     RACReplaySubject:
        重复提供信号类，RACSubject的子类。
 
     RACReplaySubject 和 RACSubject 共同点：
        既可以充当信号也可以充当订阅者；
 
     RACReplaySubject 和 RACSubject 区别：
         RACReplaySubject可以先发送信号，在订阅信号，RACSubject就不可以。
         使用场景一:如果一个信号每被订阅一次，就需要把之前的值重复发送一遍，使用重复提供信号类。
         使用场景二:可以设置capacity数量来限制缓存的value的数量,即只缓充最新的几个值。
**/
   
/**
     //RACSubject 代替代理
     RACSubjectTestView *v = [[RACSubjectTestView alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
     v.backgroundColor = [UIColor redColor];
     [self.view addSubview:v];
     [v.subject subscribeNext:^(id  _Nullable x) {
     NSLog(@"%@",x);
     }];
**/
  
/**
    //元组类
    //RACTuple : 类似NSArray ,用来包装值
    //集合类
    //RACSequence : 用于代替NSArray,NSDictionary,可以使用它来快速遍历数组和字典。
    
    //1、遍历数组
    NSArray *arr = @[@1,@2,@3,@4,@5];
    //这里分为三步：
    //1、把数组转换成集合RACSequence arr.rac_sequence
    //2、把集合RACSequence 转换为RACSignal类，arr.rac_sequence.signal
    //3、订阅信号 ，激活信号，会自动把集合中的所有值遍历出来
    [arr.rac_sequence.signal subscribeNext:^(id  _Nullable x) {
        //不能直接更新UI 需要切换到主线程
        NSLog(@"%@",[NSThread currentThread]);
        NSLog(@"%@",x);
    }];
    
    //2、遍历字典 遍历出来的键值对会包装成RACTuple(元组对象)
    NSDictionary *dict = @{@"name":@"rose",@"age":@18};
    [dict.rac_sequence.signal subscribeNext:^(id  _Nullable x) {
        //NSLog(@"%@",x);
        //元组解包 会把元组的值，按顺序给参数里面的变量赋值
        RACTupleUnpack(NSString *key,NSString *value) = x;
        NSLog(@"%@ %@",key,value);
    }];
 
     //把值包装成元组
     RACTuple *tuple = RACTuplePack_(@1,@2,@3,@4);
     NSLog(@"%@",tuple);
    
    RACTuple *tuple1 = [RACTuple tupleWithObjectsFromArray:@[@"123",@"456"]];
    NSLog(@"%@",tuple1[0]);
**/
   
/**
    //RACMulticastConnection   Multicast: 广播 
    //用于当一个信号被多次订阅的时候，避免多次调用创建信号中的block，可以使用这个类处理
    //RACMulticastConnection 通过 RACSignal 的 -publish 和 -muticast: 方法创建
    //使用步骤:
    //1.创建信号 + (RACSignal *)createSignal:(RACDisposable * (^)(id<RACSubscriber> subscriber))didSubscribe
    //2.创建连接 RACMulticastConnection *connect = [signal publish];
    //3.订阅信号,注意：订阅的不在是之前的信号，而是连接的信号。 [connect.signal subscribeNext:nextBlock]
    //4.连接 [connect connect]
    
    // RACMulticastConnection底层原理:
    // 1.创建connect，connect.sourceSignal -> RACSignal(原始信号)  connect.signal -> RACSubject
    // 2.订阅connect.signal，会调用RACSubject的subscribeNext，创建订阅者，而且把订阅者保存起来，不会执行block。
    // 3.[connect connect]内部会订阅RACSignal(原始信号)，并且订阅者是RACSubject
    // 3.1.订阅原始信号，就会调用原始信号中的didSubscribe
    // 3.2 didSubscribe，拿到订阅者调用sendNext，其实是调用RACSubject的sendNext
    // 4.RACSubject的sendNext,会遍历RACSubject所有订阅者发送信号。
    // 4.1 因为刚刚第二步，都是在订阅RACSubject，因此会拿到第二步所有的订阅者，调用他们的nextBlock
    
    // 假设在一个信号中发送请求，每次订阅一次都会发送请求，这样就会导致多次请求。
    // 解决：使用RACMulticastConnection就能解决.
    
    //1、创建请求信号
    RACSignal *signal = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        NSLog(@"发送请求");
        [subscriber sendNext:@1];
        return nil;
    }];
    //2、创建连接
    RACMulticastConnection *connection = [signal publish];
    //3、订阅信号
    //注意：订阅信号，也不能激活信号，只是保存订阅者到数组，必须通过连接,当调用连接，就会一次性调用所有订阅者的sendNext:
    [connection.signal subscribeNext:^(id  _Nullable x) {
        NSLog(@"接收数据%@",x);
    }];
    [connection.signal subscribeNext:^(id  _Nullable x) {
        NSLog(@"接收数据%@",x);
    }];
    //4、连接激活信号
    //RACSubject 订阅 signal
    [connection connect];
**/
    
/**
    // RACCommand : 用于处理事件的类，可以把事件如何处理,事件中的数据如何传递，包装到这个类中，他可以很方便的监控事件的执行过程。
    //使用步骤：
    //1、创建命令
    // 使用场景 : 监听按钮点击 网络请求
    //1、创建命令  initWithSignalBlock:(RACSignal * (^)(id input))signalBlock
    //2、在signalBlock中，创建RACSignal，并且作为signalBlock的返回值
    //3、订阅command 信号
    //4、监听命令是否执行完毕
    //5、执行命令 - (RACSignal *)execute:(id)input
    
    //使用注意
    //1、signalBlock必须要返回一个信号，不能传nil。
    //2、如果不想要传递信号，直接创建空的信号[RACSignal empty];
    //3.RACCommand中信号如果数据传递完，必须调用[subscriber sendCompleted]，这时命令才会执行完毕，否则永远处于执行中。
    //4.RACCommand需要被强引用，否则接收不到RACCommand中的信号，因此RACCommand中的信号是延迟发送的。
    //5、executionSignals 信号中的信号 一开始获取不到内部信号
    //5.1、 switchToLatest : 获取内部信号
    //5.2、 execute 获取内部信号
    
    RACCommand *command = [[RACCommand alloc] initWithSignalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
        // input 执行命令传入的参数
        NSLog(@"执行命令 %@",input);
        
        //创建空信号
        //return [RACSignal empty];
        //2、创建信号，用来传递数据
        return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
            //信号的block
            NSLog(@"执行信号的block");
            //发送数据
            [subscriber sendNext:@"哈哈哈啊"];
            //注意：数据传递完，最好调用sendCompleted，这时命令才执行完毕。
            [subscriber sendCompleted];
            return nil;
        }];
    }];
    
    _command = command;
    
    // 3.订阅RACCommand中的信号
    //第一种方式
//    [[command execute:@""] subscribeNext:^(id  _Nullable x) {
//        NSLog(@"%@",x);
//    }];
    //第二种方式
    //executionSignals 信号中的信号，信号发送信号
//    [command.executionSignals subscribeNext:^(id  _Nullable x) {
//        NSLog(@"111 == %@",x);  //RACDynamicSignal
//        [x subscribeNext:^(id  _Nullable x) {
//            NSLog(@"222 == %@",x);
//        }];
//    }];
    
    //RAC 高级用法
    //switchToLatest 获取最近发送的信号
    //switchToLatest : 用于signal of signals，获取signal of signals发出的最新信号,也就是可以直接拿到RACCommand中的信号
    [command.executionSignals.switchToLatest subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
    
    //4、监听命令是否执行完毕，默认会来一次，直接跳过，skip 表示跳过第一次信号
    //不加skip   执行完毕 执行命令 正在执行 哈哈哈啊
    //加skip    执行命令 正在执行 哈哈哈啊
    [[command.executing skip:1] subscribeNext:^(NSNumber * _Nullable x) {
        if ([x boolValue] == YES) {
            NSLog(@"正在执行");
        }else {
            NSLog(@"执行完毕");
        }
    }];
    
    //5、执行命令
    [command execute:@"1"];
    
**/
    
/**
    //RACComman 使用一 ： 监听按钮点击
   
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(100, 100, 100, 40);
    btn.backgroundColor = [UIColor redColor];
    [self.view addSubview:btn];
    
    //方式 1
//    btn.rac_command = [[RACCommand alloc] initWithSignalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
//        //command block  处理点击的业务
//        NSLog(@"点击了按钮");
//
//        return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
//            //信号的block  往外传值出去
//            [subscriber sendNext:@"123"];
//            [subscriber sendCompleted];
//
//            return nil;
//        }];
//    }];
    
    //方式 2
    RACSubject *enableSignal = [RACSubject subject];
    btn.rac_command = [[RACCommand alloc] initWithEnabled:enableSignal signalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
        //command block  处理点击的业务
        NSLog(@"点击了按钮");
        
        return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
            //信号的block  往外传值出去
            [subscriber sendNext:@"123"];
            //请求完成的时候 需要调用
            [subscriber sendCompleted];
            return nil;
        }];
    }];
    
    //控制按钮的交互 按钮不能点击
    //[enableSignal sendNext:@(NO)];
    // 可以用来控制在执行任务的时候控制不能点击
    [[btn.rac_command.executing skip:1] subscribeNext:^(NSNumber * _Nullable x) {
        //开发中控制按钮的点击
        BOOL executing = [x boolValue];
        [enableSignal sendNext:@(executing)];
    }];
    
    
    //监听
    [btn.rac_command.executionSignals.switchToLatest subscribeNext:^(RACSignal<id> * _Nullable x) {
        NSLog(@"== %@ == ",x);
    }];
**/
    
    
    //常见的运用
    //1、监听某个方法有没有调用(代替代理)
    //2、代替KVO
    //3、监听事件
    //4、代替通知
    //5、监听文本框文字改变
    //6、处理一个界面，多个请求的问题
    
/**
    //1、监听某个方法有没有调用(代替代理)
    RACSubjectTestView *v = [[RACSubjectTestView alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
    v.backgroundColor = [UIColor redColor];
    [self.view addSubview:v];
    [[v rac_signalForSelector:@selector(touchesBegan:withEvent:)] subscribeNext:^(RACTuple * _Nullable x) {
        NSLog(@"调用了touchesBegan:withEvent:");
    }];
**/
    
/**
    //2、代替KVO
    //只要值变化就会发送信号
//    [[self rac_valuesForKeyPath:@keypath(self,age) observer:self] subscribeNext:^(id  _Nullable x) {
//        NSLog(@"%@",x);
//    }];
    self.age = 10;
    
    //开发中常用如下的宏
    [RACObserve(self, age) subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
    
    //移除监听
    //[self removeObserver:self forKeyPath:@keypath(self,age)];
**/
   
/**
    //3、监听事件(文本框或者按钮的点击)
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(100, 100, 100, 40);
    btn.backgroundColor = [UIColor redColor];
    [self.view addSubview:btn];
    
    [[btn rac_signalForControlEvents:UIControlEventTouchUpInside] subscribeNext:^(__kindof UIControl * _Nullable x) {
        NSLog(@"点击了按钮 == %@",x);
    }];
**/
    
/**
    //4、代替通知
    //监听通知
    [[[NSNotificationCenter defaultCenter] rac_addObserverForName:@"NOTI" object:nil] subscribeNext:^(NSNotification * _Nullable x) {
        NSLog(@"监听到通知了%@",x);
    }];
    //发送通知
    [[NSNotificationCenter defaultCenter] postNotificationName:@"NOTI" object:nil];
**/
   
/**
    //5、监听文本框文字改变
    UITextField *textfield = [[UITextField alloc] initWithFrame:CGRectMake(100, 100, 100, 50)];
    [self.view addSubview:textfield];
    textfield.backgroundColor = [UIColor greenColor];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(100, 200, 100, 50)];
    [self.view addSubview:label];
    
    //方式 1
//    [[textfield rac_textSignal] subscribeNext:^(NSString * _Nullable x) {
//        label.text = x;
//        NSLog(@"%@",x);
//    }];
    
    //方式 2 绑定信号
    RAC(label,text) = textfield.rac_textSignal;
**/
    
    
/**
    //6、处理多个请求，都返回结果的时候，统一做处理
    RACSignal *request1 = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        NSLog(@"发送请求1");
        [subscriber sendNext:@"发送请求1"];
        return nil;
    }];
    RACSignal *request2 = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        NSLog(@"发送请求2");
        [subscriber sendNext:@"发送请求2"];
        return nil;
    }];
    //使用注意：几个信号，参数一的方法就几个参数，每个参数对应信号发出的数据。
    [self rac_liftSelector:@selector(updateUIWithR1:r2:) withSignalsFromArray:@[request1,request2]];
 **/
    
    //ReactiveCocoa 常见宏
    //1、RAC(TARGET, [KEYPATH, [NIL_VALUE]]):用于给某个对象的某个属性绑定。
    // 只要文本框文字改变，就会修改label的文字
    //RAC(self.labelView,text) = _textField.rac_textSignal;
    
    //2、RACObserve(self, name):监听某个对象的某个属性,返回的是信号。
//    [RACObserve(self.view, center) subscribeNext:^(id x) {
//    NSLog(@"%@",x);
//    }];
    
    //3、  @weakify(Obj)和@strongify(Obj),一般两个都是配套使用,在主头文件(ReactiveCocoa.h)中并没有导入，需要自己手动导入，RACEXTScope.h才可以使用。但是 每次导入都非常麻烦，只需要在主头文件自己导入就好了。
    
    //4、RACTuplePack：把数据包装成RACTuple（元组类）
    
    //5、 RACTupleUnpack：把RACTuple（元组类）解包成对应的数据
    
    
    //架构思想 : 把业务逻辑划分的更清楚
    //MVC
    //MVC S(业务类：manager)
    //MVVM  VM (处理显示和业务逻辑)
    //VIPER  E:模型  I:交互  P:展示  R:路由(跳转)
    
    //self.testBlock => 返回一个block => 然后block() 两步执行
    //self.testBlock();
    //[self testBlock]();
    
    
    //ReactiveCocoa 高级
    //bind (绑定) 一般很少用 了解原理即可
/**
    //需求： 假设想要在文本框输入的内容拼接一段文字“输出:”
    //方式一 ： 直接在返回结果后，拼接
    [_textField.rac_textSignal subscribeNext:^(NSString * _Nullable x) {
        NSLog(@"输出:%@",x);
    }];
    //方式二 ： 在返回结果前拼接，RAC 中 bind 方法来处理
    //bind 使用步骤：
    //1、传入一个返回值 RACSignalBindBlock 的 block
    //2、描述一个 RACSignalBindBlock 类型的 bindBlock 作为 block 的返回值
    //3、描述一个返回结果的信号，作为bindBlock 的返回值
    // 在 bindBlock 中做信号结果的处理
    
    //底层实现：
    //1、源信号调用bind,会重新创建一个绑定信号 RACSignalBindBlock
    //2、当绑定信号被订阅，就会调用绑定信号中的didSubscribe，生成一个bindingBlock。
    //3、当源信号有内容发出，就会把内容传递到bindingBlock处理，调用bindingBlock(value,stop)
    //4、调用bindingBlock(value,stop)，会返回一个内容处理完成的信号（RACReturnSignal）。
    //5、订阅RACReturnSignal，就会拿到绑定信号的订阅者，把处理完成的信号内容发送出来
    
    [[_textField.rac_textSignal bind:^RACSignalBindBlock _Nonnull{
        NSLog(@"执行bindBlock");
        
        return ^RACSignal *(id  value, BOOL *stop){
            //信号一改变,就会执行,并且把值传递过来
            NSString *result = [NSString stringWithFormat:@"输出：%@",value];
            return [RACReturnSignal return:result];
        };
        
    }] subscribeNext:^(id  _Nullable x) {
        NSLog(@"获取到处理完的数据 == %@",x);
    }] ;
**/
    
/**
    //flattenMap 和 Map 用于把信号内容映射成新的内容
    
    // flattenMap 和 Map 区别：
    // flattenMap 中的 block 返回的是信号
    // Map 中的block 返回的是对象
    
    // 开发中如果信号发出的值不是信号，映射一般使用Map，如果是信号就用 flattenMap

    //flattenMap 简单使用: (使用的比较少 一般使用在信号中的信号时候使用)
    //flattenMap 作用： 把源信号的内容映射成新的信号，信号可以是任意类型
    
    // flattenMap使用步骤:
    // 1.传入一个block，block类型是返回值RACSignal，参数value
    // 2.参数value就是源信号的内容，拿到源信号的内容做处理
    // 3.包装成RACReturnSignal信号，返回出去。
    
    // flattenMap底层实现:
    // 0.flattenMap内部调用bind方法实现的,flattenMap中block的返回值，会作为bind中bindBlock的返回值。
    // 1.当订阅绑定信号，就会生成bindBlock。
    // 2.当源信号发送内容，就会调用bindBlock(value, *stop)
    // 3.调用bindBlock，内部就会调用flattenMap的block，flattenMap的block作用：就是把处理好的数据包装成信号。
    // 4.返回的信号最终会作为bindBlock中的返回信号，当做bindBlock的返回信号。
    // 5.订阅bindBlock的返回信号，就会拿到绑定信号的订阅者，把处理完成的信号内容发送出来。
    
    [[_textField.rac_textSignal flattenMap:^__kindof RACSignal * _Nullable(NSString * _Nullable value) {
        //返回值 绑定信号的内容
        return [RACReturnSignal return:[NSString stringWithFormat:@"输出:%@",value]];
    }] subscribeNext:^(id  _Nullable x) {
        //订阅绑定信号，每当源信号发送内容，做完处理就会调用
        NSLog(@"%@",x);
    }];
    
    //signalOfsignals用FlatternMap
    // 创建信号中的信号
    RACSubject *signalOfsignals = [RACSubject subject];
    RACSubject *signal = [RACSubject subject];
    
    [[signalOfsignals flattenMap:^__kindof RACSignal * _Nullable(id  _Nullable value) {
        // 当signalOfsignals的signals发出信号才会调用
        return value;
    }] subscribeNext:^(id  _Nullable x) {
        // 只有signalOfsignals的signal发出信号才会调用，因为内部订阅了bindBlock中返回的信号，也就是flattenMap返回的信号。
        // 也就是flattenMap返回的信号发出内容，才会调用。
        
        NSLog(@"%@aaa",x);
    }];
    // 信号的信号发送信号
    [signalOfsignals sendNext:signal];
    // 信号发送内容
    [signal sendNext:@1];
    
    //Map 的简单使用 (经常使用)
    
    //Map作用:把源信号的值映射成一个新的值
    
    // Map使用步骤:
    // 1.传入一个block,类型是返回对象，参数是value
    // 2.value就是源信号的内容，直接拿到源信号的内容做处理
    // 3.把处理好的内容，直接返回就好了，不用包装成信号，返回的值，就是映射的值。

    // Map底层实现:
    // 0.Map底层其实是调用flatternMap,Map中block中的返回的值会作为flatternMap中block中的值。
    // 1.当订阅绑定信号，就会生成bindBlock。
    // 3.当源信号发送内容，就会调用bindBlock(value, *stop)
    // 4.调用bindBlock，内部就会调用flattenMap的block
    // 5.flattenMap的block内部会调用Map中的block，把Map中的block返回的内容包装成返回的信号。
    // 5.返回的信号最终会作为bindBlock中的返回信号，当做bindBlock的返回信号。
    // 6.订阅bindBlock的返回信号，就会拿到绑定信号的订阅者，把处理完成的信号内容发送出来。
    
    [[_textField.rac_textSignal map:^id _Nullable(NSString * _Nullable value) {
        return [NSString stringWithFormat:@"输出:%@",value];
    }] subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }] ;
**/
    
/**
    //concat : 按照一定顺序拼接信号 当多个信号发出的时候，有顺序的接收信号
    
    // concat底层实现:
    // 1.当拼接信号被订阅，就会调用拼接信号的didSubscribe
    // 2.didSubscribe中，会先订阅第一个源信号（signalA）
    // 3.会执行第一个源信号（signalA）的didSubscribe
    // 4.第一个源信号（signalA）didSubscribe中发送值，就会调用第一个源信号（signalA）订阅者的nextBlock,通过拼接信号的订阅者把值发送出来.
    // 5.第一个源信号（signalA）didSubscribe中发送完成，就会调用第一个源信号（signalA）订阅者的completedBlock,订阅第二个源信号（signalB）这时候才激活（signalB）。
    // 6.订阅第二个源信号（signalB）,执行第二个源信号（signalB）的didSubscribe
    // 7.第二个源信号（signalA）didSubscribe中发送值,就会通过拼接信号的订阅者把值发送出来.
    
    RACSignal *signal1 = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@1];
        [subscriber sendCompleted];
        return nil;
    }];
    RACSignal *signal2 = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@2];
        [subscriber sendCompleted];
        return nil;
    }];
    
    //把 signal1 拼接到 signal2 之后，signal1 发送完，signal2才被激活
    RACSignal *concatSignal = [signal1 concat:signal2];
    
    //只需要面对拼接信号开发。
    //订阅拼接的信号，不需要单独订阅signalA，signalB
    //注意：第一个信号必须发送完成，第二个信号才会被激活
    [concatSignal subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
**/
    
/**
    //then 用于连接两个信号，当第一个信号完成，才会连接 then 返回的信号
    //注意使用then，之前信号的值会被忽略掉.
    // 底层实现：
    //1、先过滤掉之前的信号发出的值。
    //2.使用concat连接then返回的信号
    [[[RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@1];
        [subscriber sendCompleted];
        return nil;
    }] then:^RACSignal * _Nonnull{
        return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
            [subscriber sendNext:@2];
            [subscriber sendCompleted];
            return nil;
        }];
    }] subscribeNext:^(id  _Nullable x) {
        //只能接收到第二个信号的值，也就是 then 返回信号的值
        NSLog(@"%@",x);
    }];
**/
    
/**
    //merge 把多个信号合并为一个信号，任何一个信号有新值的时候就会调用
    // 底层实现：
    // 1.合并信号被订阅的时候，就会遍历所有信号，并且发出这些信号。
    // 2.每发出一个信号，这个信号就会被订阅
    // 3.也就是合并信号一被订阅，就会订阅里面所有的信号。
    // 4.只要有一个信号被发出就会被监听。
    RACSignal *signalA = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@1];
        return nil;
    }];
    RACSignal *signalB = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@2];
        return nil;
    }];
    
    //合并信号 任何一个信号发送数据 都能监听到
   RACSignal *mergeSignal = [signalA merge:signalB];
    [mergeSignal subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
**/
    
/**
    //zipWith
    //zipWith 把两个信号压缩成一个信号，只有当两个信号同时发出信号内容时，并且把两个信号的内容合并成一个元组，才会触发压缩流的next 事件
    // 底层实现:
    // 1.定义压缩信号，内部就会自动订阅signalA，signalB
    // 2.每当signalA或者signalB发出信号，就会判断signalA，signalB有没有发出个信号，有就会把最近发出的信号都包装成元组发出。
    RACSignal *signalA = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@1];
        return nil;
    }];
    RACSignal *signalB = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
       
        [subscriber sendNext:@2];
        return nil;
    }];
    
    //压缩信号 A 和 B
    RACSignal *zipSignal = [signalA zipWith:signalB];
    [zipSignal subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
**/
    

    /**
    //combineLatest
    //combineLatest 将多个信号合并起来，并且拿到各个信号的最新的值，必须每个合并的signal 至少有过一次senNext ，才会触发信号
    // 底层实现：
    // 1.当组合信号被订阅，内部会自动订阅signalA，signalB,必须两个信号都发出内容，才会被触发。
    // 2.并且把两个信号组合成元组发出。
    RACSignal *signalA = [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
        
        [subscriber sendNext:@1];
        
        return nil;
    }];
    
    RACSignal *signalB = [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
        
        [subscriber sendNext:@2];
        
        return nil;
    }];
    
    // 把两个信号组合成一个信号,跟zip一样，没什么区别
    RACSignal *combineSignal = [signalA combineLatestWith:signalB];
    
    [combineSignal subscribeNext:^(id x) {
        
        NSLog(@"%@",x);
    }];
    
     //reduce 聚合 用于信号发出的内容是元组，把信号发出元组的值聚合成一个值
    //底层实现：
    //1.订阅聚合信号，每次有内容发出，就会执行reduceblcok，把信号内容转换成reduceblcok返回的值。
    RACSignal *signalA = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@1];
        return nil;
    }];
    RACSignal *signalB = [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@2];
        return nil;
    }];
    //聚合
    //常见的用法，（先组合再聚合）。combineLatest:(id<NSFastEnumeration>)signals reduce:(id (^)())reduceBlock
    // reduce中的block简介:
    // reduceblcok中的参数，有多少信号组合，reduceblcok就有多少参数，每个参数就是之前信号发出的内容
    // reduceblcok的返回值：聚合信号之后的内容。
    RACSignal *reduceSignal = [RACSignal combineLatest:@[signalA,signalB] reduce:^id(NSNumber *num1,NSNumber *num2){
        return [NSString stringWithFormat:@"%@ %@ ",num1,num2];
    }];
    [reduceSignal subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
**/
    
    //过滤
/**
    //filter 过滤信号 ，使用其可以获取满足条件的信号
    //每次信号发出，都会执行过滤条件判断
    [[_textField.rac_textSignal filter:^BOOL(NSString * _Nullable value) {
        return value.length > 3;
    }] subscribeNext:^(NSString * _Nullable x) {
        NSLog(@"%@",x);
    }] ;
 
    //ignore 忽略某些值的信号
    [[_textField.rac_textSignal ignore:@"a"] subscribeNext:^(NSString * _Nullable x) {
        NSLog(@"%@",x);
    }];
 
    //distinctUntilChanged 当上一次的值和当前的值有明显的变化就会发出信号，否者会被忽略掉
    //在开发中，刷新UI 经常使用，只有两次数据不一样才需要刷新
    [[_textField.rac_textSignal distinctUntilChanged] subscribeNext:^(NSString * _Nullable x) {
        NSLog(@"%@",x);
    }];
 
    //take 从开始一共取N次的信号
    //1、创建信号
    RACSubject *subject = [RACSubject subject];
    //2、处理信号
    [[subject take:1] subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
    //3.发送信号
    [subject sendNext:@1];
    [subject sendNext:@2];
 
    
    //takeLast ： 获取最后N次的信号，前提条件，订阅者必须调用完成，因为只有完成，就知道总共有多少信号
    //1、创建信号
    RACSubject *subject = [RACSubject subject];
    //2、处理信号 订阅信号
    [[subject takeLast:1] subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
    //3、发送信号
    [subject sendNext:@1];
    [subject sendNext:@2];
    [subject sendCompleted];
 

    //takeUntil : 获取信号直到某个信号执行完成
    [[_textField.rac_textSignal takeUntil:self.rac_willDeallocSignal] subscribeNext:^(NSString * _Nullable x) {

    }];
 
    
    //skip 跳过几个信号不接受
    [[_textField.rac_textSignal skip:1] subscribeNext:^(NSString * _Nullable x) {
        NSLog(@"%@",x);
    }];
 
    
    //switchToLatest:用于signalOfSignals（信号的信号），有时候信号也会发出信号，会在signalOfSignals中，获取signalOfSignals发送的最新信号
    RACSubject *signalOfSignals = [RACSubject subject];
    RACSubject *signal = [RACSubject subject];
    
    // 获取信号中信号最近发出信号，订阅最近发出的信号。
    // 注意switchToLatest：只能用于信号中的信号
    [signalOfSignals.switchToLatest subscribeNext:^(id x) {
        
        NSLog(@"%@",x);
    }];
    [signalOfSignals sendNext:signal];
    [signal sendNext:@1];
**/
    
    // 秩序
/**
    //doNext : 执行Next 之前，会先执行这个Block
    //doCompleted : 执行sendCompleted 之前，会先执行这个Block
    [[[[RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
        [subscriber sendNext:@1];
        [subscriber sendCompleted];
        return nil;
    }] doNext:^(id x) {
        // 执行[subscriber sendNext:@1];之前会调用这个Block
        NSLog(@"doNext");;
    }] doCompleted:^{
        // 执行[subscriber sendCompleted];之前会调用这个Block
        NSLog(@"doCompleted");
    }] subscribeNext:^(id x) {
        NSLog(@"%@",x);
    }];
**/
   
/**
    //线程
    //deliverOn: 内容传递切换到制定线程中，副作用在原来线程中,把在创建信号时block中的代码称之为副作用。
    //subscribeOn: 内容传递和副作用都会切换到制定线程中。
    
    //时间
    //timeout 超时，可以让一个信号再一定时间后，自动报错
    RACSignal *signal = [[RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {

        return nil;
    }] timeout:3 onScheduler:[RACScheduler currentScheduler]] ;

    [signal subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    } error:^(NSError * _Nullable error) {
        //3秒后自动调用
        NSLog(@"%@",error);
    }];
 
    
    //interval 定时，每隔一段时间发出信号
    [[RACSignal interval:1 onScheduler:[RACScheduler currentScheduler]] subscribeNext:^(NSDate * _Nullable x) {
        NSLog(@"%@",x);
    }];
 
    //delay 延时发送next
    [[[RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
        [subscriber sendNext:@1];
        [subscriber sendCompleted];
        return nil;
    }] delay:3] subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
**/
    
    //重复
/**
   // retry重试 ：只要失败，就会重新执行创建信号中的block,直到成功.
    __block int i = 0;
    [[[RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
        if (i == 10) {
            [subscriber sendNext:@1];
        }else{
            NSLog(@"接收到错误");
            [subscriber sendError:nil];
        }
        i++;
        return nil;
    }] retry] subscribeNext:^(id x) {
        NSLog(@"%@",x);
    } error:^(NSError *error) {

    }];
 
    //replay重放：当一个信号被多次订阅,反复播放内容
    RACSignal *signal = [[RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
        [subscriber sendNext:@1];
        [subscriber sendNext:@2];
        return nil;
    }] replay];
    [signal subscribeNext:^(id x) {
        NSLog(@"第一个订阅者%@",x);
    }];
    [signal subscribeNext:^(id x) {
        NSLog(@"第二个订阅者%@",x);
    }];
    
    //throttle节流:当某个信号发送比较频繁时，可以使用节流，在某一段时间不发送信号内容，过了一段时间获取信号的最新内容发出。
    RACSubject *signal = [RACSubject subject];
    _signal = signal;
    // 节流，在一定时间（1秒）内，不接收任何信号内容，过了这个时间（1秒）获取最后发送的信号内容发出。
    [[signal throttle:1] subscribeNext:^(id x) {

        NSLog(@"%@",x);
    }];
 
**/
}

//更新UI
- (void)updateUIWithR1:(id)data r2:(id)data1
{
    NSLog(@"更新UI%@  %@",data,data1);
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.navigationController pushViewController:[HomeViewController new] animated:YES];
//    [self.navigationController pushViewController:[LoginViewController new] animated:YES];
}

#pragma mark - 测试block

- (void(^)(void))testBlock {
    return ^{
        NSLog(@"%s",__func__);
    };
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
