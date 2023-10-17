//
//  ViewController.m
//  画板
//
//  Created by WTW on 2020/1/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "DrawView.h"
#import "CoverView.h"


@interface ViewController ()<UIImagePickerControllerDelegate,UINavigationControllerDelegate>

@property (weak, nonatomic) IBOutlet DrawView *DrawView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
        
}

// 清屏
- (IBAction)cls:(UIBarButtonItem *)sender {
    [self.DrawView cls];
}
// 撤销
- (IBAction)undo:(UIBarButtonItem *)sender {
    [self.DrawView undo];
}
// 擦除
- (IBAction)erase:(UIBarButtonItem *)sender {
    [self.DrawView erase];
}
// 选择线宽
- (IBAction)slider:(UISlider *)sender {
    [self.DrawView setLineWidth:sender.value];
}
// 选择颜色
- (IBAction)setLineColor:(UIButton *)sender {
    [self.DrawView  setLineColor:sender.backgroundColor];
}

// 照片
- (IBAction)photo:(UIBarButtonItem *)sender {
    // 从系统相册中读取图片
    // 1、弹出系统相册
    UIImagePickerController *pickVc = [[UIImagePickerController alloc] init];
    pickVc.sourceType = UIImagePickerControllerSourceTypeSavedPhotosAlbum;
    pickVc.delegate = self;
    [self presentViewController:pickVc animated:YES completion:nil];
    //
    
}
// 保存
- (IBAction)save:(UIBarButtonItem *)sender {
    // 把绘制的东西保存到系统相册
    // 1、开启一个位图上下文
    UIGraphicsBeginImageContextWithOptions(self.DrawView.bounds.size,
                                           NO,
                                           0);
    
    // 2、把上下文内容绘制到上下文当中
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    [self.DrawView.layer renderInContext:ctx];
    
    // 3、从上下文中取出图片
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    
    // 4、关闭上下文
    UIGraphicsEndImageContext();
    
    // 5、把图片保存到系统相册
    UIImageWriteToSavedPhotosAlbum(image,
                                   self,
                                   @selector(image:didFinishSavingWithError:contextInfo:),
                                   nil);
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    NSLog(@"保存成功");
}

#pragma mark - UIImagePickerControllerDelegate

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<UIImagePickerControllerInfoKey,id> *)info {
    NSLog(@"%@",info);
    
    UIImage *image = info[UIImagePickerControllerOriginalImage];
    
//    NSData *data = UIImagePNGRepresentation(image);
//    [data writeToFile:@"/Users/wtw/Desktop/aaa.png" atomically:YES];
    
//    NSData *data = UIImageJPEGRepresentation(image, 1);
//    [data writeToFile:@"/Users/wtw/Desktop/aaa.jpg" atomically:YES];
    
    // 蒙一个 View 做缩放/旋转/长按操作
    CoverView *coverView = [[CoverView alloc] initWithFrame:self.DrawView.frame];
    coverView.backgroundColor = [UIColor clearColor];
    coverView.image = image;
    [self.view addSubview:coverView];
    
    coverView.handleImageBlcok = ^(UIImage * _Nonnull image) {
        self.DrawView.image = image;
    };
    
    [self dismissViewControllerAnimated:YES completion:nil];
}

// 隐藏状态栏
- (BOOL)prefersStatusBarHidden {
    return YES;
}

@end
