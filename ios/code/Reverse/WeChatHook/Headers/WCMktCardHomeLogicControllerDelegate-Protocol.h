//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMUIViewController, NSIndexPath;

@protocol WCMktCardHomeLogicControllerDelegate <NSObject>
- (void)onUpdateTopCellWithIndexPath:(NSIndexPath *)arg1;
- (void)onTableViewNeedRefresh;
- (void)onUpdateStoreElemDataSuccWithIndexPath:(NSIndexPath *)arg1;
- (void)onTableviewGetHomePageDataFail;
- (void)onTableviewNeedReloadWhenGetResp;
- (void)onTableviewNeedReloadWhenLoadCache;
- (void)vcStopLoading;
- (void)vcStartLoading;
- (MMUIViewController *)getViewController;
@end

