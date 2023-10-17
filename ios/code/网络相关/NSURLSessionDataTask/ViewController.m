//
//  ViewController.m
//  NSURLSessionDataTask
//
//  Created by WTW on 2019/12/2.
//  Copyright © 2019 WTW. All rights reserved.
//

/*
 此demo 包含:
 1、dataTask 数据的获取
 2、dataTask 转 download task
 */

#import "ViewController.h"

@interface ViewController ()<
NSURLSessionDelegate,
NSURLSessionTaskDelegate,
NSURLSessionDataDelegate,
NSURLSessionDownloadDelegate>

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UIProgressView *progressView;

@property (nonatomic,strong) NSURLSession *session;
@property (nonatomic,strong) NSURLSessionDataTask *dataTask;
@property (nonatomic,strong) NSMutableData *allData;

@end

@implementation ViewController

- (IBAction)cancelClick {
    switch (self.dataTask.state) {
            case NSURLSessionTaskStateRunning:
            case NSURLSessionTaskStateSuspended:
                [self.dataTask cancel];
                break;
            default:
                break;
        }
}
- (IBAction)suspendClick {
    if (self.dataTask.state == NSURLSessionTaskStateRunning) {
           [self.dataTask suspend];
       }
}
- (IBAction)resumeClick{
    if (self.dataTask.state == NSURLSessionTaskStateSuspended) {
           [self.dataTask resume];
       }
}
/**
 Task 是由 Session 创建，Session 会保持对 Task 的强引用，直到 Task 完成或者出错才会释放
 通过 NSURLSessionTask  可以获得 Task 的各种状态，以及对 Task 进行取消，挂起，继续等操作
 NSURLSessionTask
 NSURLSessionDataTask  NSURLSessionDownloadTask
 NSURLSessionUploadTask
 */

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.allData = [NSMutableData data];
    
    //1、创建NSURLSessionConfiguration类的对象, 这个对象被用于创建NSURLSession类的对象
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    
    //2、创建 NSUrlSession 对象
    // configuration 配置信息
    // delegate 代理
    // delegateQueue 设置代理方法在哪个线程执行
    self.session = [NSURLSession sessionWithConfiguration:configuration delegate:self delegateQueue:[NSOperationQueue mainQueue]];
    
    //3、创建 URL
    NSString *picStr =  @"http://lvzhushou.oss-cn-hangzhou.aliyuncs.com/2019-11-20/157422655747264393577b88ecabb76fe0924352c5_thumb.jpg?x-oss-process=style/thumb";
    NSURL *picUrl = [NSURL URLWithString:picStr];
    
    //4、创建 request
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:picUrl];
    
    // 5、创建数据类型任务
    // request请求方式为: GET. 如果是POST, 还需要设置HTTPBody属性
//    request.HTTPMethod = @"POST";
//    request.HTTPBody = [@"name=xxx&password=xxx" dataUsingEncoding:NSUTF8StringEncoding];
    
    // block 方式  不关注过程只关注结果
//    self.dataTask = [self.session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
//        if (!error) {
//            dispatch_async(dispatch_get_main_queue(), ^{ // 需要回到主线程更新UI
//                UIImage *image = [UIImage imageWithData:data];
//                self.imageView.image = image;
//            });
//        }
//    }];
//      // 开始任务
//    [self.dataTask resume];
    
    // 通过代理方式   可以详细看到全过程，需要实现代理方法 
    self.dataTask = [self.session dataTaskWithRequest:request];
    
    // 6、 开始任务
    [self.dataTask resume];
    
    // 7、任务完成之后 session 销毁 (不用的时候一定要释放，不然会有内存泄露，官方文档要求)
    [self.session finishTasksAndInvalidate];
    //[self.session invalidateAndCancel];
    
}

#pragma mark - NSURLSessionDelegate  处理Session 层次的事件

- (void)URLSession:(NSURLSession *)session didBecomeInvalidWithError:(nullable NSError *)error {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler{
      NSLog(@"%s",__func__);
}

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)session {
      NSLog(@"%s",__func__);
}

