//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface UUIDInfo : NSObject
{
    NSString *_WeChatUUID;
    NSString *_MultiMediaUUID;
    NSString *_MarsUUID;
    NSString *_WCDBUUID;
}

@property(retain, nonatomic) NSString *WCDBUUID; // @synthesize WCDBUUID=_WCDBUUID;
@property(retain, nonatomic) NSString *MarsUUID; // @synthesize MarsUUID=_MarsUUID;
@property(retain, nonatomic) NSString *MultiMediaUUID; // @synthesize MultiMediaUUID=_MultiMediaUUID;
@property(retain, nonatomic) NSString *WeChatUUID; // @synthesize WeChatUUID=_WeChatUUID;
- (void).cxx_destruct;
- (_Bool)isMatch:(id)arg1;

@end
