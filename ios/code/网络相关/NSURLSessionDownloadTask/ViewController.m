//
//  ViewController.m
//  NSURLSessionDownloadTask
//
//  Created by WTW on 2019/12/2.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "ViewController.h"

/*
 一般的下载 和 断点续传
 一般的下载没问题，但是断点下载有点问题：
 这样会有一个弊端，用户如果正在下载期间杀死应用程序，或者点了暂停杀死app，再次点击下载的时候又是从头开始下载
 虽然可以保存进度下次继续，但是比较复杂，所以推荐用
 */

@interface ViewController ()<NSURLSessionDelegate>

@property (weak, nonatomic) IBOutlet UIProgressView *progressView;

@property (nonatomic,strong) NSURLSession *session;
@property (nonatomic,strong) NSURLSessionDownloadTask *downLoadTask;

@property (nonatomic,strong) NSData *resumeData;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (IBAction)startDownload:(id)sender {
    [self downloadTaskTestWithConfig:[NSURLSessionConfiguration defaultSessionConfiguration]];
}

// 暂停可以恢复
- (IBAction)pauseDownload:(id)sender {
    NSLog(@"%s",__func__);
    [self.downLoadTask suspend];
}

- (IBAction)continueDownload:(id)sender {
    NSLog(@"%s",__func__);
    if (self.resumeData) { // cancelByProducingResumeData
        self.downLoadTask = [self.session downloadTaskWithResumeData:self.resumeData];
    }
    
    [self.downLoadTask resume];
}

// cancel : 取消是不能恢复的
// cancelByProducingResumeData : 这种取消是可以恢复的
- (IBAction)cancelDownload:(id)sender {
//    [self.downLoadTask cancel];
    
    __weak typeof(self) weakSelf = self;
    [self.downLoadTask cancelByProducingResumeData:^(NSData * _Nullable resumeData) {
        weakSelf.resumeData = resumeData;
    }];
    NSLog(@"%s",__func__);
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
 
    // 一般下载
//    [self downloadTaskTestWithConfig:[NSURLSessionConfiguration defaultSessionConfiguration]];
    
    // 后台下载
//    [self downloadTaskTestWithConfig:[NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:@"com.rocedar.networkTest"]];
    
}


#pragma mark - download
- (void)downloadTaskTestWithConfig:(NSURLSessionConfiguration *)config {
  
    //1、创建NSURLSessionConfiguration类的对象, 这个对象被用于创建NSURLSession类的对象
    NSURLSessionConfiguration *configuration = config;
    
    //2、创建 NSUrlSession 对象
    // delegateQueue : [NSOperationQueue mainQueue] 代理的消息都会在主线程中收到
    self.session = [NSURLSession sessionWithConfiguration:configuration delegate:self delegateQueue:[NSOperationQueue mainQueue]];
    
    //3、创建 URL
    // https://nodejs.org/dist/v8.11.4/node-v8.11.4.pkg
    // https://cn.bing.com/th?id=OHR.BrightonJetty_ZH-CN1526526038_UHD.jpg&pid=hp&w=3840&h=2160&rs=1&c=4&r=0
    NSURL *downLoadUrl = [NSURL URLWithString:@"https://nodejs.org/dist/v8.11.4/node-v8.11.4.pkg"];
    
    //4、创建 request
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:downLoadUrl];
    
    // 5、创建数据类型任务
//    // block 方式  不关注过程只关注结果
    // 无法监听文件的下载进度
    // 优点：不需要关心内存
    // 该方法内部已经实现了边接收数据边写沙盒(tmp)的操作
//    self.downLoadTask = [self.session downloadTaskWithRequest:request completionHandler:^(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error) {
//        // location 临时文件的存储位置
//        // 响应头信息
//        NSLog(@"location:%@ == Thread:%@",location,[NSThread currentThread]);
//
//        // 接收文件全路径
//        NSString *fullPath = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:response.suggestedFilename];
//
//        // 剪切文件
//        NSError *moveError;
//        BOOL success = [[NSFileManager defaultManager] moveItemAtURL:location toURL:[NSURL fileURLWithPath:fullPath] error:&moveError];
//        if (success) {
//            NSLog(@"fullPath ==  %@ success:%d",fullPath,success);
//        }else {
//            NSLog(@"%@",moveError);
//        }
//
//    }];
//      // 开始任务
//    [self.downLoadTask resume];
  
    
     // 通过代理方式   可以详细看到全过程，需要实现代理方法
    self.downLoadTask = [self.session downloadTaskWithRequest:request];

    // 6、 开始任务
    [self.downLoadTask resume];

    // 7、任务完成之后 session 销毁
//    [self.session finishTasksAndInvalidate];
    // 或者
    //[self.session invalidateAndCancel];
}

