//
//  DelegateProxyTestController.swift
//  RXSwift 语法基础
//
//  Created by WTW on 2020/11/20.
//  Copyright © 2020 WTW. All rights reserved.
//  https://www.cnblogs.com/duzhaoquan/p/12195711.html
/**
 *
 *  DelegateProxy 是代理委托，代理的代理
 *  DelegateProxy 是作为中间代理，先把系统的 delegate 保存一份，然后拦截 delagate 的方法，即每次触发delegate 方法之前，先调用DelegateProxy 这一百年对应的方法，可以在这里发送序列给多个订阅者
 */

import UIKit
import RxSwift
import RxCocoa

// 自定义代理实现代理的一对多
/// 1、实现一个需要代理的类
@objc public protocol CarOilProtocol: AnyObject {
    
    @discardableResult
    func oil80(name: String) -> String
    
    @discardableResult
    func oil50(name: String) -> String
}

extension CarOilProtocol {
    
    public func oil10(whoCar: String) {}
    
    public func oil20(whoCar: String) {}
}

public class CarCar: ReactiveCompatible {
    
    var name: String
    var oilQulity: Int32 = 100
    var disposeBag: DisposeBag = DisposeBag()
    var timer: Observable<Int>?
    public weak var delegate: CarOilProtocol?
    
    init(name: String) {
        self.name = name
    }
    
    func startRun() {
        timer = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
        
        timer?.subscribe(onNext: {[weak self] (i) in
            self?.oilQulity -= 1
            
            if self?.oilQulity == 80 {
                
                self?.delegate?.oil80(name: self?.name ?? "")
                
            }else if self?.oilQulity == 50 {
                
                self?.delegate?.oil50(name: self?.name ?? "")
                
            }else {
                
            }
            
            }).disposed(by: disposeBag)
    }
    
}

// 2、继承 DelegateProxy 创建一个关于上述类代理委托,同时还要遵守 DelegateProxyType 和 CarOilProtocol协议

extension CarCar : HasDelegate {
    
    public typealias Delegate = CarOilProtocol
    
}

public class RxCarCarOilProtocolProxy: DelegateProxy<CarCar,CarOilProtocol>,DelegateProxyType,CarOilProtocol {
    
    public init(car: CarCar) {
        super.init(parentObject: car, delegateProxy: RxCarCarOilProtocolProxy.self)
    }
    
    public static func registerKnownImplementations() {
        self.register { RxCarCarOilProtocolProxy(car: $0) }
    }
    
    internal lazy var oil80Subject = PublishSubject<String>()
    internal lazy var oil50Subject = PublishSubject<String>()
    
    public func oil80(name: String) -> String {
        let nn = _forwardToDelegate?.oil80(name:name)
        oil80Subject.onNext(name)
        return nn ?? name
    }
    
    public func oil50(name: String) -> String {
        let mm = _forwardToDelegate?.oil50(name: name)
        oil50Subject.onNext(name)
        return mm ?? name
    }
    
    deinit {
        self.oil80Subject.on(.completed)
        self.oil50Subject.on(.completed)
    }
    
}

// 3、对 Carcar 进行 Rx 扩展，将Carcar与前面创建的代理委托关联起来，将相关的 delegate 方法转为可观察序列。

extension Reactive where Base: CarCar {
    
    public var delegate: DelegateProxy<CarCar,CarOilProtocol> {
        
        return RxCarCarOilProtocolProxy.proxy(for: base)
    }
    
    public var dao80:Observable<String>{
        
        return RxCarCarOilProtocolProxy.proxy(for: base).oil80Subject.asObserver()
    }
     
    public var dao50:Observable<String>{
        
        return RxCarCarOilProtocolProxy.proxy(for: base).oil50Subject.asObserver()
    }
     
    public func setDelegate(_ delegate:CarOilProtocol) -> Disposable{
        
        return RxCarCarOilProtocolProxy.installForwardDelegate(delegate, retainDelegate: false, onProxyForObject: self.base)
    }
}


// 使用

class DelegateProxyTestController: UIViewController {

    var car: CarCar!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        car  = CarCar(name: "beijing")
        car.delegate = self as! CarOilProtocol
        car.startRun()
        car.rx.dao80.asObservable().subscribe ({ (str) in
            print("\(str.element)")
            }).disposed(by: DisposeBag())
    }
}
