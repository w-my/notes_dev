//
//  ViewController.m
//  CoreAnimation
//
//  Created by wtw on 2019/1/7.
//  Copyright © 2019 wtw. All rights reserved.
//

/**
  // 以文本的形式打印出视图的层次结构
  po [[UIWindow keyWindow] recursiveDescription]
 
          <UIWindow: 0x7fca37608470; frame = (0 0; 414 736); gestureRecognizers = <NSArray: 0x600001c68150>; layer = <UIWindowLayer: 0x60000121a5e0>>
            | <UITransitionView: 0x7fca3750c8a0; frame = (0 0; 414 736); autoresize = W+H; layer = <CALayer: 0x6000012111e0>>
            |    | <UIDropShadowView: 0x7fca37508640; frame = (0 0; 414 736); autoresize = W+H; layer = <CALayer: 0x6000012115a0>>
            |    |    | <UIView: 0x7fca3750b4f0; frame = (0 0; 414 736); autoresize = W+H; layer = <CALayer: 0x600001211260>>
            |    |    |    | <UIView: 0x7fca3750a460; frame = (0 40; 320 568); clipsToBounds = YES; layer = <CALayer: 0x6000012110c0>>
            |    |    |    |    | <UIView: 0x7fca37609bd0; frame = (40 40; 100 100); layer = <CALayer: 0x60000121b1e0>>
 // 检查视图控制器层级
 po [[[UIWindow keyWindow] rootViewController] _printHierarchy]
 
        <ViewController 0x7fca37607f20>, state: appeared, view: <UIView 0x7fca3750b4f0>
 
 // 打印 view 的层级
 po [[self view] recursiveDescription]
         <UIView: 0x7fb588c0b820; frame = (0 0; 414 736); autoresize = W+H; layer = <CALayer: 0x600001cc4e80>>         // self.vew
            | <UIView: 0x7fb588e07f70; frame = (0 40; 320 568); layer = <CALayer: 0x600001ccd880>>                               // greenView
            |    | <UIView: 0x7fb588f081a0; frame = (40 40; 100 100); layer = <CALayer: 0x600001cc1200>>                        // redView

 po [self view]
        <UIView: 0x7fb588c0b820; frame = (0 0; 414 736); autoresize = W+H; layer = <CALayer: 0x600001cc4e80>>

 po self
        <ViewController: 0x7fb588c08c50>
 */

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIView *greenView = [[UIView alloc] initWithFrame:CGRectMake(0, 40, 320, 568)];
    greenView.backgroundColor = [UIColor greenColor];
    [self.view addSubview:greenView];
    
    NSLog(@"%@ =11= %@",greenView.backgroundColor,greenView.layer.backgroundColor);  // UIExtendedSRGBColorSpace 0 1 0 1   ( 0 1 0 1 )
    
    greenView.layer.backgroundColor = [UIColor yellowColor].CGColor;
    
    NSLog(@"%@ =22= %@",greenView.backgroundColor,greenView.layer.backgroundColor);  // UIExtendedSRGBColorSpace 1 1 0 1   ( 1 1 0 1 )
    
    UIView *redView = [[UIView alloc] initWithFrame:CGRectMake(40, 40, 100, 100)];
    redView.backgroundColor = [UIColor redColor];
    [greenView addSubview:redView];
    
//    redView.layer.borderColor = [UIColor yellowColor].CGColor;
//    redView.layer.borderWidth = 20;
//    redView.layer.shadowOffset = CGSizeMake(20, 20);
    
    redView.layer.shadowColor = [UIColor whiteColor].CGColor;
    redView.layer.shadowRadius = 20;
    redView.layer.shadowOpacity = 1;
    
    CGMutablePathRef refPath = CGPathCreateMutable();
    CGPathAddRect(refPath, NULL, CGRectMake(0, 0, 150, 150));
    redView.layer.shadowPath = refPath;
    CGPathRelease(refPath);

    CALayer *masklayer = [CALayer layer];
    masklayer.frame = CGRectMake(0, 0, 80, 80);
    
    greenView.layer.cornerRadius  = 20;
    greenView.layer.masksToBounds = YES;
    
    
    NSLog(@"%@",NSStringFromCGRect(self.view.frame));
    NSLog(@"\n scale == %f \n nativeScale == %f \n bounds == %@  \n nativeBounds == %@", [UIScreen mainScreen].scale,[UIScreen mainScreen].nativeScale , NSStringFromCGRect([UIScreen mainScreen].bounds), NSStringFromCGRect([UIScreen mainScreen].nativeBounds));
    
    
    //x max 414 896
    /*
     scale == 3.000000
     nativeScale == 3.000000
     bounds == {{0, 0}, {414, 896}}
     nativeBounds == {{0, 0}, {1242, 2688}}
     */
    
    //se 320 568
    /*
     scale == 2.000000
     nativeScale == 2.000000
     bounds == {{0, 0}, {320, 568}}
     nativeBounds == {{0, 0}, {640, 1136}}
     */
    
}


@end
