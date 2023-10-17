//
//  ViewController.swift
//  CATiledLayer
//
//  Created by WTW on 2021/1/26.
//  Copyright © 2021 wtw. All rights reserved.
//


/**
    CATiledLayer
        对于需要绘制一个很大的图片时(比如高像素的地球表面详细图) 读取整个图片到内存是不明智的，载入的时候可能会很慢(在主线程调用UIImage的-imageNamed:方法或者-imageWithContentsOfFile:方法) 将会阻塞界面，至少会引起画面的卡顿。
 
        能高效绘制在 iOS 上的图片也有一个大小限制，所有显示在屏幕上的图片最终都会被转化为 OPenGL 纹理，同时 OPenGL 有一个最大的纹理尺寸(通常是 2048*2048 或 4096* 4096，这个取决于设备的型号)，如果想在一个纹理中显示一个比较大的图，即使图片已经存在于内存中，仍然会有很大的性能问题，因为 Core Animation 强制用 CPU 处理图片而不是更快的GPU
 
        CATiledLayer 为载入大图造成的性能问题提供了一个解决方案：将大图分解成小片(tile)然后将他们单独按需载入。
 
 */

import UIKit

class ViewController: UIViewController {

    lazy var scrollview: UIScrollView = {
        
        let scrollview = UIScrollView(frame: CGRect(x: 10, y: 100, width: UIScreen.main.bounds.size.width - 20, height: 400))
        scrollview.backgroundColor = .green
        scrollview.minimumZoomScale = 0.5
        scrollview.maximumZoomScale = 3
        return scrollview
    }()
    
    lazy var imageView: UIImageView = {
       
        let imageView = UIImageView()
        return imageView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.backgroundColor = .white
        
        view.addSubview(scrollview)
        scrollview.addSubview(imageView)
        
        let path = Bundle.main.path(forResource: "map_11935x8554", ofType: "jpg")
        
        let image = UIImage(contentsOfFile: path!)
        
        imageView.frame = CGRect(x: 0, y: 0, width: image!.size.width, height: image!.size.height)
        scrollview.contentSize = image!.size
        
        imageView.image = image
        
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        
    }
    
}

extension ViewController {
    
    
    // 裁剪图片成小图
    
    
    
    
    
}
