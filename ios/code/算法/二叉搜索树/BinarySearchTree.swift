//
//  BinarySearchTree.swift
//  二叉搜索树
//
//  Created by WTW on 2020/4/7.
//  Copyright © 2020 wtw. All rights reserved.
//

/*
 时间复杂度 O(h) == O(logn)
 最坏时间复杂度 O(n) （效率和链表一样）
 防止退化成链表，让他始终维持在 O(logn)级别 最好是用平衡二叉树
 */

import UIKit

class BinarySearchTree: NSObject {

    var size : Int = 0
    var root : Node?
    
    // 大小
    func Size() -> Int {
        return size
    }
    
    // 清空
    func clear() {
        root = nil
        size = 0
    }
    
    // 是否为空
    func isEmpty() -> Bool {
        return size == 0
    }
    
    // 是否包含元素
    func contains(element : Int) -> Bool {
        return node(element: element) != nil
    }
    
    //MARK: 添加元素
    /*
     找到父节点 parent
     创建新节点 newNode
     parent.left = newNode  或者 parent.right = newNode
     */
    func add(element : Int)  {
        
        // 根节点为空，那就是空树，先创建根节点
        if root == nil {
            root = Node(element: element)
            size += 1
            return
        }
        
        // 添加的不是第一个节点
        var node : Node? = root  // 先拿到根节点
        var parent : Node? = root // 临时变量父节点，默认一开始是根节点
        var cmp = 0
        
        // 先找到父结点
        while node != nil {
            // 比较父节点和当前值的大小
            cmp = compare(element1: element, element2: node!.element)
            parent = node
            if cmp > 0   {  // 如果传入的元素比根结点的值大，那就让根节点等于它的右节点，然后循环
                node = node!.right
            }else if cmp < 0 {  // 如果传入的元素比根节点小，那就让根节点等于它的左结点，然后循环
                node = node!.left
            }else {  // 相等
                node?.element = element  // 相等就覆盖
                return
            }
        }
        
        // 看看插入父节点的哪个位置
        let newNode = Node(element: element, parent: parent!)
        if cmp > 0 {
            parent?.right = newNode
        }else {
            parent?.left = newNode
        }
        size += 1
    }
    
    // 0 相等 大于0 e1>e2 小于0 e1 < e2
    private func compare(element1 : Int,element2 : Int) -> Int {
        return element1 - element2;
    }
    
    //MARK: 删除元素
    func remove(element : Int)  {
        var n = node(element: element)
        remove(node: &n)
    }
    
    private func remove(node :inout  Node?)  {
        if node == nil { return }
        size -= 1
            
        // 度为 2 的情况 (只需要找到后继)
        if node?.left != nil && node?.right != nil {
            // 找到后继节点
            let s = successor(node: node)
            // 用后继节点的值覆盖度为 2 的节点的值
            node?.element = s!.element
            // 删除后继结点
            node = s
        }
        
        // 删除 node 节点 (node 的度必然是1或者0)
        let replacement = node?.left != nil ? node?.left : node?.right
        if replacement != nil { // node 是度为1的节点
            //更改 parent
            replacement?.parent = node?.parent
            //更改 parent 的 left 和 right 的指向
            if node?.parent == nil {
                root = replacement
            }else if node == node?.parent?.left {
                node?.parent?.left = replacement
            }else if node == node?.parent?.right {
                node?.parent?.right = replacement
            }
        }else if node?.parent == nil{ // 是叶子节点,且是根节点
             root = nil
        }else {  // 是叶子节点，不是根节点
            if node == node?.parent?.right{
                node?.parent?.right = nil
            }else {
                node?.parent?.left = nil
            }
        }
        
        
    }
    
    // 根据元素返回节点
    private func node(element : Int) -> Node? {
        var node = root
        while node != nil {
            if node?.element == element { // 相等
               return node
            }else if node!.element < element {  // 右子树
                node = node?.right
            }else {  // 左子树
                node = node?.left
            }
        }
        return nil
    }
    
    //MARK:二叉树的高度
    // 递归方式计算二叉树的高度
    func height() -> Int {
        return height(node: root)
    }
    private func height(node : Node?) ->Int{  // 递归方式计算
        if node == nil { return 0 }
        return  1 + max(height(node: node?.left), height(node:node?.right))
    }
    
    //非递归方式计算二叉树高度
    func height2() -> Int {
        height2(node: root)
    }
    /*
     每当每一层最后一个元素访问完，队列的长度就是下一层元素的个数
     */
    private func height2(node : Node?) -> Int {
        if node == nil { return 0 }
        
        var height : Int = 0  // 树的高度
        
        var levelSize = 1  // 队列的长度
        
        var queue = [Node]() // 创建数组(队列)
        queue.append(root!) // 先把根节点入队
        
        while queue.count > 0 {
            let node = queue.first!  // 取出队首元素 并打印，然后删除
//            print(node.element)
            queue.removeFirst()
            
            levelSize -= 1
            
            // 如果左节点不为空，入队
            if node.left != nil {
                queue.append(node.left!)
            }
            
            // 如果右节点不为空，入队
            if node.right != nil {
                queue.append(node.right!)
            }
            
            if levelSize == 0 {  // 当每一层元素访问完了，就让height + 1  ,重新开始新的一层
                levelSize = queue.count  //  levelSize 等于新的一层的元素的个数
                height += 1
            }
        }
        return height
    }
    
