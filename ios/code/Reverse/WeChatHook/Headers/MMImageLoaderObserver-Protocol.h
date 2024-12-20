//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData, NSMutableDictionary, NSNumber, NSString, UIImage;

@protocol MMImageLoaderObserver <NSObject>

@optional
- (void)ImageDidAsyncLoadEndWithImage:(UIImage *)arg1 imageDataSize:(NSNumber *)arg2 data:(NSData *)arg3 Url:(NSString *)arg4 userInfo:(id)arg5;
- (void)ImageDidFail:(NSString *)arg1;
- (void)ImageDidLoadWithData:(NSData *)arg1 Url:(NSString *)arg2 extraInfo:(NSMutableDictionary *)arg3;
- (void)ImageDidLoadWithData:(NSData *)arg1 Url:(NSString *)arg2;
- (void)ImageDidLoad:(UIImage *)arg1 Url:(NSString *)arg2 extraInfo:(NSMutableDictionary *)arg3;
- (void)ImageDidLoad:(UIImage *)arg1 Url:(NSString *)arg2;
@end

