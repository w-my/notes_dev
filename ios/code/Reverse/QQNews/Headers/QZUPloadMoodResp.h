//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QZUploadRespPacket.h"

@class NSData;

@interface QZUPloadMoodResp : QZUploadRespPacket
{
    NSData *_busiData;
}

@property(retain, nonatomic) NSData *busiData; // @synthesize busiData=_busiData;
- (void).cxx_destruct;
- (void)decodeBodyForSDKV2WithData:(id)arg1;
- (void)decodeBody:(void *)arg1;

@end

