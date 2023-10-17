//
//  AsyncLabel.swift
//  UIView 的异步绘制
//
//  Created by WTW on 2020/3/25.
//  Copyright © 2020 wtw. All rights reserved.
//

import UIKit
import CoreText

class AsyncLabel: UIView {

    var asyncText : String?
    var asyncFont : UIFont = UIFont()
    var asyncBGColor : UIColor = UIColor()
    
    override func display(_ layer: CALayer) {
        // 除了 drawRect 方法中，其他地方需要 context 需要自己创建
        
        let size = self.bounds.size
        let scale = UIScreen.main.scale
        
        // 异步绘制
        DispatchQueue.global().async {
            
            UIGraphicsBeginImageContextWithOptions(size, false, scale)
            
            // 获取上下文
            let context = UIGraphicsGetCurrentContext()
           
            // 坐标系反转
            context?.textMatrix = CGAffineTransform.identity
            
            // 文本沿着Y轴移动
            context?.translateBy(x: 0, y: size.height)
            
            // 文本反转成context 坐标系
            context?.scaleBy(x: 1.0, y: -1.0)
            
            // 创建绘制区域
            let path = CGMutablePath()
            path.addRect(CGRect(x: 0, y: 0, width: size.width, height: size.height))
            
            // 创建需要绘制文字
            let attr = NSMutableAttributedString(attributedString: NSAttributedString(string: self.asyncText!))
            attr.addAttribute(NSAttributedString.Key.font, value: self.asyncFont, range: NSRange(location: 0, length:self.asyncText!.count))
            attr.addAttribute(NSAttributedString.Key.backgroundColor, value: self.asyncBGColor, range: NSRange(location: 0, length:self.asyncText!.count))
            
            // 根据attrStr 生成CTFramesetterRef
            let framesetter = CTFramesetterCreateWithAttributedString(attr)
            let frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, self.asyncText!.count), path, nil)
            
            // 将frame 的内容绘制到 context 中
            CTFrameDraw(frame, context!)

            let image = UIGraphicsGetImageFromCurrentImageContext()
            
            UIGraphicsEndImageContext()
            
            // 子线程完成工作，切换到主线程展示
            DispatchQueue.main.async {
                self.layer.contents = image?.cgImage
            }
        }
    }
}
