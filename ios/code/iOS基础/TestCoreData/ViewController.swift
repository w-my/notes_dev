//
//  ViewController.swift
//  TestCoreData
//
//  Created by WTW on 2020/4/15.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 持久化存储器
    代表了存储在磁盘上的实际数据库。但从不会直接使用此对象。
 持久化存储协调器
    此对象协调了持久化存储器信息的写入和读出。协调器是管理对象上下文与持久化存储器之间的桥梁。
 管理对象模型（MOM）
    这是磁盘上代表了数据模型的简单文件。可以将其看作是数据库模式（schema）。
 管理对象
    此类代表了要存入Core Data中的实体。传统数据库开发者会将实体理解为表。
    管理对象为NSManagedObject类型，其实例会被放置在管理对象上下文中。
    管理对象会遵守管理对象模型中所描述的模式，并通过持久化存储协调器从而被保存到持久化存储器中。
 管理对象上下文
    这是一个虚拟的区域。听起来很奇怪，不是吗？来解释一下。Core Data对象会在内存中创建、
    设置属性以及被使用。所有这些操作都是在管理对象上下文中完成的。
    此上下文跟踪了对管理对象所做的所有事情，甚至可以允许撤销这些动作。
    你可以将管理对象想象成桌子上的玩具。可以在桌子上将这些玩具移动、破坏、拿走以及添加新的玩具进来。
    这个桌子就是管理对象上下文，当都准备好时还可以将其状态进行保存。当在保存管理对象上下文的状态时，
    此保存操作将会与上下文连接的持久化存储协调器进行通信。
    随后持久化存储协调器便会将信息存储到持久化存储器中，然后再到磁盘上。
 
 NSPersistentContainer : 创建一个新的 CoreData堆，维持了项目中的 NSManagedObjectModel NSPersistentStoreCoordinator 和其他资源的引用
 Context : 所有的动作都是在 Context 上，由 Context 去调用 Coordinator
 Managed Object : 简称 MO 要持久化的对象必须是 MO,通过 CoreData 查出来的对象也是 MO ,派生自 NSManagedObject
 NSManaged Object Model : 模型 比如 xxx.xcdatamodeld
 
 */


import UIKit
import CoreData

class ViewController: UIViewController {

    let appDeleage = UIApplication.shared.delegate as! AppDelegate
    let context = (UIApplication.shared.delegate as! AppDelegate).persistentContainer.viewContext
    
    @IBOutlet weak var nameTextfield: UITextField!
    @IBOutlet weak var phoneTextfileld: UITextField!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        print(NSHomeDirectory())
        
    }
    
    // 新增
    @IBAction func add() {
        let student = Student(context: context)
        student.name = nameTextfield.text
        student.phone = phoneTextfileld.text
//        appDeleage.saveContext()  // 根据情况选择，可以在APP进入后台或者将杀死的时候保存
    }
    
    
    // 删除
    @IBAction func del() {
        let fetch : NSFetchRequest<Student> = Student.fetchRequest()
       fetch.predicate = NSPredicate(format: "name=%@", nameTextfield.text!)  // 查询条件
       do {
           // 处理查询结果
           let students = try context.fetch(fetch)
           let student = students.first!
           context.delete(student)  //删除
//           appDeleage.saveContext()
       } catch let error as NSError {
           print("查询失败\(error.description)")
       }
    }
    
    //查询
    @IBAction func query() {
        let fetch : NSFetchRequest<Student> = Student.fetchRequest()
        fetch.predicate = NSPredicate(format: "name=%@", nameTextfield.text!)  // 查询条件
        do {
            // 处理查询结果
            let students = try context.fetch(fetch)
            let student = students.first!
            phoneTextfileld.text = student.phone
        } catch let error as NSError {
            print("查询失败\(error.description)")
        }
    }
    
    // 更新
    @IBAction func update() {
       let fetch : NSFetchRequest<Student> = Student.fetchRequest()
       fetch.predicate = NSPredicate(format: "name=%@", nameTextfield.text!)  // 查询条件
       do {
           // 处理查询结果
           let students = try context.fetch(fetch)
           let student = students.first!
           student.phone = phoneTextfileld.text  // 更细数据
//           appDeleage.saveContext()
       } catch let error as NSError {
           print("查询失败\(error.description)")
       }
    }
    
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
       
        // 查找所有用用户的 age 小于 20的，更新为 20
//        let batch = NSBatchUpdateRequest(entityName: "Student")
//        batch.propertiesToUpdate = ["age" : 20]
//        batch.predicate = NSPredicate(format: "age<%@", 20 as NSNumber)
//        batch.resultType = .updatedObjectsCountResultType
//
//        let result = try? context.execute(batch)   // NSPersistentStoreResult
//        if let theresult = result as? NSBatchUpdateResult {  // NSBatchUpdateRequestResultType
//            if let numbersOfAffectedStudents = theresult.result as? Int32 {  // 更新的项数
//                print(numbersOfAffectedStudents)
//            }
//        }
        
        
        
    }
}

