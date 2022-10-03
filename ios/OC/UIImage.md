# UIImage

## UIImage 添加圆角

```objc
- (UIImage *)hyb_imageWithCornerRadius:(CGFloat)radius {
		CGRect rect = (CGRect){0.f, 0.f, self.size};
		UIGraphicsBeginImageContextWithOptions(self.size, NO, UIScreen.mainScreen.scale);
		CGContextAddPath(UIGraphicsGetCurrentContext(), 
    		[UIBezierPath bezierPathWithRoundedRect:rect cornerRadius:radius].CGPath);
		CGContextClip(UIGraphicsGetCurrentContext());
		[self drawInRect:rect];
		UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
		UIGraphicsEndImageContext();
		return image;
}
```