#pragma mark - 后台下载
/*
只需要在普通下载的基础上做如下修改即可：
1、NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:@"com.rocedar.testNetWork"];
2、如果APP启动了一个或多个下载任务，而且任务又没有完成的情况下，APP被用户退出到后台，这个时候仍然可以在后台继续执行下载任务。但是不会再调用任何sessionDelegate的方法，不会再与session做交互，用户无法收到下载进度的提示。
 3、退出到后台之后，虽然下载任务仍然在后台执行，但是还未下载完成的情况下，用户又重新将APP唤起到前台。那么这些下载任务就跟正常下载一样，继续可以收到下载进度的代理消息
 4、后台任务完成会先调用一个application的代理方法。
 - (void)application:(UIApplication*)application handleEventsForBackgroundURLSession:(NSString*)identifier completionHandler:(void(^)(void))completionHandler
     {

         //后台任务下载完成后会调用
     }
 5、之后会调用session的代理方法
    - (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session;
 6、之后会正常调用所有已经完成下载的task任务的完成的代理方法，同样在这个代理方法中APP可以将下载完成的临时文件转移到沙盒中保存，这样就完成了后台下载。
 
 2019-12-02 17:50:48.075209+0800 NSURLSessionDownloadTask[53864:3234221] 后台任务下载完成后调用 -[AppDelegate application:handleEventsForBackgroundURLSession:completionHandler:]
 2019-12-02 17:50:48.087281+0800 NSURLSessionDownloadTask[53864:3234221] 下载完了 -[ViewController URLSession:downloadTask:didFinishDownloadingToURL:]
 2019-12-02 17:50:48.112367+0800 NSURLSessionDownloadTask[53864:3234221] -[ViewController URLSession:task:didFinishCollectingMetrics:]
 2019-12-02 17:50:48.112897+0800 NSURLSessionDownloadTask[53864:3234221] -[ViewController URLSessionDidFinishEventsForBackgroundURLSession:]
 2019-12-02 17:50:48.113377+0800 NSURLSessionDownloadTask[53864:3234221] -[ViewController URLSession:task:didCompleteWithError:]
 */

#pragma mark - NSURLSessionDownloadDelegate

//下载过程中，反馈下载进度
- (void)URLSession:(NSURLSession *)session
      downloadTask:(NSURLSessionDownloadTask *)downloadTask
      didWriteData:(int64_t)bytesWritten
 totalBytesWritten:(int64_t)totalBytesWritten
totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
        
    dispatch_async(dispatch_get_main_queue(), ^{
        self.progressView.progress = [NSNumber numberWithLongLong:totalBytesWritten].floatValue / [NSNumber numberWithLongLong:totalBytesExpectedToWrite].floatValue;
        NSLog(@"下载进度:%f", [NSNumber numberWithLongLong:totalBytesWritten].floatValue / [NSNumber numberWithLongLong:totalBytesExpectedToWrite].floatValue);
    });
}

// 当恢复下载的时候调用该方法
- (void)URLSession:(NSURLSession *)session
      downloadTask:(NSURLSessionDownloadTask *)downloadTask
didResumeAtOffset:(int64_t)fileOffset
expectedTotalBytes:(int64_t)expectedTotalBytes {
    
    NSLog(@"%s",__func__);
}

// 下载任务完成时会调用该代理方法，可以在该方法中将下载的临时文件移动到沙盒中保存，当该代理方法返回时，临时文件将被删除
// 一定要在这个函数返回之前，对数据进行使用，或者保存
- (void)URLSession:(NSURLSession *)session
      downloadTask:(NSURLSessionDownloadTask *)downloadTask
didFinishDownloadingToURL:(NSURL *)location {
    
    // 从提供的URL中读取数据
    NSData *data = [NSData dataWithContentsOfURL:location];
    
    // 接收文件全路径
    NSString *fullPath = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:downloadTask.response.suggestedFilename];

    // 剪切文件
    NSError *moveError;
    BOOL success = [[NSFileManager defaultManager] moveItemAtURL:location toURL:[NSURL fileURLWithPath:fullPath] error:&moveError];
    if (success) {
        NSLog(@"fullPath ==  %@ success:%d",fullPath,success);
    }else {
        NSLog(@"%@",moveError);
    }
    
    NSLog(@"下载完了 %s location:%@ Data:%@",__func__,location,data);
}

#pragma mark - NSURLSessionTaskDelegate

- (void)URLSession:(NSURLSession *)session
              task:(NSURLSessionTask *)task
didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics {
      NSLog(@"%s",__func__);
}

// 告诉delegate, task已经完成
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
didCompleteWithError:(nullable NSError *)error{
    
    NSLog(@"%s",__func__);
}
#pragma mark - NSURLSessionDelegate

- (void)URLSession:(NSURLSession *)session
didBecomeInvalidWithError:(nullable NSError *)error {
      NSLog(@"%s",__func__);
}

// 后台下载任务完成后会调用这个方法 
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)session {
      NSLog(@"%s",__func__);
}

@end
