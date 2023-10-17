//
//  HPInstrumentation.m
//  性能优化
//
//  Created by WTW on 2022/2/22.
//  Copyright © 2022 wtw. All rights reserved.
//

#import "HPInstrumentation.h"
//#import <Flurry.h>

static HPInstrumentation *_instance;

@implementation HPInstrumentation

+ (HPInstrumentation *)sharedInstance {
    return  _instance;
}

+ (void)setSharedInstance:(HPInstrumentation *)instance {
    _instance = instance;
}

+(void)logEvent:(NSString *)name {
    [[HPInstrumentation sharedInstance] logEventImpl:name];
}

-(instancetype)initWithAPIKey:(NSString *)apiKey {
    if(self = [super init]) {
        self.initialized = NO;
//        self.events = [NSMutableArray array];
//        /// 栅栏函数必须使用自定义并发队列 不能使用系统的并发队列
//        self.queue = dispatch_queue_create("com.m10v.queue.analytics",DISPATCH_QUEUE_CONCURRENT);
//        dispatch_async(
//                       dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
//                           [Flurry startSession:@"apiKey"];
//
//                               dispatch_barrier_sync(self.queue, ^{
//
//                                for(NSDictionary *name in self.events) {
//
//                                    [Flurry logEvent:name];
//
//                                }
//
//                               self.events = nil;
//                               self.initialized = YES;
//
//                           });
//
//                       });
//
    }
    return self;
}

-(void)logEventImpl:(NSString *)name {
//    dispatch_sync(self.queue, ^{
//        if(self.initialized) {
////            [Flurry logEvent:name withParameters:params];
//        } else {
//            [self.events addObject:name];
//        }
//    });
}

@end
