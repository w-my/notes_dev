//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class KBListItemCollection, NSArray, NSString, QNAdItem, QNLayoutTableView;

@protocol TADStreamStrategyProtocol <NSObject>

@optional
- (void)checkAdCellExposureFrom:(unsigned long long)arg1 tableView:(QNLayoutTableView *)arg2;
- (QNAdItem *)getReplaceAdForItem:(QNAdItem *)arg1;
- (void)didFinishMergeWithItems:(NSArray *)arg1 itemCollection:(KBListItemCollection *)arg2 curIndex:(long long)arg3 pluginIndex:(long long)arg4;
- (void)parseRTStreamAdResponse:(NSString *)arg1 withDirection:(unsigned long long)arg2;
- (void)requestStreamAdsForCurIndex:(NSString *)arg1;
@end

