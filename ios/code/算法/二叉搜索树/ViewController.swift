//
//  ViewController.swift
//  二叉搜索树
//
//  Created by WTW on 2020/4/7.
//  Copyright © 2020 wtw. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        /*
             4
           /   \
          2     7
         / \   / \
        1   3 6   9
        
         */
        
        
        let binaryTree  = BinarySearchTree()
        
        binaryTree.add(element: 4)
        binaryTree.add(element: 2)
        binaryTree.add(element: 7)
        binaryTree.add(element: 1)
        binaryTree.add(element: 3)
        binaryTree.add(element: 6)
        binaryTree.add(element: 9)
        
        // 先序
//        binaryTree.preorderTraversal()  // 4213769
        
        // 中序
        binaryTree.inorderTraversal()  // 1234679
        
        // 删除节点
        binaryTree.remove(element: 9)
        binaryTree.inorderTraversal()  // 1234679
        
        // 后序
//        binaryTree.postorderTraversal() // 1326974
        
        // 层序
//        binaryTree.levelOrderTranverasl() // 4271369
        
        // 计算树的高度
//        print(binaryTree.height())  // 3
//        print(binaryTree.height2()) // 3
        
        // 判断是否为完全二叉树
//        print(binaryTree.isComplete())  // true
        
        // 翻转二叉树
//        binaryTree.invertTree()
//        binaryTree.levelOrderTranverasl()  // 4729631
    }


}

