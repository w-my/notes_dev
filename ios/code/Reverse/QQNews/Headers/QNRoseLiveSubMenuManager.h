//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CSubMenuManager.h"

@class NSArray, NSString;

@interface QNRoseLiveSubMenuManager : CSubMenuManager
{
    unsigned long long _remoteConfigItems;
    NSArray *_webTabInfos;
    NSString *_talkTabTitle;
}

@property(copy, nonatomic) NSString *talkTabTitle; // @synthesize talkTabTitle=_talkTabTitle;
@property(copy, nonatomic) NSArray *webTabInfos; // @synthesize webTabInfos=_webTabInfos;
@property(nonatomic) unsigned long long remoteConfigItems; // @synthesize remoteConfigItems=_remoteConfigItems;
- (void).cxx_destruct;
- (id)getMenuItemByID:(id)arg1;
- (void)setRoseRoomWebTabInfo:(id)arg1;
- (id)createSubMenuItem:(id)arg1;
- (void)createSubMenuList;
- (id)p_talkTabTitleWithViewCount:(long long)arg1;
- (id)initWithConfig:(unsigned long long)arg1 itemInfos:(id)arg2 context:(id)arg3;
- (id)initWithConfig:(unsigned long long)arg1 context:(id)arg2;

@end
