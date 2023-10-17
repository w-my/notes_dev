//
//  AppDelegate.swift
//  TESTScroll
//
//  Created by WTW on 2021/1/21.
//

import UIKit

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        window = UIWindow(frame: UIScreen.main.bounds)
        
        window?.backgroundColor = .white
        
        let vc = SNSHNewHomePageViewController()
        
        window?.rootViewController = NavigationController(rootViewController: vc)
        
        window?.makeKeyAndVisible()
        
        return true
    }

}

