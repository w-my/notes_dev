//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMSessionInfo, NSString;

@protocol mainFrameLogicControllerDelegate <NSObject>

@optional
- (void)clearSessionCache;
- (void)stopLoadingForSessionRebuild;
- (void)startLoadingForSessionRebuild;
- (void)stopIniting:(unsigned int)arg1;
- (void)percentIniting:(NSString *)arg1;
- (void)changeNetworkStatus:(unsigned int)arg1;
- (void)updateUnReadCount;
- (void)deleteSessionCell:(unsigned int)arg1 withUser:(NSString *)arg2;
- (void)selectCellForName:(NSString *)arg1;
- (void)cancelSelectedCell;
- (void)updateAllItemTimeLabel;
- (void)updateSession:(MMSessionInfo *)arg1;
- (void)reloadSessions;
@end

