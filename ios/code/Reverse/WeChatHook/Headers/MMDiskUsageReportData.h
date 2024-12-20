//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "PBCoding.h"

@class NSMutableDictionary, NSString;

@interface MMDiskUsageReportData : NSObject <PBCoding>
{
    unsigned int m_totalFileNum;
    unsigned int m_totalFileSize;
    unsigned int m_scanStartTime;
    unsigned int m_scanEndTime;
    unsigned int m_scanUsedTime;
    unsigned int m_scanCount;
    unsigned int m_totalDelFileNum;
    unsigned int m_totalDelFileSize;
    NSMutableDictionary *m_dicBizStat;
    NSMutableDictionary *m_dicFileTypeInUseStat;
    NSMutableDictionary *m_dicSpecialFileStat;
}

+ (_Bool)saveReportDataWithScanStat:(id)arg1 toFilePath:(id)arg2;
+ (id)loadReportDataFromFile:(id)arg1;
+ (void)initialize;
@property(retain, nonatomic) NSMutableDictionary *m_dicSpecialFileStat; // @synthesize m_dicSpecialFileStat;
@property(retain, nonatomic) NSMutableDictionary *m_dicFileTypeInUseStat; // @synthesize m_dicFileTypeInUseStat;
@property(nonatomic) unsigned int m_totalDelFileSize; // @synthesize m_totalDelFileSize;
@property(nonatomic) unsigned int m_totalDelFileNum; // @synthesize m_totalDelFileNum;
@property(nonatomic) unsigned int m_scanCount; // @synthesize m_scanCount;
@property(nonatomic) unsigned int m_scanUsedTime; // @synthesize m_scanUsedTime;
@property(nonatomic) unsigned int m_scanEndTime; // @synthesize m_scanEndTime;
@property(nonatomic) unsigned int m_scanStartTime; // @synthesize m_scanStartTime;
@property(retain, nonatomic) NSMutableDictionary *m_dicBizStat; // @synthesize m_dicBizStat;
@property(nonatomic) unsigned int m_totalFileSize; // @synthesize m_totalFileSize;
@property(nonatomic) unsigned int m_totalFileNum; // @synthesize m_totalFileNum;
- (void).cxx_destruct;
- (id)genSpecialFileTypeReportString:(id)arg1 specialTypeStirng:(id)arg2;
- (id)genFileTypeInUseString:(id)arg1 fileTypeString:(id)arg2;
- (id)genStatString:(id)arg1 bizTypeString:(id)arg2;
- (id)genTotalStatString;
- (unsigned long long)totalFileSizeUnit;
@property(readonly, copy) NSString *description;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

