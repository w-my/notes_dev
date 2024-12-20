//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QSAutoUpdateProtocol.h"
#import "QSBaseDataDelegate.h"

@class NSError, NSMapTable, NSMutableArray, NSString;

@interface QSCombiningData : NSObject <QSBaseDataDelegate, QSAutoUpdateProtocol>
{
    _Bool _isInitSuccess;
    _Bool _isForceReload;
    id <QSCombiningDataDelegate> _delegate;
    unsigned long long _type;
    NSMutableArray *_combinedDatas;
    NSMutableArray *_needUpdateDatas;
    NSMapTable *_combinedDataConfigs;
}

@property(nonatomic) _Bool isForceReload; // @synthesize isForceReload=_isForceReload;
@property(nonatomic) _Bool isInitSuccess; // @synthesize isInitSuccess=_isInitSuccess;
@property(retain, nonatomic) NSMapTable *combinedDataConfigs; // @synthesize combinedDataConfigs=_combinedDataConfigs;
@property(retain, nonatomic) NSMutableArray *needUpdateDatas; // @synthesize needUpdateDatas=_needUpdateDatas;
@property(retain, nonatomic) NSMutableArray *combinedDatas; // @synthesize combinedDatas=_combinedDatas;
@property(nonatomic) unsigned long long type; // @synthesize type=_type;
@property(nonatomic) __weak id <QSCombiningDataDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)onAutoUpdate;
- (_Bool)canUpdate;
- (void)forceReloadData;
- (_Bool)initData;
- (void)startReload;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)startSerialNextWithCurrentData:(id)arg1;
- (void)dataWillStartLoad:(id)arg1;
- (void)addCombinedData:(id)arg1 config:(id)arg2;
- (id)initWithType:(unsigned long long)arg1;
@property(readonly, nonatomic) _Bool needUpdate; // @dynamic needUpdate;
- (id)errorOfData:(id)arg1;
@property(readonly, nonatomic) __weak NSError *error; // @dynamic error;
@property(readonly, nonatomic) _Bool isUpdating; // @dynamic isUpdating;
@property(readonly, nonatomic) _Bool isReady; // @dynamic isReady;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

