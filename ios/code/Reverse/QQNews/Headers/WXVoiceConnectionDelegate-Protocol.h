//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData, NSString;

@protocol WXVoiceConnectionDelegate <NSObject>
- (_Bool)shouldSendData:(NSData *)arg1 withUrlArgs:(NSString *)arg2 delegate:(id <WXNetDelegate>)arg3;
- (void)voiceConnectionDidCancel;
- (void)voiceConnectionReceiveBytes:(char *)arg1 length:(long long)arg2;
- (void)voiceConnectionError:(long long)arg1 andHttpStatus:(long long)arg2;
@end

