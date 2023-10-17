//
//  ViewController.swift
//  RXDataSourceTest
//
//  Created by WTW on 2020/11/12.
//  Copyright © 2020 WTW. All rights reserved.
//

/**
 *  RxDataSources 是以 section 来做为数据结构的。所以不管 tableView 是单分区还是多分区，在使用 RxDataSources 的过程中，都需要返回一个 section 的数组
 *  解析 https://my.oschina.net/dahuilang123/blog/1627404
 */

import UIKit
@_exported import RxSwift
@_exported import RxCocoa
@_exported import RxDataSources
@_exported import NSObject_Rx
@_exported import Then
@_exported import Reusable

class ViewController: UIViewController {
    
    // 多样式cell 使用
    var dataSource:RxTableViewSectionedReloadDataSource<MutiSection>?
    
    let tableView = UITableView().then {
        $0.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height)
        $0.backgroundColor = .white
        $0.register(cellType: TitleSwitchCell.self)
        $0.register(cellType: TitleImageCell.self)  // 测试多样式cell时使用
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        view.addSubview(tableView)
        
        /**************************** 单分区自带的section begin **********************************/
        // 使用自带的section
        // 初始化数据
        let items = Observable.just([SectionModel(model: "", items: ["测试MJRefresh刷新","item2","item3"])])
        // 创建数据源
        let datasource = RxTableViewSectionedReloadDataSource<SectionModel<String,String>>(configureCell:{ (datasource, tableView, indexPath, item)  in

            let cell = tableView.dequeueReusableCell(for: indexPath, cellType: TitleSwitchCell.self)

            cell.label.text = "indexPath: \(indexPath.row) item:\(item)"

            return cell

        })
        // 绑定单元格数据
        items.bind(to: tableView.rx.items(dataSource: datasource)).disposed(by: rx.disposeBag)

//        tableView.rx.itemSelected.subscribe { (index) in
//            print("选中索引 \(index)")
//        }.disposed(by: rx.disposeBag)
//
//        tableView.rx.modelSelected(String.self).subscribe { (item) in
//            print("选中内容 \(item)")
//        }.disposed(by: rx.disposeBag)

        // 同时输出索引和数据
        Observable.zip(tableView.rx.itemSelected, tableView.rx.modelSelected(String.self)).subscribe(onNext: { (indexPath, item) in
            print("\(indexPath.item) \(item)")
              
            if indexPath.row == 0 {
                self.navigationController?.pushViewController(TestMJRefreshController(), animated: true)
            }
            
        }).disposed(by: rx.disposeBag)
            
        Observable.zip(tableView.rx.itemDeleted, tableView.rx.modelDeleted(String.self)).subscribe(onNext: { (indexPath,item) in
            print("删除的 indexpath：\(indexPath) item:\(item)")
        }).disposed(by: rx.disposeBag)
         /**************************** 自带的section end **********************************/
        
       
         /**************************** 单分区自定义 section begin **********************************/
//        // 使用自定义的section
//        // 初始化数据
//        let items = Observable.just([TDSection(header: "", items: ["item1","item2","item3","item4"])])
//        // 创建数据源
//        let dataSource = RxTableViewSectionedReloadDataSource<TDSection>(configureCell: { (datasource, tableView, indexPath, item) in
//
//            let cell = tableView.dequeueReusableCell(for: indexPath, cellType: TitleSwitchCell.self)
//
//            cell.label.text = "indexPath: \(indexPath.row) item:\(item)"
//
//            return cell
//        })
//
//        // 绑定单元格数据
//        items.bind(to: tableView.rx.items(dataSource: dataSource)).disposed(by: rx.disposeBag)
         /**************************** 自定义 section end **********************************/

        
         /**************************** 多分区自带 section begin **********************************/
        
//         // 初始化数据
//        let items = Observable.just([SectionModel(model: "section1", items: ["sectin1-item1","sectin1-item2","sectin1-item3",]),
//                                       SectionModel(model: "section2", items: ["sectin2-item1","sectin2-item2","sectin2-item3",])])
//        // 创建数据源
//        let dataSource = RxTableViewSectionedReloadDataSource<SectionModel<String,String>>.init(configureCell: { (datasource, tableView, indexPath, item)  in
//
//            let cell = tableView.dequeueReusableCell(for: indexPath, cellType: TitleSwitchCell.self)
//
//            cell.label.text = "indexPath: \(indexPath.row) item:\(item)"
//
//            return cell
//        })
//
//        // 设置分区头标题
//        dataSource.titleForHeaderInSection = { ds, index in
//            return ds.sectionModels[index].model
//        }
//
//        // 绑定单元数据
//        items.bind(to: tableView.rx.items(dataSource: dataSource)).disposed(by: rx.disposeBag)
         /**************************** 多分区自带 section end **********************************/
        
        
        /**************************** 自定义多分区 section begin **********************************/
//        //初始化数据
//        let sections = Observable.just([
//            TDSection(header: "基本控件", items: [
//                "UILable的用法",
//                "UIText的用法",
//                "UIButton的用法"
//                ]),
//            TDSection(header: "高级控件", items: [
//                "UITableView的用法",
//                "UICollectionViews的用法"
//                ])
//            ])
//
//        //创建数据源
//        let dataSource = RxTableViewSectionedReloadDataSource<TDSection>(
//            //设置单元格
//            configureCell: { dataSource, tableView, indexPath, item in
//
//                let cell = tableView.dequeueReusableCell(for: indexPath, cellType: TitleSwitchCell.self)
//
//                cell.label.text = "\(indexPath.row)：\(item)"
//
//                return cell
//            },
//            //设置分区头标题
//            titleForHeaderInSection: { ds, index in
//                return ds.sectionModels[index].header
//            }
//        )
//
//        //绑定单元格数据
//        sections
//            .bind(to: tableView.rx.items(dataSource: dataSource))
//            .disposed(by: rx.disposeBag)
        /**************************** 自定义多分区 section end **********************************/
     
        
        /**************************** 多种样式 cell  begin **********************************/
        
