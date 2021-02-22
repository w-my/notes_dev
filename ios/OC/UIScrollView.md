##### 判断拖拽滚动方向

```objective-c
- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
	CGPoint vel = [scrollView.panGestureRecognizer velocityInView:scrollView];
	if (vel.y < -5) { // 向上拖动
		NSLog(@"向上拖动");
	}else if (vel.y > 5) { // 向下拖动
		NSLog(@"向下拖动");
	}else if (vel.y == 0) { // 停止拖拽
		NSLog(@"停止拖拽");
	}
}
```

