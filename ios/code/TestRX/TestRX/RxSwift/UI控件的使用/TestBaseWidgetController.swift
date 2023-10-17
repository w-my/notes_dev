//
//  TestBaseWidgetController.swift
//  TestRX
//
//  Created by WTW on 2020/10/29.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import RxCocoa
import RxSwift

class TestBaseWidgetController: UIViewController {
    
    let disposeBag = DisposeBag()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = .white
        self.view.addSubview(testBtn)

        // 方式1
//        testBtn.rx.tap.subscribe(onNext: { [weak self] in
//
//            print("testBtn Click")
//            self?.test()
//
//        }).disposed(by: disposeBag)
        
        // 方式2
//        testBtn.rx.tap.bind { [weak self]  in
//
//            print("testBtn Click 222")
//            self?.test()
//        }
        
        //MARK: - 按钮标题的绑定
        // 按钮标题的绑定
        // rx.title 为 setTitle(_:for)的封装
//        Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//            .map { "计数\($0)" }
//            .bind(to: testBtn.rx.title(for: .normal))
//            .disposed(by: disposeBag)
        
        // 按钮富文本标题绑定
        // rx.attributedTitle 为 setAttributedTitle(_:controlState:) 的封装
//        let timer = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//
//        timer.map { formatTimeInterval(ms: $0) }
//            .bind(to: testBtn.rx.attributedTitle())
//            .disposed(by: disposeBag)
        
        //将数字转成对应的富文本
        func formatTimeInterval(ms: NSInteger) -> NSMutableAttributedString {
            let string = String(format: "%0.2d:%0.2d.%0.1d",
                                arguments: [(ms / 600) % 600, (ms % 600 ) / 10, ms % 10])
            //富文本设置
            let attributeString = NSMutableAttributedString(string: string)
            //从文本0开始6个字符字体HelveticaNeue-Bold,16号
            attributeString.addAttribute(NSAttributedString.Key.font,
                                         value: UIFont(name: "HelveticaNeue-Bold", size: 16)!,
                                         range: NSMakeRange(0, 5))
            //设置字体颜色
            attributeString.addAttribute(NSAttributedString.Key.foregroundColor,
                                         value: UIColor.white, range: NSMakeRange(0, 5))
            //设置文字背景颜色
            attributeString.addAttribute(NSAttributedString.Key.backgroundColor,
                                         value: UIColor.orange, range: NSMakeRange(0, 5))
            return attributeString
        }
        
        // 按钮避免多次连续点击
        testBtn.rx.tap.throttle(5, scheduler: MainScheduler.instance).subscribe { event in
            print(event)
        }.disposed(by: disposeBag)
        
        // MARK: - 按钮图片的绑定
        //  rx.image 为 setImage(_:for:) 的封装
        //  rx.backgroundImage 为 setBackgroundImage(_:for:) 的封装。
//        let timer = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//
//        timer.map ({
//            let name = $0%2 == 0 ?  "back" : "forward"
//            return UIImage(named: name)!
//        })
//            .bind(to: testBtn.rx.image())
//            .disposed(by: disposeBag)
    }
 
    fileprivate lazy var testBtn: UIButton = {
       
        let testBtn = UIButton()
        testBtn.frame = CGRect(x: 10, y: 100, width: 100, height: 40)
        testBtn.backgroundColor = .red
        return testBtn
    }()
    
    func test() {
        
        print("hello world")
    }
}
