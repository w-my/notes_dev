//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBCoding.h"
#import "WCTColumnCoding.h"

@class NSMutableArray, NSMutableDictionary, NSString;

@interface WePkgUpdateConfigExt : MMObject <PBCoding, WCTColumnCoding>
{
    _Bool isReadyForOperation;
    _Bool isClearAllPkgExceptCurrentEnabledVersion;
    _Bool bigPackageDownloadSuccess;
    _Bool isPatchDownloadSuccess;
    unsigned int lastUnusedSeconds;
    unsigned int checkIntervalSeconds;
    unsigned int pkgSizeInBytes;
    unsigned int bigPackagedownloadNetworkType;
    unsigned int atomicSingleFileTotalCount;
    unsigned int checkUpdateSuccessTime;
    unsigned int controlCommand;
    unsigned int patchDownloadNetworkType;
    unsigned int patchSizeInBytes;
    NSString *currentEnabledVersion;
    NSString *currentPkgMd5;
    NSString *downloadUrl;
    NSString *checkResponseMd5;
    NSMutableArray *atomicSingleFileListNeedDownload;
    NSMutableArray *atomicSingleFileListDownloadSuccessed;
    NSString *charSet;
    NSMutableDictionary *file2DownloadFailCount;
    NSString *patchDownloadUrl;
    NSString *patchMd5;
}

+ (int)columnTypeForWCDB;
+ (id)unarchiveWithWCTValue:(struct NSObject *)arg1;
+ (void)initialize;
@property(nonatomic) _Bool isPatchDownloadSuccess; // @synthesize isPatchDownloadSuccess;
@property(nonatomic) unsigned int patchSizeInBytes; // @synthesize patchSizeInBytes;
@property(nonatomic) unsigned int patchDownloadNetworkType; // @synthesize patchDownloadNetworkType;
@property(retain, nonatomic) NSString *patchMd5; // @synthesize patchMd5;
@property(retain, nonatomic) NSString *patchDownloadUrl; // @synthesize patchDownloadUrl;
@property(nonatomic) unsigned int controlCommand; // @synthesize controlCommand;
@property(nonatomic) _Bool bigPackageDownloadSuccess; // @synthesize bigPackageDownloadSuccess;
@property(nonatomic) unsigned int checkUpdateSuccessTime; // @synthesize checkUpdateSuccessTime;
@property(retain, nonatomic) NSMutableDictionary *file2DownloadFailCount; // @synthesize file2DownloadFailCount;
@property(retain, nonatomic) NSString *charSet; // @synthesize charSet;
@property(retain, nonatomic) NSMutableArray *atomicSingleFileListDownloadSuccessed; // @synthesize atomicSingleFileListDownloadSuccessed;
@property(retain, nonatomic) NSMutableArray *atomicSingleFileListNeedDownload; // @synthesize atomicSingleFileListNeedDownload;
@property(nonatomic) unsigned int atomicSingleFileTotalCount; // @synthesize atomicSingleFileTotalCount;
@property(nonatomic) unsigned int bigPackagedownloadNetworkType; // @synthesize bigPackagedownloadNetworkType;
@property(retain, nonatomic) NSString *checkResponseMd5; // @synthesize checkResponseMd5;
@property(nonatomic) _Bool isClearAllPkgExceptCurrentEnabledVersion; // @synthesize isClearAllPkgExceptCurrentEnabledVersion;
@property(nonatomic) _Bool isReadyForOperation; // @synthesize isReadyForOperation;
@property(nonatomic) unsigned int pkgSizeInBytes; // @synthesize pkgSizeInBytes;
@property(retain, nonatomic) NSString *downloadUrl; // @synthesize downloadUrl;
@property(nonatomic) unsigned int checkIntervalSeconds; // @synthesize checkIntervalSeconds;
@property(nonatomic) unsigned int lastUnusedSeconds; // @synthesize lastUnusedSeconds;
@property(retain, nonatomic) NSString *currentPkgMd5; // @synthesize currentPkgMd5;
@property(retain, nonatomic) NSString *currentEnabledVersion; // @synthesize currentEnabledVersion;
- (void).cxx_destruct;
- (struct NSObject *)archivedWCTValue;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

