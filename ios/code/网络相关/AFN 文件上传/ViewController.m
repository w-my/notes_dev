//
//  ViewController.m
//  AFN 文件上传
//
//  Created by WTW on 2020/2/12.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import <AFNetworking/AFNetworking.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
//    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
//    NSURL *url = [NSURL URLWithString:@"http://www.freeimagehosting.net/upload.php"];
//    // 创建请求对象
//    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
//    // 设置请求方法
//    request.HTTPMethod = @"POST";
//    // 设置请求头信息
//    [request setValue:[NSString stringWithFormat:@"multipart/form-data;boundary=%@",@"111111111"] forHTTPHeaderField:@"Content-Type"];
//
//    NSData * imagedata = UIImagePNGRepresentation([UIImage imageNamed:@"Image"]);
//
//    NSURLSessionUploadTask *uploadTask = [manager uploadTaskWithRequest:request
//                          fromData:imagedata
//                          progress:^(NSProgress * _Nonnull uploadProgress) {
//
//    } completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
//
//    }];
//    [uploadTask resume];
        
    // 一般用post 这种
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    
    manager.requestSerializer = [AFHTTPRequestSerializer serializer];
    manager.responseSerializer = [AFHTTPResponseSerializer serializer];

    manager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"text/html",@"application/json",@"text/json",@"text/javascript",@"text/plain", nil];
    
    [manager POST:@"http://www.freeimagehosting.net/upload.php"
       parameters:nil
constructingBodyWithBlock:^(id<AFMultipartFormData>  _Nonnull formData) {
        
//        UIImage *image = [UIImage imageNamed:@"Image"];
//        NSData *imageData = UIImagePNGRepresentation(image);
        
        // 方式1
//        [formData appendPartWithFileData:imageData
//                                    name:@"file"
//                                fileName:@"fileName.png"
//                                mimeType:@"image/png"];
        
        // 方式2
//        [formData appendPartWithFileURL:[NSURL fileURLWithPath:@"/Users/wtw/Desktop/th.png"]
//                                   name:@"fileName"
//                                  error:nil];
        
        // 方式 3
        [formData appendPartWithFileURL:[NSURL fileURLWithPath:@"/Users/wtw/Desktop/th.png"]
                                   name:@"name"
                               fileName:@"fileName"
                               mimeType:@"image/png"
                                  error:nil];
        
    }
         progress:^(NSProgress * _Nonnull uploadProgress) {
        NSLog(@"上传进度: %f",1.0 * uploadProgress.completedUnitCount / uploadProgress.totalUnitCount);
    }
          success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        NSLog(@"success == %@",[[NSString alloc]initWithData: responseObject encoding:NSUTF8StringEncoding]);
    }
          failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        NSLog(@"failure == %@",error);
    }];
}


@end