    //MARK: 判断一棵树是否为完全二叉树 (使用层序遍历)
    /*
     如果树为空，返回 false
     如果树不为空，开始层序遍历二叉树(用队列)
        如果 node.left!=null && node.right!=null，将 node.left, node.right 入队
        如果 node.left==null && node.right!=null，返回 false
        如果 node.left!=null && node.right==null 或者 node.left==null && node.right==null
            那么后面遍历的节点应该都为叶子节点，才是完全二叉树
            否则返回 false
     遍历结束，返回 true
     */
    func isComplete() -> Bool {
        if root == nil { return false }
        
        var queue = [Node]() // 创建数组(队列)
        queue.append(root!) // 先把根节点入队
        
        var leaf : Bool = false  // 标记是否是叶子结点
        
        while queue.count > 0 {
            let node = queue.first!
            queue.removeFirst()
            
            // 如果是叶子节点，且左右子树不为空 返回 false
            if leaf && node.left != nil && node.right != nil {
                return false
            }
            
            if node.left != nil {
                queue.append(node.left!)
            }else if node.right != nil{
                return false  // node.left == nil && node.right != nil
            }
                
            if node.right != nil {
                queue.append(node.right!)
            }else { // node.right == nil
                leaf = true
            }
        }
        return true
    }
    
    //MARK: 翻转二叉树 (226 - leetCode)
    // 哪一种遍历都可以
    func invertTree() -> Node {
        return invertTree(node: root)!
    }
    private func invertTree(node : Node?) -> Node? {
        if node == nil { return root }
        
        // 交换 (先序遍历)
        let temp = node?.left
        node?.left = node?.right
        node?.right = temp
     
        invertTree(node: node?.left)
        invertTree(node: node?.right)
        
        return root
    }
    
    
    //MARK: 遍历二叉树
    // 先序遍历  (可以用来树状结构的展示)
    /*
     先访问根节点，再访问左子树，再访问右子树
     */
    func preorderTraversal() {
        preorderTraversal(node: root!)
    }
    private func preorderTraversal(node : Node?) {
        if node == nil { return }
        
        print(node!.element)
        preorderTraversal(node: node?.left)
        preorderTraversal(node: node?.right)
    }
    
    // 中序遍历
    /*
     先访问左子树，再访问根节点，再访问右子树
     */
    func inorderTraversal() {
        inorderTraversal(node: root)
    }
    private func inorderTraversal(node : Node?) {
        if node == nil { return }
        
        inorderTraversal(node: node?.left)
        print(node!.element)
        inorderTraversal(node: node?.right)
    }
    
    // 后序遍历
    /*
     先访问左子树再访问右子树，最后访问根节点
     */
    func postorderTraversal() {
       postorderTraversal(node: root)
   }
   private func postorderTraversal(node : Node?) {
       if node == nil { return }
       
       postorderTraversal(node: node?.left)
       postorderTraversal(node: node?.right)
       print(node!.element)
   }
    
    // 层序遍历  (可以用来计算二叉树的高度，或者判断一棵树是否问完全二叉树)
    /*
     1、将根结点入队
     2、循环执行以下操作，直到队列为空
        将队头节点A出队，进行访问
        将A的左子节点入队
        将A的右子节点入队
     */
    func levelOrderTranverasl() {
        levelOrderTranverasl(node: root)
    }
    private func levelOrderTranverasl(node : Node?) {
        if node == nil { return }
        
        var queue = [Node]() // 创建数组(队列)
        queue.append(root!) // 先把根节点入队
        
        while queue.count > 0 {
            let node = queue.first!  // 取出队首元素 并打印，然后删除
            print(node.element)
            queue.removeFirst()
            
            // 如果左节点不为空，入队
            if node.left != nil {
                queue.append(node.left!)
            }
            
            // 如果右节点不为空，入队
            if node.right != nil {
                queue.append(node.right!)
            }
        }
    }
    
    
    //MARK: 前驱节点：(中序遍历的前一个节点)
    func precursor(node : Node?) -> Node? {
        if node == nil {return nil}
        
        // 前驱节点在左子树当中(找右子树的右子树)
        var p = node?.left
        if node?.left != nil {
            while p?.right != nil {
                p = p?.right
            }
            return p
        }
        
        // 从父节点、祖父节点中寻找前驱节点
        while node?.parent != nil && node == node?.parent?.left {
            node == node?.parent
        }
        return node?.parent
    }
    
    //MARK: 后继节点 (中序遍历的后一个节点)
    func successor(node : Node?) -> Node? {
        if node == nil {return nil}
        
        var p = node?.right
        if node?.right != nil {
            while p?.left != nil {
                p = p?.left
            }
            return p
        }
        
        while node?.parent != nil && node == node?.parent?.right {
            node == node?.parent
        }
        return node?.parent
    }
}

// 节点 Node 类
class Node : NSObject {
    var element : Int  // 节点的值
    var left : Node?   // 左节点
    var right : Node?  // 右节点
    var parent : Node?  // 父节点

    init(element : Int,parent : Node) {
        self.element = element
        self.parent = parent
    }
    
    init(element : Int) {
        self.element = element
    }
}


