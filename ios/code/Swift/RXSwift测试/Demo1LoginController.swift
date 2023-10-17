//
//  Demo1LoginController.swift
//  RXSwift测试
//
//  Created by WTW on 2020/3/28.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxSwift

private let minimalUsernameLength = 5
private let minimalPasswordLength = 5

class Demo1LoginController: UIViewController {

    @IBOutlet weak var nameTextField: UITextField!
    @IBOutlet weak var passwordField: UITextField!
    
    @IBOutlet weak var loginBtn: UIButton!
    
    @IBOutlet weak var tipLabel1: UILabel!
    @IBOutlet weak var tipLabel2: UILabel!
    
    fileprivate lazy var disposeBag: DisposeBag = DisposeBag()
        
    override func viewDidLoad() {
        super.viewDidLoad()
         
        tipLabel1.text = "Username has to be at least \(minimalUsernameLength) characters"
        tipLabel2.text = "Password has to be at least \(minimalPasswordLength) characters"
        
        /*
         需求：
         当用户输入用户名时，如果用户名不足5个字就给出红色提示语，并且无法输入密码，当用户名符合要求才能输入密码
         同样的当用户输入的密码不到 5 个字时也给出红色提示语。
         当用户名和密码有一个不符合要求时底部的绿色按钮不可点击，只有当用户名和密码同时有效时按钮才可点击。
         */
        
        // 校验用户名是否有效
        let usernameValid = nameTextField.rx.text.orEmpty
            .map{
                $0.count >= minimalUsernameLength
        }
            .share(replay: 1)
        
        // 校验密码是否有效
        let passwordValid = passwordField.rx.text.orEmpty
            .map { $0.count >= minimalPasswordLength }
            .share(replay: 1)
        
        //校验是否都有效
        let everythingValid = Observable.combineLatest(usernameValid, passwordValid){ $0 && $1 }
            .share(replay: 1)
        
        // 根据用户名是否有效，输入框是否可用
        usernameValid
            .bind(to: passwordField.rx.isEnabled)
            .disposed(by: disposeBag)

        // 用户名是否有效，提示语是否隐藏
        usernameValid
            .bind(to: tipLabel1.rx.isHidden)
            .disposed(by: disposeBag)

        // 密码是否有效，提示语是否隐藏
        passwordValid
            .bind(to: tipLabel2.rx.isHidden)
            .disposed(by: disposeBag)
        
        // 用户名密码都有效才让按钮有效
        everythingValid
            .bind(to: loginBtn.rx.isEnabled)
            .disposed(by: disposeBag)

        // 登录事件
        loginBtn.rx.tap
            .subscribe(onNext: {
                [weak self]
                _ in self?.showAlert()
                print("click")
            })
            .disposed(by: disposeBag)
    }
    
    func showAlert() {
        let alertView = UIAlertView(
            title: "RxExample",
            message: "This is wonderful",
            delegate: nil,
            cancelButtonTitle: "OK"
        )

        alertView.show()
    }

}
