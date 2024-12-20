//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "WCTTableCoding.h"

@class MMResSignatureDataInfos, NSData, NSString;

@interface MMResInfo : MMObject <WCTTableCoding>
{
    _Bool isEncrypt;
    _Bool isCompress;
    _Bool isTemp;
    _Bool isAutoIncrement;
    unsigned int resInfoId;
    unsigned int createTime;
    unsigned int expireTime;
    unsigned int accessTime;
    unsigned int crc32;
    unsigned int resType;
    unsigned int resSubType;
    unsigned int fileId;
    unsigned int supportVersion;
    unsigned int eid;
    unsigned int reportId;
    unsigned int clientVersion;
    NSString *resUrlMd5;
    NSString *resMd5;
    NSString *appId;
    NSString *domain;
    NSString *version;
    NSString *localSubPath;
    unsigned long long size;
    long long offset;
    long long chunkLength;
    NSString *sampleId;
    NSData *signatureData;
    MMResSignatureDataInfos *arrSignatureDataInfo;
    NSString *resOriginalMd5;
    long long lastInsertedRowID;
}

+ (void)__wcdb_column_constraint_28:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_27:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)arrSignatureDataInfo;
+ (const struct WCTProperty *)__wcdb_synthesize_26:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)clientVersion;
+ (const struct WCTProperty *)__wcdb_synthesize_25:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)resOriginalMd5;
+ (const struct WCTProperty *)__wcdb_synthesize_24:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)signatureData;
+ (const struct WCTProperty *)__wcdb_synthesize_23:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)reportId;
+ (const struct WCTProperty *)__wcdb_synthesize_22:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)sampleId;
+ (const struct WCTProperty *)__wcdb_synthesize_21:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)eid;
+ (const struct WCTProperty *)__wcdb_synthesize_20:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)isTemp;
+ (const struct WCTProperty *)__wcdb_synthesize_19:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)supportVersion;
+ (const struct WCTProperty *)__wcdb_synthesize_18:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)fileId;
+ (const struct WCTProperty *)__wcdb_synthesize_17:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)resSubType;
+ (const struct WCTProperty *)__wcdb_synthesize_16:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)isCompress;
+ (const struct WCTProperty *)__wcdb_synthesize_15:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)isEncrypt;
+ (const struct WCTProperty *)__wcdb_synthesize_14:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)chunkLength;
+ (const struct WCTProperty *)__wcdb_synthesize_13:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)resType;
+ (const struct WCTProperty *)__wcdb_synthesize_12:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)crc32;
+ (const struct WCTProperty *)__wcdb_synthesize_11:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)offset;
+ (const struct WCTProperty *)__wcdb_synthesize_10:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)size;
+ (const struct WCTProperty *)__wcdb_synthesize_9:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)accessTime;
+ (const struct WCTProperty *)__wcdb_synthesize_8:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)expireTime;
+ (const struct WCTProperty *)__wcdb_synthesize_7:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)createTime;
+ (const struct WCTProperty *)__wcdb_synthesize_6:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)localSubPath;
+ (const struct WCTProperty *)__wcdb_synthesize_5:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)version;
+ (const struct WCTProperty *)__wcdb_synthesize_4:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)domain;
+ (const struct WCTProperty *)__wcdb_synthesize_3:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)appId;
+ (const struct WCTProperty *)__wcdb_synthesize_2:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)resMd5;
+ (const struct WCTProperty *)__wcdb_synthesize_1:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)resUrlMd5;
+ (const struct WCTProperty *)__wcdb_synthesize_0:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)resInfoId;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(nonatomic) long long lastInsertedRowID; // @synthesize lastInsertedRowID;
@property(nonatomic) _Bool isAutoIncrement; // @synthesize isAutoIncrement;
@property(nonatomic) unsigned int clientVersion; // @synthesize clientVersion;
@property(retain, nonatomic) NSString *resOriginalMd5; // @synthesize resOriginalMd5;
@property(retain, nonatomic) MMResSignatureDataInfos *arrSignatureDataInfo; // @synthesize arrSignatureDataInfo;
@property(retain, nonatomic) NSData *signatureData; // @synthesize signatureData;
@property(nonatomic) unsigned int reportId; // @synthesize reportId;
@property(retain, nonatomic) NSString *sampleId; // @synthesize sampleId;
@property(nonatomic) unsigned int eid; // @synthesize eid;
@property(nonatomic) _Bool isTemp; // @synthesize isTemp;
@property(nonatomic) unsigned int supportVersion; // @synthesize supportVersion;
@property(nonatomic) unsigned int fileId; // @synthesize fileId;
@property(nonatomic) unsigned int resSubType; // @synthesize resSubType;
@property(nonatomic) _Bool isCompress; // @synthesize isCompress;
@property(nonatomic) _Bool isEncrypt; // @synthesize isEncrypt;
@property(nonatomic) long long chunkLength; // @synthesize chunkLength;
@property(nonatomic) unsigned int resType; // @synthesize resType;
@property(nonatomic) unsigned int crc32; // @synthesize crc32;
@property(nonatomic) long long offset; // @synthesize offset;
@property(nonatomic) unsigned long long size; // @synthesize size;
@property(nonatomic) unsigned int accessTime; // @synthesize accessTime;
@property(nonatomic) unsigned int expireTime; // @synthesize expireTime;
@property(nonatomic) unsigned int createTime; // @synthesize createTime;
@property(retain, nonatomic) NSString *localSubPath; // @synthesize localSubPath;
@property(retain, nonatomic) NSString *version; // @synthesize version;
@property(retain, nonatomic) NSString *domain; // @synthesize domain;
@property(retain, nonatomic) NSString *appId; // @synthesize appId;
@property(retain, nonatomic) NSString *resMd5; // @synthesize resMd5;
@property(retain, nonatomic) NSString *resUrlMd5; // @synthesize resUrlMd5;
@property(nonatomic) unsigned int resInfoId; // @synthesize resInfoId;
- (void).cxx_destruct;
- (long long)compareAccessTimeByResInfo:(id)arg1;
- (void)dealloc;
- (id)init;

@end

