//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBCoding.h"

@class NSDictionary, NSString;

@interface MMExptItem : MMObject <PBCoding>
{
    unsigned int exptId;
    unsigned int groupId;
    unsigned int exptSeq;
    unsigned int startTimeSec;
    unsigned int endTimeSec;
    unsigned int exptType;
    unsigned int subType;
    NSDictionary *exptArgs;
    NSString *exptCheckSum;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *exptCheckSum; // @synthesize exptCheckSum;
@property(nonatomic) unsigned int subType; // @synthesize subType;
@property(nonatomic) unsigned int exptType; // @synthesize exptType;
@property(retain, nonatomic) NSDictionary *exptArgs; // @synthesize exptArgs;
@property(nonatomic) unsigned int endTimeSec; // @synthesize endTimeSec;
@property(nonatomic) unsigned int startTimeSec; // @synthesize startTimeSec;
@property(nonatomic) unsigned int exptSeq; // @synthesize exptSeq;
@property(nonatomic) unsigned int groupId; // @synthesize groupId;
@property(nonatomic) unsigned int exptId; // @synthesize exptId;
- (void).cxx_destruct;
- (unsigned int)decodeReferenceLength:(id)arg1;
- (unsigned int)decodeReferenceInt:(id)arg1 andWidth:(unsigned int)arg2;
- (id)decompressJson:(id)arg1;
- (_Bool)parseJson:(id)arg1;
- (unsigned int)checkSessionPageId;
- (_Bool)needRptSessionDetail;
- (id)toSessionConfig;
- (_Bool)isSessionPageConfig;
- (_Bool)isSessionUBAConfig;
- (_Bool)isSessionConfig;
- (_Bool)isXLabExpt;
- (_Bool)needReport;
- (_Bool)isReady;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
