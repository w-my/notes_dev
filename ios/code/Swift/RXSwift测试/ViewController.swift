//
//  ViewController.swift
//  RXSwift
//
//  Created by WTW on 2020/3/24.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa

class ViewController: UIViewController {

    fileprivate lazy var bag : DisposeBag = DisposeBag()
    fileprivate lazy var label : UILabel = UILabel()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //MARK:监听按钮的点击
        let btn = UIButton(frame: CGRect(x: 100, y: 100, width: 80, height: 45))
        btn.setTitle("button", for: UIControl.State.normal)
        btn.backgroundColor = UIColor.green
        view.addSubview(btn)
        
//        // 传统实现方式
//        btn.addTarget(self, action: #selector(btnclick), for:.touchUpInside)
        
        btn.rx.tap.subscribe { (event:Event<()>) in
            print("点击了按钮")
        }.disposed(by: bag)
        
        // MARK:监听textView 的文字改变
        let textView = UITextView(frame: CGRect(x: 100, y: 160, width: 100, height: 40))
        textView.layer.borderColor = UIColor.green.cgColor
        textView.layer.borderWidth = 1.0
        view.addSubview(textView)
        
        // MARK:textView 文字改变的内容显示到label 上
        label.frame = CGRect(x: 100, y: 220, width: 200, height: 40)
        label.textColor = UIColor.red
        view.addSubview(label)
        
//        textView.rx.text.subscribe { (event:Event<String?>) in
//            print(event)
//        }.disposed(by: bag)
        
//        textView.rx.text.subscribe(onNext: { (str:String?) in
//            print(str!)
//            label.text = str!
//        }, onError: { (Error) in
//
//        }, onCompleted: {
//
//        }) {
//
//        }.disposed(by: bag)
     
        // 使用绑定直接给label 进行关联
        textView.rx.text.bind(to: label.rx.text).disposed(by: bag)
        
        // MARK: KVO
        // 传统写法
//        label.addObserver(self, forKeyPath: "text", options: .new, context: nil)
     
        // RAC 写法
        label.rx.observe(String.self, "text").subscribe(onNext: { (str:String?) in
            print(str!)
        }, onError: { (Error) in
            
        }, onCompleted: {
            
        }) {
            
        }.disposed(by: bag)
        
        // MARK:监听scrollView 滚动
        
        let scrollview = UIScrollView(frame: CGRect(x: 100, y: 250, width: 300, height: 300))
        scrollview.contentSize = CGSize(width: 300, height: 500)
        view.addSubview(scrollview)
        
        scrollview.rx.contentOffset.subscribe(onNext: { (point:CGPoint) in
            print(point.y)
        }, onError: { (Error) in
            
        }, onCompleted: {
            
        }) {
            
        }.disposed(by: bag)
        
        // MARK: 闭包回调
        // 传统实现方法
        let url = URL(fileURLWithPath: "")
        URLSession.shared.dataTask(with: url) { (data, response, error) in
            guard error == nil else {
                print("Data Task Error \(error) ")
                return
            }
            
            guard let data = data else{
                print("Data Task Error \(error)")
                return
            }
            print("Data Task success")
        }.resume()
        // RX 来实现
        URLSession.shared.rx.data(request:URLRequest(url:url)).subscribe(onNext: { (Data) in
            print("Data Task Success")
        }, onError: { (Error) in
             print("Data Task Error \(Error)")
            }).disposed(by: bag)
           
        //MARK:通知
        // 一般操作
        let ntfObserver = NotificationCenter.default.addObserver(forName: UIApplication.willEnterForegroundNotification, object: nil, queue: nil) { (notification) in
            print("UIApplicationWillEnterForeground")
        }
         // 记得销毁
//        deinit {
//            NotificationCenter.default.removeObserver(ntfObserver)
//        }
        // RX 实现
        NotificationCenter.default.rx.notification(UIApplication.willEnterForegroundNotification).subscribe(onNext: { (Notification) in
            print("UIApplicationWillEnterForeground")
            }).disposed(by: bag)
        
        //MARK:多个任务之间有依赖关系
        // 比如用户拿到token 之后通过 token 拿到用户信息
        // 传统实现
        /*
        enum API {
            // 通过用户名密码获取token
            static func token(username:String,password:String,success:(String)->Void,failure:(Error)->Void){}
        
            // 通过 token 获取用户信息
            static func userinfo(token:String,success:(userinfo)->(Void),failure:(Error)->Void){}
        }
        API.token(username: "name", password: "password", success: { token in
            API.userinfo(token: token, success: {
                userInfo in
                print("获取用户信息成功")
            }) { (error) in
                print("获取用户信息失败")
            }
        }) { (error) in
            print("获取用户信息失败")
        }
        */
        // Rx 实现
        /*
        enum API {
            static func token(username:String,password:String)->Observable<String>{}
            static func userInfo(token:String)->Observable<userinfo>{}
        }
        API.token(username: "name", password: "password")
            .flatMapLatest(API.userInfo)
            .subscribe(onNext: { userInfo in
                print("获取用户信息成功: \(userInfo)")
            }, onError: { error in
                print("获取用户信息失败: \(error)")
            })
            .disposed(by: bag)
         */
        
