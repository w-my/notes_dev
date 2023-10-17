//
//  ViewController.m
//  NSURLSessionDataTask
//
//  Created by WTW on 2019/12/2.
//  Copyright © 2019 WTW. All rights reserved.
//

// 基于 NSURLSessionDataTask 支持离线断点续传的下载

#import "ViewController.h"

@interface ViewController ()<
NSURLSessionTaskDelegate,
NSURLSessionDataDelegate>

@property (weak, nonatomic) IBOutlet UIProgressView *progressView;

@property (nonatomic,strong) NSURLSession *session;
@property (nonatomic,strong) NSURLSessionDataTask *dataTask;

// 文件句柄
@property (nonatomic,strong) NSFileHandle *handle;
@property (nonatomic,assign) NSInteger currentSize;
@property (nonatomic,assign) NSInteger totalSize;

@property (nonatomic,copy) NSString *fullPath;

@end

#define FilePathName @"testFilePath"

@implementation ViewController

- (NSString *)fullPath {
    if (!_fullPath) {
        _fullPath = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]stringByAppendingPathComponent:FilePathName];
    }
    return _fullPath;
}

- (NSURLSession *)session {
    if (!_session) {
        //1、创建NSURLSessionConfiguration类的对象, 这个对象被用于创建NSURLSession类的对象
        NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
        
        //2、创建 NSUrlSession 对象
        _session = [NSURLSession sessionWithConfiguration:configuration delegate:self delegateQueue:[NSOperationQueue mainQueue]];
    }
    return _session;
}

- (NSURLSessionDataTask *)dataTask {
    if (!_dataTask) {
        
        //3、创建 URL
        NSURL *picUrl = [NSURL URLWithString:@"https://nodejs.org/dist/v8.11.4/node-v8.11.4.pkg"];
        
        //4、创建 request
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:picUrl];
        
        // 获取指定文件路径对应的文件大小
        NSDictionary *fileInfo = [[NSFileManager defaultManager] attributesOfItemAtPath:self.fullPath error:nil];
        // 当前本地已经下载缓存的文件大小
        self.currentSize = [[fileInfo objectForKey:@"NSFileSize"] integerValue];
        
//        NSLog(@"fileInfo == %@",fileInfo);
        /* fileInfo :
         NSFileCreationDate = "2020-02-11 13:19:05 +0000";
         NSFileExtensionHidden = 0;
         NSFileGroupOwnerAccountID = 20;
         NSFileGroupOwnerAccountName = staff;
         NSFileModificationDate = "2020-02-11 13:19:15 +0000";
         NSFileOwnerAccountID = 501;
         NSFilePosixPermissions = 420;
         NSFileReferenceCount = 1;
         NSFileSize = 1086731;  // 主要是获取已经下载的文件的大小
         NSFileSystemFileNumber = 30984788;
         NSFileSystemNumber = 16777220;
         NSFileType = NSFileTypeRegular;
         */
        
        // 设置请求头信息，告诉服务器请求哪一部分数据 (本地已经有的数据就不再下载)
        NSString *range = [NSString stringWithFormat:@"bytes=%zd-",self.currentSize];
        [request setValue:range forHTTPHeaderField:@"Range"];
        
        // 通过代理方式   可以详细看到全过程，需要实现代理方法
        _dataTask = [self.session dataTaskWithRequest:request];
    }
    return _dataTask;
}

- (IBAction)startClick {
    NSLog(@"%s",__func__);
   [self.dataTask resume];
}

// 该取消是不可恢复的 dataTask只要这一种取消
- (IBAction)cancelClick {
    NSLog(@"%s",__func__);
    [self.dataTask cancel];
    // 每次取消的时候，task 清空，保证下次走懒加载的时候，根据当前的大小设置请求头进行续传
    self.dataTask = nil;
}
- (IBAction)suspendClick {
    NSLog(@"%s",__func__);
    [self.dataTask suspend];
}
- (IBAction)resumeClick{
    NSLog(@"%s",__func__);
    [self.dataTask resume];
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

#pragma mark - NSURLSessionTaskDelegate

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
willBeginDelayedRequest:(NSURLRequest *)request
 completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition disposition, NSURLRequest * _Nullable newRequest))completionHandler{
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                                didSendBodyData:(int64_t)bytesSent
                                 totalBytesSent:(int64_t)totalBytesSent
totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend {
      NSLog(@"%s",__func__);
}

// 告诉delegate, task已经完成
- (void)URLSession:(NSURLSession *)session
                                    task:(NSURLSessionTask *)task
                    didCompleteWithError:(nullable NSError *)error{
    
    NSLog(@"%s",__func__);
        
    [self.handle closeFile];
    self.handle = nil;
        
}

#pragma mark - NSURLSessionDataDelegate
                     
//告诉delegate已经接受到服务器的初始应答, 准备接下来的数据任务的操作
- (void)URLSession:(NSURLSession *)session
          dataTask:(NSURLSessionDataTask *)dataTask
didReceiveResponse:(NSURLResponse *)response
 completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler {
    
    // 获得文件的总大下
    // 加当前的大小是为了续传的时候 不然会计算错误
    self.totalSize = response.expectedContentLength + self.currentSize;
    
    // 使用文件句柄的方式
    // 获取文件全路径
//    NSString *fullPath = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]stringByAppendingPathComponent:response.suggestedFilename];
    
    if (self.currentSize == 0) {
        // 创建空的文件 只有第一次开始下载的时候才创建，续传的时候不需要重新创建 ，不然会数据大小对不上
        [[NSFileManager defaultManager] createFileAtPath:self.fullPath contents:nil attributes:nil];
    }
    
    // 创建文件句柄
    self.handle = [NSFileHandle fileHandleForWritingAtPath:self.fullPath];
    
    // 移动指针
    [self.handle seekToEndOfFile];
    
    // 一般 data 任务 让任务继续正常运行(如果没有这行代码，将不会执行下面的代理方法)
    completionHandler(NSURLSessionResponseAllow);
}
                     
/*
* 每收到一次 Data 时候调用(数据是分段接收的)
*/
- (void)URLSession:(NSURLSession *)session
          dataTask:(NSURLSessionDataTask *)dataTask
    didReceiveData:(NSData *)data {
    
    // 写入数据到文件
    [self.handle writeData:data];
    
    // 计算文件的下载进度
    self.currentSize += data.length;
    self.progressView.progress = 1.0 * self.currentSize / self.totalSize;
    NSLog(@"%s == %f",__func__,1.0 * self.currentSize / self.totalSize);
}
              
/*
* 是否把 Response 存储到 Cache 中
*/
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                  willCacheResponse:(NSCachedURLResponse *)proposedResponse
 completionHandler:(void (^)(NSCachedURLResponse * _Nullable cachedResponse))completionHandler {
      NSLog(@"%s",__func__);
}

@end
