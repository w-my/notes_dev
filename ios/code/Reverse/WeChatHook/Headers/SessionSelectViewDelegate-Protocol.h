//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CContact, MMUIViewController, NSArray, NSDictionary, NSString, SessionSelectView;

@protocol SessionSelectViewDelegate <NSObject>
- (MMUIViewController *)getViewController;
- (void)OnSelectSession:(CContact *)arg1 SelectView:(SessionSelectView *)arg2;

@optional
- (void)contactInBizChatSessionViewDidSelect:(CContact *)arg1;
- (CContact *)contactInBizChatSessionViewAtRow:(unsigned long long)arg1;
- (long long)numberOfRowInBizChatSessionView;
- (NSString *)sectionTitleForBizChatSessionView;
- (_Bool)showChatRoomOnly;
- (void)onSelectChatRoomWithArrKeywords:(NSArray *)arg1;
- (void)selectViewWillBeginDragging:(SessionSelectView *)arg1;
- (void)onSessionSelectSearchSessions:(NSArray *)arg1 sectionTitles:(NSDictionary *)arg2 sectionResults:(NSDictionary *)arg3;
- (void)OnSelectFromContactSelectView:(SessionSelectView *)arg1;
- (void)OnSelectEnterpriseChat:(CContact *)arg1 SelectView:(SessionSelectView *)arg2;
- (void)OnSelectCreateRoomSelectView:(SessionSelectView *)arg1;
- (NSString *)onSessionSelectGetSearchString;
- (void)onSessionSelectSearch:(NSArray *)arg1;
- (_Bool)onShouldSelectContact:(CContact *)arg1;
@end