        //MARK:等待多个并发任务完成后处理结果
        // 比如将两个接口请求合并成一个
        // rx 封装接口
        
        /*
        class Teacher {}
        class Comment {}
        
        enum API {
            static func teacher(teacherId:Int)->Observable<Teacher> {}
            static func teacherComments(teacherId:Int)->Observable<[Comment]>{}
        }
        
        // 获取老师信息的同时获取老师评论
        let teacherId = 10
        Observable.zip(
         API.teacher(teacherId: teacherId),
         API.teacherComments(teacherId: teacherId)
         .subscribe(onNext: { ((teacher, comments)) in
//             print("获取老师信息成功: \(teacher)")
//             print("获取老师评论成功: \(comments.count) 条")
        }, onError: { (Error) in
            
        }).disposed(by:bag)
        */

        
        
        // MARK:- 常见操作
        // MARK:never 创建一个 sequence 但是不发出任何事件信号
        let neverSequence = Observable<String>.never()
        neverSequence.subscribe { (event:Event<String>) in
            print("This will never be printed")
        }.disposed(by: bag)
        
        // MARK:empty 就是创建一个空的sequence,只能发出一个completed事件
        Observable<Int>.empty().subscribe { (event:Event<Int>) in
            print(event)  // completed
        }.disposed(by: bag)
        
        // MARK:just是创建一个sequence只能发出一种特定的事件，能正常结束
        Observable.just("coder123").subscribe { (event:Event<String>) in
            print(event)  // next(coder123)/Users/wtw/Desktop/note/iOS/code/Swift/RXSwift测试/ViewController.swift
        }.disposed(by: bag)
        
        //MARK: of是创建一个sequence能发出很多种事件信号
        Observable.of("a","b","c").subscribe { (event:Event<String>) in
            print(event)  // next(a)  next(b)  next(c)
        }.disposed(by: bag)
        
        //MARK:from就是从数组中创建sequence
        Observable.from(["a","b","c"]).subscribe { (event:Event<String>) in
            print(event)
        }.disposed(by: bag)
        
        // MARK:creat
        // create操作符传入一个观察者observer，然后调用observer的onNext，onCompleted和onError方法。
        // 返回一个可观察的obserable序列
        func myobservable() ->Observable<Any> {
            Observable.create { (observer:AnyObserver<Any>) -> Disposable in
                observer.onNext("abc")
                observer.onNext("123")
                observer.onCompleted()
                
                return Disposables.create()
            }
        }
        
        func myJunst(element : String) -> Observable<String> {
            return Observable.create({ (observer : AnyObserver<String>) -> Disposable in
                observer.onNext(element)
                observer.onCompleted()
                return Disposables.create()
            })
        }
        
        myobservable().subscribe { (event:Event<Any>) in
            print(event)  // next(abc)   next(123)  completed
        }.disposed(by: bag)
        
        myJunst(element: "hello").subscribe { (event:Event<String>) in
            print(event)  // next(hello)  completed
        }.disposed(by: bag)
        
        //MARK:range
        // range就是创建一个sequence，他会发出这个范围中的从开始到结束的所有事件
        Observable.range(start: 1, count: 10)
            .subscribe { (event : Event<Int>) in
                print(event)
        }.disposed(by: bag)
        
        
        // MARK: repeatElement
        // 创建一个sequence，发出特定的事件n次
        Observable.repeatElement("hello world")
            .take(3)
            .subscribe(onNext: { (str:String) in
            print(str)
            }).disposed(by: bag)
        
        
        // MARK:- Subjects
        // Subjet是observable和Observer之间的桥梁，一个Subject既是一个Obserable也是一个Observer，
        // 既可以发出事件，也可以监听事件
        
        //MARK: PublishSubject
        // 当你订阅PublishSubject的时候，你只能接收到订阅他之后发生的事件。
        // subject.onNext()发出onNext事件，对应的还有onError()和onCompleted()事件
        
        let publishSub = PublishSubject<String>()
        
        // 必须要先订阅再发送
        publishSub.subscribe { (event:Event<String>) in
            print("也可以订阅消息\(event)")
        }.disposed(by: bag)
        
        publishSub.onNext("可以发送消息");
        
        publishSub.subscribe { (event:Event<String>) in
            print("2\(event)")
        }.disposed(by: bag)
        
        publishSub.onNext("2222")
        
        
        //MARK:ReplaySubject
        // 当你订阅ReplaySubject的时候，你可以接收到订阅他之后的事件，
        // 也可以接受订阅他之前发出的事件，接受几个事件取决与bufferSize的大小
//        let replaySubject = ReplaySubject<String>.create(bufferSize: 2)
        let replaySubject = ReplaySubject<String>.createUnbounded()
        
        replaySubject.subscribe { (event:Event<String>) in
            print("1 == \(event)")
        }.disposed(by: bag)
        
