//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TADBaseStreamReportManager.h"

@interface TADRTStreamReportManager : TADBaseStreamReportManager
{
}

- (void)reportPVItem:(id)arg1 withExpSource:(unsigned long long)arg2;
- (void)checkAdCellExposureFrom:(unsigned long long)arg1 tableView:(id)arg2;
- (void)onCellLoaded:(id)arg1 parentView:(id)arg2 adItem:(id)arg3;
- (void)didFinishMergeWithItems:(id)arg1 itemCollection:(id)arg2 curIndex:(long long)arg3 pluginIndex:(long long)arg4;
- (void)p_updateAdListWithNewAdList:(id)arg1 hotSpotAdList:(id)arg2 refreshDirection:(unsigned long long)arg3;
- (void)parseRTStreamAdResponse:(id)arg1 withDirection:(unsigned long long)arg2;
- (id)adRequestDataFromCurList:(id)arg1 refreshDirection:(unsigned long long)arg2;
- (void)loadChannelAdInOffline:(_Bool)arg1 inFavorite:(_Bool)arg2;
- (void)reportDisabledLoadingForAdType:(id)arg1;
- (_Bool)canShowRtAdInChannel;

@end
