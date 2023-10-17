//
//  ViewController.m
//  AFNetworkingAnalyse
//
//  Created by wtw on 2018/12/3.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "ViewController.h"
#import <AFNetworking.h>

@interface ViewController ()<NSURLSessionDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    NSLog(@"%@",NSHomeDirectory());
    
    AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc] init];
    AFHTTPRequestSerializer *serializer = [AFHTTPRequestSerializer serializer];
    [serializer setTimeoutInterval:20];
//    manager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript",@"text/html", nil];
    [manager GET:@"https://www.baidu.com"
      parameters:nil
        progress:^(NSProgress * _Nonnull downloadProgress) {
                                   NSLog(@"downloadProgress == %@",downloadProgress);
                               }
                                success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
                                    NSLog(@"task = %@  =😝😝\nresponseObject = %@ 😝😝",task,responseObject);
                                }
                                failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
                                    NSLog(@"%@  == %@ ",task,error);
                                }];
}

- (nullable NSCachedURLResponse *)connection:(NSURLConnection *)connection willCacheResponse:(NSCachedURLResponse *)cachedResponse {
    NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)cachedResponse;

    if ([connection currentRequest].cachePolicy == NSURLRequestUseProtocolCachePolicy) {
        NSDictionary *headers = [httpResponse allHeaderFields];
        NSString *cacheControl = [headers valueForKey:@"Cache-Control"];
        NSString *expires = [headers valueForKey:@"Expires"];
        // don't cache
        if (cacheControl == nil && expires == nil) {
            return nil;
        }
    }

    return cachedResponse;
}


@end
