//
//  AppDelegate.swift
//  TestCoreData
//
//  Created by WTW on 2020/4/15.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import CoreData

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
               
       // 构建一个数据库，插入批量数据
//       func populateDatabase() {
//           for counter in 0..<100 {
//
//            let student = NSEntityDescription.insertNewObject(forEntityName: "Student", into: ((UIApplication.shared.delegate as? AppDelegate)?.persistentContainer.viewContext)!) as! Student
//               student.name = "name\(counter)"
//               student.phone = "phone \(counter)"
//               student.age = Int32(truncating: NSNumber(value: arc4random_uniform(120)))
//           }
//           do {
//               try (UIApplication.shared.delegate as? AppDelegate)?.persistentContainer.viewContext.save()
//               print("populateDatabase == 保存成功")
//           } catch let error as NSError {
//               print(error.description)
//           }
//       }
//
//        populateDatabase()
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        saveContext() // 保证应用程序退出时可以保存数据库中改变的数据
    }

    // MARK: - Core Data stack

    // Persistent 容器
    lazy var persistentContainer: NSPersistentContainer = {
        let container = NSPersistentContainer(name: "TestCoreData")
        container.loadPersistentStores(completionHandler: { (storeDescription, error) in
            if let error = error as NSError? {
                
                fatalError("Unresolved error \(error), \(error.userInfo)")
            }
        })
        return container
    }()

    // MARK: - Core Data Saving support

    // 将数据存储到数据库
    func saveContext () {
        let context = persistentContainer.viewContext  // context 临时区 可以修改和删除数据
        if context.hasChanges {
            do {
                try context.save()
            } catch {
                let nserror = error as NSError
                fatalError("Unresolved error \(nserror), \(nserror.userInfo)")
            }
        }
    }

}