        replaySubject.onNext("a")
        replaySubject.onNext("b")
        
        replaySubject.subscribe { (event:Event<String>) in
            print("2 == \(event)")
        }.disposed(by: bag)
        
        replaySubject.onNext("c")
        
        /*
         1 == next(a)
         1 == next(b)
         2 == next(a)
         2 == next(b)
         1 == next(c)
         2 == next(c)
         */
        
        //MARK:BehaviorSubject (最常用) 订阅了BehaviorSubject，你会接受到订阅之前的最后一个事件
        let bSubject = BehaviorSubject(value: "a")
        bSubject.subscribe { (event:Event<String>) in
            print("1",event)
        }.disposed(by: bag)
        
        bSubject.onNext("b")
        bSubject.onNext("c")
        
        bSubject.subscribe { (event:Event<String>) in
            print("2",event)
        }.disposed(by: bag)
        
        bSubject.onNext("d")
        
        /*
         1 next(a)
         1 next(b)
         1 next(c)
         2 next(c)
         1 next(d)
         2 next(d)
         */
        
        // MARK:Variable
        // Variable是BehaviorSubject一个包装箱，就像是一个箱子一样，
        // 使用的时候需要调用asObservable()拆箱，里面的value是一个BehaviorSubject，
        // 如果 Variable 打算发出事件，直接修改对象的 value 即可
        // 当事件结束时，Variable 会自动发出completed事件。
        // a 是个默认值
        let v = Variable("a")
        v.asObservable().subscribe { (event) in
           print("1 == ", event)
        }.disposed(by:bag)

        v.value = "b"
        v.value = "c"

        v.asObservable().subscribe { (event) in
           print("2 == ", event)
        }.disposed(by:bag)

        v.value = "d"
        
        /*
         1 ==  next(a)
         1 ==  next(b)
         1 ==  next(c)
         2 ==  next(c)
         1 ==  next(d)
         2 ==  next(d)
         1 ==  completed
         2 ==  completed
         */
        
        // MARK:-变换操作
        //MARK: map 通过传入一个函数闭包把原来的sequence转变为一个新的sequence的操作
        Observable.of(1,2,3,4).map { (num:Int) -> Int in
            return num * num
        }.subscribe { (event:Event<Int>) in
            print(event)
        }.disposed(by: bag)
        
        
        // MARK:flatMap
        // 将一个sequence转换为一个sequences
        // 当你接收一个sequence的事件，你还想接收其他sequence发出的事件的话可以使用flatMap，
        // 会将每一个sequence事件进行处理以后，然后再以一个sequence形式发出事件
        
        struct Student {
            var score : Variable<Int>
        }
        
        let stu1 = Student(score: Variable(80))
        let stu2 = Student(score: Variable(100))
        let stu3 = Student(score: Variable(60))

        let student = Variable(stu1)
        student.asObservable().flatMap { (stu:Student) -> Observable<Int> in
            return stu.score.asObservable()
        }.subscribe { (event:Event<Int>) in
            print("======",event)
        }.disposed(by: bag)
        

        student.value = stu2
        stu1.score.value = 10
        stu2.score.value = 20
        
        /*
         ====== next(80)
         ====== next(100)
         ====== next(10)
         ====== next(20)
         ====== completed
         */
        
        // MARK:-释放资源
        // 当监听一个事件序列的时候，有消息事件来了，我们做某些事情。
        // 但是这个事件序列不再发出消息了，我们的监听也就没有什么存在价值了，
        // 所以我们需要释放我们这些监听资源，其实也就是每种编程语言中的内存资源释放。
        // OC和Swift中也一样，在你不需要用某些变量的时候，你需要把这些变量所占用的内存空间释放掉。
        // 释放某一个监听的时候我们可以手动调用释放方法
        
        // MARK:dispose
        // 相当于MRC中手动调用release操作
        // 注意: 因为观察者已经销毁, 所有后面无法接受事件
        let testVariable = Variable("abc")
        testVariable.asObservable().subscribe { (event : Event<String>) in
            print(event)
        }.dispose()

        testVariable.value = "123"
     
        
        //MARK: Dispose Bags
        // 推荐使用这种方式，这种方式就好像iOS中的ARC方式似得，会自动去释放资源
        
        //MARK: UIBindingObserver
        // UIBindingObserver这个东西很有用的，创建我们自己的监听者，
        // 有时候RxCocoa(RxSwiftz中对UIKit的一个扩展库)给的扩展不够我们使用
        // 比如一个UITextField有个isEnabled属性，我想把这个isEnabled变为一个observer，我们可以这样做：
//        extension Reactive where Base: UITextField {
//            var inputEnabled: UIBindingObserver<Base, Result> {
//                return UIBindingObserver(UIElement: base) { textFiled, result in
//                    textFiled.isEnabled = result.isValid
//                }
//            }
//        }
    }
    
    
    
    
    
//    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
//        print(change)
//    }

    
//    @objc fileprivate func btnclick() {
//        print("=====")
//    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.navigationController?.pushViewController(Demo1LoginController(), animated: true)
    }
}



