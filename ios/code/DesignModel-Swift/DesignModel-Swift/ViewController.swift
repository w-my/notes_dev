//
//  ViewController.swift
//  DesignModel-Swift
//
//  Created by WTW on 2020/11/21.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var totalStockLabel: UILabel!
    
    @IBOutlet weak var tableView: UITableView!
    
    var products = [
        ("Kayak","A boat for one person","Watersportes",275.0,10),
        ("Lifejacket","Protetive and fashionable","Watersportes",48.95,14),
        ("Soccer Ball","FIFA-approved size and weight","Soccer",19.5,32),
        ("Corner Flags","Give your playing field a professional touch","Soccer",34.95,1),
        ("Sradium","Flat-packed 35,000-seat stadium","Soccer", 79500.0,4)
    ]
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        displayStockTotal()
    }

    func displayStockTotal() {
        
        let stockTotal = products.reduce(0) { (total, product) -> Int in
            return total + product.4
        }
        
        totalStockLabel.text = "\(stockTotal) Products in Stock"
    }
    
    @IBAction func stockLevelDidChange(_ sender: Any) {
    
        if var currentCell = sender as? UIView{
            while true {
                currentCell = currentCell.superview!
                if let cell = currentCell as? ProductTableCell {
                    if let id = cell.productId {
                        var newStockLevel: Int?
                        
                        if let stepper = sender as? UIStepper {
                            newStockLevel = Int(stepper.value)
                        }else if let textfield = sender as? UITextField {
                            if let newValue = Int(textfield.text ?? "0") {
                                newStockLevel = newValue
                            }
                        }
                        if let level = newStockLevel {
                            products[id].4 = level
                            cell.stockStepper.value = Double(level)
                            cell.stockField.text = String(level)
                        }
                    }
                    break;
                }
            }
            
            displayStockTotal()
        }
    }
}

extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return products.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "ProductCell") as! ProductTableCell
        
        let product = products[indexPath.row]
        cell.productId = indexPath.row
        cell.nameLabel.text = product.0
        cell.descriptionLabel.text = product.1
        cell.stockStepper.value = Double(product.4)
        cell.stockField.text = String(product.4)
        return cell
    }
    
}
