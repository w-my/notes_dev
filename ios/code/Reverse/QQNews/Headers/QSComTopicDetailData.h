//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSStatedData.h"

@class NSDictionary, NSString, QSTopicDetailItem;

@interface QSComTopicDetailData : QSStatedData
{
    NSString *_tid;
    NSDictionary *_report;
}

+ (_Bool)cleanCacheWhenUserChanged;
+ (void)userLoginStateChanged;
+ (void)cleanCacheWhenCommunityUserAttendStatusChanged:(id)arg1;
+ (void)load;
@property(retain, nonatomic) NSDictionary *report; // @synthesize report=_report;
@property(copy, nonatomic) NSString *tid; // @synthesize tid=_tid;
- (void).cxx_destruct;
@property(readonly, nonatomic) __weak QSTopicDetailItem *topicDetailItem; // @dynamic topicDetailItem;
- (void)resetWithResponseModel:(id)arg1;
- (id)identifier;
- (id)httpURLComponents;
- (void)clearCurrentCache;
- (void)saveToFile;

@end
