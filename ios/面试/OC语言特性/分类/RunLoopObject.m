//
//  RunLoopObject.m
//  分类
//
//  Created by wtw on 2018/12/29.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "RunLoopObject.h"

static NSThread *thread = nil;

//标记是否要继续事件循环
static BOOL runAlways = YES;

@implementation RunLoopObject

+ (NSThread *)threadForDispatch {
    if (thread == nil) {
        @synchronized (self) {
            if (thread == nil) {
                //线程的创建
                thread = [[NSThread alloc] initWithTarget:self selector:@selector(runRequest) object:nil];
                [thread setName:@"com.rocedar.thread"];
                //启动
                [thread start];
            }
        }
    }
    return thread;
}

+ (void)runRequest {
    //创建一个Source
    CFRunLoopSourceContext context = {0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    CFRunLoopSourceRef source = CFRunLoopSourceCreate(kCFAllocatorDefault, 0, &context);
    
    //创建RunLoop 同时向RunLoop的DefaultMode 下面添加Source
    //CFRunLoopGetCurrent() 会创建一个RunLoop 或者使用  [NSRunLoop currentRunLoop];
    CFRunLoopAddSource(CFRunLoopGetCurrent(), source, kCFRunLoopDefaultMode);
    
    //如果可以运行
    while (runAlways) {
        @autoreleasepool {
            //令当前RunLoop 运行在DefaultMode 下面
            //第二个参数代表多少时间后退出
            //第三个参数是是否允许运行
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 1.0e10, true);
        }
    }
    //某一时机 静态变量 runAlways = NO时，可以保证条船RunLoop 线程退出
    CFRunLoopRemoveSource(CFRunLoopGetCurrent(), source, kCFRunLoopDefaultMode);
    CFRelease(source);
}

@end
