//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QSEntranceSportsTabInfo, QSMatchHeaderEntranceView;

@protocol QSMatchHeaderEntranceViewDelegate <NSObject>
- (void)vipButtonDidTapInMatchHeaderEntranceView:(QSMatchHeaderEntranceView *)arg1 entranceSportsTabInfo:(QSEntranceSportsTabInfo *)arg2;
- (void)communityButtonDidTapInMatchHeaderEntranceView:(QSMatchHeaderEntranceView *)arg1;
- (void)matchEntranceButtonDidTapInMatchHeaderEntranceView:(QSMatchHeaderEntranceView *)arg1;
- (void)dataButtonDidTapInMatchHeaderEntranceView:(QSMatchHeaderEntranceView *)arg1;
- (void)matchButtonDidTapInMatchHeaderEntranceView:(QSMatchHeaderEntranceView *)arg1;
@end
