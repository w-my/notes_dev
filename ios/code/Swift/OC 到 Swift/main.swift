//
//  main.swift
//  OC 到 Swift
//
//  Created by WTW on 2020/5/25.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class MyApplication: UIApplication {}

UIApplicationMain(CommandLine.argc,
                  CommandLine.unsafeArgv,
                  NSStringFromClass(MyApplication.self),
                  NSStringFromClass(AppDelegate.self))
