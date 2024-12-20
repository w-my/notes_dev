//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class WCTimelineEditBehaviorInfo;

@interface WCTimelineEditBehaviorReporter : NSObject
{
    WCTimelineEditBehaviorInfo *_info;
}

+ (id)sharedInstance;
@property(retain, nonatomic) WCTimelineEditBehaviorInfo *info; // @synthesize info=_info;
- (void).cxx_destruct;
- (void)kvDataReport;
- (void)updatePublishID:(id)arg1;
- (void)clickLatestSetting;
- (void)importFromChatroomClickCount;
- (void)importFromContactClickCount;
- (void)visibleSettingClickCount;
- (void)chatroomDetailClickCount:(id)arg1;
- (void)updateSelectedContactlabel:(id)arg1;
- (void)updateSelectedContact:(id)arg1;
- (void)updateSelectedChatroom:(id)arg1;
- (void)updateTimelineStatuePost;
- (void)updateTimelineStatueCancel:(_Bool)arg1;
- (void)updatePostPrivacy:(int)arg1;
- (void)resetReporterStatus;

@end

