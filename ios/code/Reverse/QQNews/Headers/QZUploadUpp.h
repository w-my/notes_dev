//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QZUploadPacket.h"

@class NSString;

@interface QZUploadUpp : QZUploadPacket
{
    NSString *_appid;
}

@property(retain, nonatomic) NSString *appid; // @synthesize appid=_appid;
- (void).cxx_destruct;
- (id)packetRespWithRspData:(id)arg1;
- (id)getControlDataWithError:(id *)arg1;
- (id)sliceUploadAppId;
- (id)ipMgrKey;
- (id)appidName;
- (id)generateDescription;
- (void)dealloc;
- (id)init;

@end
