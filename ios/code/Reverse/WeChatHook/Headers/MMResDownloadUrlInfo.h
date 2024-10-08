//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBCoding.h"
#import "WCTColumnCoding.h"

@class MMResSignatureDataInfos, NSData, NSString;

@interface MMResDownloadUrlInfo : MMObject <PBCoding, WCTColumnCoding>
{
    _Bool isEncrypt;
    _Bool isCompress;
    _Bool isLoginUsrRelated;
    _Bool isDownloaded;
    _Bool _isPage;
    unsigned int fileId;
    unsigned int supportVersion;
    unsigned int downloadPriority;
    unsigned int retryCnt;
    unsigned int _protocal;
    NSString *srcUrl;
    NSString *version;
    NSString *md5;
    NSData *signatureData;
    MMResSignatureDataInfos *arrSignatureDataInfo;
    NSString *originalMd5;
}

+ (int)columnTypeForWCDB;
+ (id)unarchiveWithWCTValue:(struct NSObject *)arg1;
+ (void)initialize;
@property(readonly, nonatomic) unsigned int protocal; // @synthesize protocal=_protocal;
@property(nonatomic) _Bool isPage; // @synthesize isPage=_isPage;
@property(nonatomic) unsigned int retryCnt; // @synthesize retryCnt;
@property(nonatomic) unsigned int downloadPriority; // @synthesize downloadPriority;
@property(retain, nonatomic) NSString *originalMd5; // @synthesize originalMd5;
@property(retain, nonatomic) MMResSignatureDataInfos *arrSignatureDataInfo; // @synthesize arrSignatureDataInfo;
@property(retain, nonatomic) NSData *signatureData; // @synthesize signatureData;
@property(nonatomic) _Bool isDownloaded; // @synthesize isDownloaded;
@property(nonatomic) unsigned int supportVersion; // @synthesize supportVersion;
@property(nonatomic) unsigned int fileId; // @synthesize fileId;
@property(nonatomic) _Bool isLoginUsrRelated; // @synthesize isLoginUsrRelated;
@property(nonatomic) _Bool isCompress; // @synthesize isCompress;
@property(retain, nonatomic) NSString *md5; // @synthesize md5;
@property(nonatomic) _Bool isEncrypt; // @synthesize isEncrypt;
@property(retain, nonatomic) NSString *version; // @synthesize version;
@property(retain, nonatomic) NSString *srcUrl; // @synthesize srcUrl;
- (void).cxx_destruct;
- (void)dealloc;
- (struct NSObject *)archivedWCTValue;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

