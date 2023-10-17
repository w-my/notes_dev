//
//  RCPermenantThread.m
//  RunLoop 线程保活封装工具
//
//  Created by WTW on 2019/8/19.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "RCPermenantThread.h"

@interface RCThread : NSThread

@end
@implementation RCThread
- (void)dealloc {
    NSLog(@"%s",__func__);
}

@end

@interface RCPermenantThread ()

//RCThread 仅仅是为了测试线程声明周期，完全可以使用 NSThread
@property (nonatomic,strong) RCThread *thread;
@property (nonatomic,assign,getter=isStoped) BOOL stoped;

@end

@implementation RCPermenantThread

- (instancetype)init {
    if (self = [super init]) {
        self.stoped = NO;
        __weak typeof(self) weakSelf = self;
        self.thread = [[RCThread alloc] initWithBlock:^{
            /*
            // C 语言实现
            //创建上下文 (要初始化一下结构体)
            CFRunLoopSourceContext context = {0};
            //创建source
            CFRunLoopSourceRef source = CFRunLoopSourceCreate(kCFAllocatorDefault, 0, &context);
            //往RunLoop 中添加 source
            CFRunLoopAddSource(CFRunLoopGetCurrent(), source, kCFRunLoopDefaultMode);
            //销毁 source
            CFRelease(source);
            //启动
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 1.0e10, false);
            */
//            while (weakSelf && !weakSelf.isStoped) {
//                // 第三个参数 returnAfterSourceHandled 设置为 true 代表执行完 source 后就会退出 当前loop
//                CFRunLoopRunInMode(kCFRunLoopDefaultMode, 1.0e10, true);
//            }
            
            [[NSRunLoop currentRunLoop] addPort:[[NSPort alloc] init] forMode:NSDefaultRunLoopMode];
            while (weakSelf && !weakSelf.isStoped) {
                [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
            }
            NSLog(@"=== thread end === ");
        }];
        [self.thread start];
    }
    return self;
}

- (void)run {
    if (!self.thread) { return; }
    if (!self.thread.isExecuting) {
        [self.thread start];
    }
}

- (void)executeTask:(void (^)(void))task {
    if (!self.thread || !task) { return; }
    if (!self.thread.isExecuting) {
        [self.thread start];
    }
    [self performSelectorOnMainThread:@selector(__executeTask:) withObject:task waitUntilDone:NO];
}

- (void)stop {
    if (!self.thread) { return; }
    [self performSelector:@selector(__stop) onThread:self.thread withObject:nil waitUntilDone:YES];
}

- (void)dealloc {
    [self stop];
}

#pragma mark - private methods
- (void)__stop {
    self.stoped = YES;
    CFRunLoopStop(CFRunLoopGetCurrent());
    self.thread = nil;
}

- (void)__executeTask:(void(^)(void))task {
    task();
}

@end
