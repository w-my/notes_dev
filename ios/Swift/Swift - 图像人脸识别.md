## Swift - 图像人脸识别

提取图片人脸居中显示
```swift
class func centerImageViewOnFace (_ imageView: UIImageView) {
    
    let context = CIContext(options: nil)
    let options = [CIDetectorAccuracy:CIDetectorAccuracyHigh]
    let detector = CIDetector(ofType: CIDetectorTypeFace, context: context, options: options)
    
    let faceImage = imageView.image
    let ciImage = CIImage(cgImage: faceImage!.cgImage!)
    
    let features = detector?.features(in: ciImage)
    
    if (features?.count)! > 0 {
        
        var face:CIFaceFeature!
        
        for rect in features! {
            face = rect as? CIFaceFeature
        }
        
        var faceRectWithExtendedBounds = face.bounds
        faceRectWithExtendedBounds.origin.x -= 20
        faceRectWithExtendedBounds.origin.y -= 30
        
        faceRectWithExtendedBounds.size.width += 40
        faceRectWithExtendedBounds.size.height += 60
        
        let x = faceRectWithExtendedBounds.origin.x / faceImage!.size.width
        let y = (faceImage!.size.height - faceRectWithExtendedBounds.origin.y - faceRectWithExtendedBounds.size.height) / faceImage!.size.height
        
        let widthFace = faceRectWithExtendedBounds.size.width / faceImage!.size.width
        let heightFace = faceRectWithExtendedBounds.size.height  / faceImage!.size.height
        
        imageView.layer.contentsRect = CGRect(x: x, y: y, width: widthFace, height: heightFace)
        
        
    }
}
```
