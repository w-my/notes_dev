//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class NSString;

@interface CdnRecordMediaInfo : NSObject <NSCopying>
{
    NSString *m_nsClientMsgID;
    NSString *m_nsFilePath;
    NSString *m_nsUsername;
    NSString *m_nsFileID;
    NSString *m_nsAesKey;
    unsigned int m_uiFileTotalLen;
    unsigned int m_uiScene;
    NSString *m_nsExtInfo;
    unsigned int m_uiFileType;
    NSString *m_authkey;
    double m_tGetMoovTime;
    unsigned int m_uiMoovPos;
    unsigned long long m_ui64StartTime;
    unsigned long long m_ui64EndTime;
}

@property(nonatomic) unsigned long long m_ui64EndTime; // @synthesize m_ui64EndTime;
@property(nonatomic) unsigned long long m_ui64StartTime; // @synthesize m_ui64StartTime;
@property(nonatomic) double m_tGetMoovTime; // @synthesize m_tGetMoovTime;
@property(nonatomic) unsigned int m_uiMoovPos; // @synthesize m_uiMoovPos;
@property(retain, nonatomic) NSString *m_authkey; // @synthesize m_authkey;
@property(nonatomic) unsigned int m_uiFileType; // @synthesize m_uiFileType;
@property(retain, nonatomic) NSString *m_nsExtInfo; // @synthesize m_nsExtInfo;
@property(nonatomic) unsigned int m_uiScene; // @synthesize m_uiScene;
@property(nonatomic) unsigned int m_uiFileTotalLen; // @synthesize m_uiFileTotalLen;
@property(retain, nonatomic) NSString *m_nsAesKey; // @synthesize m_nsAesKey;
@property(retain, nonatomic) NSString *m_nsFileID; // @synthesize m_nsFileID;
@property(retain, nonatomic) NSString *m_nsUsername; // @synthesize m_nsUsername;
@property(retain, nonatomic) NSString *m_nsFilePath; // @synthesize m_nsFilePath;
@property(retain, nonatomic) NSString *m_nsClientMsgID; // @synthesize m_nsClientMsgID;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

