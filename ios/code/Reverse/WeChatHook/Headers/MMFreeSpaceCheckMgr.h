//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMDiskUsageScannerDelegate.h"
#import "MMService.h"

@class MMDiskUsageScaner, MMFreeSpaceCheckConfig, MMTimer, NSString, NSURL;

@interface MMFreeSpaceCheckMgr : MMService <MMDiskUsageScannerDelegate, MMService>
{
    MMFreeSpaceCheckConfig *m_config;
    MMTimer *m_checkFreeSpaceTimer;
    unsigned long long _freeSizeLevelLow;
    unsigned long long _freeSizeLevelLower;
    unsigned long long _freeSizeLevelLowest;
    unsigned long long _eLevel;
    unsigned long long _deviceStorage;
    unsigned long long _deviceFreeStorage;
    unsigned int _eDeviceStorageLevel;
    _Bool _bTipsing;
    unsigned int _lastScanAppSizeTimeStamp;
    basic_string_90719d97 _statfsPath;
    NSURL *_volumnURL;
    MMDiskUsageScaner *_usageScanner;
}

+ (id)testFilePath;
+ (id)configPath;
+ (id)workDir;
@property(retain, nonatomic) MMDiskUsageScaner *usageScanner; // @synthesize usageScanner=_usageScanner;
- (id).cxx_construct;
- (void).cxx_destruct;
- (void)reportTipsType:(unsigned int)arg1 andTipsOpt:(unsigned int)arg2 important:(_Bool)arg3;
- (void)goCleanView;
- (void)saveConfig;
- (void)loadConfig;
- (void)createWorkDir;
- (void)onDiskUsageScanFinishedWithScanStat:(id)arg1;
- (void)onDiskUsageScanStart;
- (void)onDiskUsageScanCancel;
- (void)startCheckDiskSize;
- (_Bool)shouldTips;
- (void)onFreeSpaceLowest;
- (void)onFreeSpaceLower;
- (void)onFreeSpaceLow;
- (void)calFreeSpace;
- (void)setup;
- (void)checkFreeSpaceEx;
- (void)checkOtherUserUsedSpace;
- (unsigned long long)getUrgentFreeSize;
- (_Bool)isUrgentFreeSpace;
- (_Bool)getDiskSize:(unsigned long long *)arg1;
- (_Bool)getFreeSize:(unsigned long long *)arg1;
- (void)onServiceEnterForeground;
- (void)onServiceEnterBackground;
- (void)onServiceInit;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