        //初始化数据
//        let sections = Observable.just([
//            MutiSection(header: "第一个分区", items: [
//                .TitleImageSectionItem(title: "图片1", image: UIImage(named: "a")!),
//                .TitleImageSectionItem(title: "图片2", image: UIImage(named: "b")!),
//                .TitleSwitchSectionItem(title: "开关1", enabled: true)
//
//            ]),
//            MutiSection(header: "第二个分区", items: [
//                .TitleSwitchSectionItem(title: "开光2", enabled: true),
//                .TitleImageSectionItem(title: "图片3", image: UIImage(named: "a")!),
//                .TitleImageSectionItem(title: "图片4", image: UIImage(named: "b")!)
//            ])
//        ])
//
//        // 创建数据源
//        dataSource = RxTableViewSectionedReloadDataSource<MutiSection>(
//            configureCell: { datasource, tableView, indexPath, item in
//            switch datasource[indexPath] {
//                case let .TitleImageSectionItem(title, image):
//                    let cell = tableView.dequeueReusableCell(for: indexPath, cellType: TitleImageCell.self)
//                    cell.label.text = title
//                    cell.icon.image = image
//                    return cell
//
//                case let .TitleSwitchSectionItem(title, enabled):
//                    let cell = tableView.dequeueReusableCell(for: indexPath, cellType: TitleSwitchCell.self)
//                    cell.label.text = title
//                    cell.s.isOn = enabled
//                    return cell
//                }
//            },
//             // 设置分区头标题
//            titleForHeaderInSection: {
//                ds,index in
//                return ds.sectionModels[index].header
//            }
//
//        )
//
//        // 绑定单元格数据
//        sections.bind(to: tableView.rx.items(dataSource: dataSource!)).disposed(by: rx.disposeBag)
//
//
//        // 设置代理
//        tableView.rx.setDelegate(self).disposed(by: rx.disposeBag)
        
        /**************************** 多种样式 cell  end **********************************/
    }

}

extension ViewController : UITableViewDelegate {
    //设置单元格高度
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath)
        -> CGFloat {
       
        return 60
    }
    
    //返回分区头部视图
   func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int)
       -> UIView? {
       let headerView = UIView()
       headerView.backgroundColor = UIColor.black
       let titleLabel = UILabel()
       titleLabel.text = self.dataSource?[section].header
       titleLabel.textColor = UIColor.white
       titleLabel.sizeToFit()
       titleLabel.center = CGPoint(x: self.view.frame.width/2, y: 20)
       headerView.addSubview(titleLabel)
       return headerView
   }
    
   //返回分区头部高度
   func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int)
       -> CGFloat {
       return 40
   }
    
}

/// 多样式cell 使用
// 单元格类型
enum SectionItem {
    case TitleImageSectionItem(title:String,image:UIImage)
    case TitleSwitchSectionItem(title:String,enabled:Bool)
}

//自定义 Section
struct MutiSection {
    var header:String
    var items:[SectionItem]
}

extension MutiSection : SectionModelType {
    typealias Item = SectionItem
    
    init(original: Self, items: [Self.Item]) {
        self = original
        self.items = items
    }
}
