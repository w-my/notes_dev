//
//  ViewController.m
//  NSURLSessionUploadTask
//
//  Created by WTW on 2019/12/2.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
<NSURLSessionDelegate,
NSURLSessionTaskDelegate>

@property (nonatomic,strong) NSURLSession *session;
@property (nonatomic,strong) NSURLSessionUploadTask *uploadTask;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {

    [self uploadTaskTest];
}

/**
 *  上传数据的时候，一般要使用REST API里的PUT或者POST方法,需要通过 NSMutableURLRequest来设置一些HTTP配置信息：
 *  timeoutInterval //timeout的时间间隔
 *  HTTPMethod //HTTP方法
 *  //设置HTTP表头信息
 *  – addValue:forHTTPHeaderField:
 *  – setValue:forHTTPHeaderField:
 *
 *  三种上传数据的方式：
 *  1、NSData  对象已经在内存中
 *  uploadTaskWithRequest:fromData:
 *  uploadTaskWithRequest:fromData:completionHandler:
 *
 *  Session会自动计算Content－length的Header
 *  通常，还需要提供一些服务器需要的Header，Content－Type就往往需要提供
 *
 * 2、File 对象在磁盘上，这样做有助于降低内存使用
 * uploadTaskWithRequest:fromFile:
 * uploadTaskWithRequest:fromFile:completionHandler:
 *
 * 会自动计算Content－Length,如果App没有提供Content-Type,Session会自动创建一个。如果Server需要额外的Header信息，也要提供。
 *
 * 3、Stream
 * uploadTaskWithStreamedRequest:
 * 使用Stream一定要实现这个代理方法，因为Session没办法在重新尝试发送Stream的时候找到数据源。（例如需要授权信息的情况）。这个代理函数，提供了Stream的数据源
 * URLSession:task:needNewBodyStream:
 *
 * 获取上传进度的代理方法
 * -(void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend；
 */

- (void)uploadTaskTest {
    
     //1、创建NSURLSessionConfiguration类的对象, 这个对象被用于创建NSURLSession类的对象
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        
        //2、创建 NSUrlSession 对象
        // delegateQueue : [NSOperationQueue mainQueue] 代理的消息都会在主线程中收到
        self.session = [NSURLSession sessionWithConfiguration:configuration delegate:self delegateQueue:[NSOperationQueue mainQueue]];
        
        //3、创建 URL
        NSURL *uploadUrl = [NSURL URLWithString:@"http://www.freeimagehosting.net/upload.php"];
        
        //4、创建 request
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:uploadUrl];
        
        // 上传数据方式
//        [request addValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
//        [request addValue:@"application/json" forHTTPHeaderField:@"Accept"];
    
        // 上传图片方式
        [request addValue:@"image/jpeg" forHTTPHeaderField:@"Content-Type"];
        [request addValue:@"text/html" forHTTPHeaderField:@"Accept"];
    
        // 设置请求方式
        [request setHTTPMethod:@"POST"];
    
        [request setCachePolicy:NSURLRequestReloadIgnoringCacheData];
        [request setTimeoutInterval:15];

         // 待上传的数据 (请求体)
         NSData * imagedata = UIImagePNGRepresentation([UIImage imageNamed:@"th"]);
    
        // 5、创建数据类型任务
    //    // block 方式  不关注过程只关注结果
        self.uploadTask = [self.session uploadTaskWithRequest:request
                                                     fromData:imagedata
                                            completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
            // 解析数据
            NSString * htmlString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSLog(@"%@",htmlString);
        }];
          // 开始任务
        [self.uploadTask resume];
      
   
        // 通过代理方式   可以详细看到全过程，需要实现代理方法
//        self.uploadTask = [self.session uploadTaskWithStreamedRequest:request];
//
//        // 6、 开始任务
//        [self.uploadTask resume];
        
        // 7、任务完成之后 session 销毁
        [self.session finishTasksAndInvalidate];
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
         didSendBodyData:(int64_t)bytesSent
          totalBytesSent:(int64_t)totalBytesSent
totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend {
    
    NSLog(@"bytesSent: %lld totalBytesSent: %lld totalBytesExpectedToSend: %lld",bytesSent,totalBytesSent,totalBytesExpectedToSend);
    
}

@end
