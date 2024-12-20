//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "ContactsDataLogicDelegate.h"
#import "IWCMyStoryUserStateUtilExt.h"
#import "WCStoryFacadeExt.h"

@class ContactsDataLogic, MMTimer, NSMutableDictionary, NSString;

@interface WCStoryEntranceVM : NSObject <ContactsDataLogicDelegate, IWCMyStoryUserStateUtilExt, WCStoryFacadeExt>
{
    _Bool _shouldShowStoryEntrace;
    ContactsDataLogic *_dataLogic;
    struct NSMutableDictionary *_userContactDict;
    MMTimer *_reloadNotifyThrottle;
}

+ (_Bool)hasUnreadStory;
+ (id)entranceViewModel;
@property(nonatomic) _Bool shouldShowStoryEntrace; // @synthesize shouldShowStoryEntrace=_shouldShowStoryEntrace;
@property(retain, nonatomic) MMTimer *reloadNotifyThrottle; // @synthesize reloadNotifyThrottle=_reloadNotifyThrottle;
@property(retain, nonatomic) NSMutableDictionary *userContactDict; // @synthesize userContactDict=_userContactDict;
@property(retain, nonatomic) ContactsDataLogic *dataLogic; // @synthesize dataLogic=_dataLogic;
- (void).cxx_destruct;
- (void)onPermissionsHasChanged;
- (void)onUserRelatedCommentReadWithTid:(id)arg1;
- (void)onMakeAllUserRelatedCommentRead;
- (void)onMakeAllUserRelatedCommentWithUsername:(id)arg1;
- (void)onRelatedCommentAdd:(id)arg1;
- (void)onRelatedCommentDel:(id)arg1;
- (void)updateUnreadStatus;
- (void)onMarkStoryReadWithUserName:(id)arg1 Tid:(id)arg2;
- (void)onContactHasChange;
- (void)onSetNewLastReadMaxTid;
- (_Bool)onFilterContactCandidate:(id)arg1;
- (void)onContactsDataChange;
- (void)userDeleteStoryWithUserName:(id)arg1;
- (void)onClearUnreadStoryMarkWithUserName:(id)arg1;
- (void)onSetUnreadStoryMarkWithUserName:(id)arg1;
- (id)getTimestampUnreadUserNameArray;
- (void)reloadShouldShowStoryEntrace;
- (void)sendReloadNotify;
- (void)notifyReloadEntrance;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

