//
//  HPInstrumentation.h
//  性能优化
//
//  Created by WTW on 2022/2/22.
//  Copyright © 2022 wtw. All rights reserved.
//  应用加载时间的优化

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HPInstrumentation : NSObject

@property (nonatomic,assign) BOOL initialized;
@property (nonatomic, strong) NSMutableArray *events;
@property (nonatomic, strong) dispatch_queue_t queue;

-(void)markInitialized;
+(void)logEventImpl:(NSString *)name;

-(instancetype)initWithAPIKey:(NSString *)apiKey;
+ (void)setSharedInstance:(HPInstrumentation *)instance;
+(void)logEvent:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
