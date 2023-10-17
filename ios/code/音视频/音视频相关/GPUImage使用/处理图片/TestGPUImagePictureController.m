//
//  TestGPUImagePictureController.m
//  GPUImage使用
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.

//  GPUImage 处理图片 (图片滤镜基本使用)

#import "TestGPUImagePictureController.h"
#import <GPUImage/GPUImage.h>

#define K_WIDTH [UIScreen mainScreen].bounds.size.width

@interface TestGPUImagePictureController ()

@property (nonatomic,strong) UIImageView *imageView;

@end

@implementation TestGPUImagePictureController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view addSubview:self.imageView];
    
    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    //1、获取要修改的图片
    UIImage *image = [UIImage imageNamed:@"test"];
    
    // 2、创建用于处理单张图片
    GPUImagePicture *processImage =  [[GPUImagePicture alloc] initWithImage:image];
    
    // 3、创建滤镜
    // 高斯模糊
    GPUImageGaussianBlurFilter *blurFilter = [[GPUImageGaussianBlurFilter alloc] init];
    // 处理纹理
    // 模糊的强度，数值越大，模糊效果越明显
    blurFilter.texelSpacingMultiplier = 2.0;
    // 像素范围，用于计算平均值
    blurFilter.blurRadiusInPixels = 5.0;
    [processImage addTarget:blurFilter];
    
    //局部模糊
//        GPUImageGaussianSelectiveBlurFilter *blurFilter = [[GPUImageGaussianSelectiveBlurFilter alloc]init ];
//
//        blurFilter.excludeBlurSize = 0.5;      // 清晰区域的大小
//        blurFilter.blurRadiusInPixels = 5;    // 清晰区域外的模糊程度，同 GPUImageGaussianBlurFilter
//        blurFilter.excludeCirclePoint = CGPointMake(0.5, 0.5);     // 清晰区域的中心坐标
//        blurFilter.excludeCircleRadius = 0.8;  // 清晰区域的半径
//        blurFilter.aspectRatio = 3;
//        [blurFilter forceProcessingAtSize:CGSizeMake(200, 200)];
//        [processImage addTarget:blurFilter];
    
    // 4、处理图片
    [blurFilter useNextFrameForImageCapture];
    [processImage processImage];
    
    // 5、获取最新的图片
    UIImage *newImage = [blurFilter imageFromCurrentFramebuffer];
    
    // 显示处理后的图片
    self.imageView.image = newImage;
}

- (UIImageView *)imageView {
    if (!_imageView) {
        _imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, K_WIDTH, 500)];
        _imageView.image = [UIImage imageNamed:@"test"];
    }
    return _imageView;
}


@end
