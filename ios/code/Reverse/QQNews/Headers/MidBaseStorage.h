//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MidStorageDelegate.h"

@class NSString;

@interface MidBaseStorage : NSObject <MidStorageDelegate>
{
    NSString *_appId;
    long long _readType;
}

@property(nonatomic) long long readType; // @synthesize readType=_readType;
@property(copy, nonatomic) NSString *appId; // @synthesize appId=_appId;
- (void).cxx_destruct;
- (id)encryStringByRC4Error:(id)arg1;
- (id)encryStringByRC4:(id)arg1;
- (id)decode:(id)arg1;
- (id)decodeError:(id)arg1;
- (id)encode:(id)arg1;
- (void)resetMidStorageModelNilProperty;
- (void)writeMidStorageModel:(id)arg1;
- (id)readMidStorageModel;
- (id)quickReadMidStorageModel;
- (id)initWithAppInfo:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

