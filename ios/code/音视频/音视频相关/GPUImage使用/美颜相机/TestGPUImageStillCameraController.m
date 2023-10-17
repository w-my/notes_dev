//
//  TestGPUImageStillCameraController.m
//  GPUImage使用
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "TestGPUImageStillCameraController.h"
#import <GPUImage/GPUImage.h>

#define K_WIDTH [UIScreen mainScreen].bounds.size.width

/*
 // GPUImageStillCamera 相机 -> GPUImageBrightnessFilter 滤镜 -> GPUImageView 展示
 
 1、创建相机 (GPUImageStillCamera)
 2、创建滤镜(添加滤镜) GPUImagexxxxxFilter
 3、创建预览视图(GPUImageView)
 4、开始捕捉画面
 
 */

@interface TestGPUImageStillCameraController ()

// 美颜相机
@property (nonatomic,strong) GPUImageStillCamera *camera;
// 美颜相机滤镜
@property (nonatomic,strong) GPUImageBrightnessFilter * filter;
// 拍照照片展示
@property (nonatomic,strong) UIImageView *imageView;
@end

@implementation TestGPUImageStillCameraController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *button = [[UIButton alloc] init];
    [button setTitle:@"拍照" forState:UIControlStateNormal];
    button.frame = CGRectMake(100, 80, 100, 50);
    button.backgroundColor = [UIColor greenColor];
    [button addTarget:self action:@selector(takePhoto) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    
    self.imageView = [[UIImageView alloc] init];
    self.imageView.frame = CGRectMake(0, 520, 200, 200);
    [self.view addSubview:self.imageView];
    
    // 1、创建 GPUImageStillCamera 相机
    self.camera = [[GPUImageStillCamera alloc] initWithSessionPreset:AVCaptureSessionPreset640x480 cameraPosition:AVCaptureDevicePositionFront];
    self.camera.outputImageOrientation = UIInterfaceOrientationPortrait; // 设置相机的方向
    
    // 2、添加滤镜
    self.filter = [[GPUImageBrightnessFilter alloc] init];
    self.filter.brightness = 0.5;
    [self.camera addTarget:self.filter];
    
    //3、创建显示实时画面的View
    GPUImageView *showView = [[GPUImageView alloc] initWithFrame:CGRectMake(0, 120, K_WIDTH * 0.25, 100)];
    [self.filter addTarget:showView];
    [self.view addSubview:showView];
    
    GPUImageView *showView2 = [[GPUImageView alloc] initWithFrame:CGRectMake(K_WIDTH * 0.25, 120, K_WIDTH * 0.25, 100)];
    [self.filter addTarget:showView2];
    [self.view addSubview:showView2];
    
    GPUImageView *showView3 = [[GPUImageView alloc] initWithFrame:CGRectMake(K_WIDTH * 0.5, 120, K_WIDTH * 0.25, 100)];
    [self.filter addTarget:showView3];
    [self.view addSubview:showView3];
    
    GPUImageView *showView4 = [[GPUImageView alloc] initWithFrame:CGRectMake(K_WIDTH * 0.75, 120, K_WIDTH * 0.25, 100)];
    [self.filter addTarget:showView4];
    [self.view addSubview:showView4];
    
    // 4、开始捕捉画面
    [self.camera startCameraCapture];
}

// 拍照
- (void)takePhoto {
    [self.camera capturePhotoAsImageProcessedUpToFilter:self.filter withCompletionHandler:^(UIImage *processedImage, NSError *error) {
        self.imageView.image = processedImage;
        
        // 写入相册
        UIImageWriteToSavedPhotosAlbum(processedImage, self, @selector(image:didFinishSavingWithError:contextInfo:), NULL);
    }];
}

- (void) image: (UIImage *) image didFinishSavingWithError: (NSError *) error contextInfo: (void *) contextInfo {
    NSLog(@"写入相册成功");
}



@end
