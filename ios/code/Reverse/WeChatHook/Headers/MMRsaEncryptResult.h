//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface MMRsaEncryptResult : NSObject
{
    int _ret;
    NSString *_base64Str;
}

+ (id)rsaEncryptResultWithBase64Str:(id)arg1 ret:(int)arg2;
@property(readonly, nonatomic) int ret; // @synthesize ret=_ret;
@property(readonly, nonatomic) NSString *base64Str; // @synthesize base64Str=_base64Str;
- (void).cxx_destruct;
- (id)description;
- (id)initWithBase64Str:(id)arg1 ret:(int)arg2;

@end