#pragma mark - NSURLSessionTaskDelegate  Messages related to the operation of a specific task

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
willBeginDelayedRequest:(NSURLRequest *)request
 completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition disposition, NSURLRequest * _Nullable newRequest))completionHandler{
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session taskIsWaitingForConnectivity:(NSURLSessionTask *)task {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
willPerformHTTPRedirection:(NSHTTPURLResponse *)response
                newRequest:(NSURLRequest *)request
 completionHandler:(void (^)(NSURLRequest * _Nullable))completionHandler {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
 needNewBodyStream:(void (^)(NSInputStream * _Nullable bodyStream))completionHandler {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                                didSendBodyData:(int64_t)bytesSent
                                 totalBytesSent:(int64_t)totalBytesSent
totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics {
      NSLog(@"%s",__func__);
}

// 告诉delegate, task已经完成
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
didCompleteWithError:(nullable NSError *)error{
    
    NSLog(@"%s",__func__);
    
    //一般 data 任务完成回调
//    NSError *err = nil;
//    id result = [NSJSONSerialization JSONObjectWithData:self.allData options:NSJSONReadingMutableContainers error:&err];
//    NSLog(@"%@",result);
    
//    dispatch_async(dispatch_get_main_queue(), ^{
//        UIImage *image = [UIImage imageWithData:self.allData];
//        self.imageView.image = image;
//        self.session = nil;
//        self.dataTask = nil;
//        NSLog(@"%@ %@",self.session,self.dataTask);
//    });
}

#pragma mark - NSURLSessionDataDelegate  Messages related to the operation of a task that delivers data directly to the delegate.

//告诉delegate已经接受到服务器的初始应答, 准备接下来的数据任务的操作
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                 didReceiveResponse:(NSURLResponse *)response
 completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler {
    
    NSLog(@"%s",__func__);
    
    NSLog(@"%lld",dataTask.countOfBytesExpectedToReceive);  // 需要获取的数据的长度
    
    // 初始化 allData 属性
    self.allData = [NSMutableData data];
    
    // 一般 data 任务 让任务继续正常运行(如果没有这行代码，将不会执行下面的代理方法)
//    completionHandler(NSURLSessionResponseAllow);
    
    // 把 data task 转换成 Download task
    // 转成 Download task 会下载资源到磁盘上
    completionHandler(NSURLSessionResponseBecomeDownload);
    
}

/* Notification that a data task has become a download task.  No
* future messages will be sent to the data task.
* 告诉delegate, data task 已经转变成download task
* 此方法内可以不写任何代码, 但必须被调用. 否则将不会执行下面的代理方法
*/
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
didBecomeDownloadTask:(NSURLSessionDownloadTask *)downloadTask {
      NSLog(@"%s",__func__);
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
didBecomeStreamTask:(NSURLSessionStreamTask *)streamTask {
      NSLog(@"%s",__func__);
}

/* Sent when data is available for the delegate to consume.  It is
* assumed that the delegate will retain and not copy the data.  As
* the data may be discontiguous, you should use
* [NSData enumerateByteRangesUsingBlock:] to access it.
* 每收到一次 Data 时候调用(数据是分段接收的)
*/
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
    didReceiveData:(NSData *)data {
    
    NSLog(@"%s %lu %lld %f",__func__,(unsigned long)dataTask.countOfBytesExpectedToReceive,dataTask.countOfBytesReceived,[NSNumber numberWithLongLong:dataTask.countOfBytesReceived].floatValue / [NSNumber numberWithLongLong:dataTask.countOfBytesExpectedToReceive].floatValue);
    
    // 接收进度
    dispatch_async(dispatch_get_main_queue(), ^{
        self.progressView.progress =  [NSNumber numberWithLongLong:dataTask.countOfBytesReceived].floatValue / [NSNumber numberWithLongLong:dataTask.countOfBytesExpectedToReceive].floatValue;
    });
    
    // 接收返回的数据
    [self.allData appendData:data];
}

/* Invoke the completion routine with a valid NSCachedURLResponse to
* allow the resulting data to be cached, or pass nil to prevent
* caching. Note that there is no guarantee that caching will be
* attempted for a given resource, and you should not rely on this
* message to receive the resource data.
* 是否把 Response 存储到 Cache 中
*/
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                  willCacheResponse:(NSCachedURLResponse *)proposedResponse
 completionHandler:(void (^)(NSCachedURLResponse * _Nullable cachedResponse))completionHandler {
      NSLog(@"%s",__func__);
}

#pragma mark - NSURLSessionDownloadDelegate

/* Sent when a download task that has completed a download.  The delegate should
 * copy or move the file at the given location to a new location as it will be
 * removed when the delegate message returns. URLSession:task:didCompleteWithError: will
 * still be called.didCompleteWithError
 */
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
didFinishDownloadingToURL:(NSURL *)location {
    NSLog(@"%s",__func__);
    
    // 从提供的URL中读取数据
    NSData *data = [NSData dataWithContentsOfURL:location];
       
    dispatch_async(dispatch_get_main_queue(), ^{
        UIImage *image = [UIImage imageWithData:data];
        self.imageView.image = image;
        self.session = nil;
        self.dataTask = nil;
    });
}

/* Sent periodically to notify the delegate of download progress. */
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
                                           didWriteData:(int64_t)bytesWritten
                                      totalBytesWritten:(int64_t)totalBytesWritten
totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    
      NSLog(@"%s %lld %lld %lld",__func__,bytesWritten,totalBytesWritten,totalBytesExpectedToWrite);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.progressView.progress = [NSNumber numberWithLongLong:totalBytesWritten].floatValue / [NSNumber numberWithLongLong:totalBytesExpectedToWrite].floatValue;
    });
}

/* Sent when a download has been resumed. If a download failed with an
 * error, the -userInfo dictionary of the error will contain an
 * NSURLSessionDownloadTaskResumeData key, whose value is the resume
 * data.
 */
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
                                      didResumeAtOffset:(int64_t)fileOffset
expectedTotalBytes:(int64_t)expectedTotalBytes {
      NSLog(@"%s",__func__);
}

@end
