//
//  NoteDAO.swift
//  错误处理
//
//  Created by WTW on 2020/3/26.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

enum DAOError : Error {
    case noData
    case primaryKeyNull
}

class NoteDAO: NSObject {

   private var listData = [Note]()
    
    // 插入元素
    func create(_ model:Note) {
        listData.append(model)
    }
    
    //删除元素
    func remove(_ model:Note) throws {
        guard let date = model.date else {
            throw DAOError.primaryKeyNull
        }
        
        for (index,note) in listData.enumerated() where note.date == date {
            listData.remove(at:index)
        }
    }
    
    // 修改Note
    func modify(_ model:Note) throws {
        guard let date = model.date else {
            throw DAOError.primaryKeyNull
        }
        
//        for note in listData where note.date = date {
//            note.content = model.content
//        }
    }
    
    // 查询所有数据
    func findAll() throws ->[Note] {
       guard listData.count > 0 else {
           //抛出没有输数据的错误
           throw DAOError.noData
       }
        
        defer {
            print("关闭数据库")
        }
        
        defer {
            print("释放语句对象")
        }
        
       return listData
    }
    
}
