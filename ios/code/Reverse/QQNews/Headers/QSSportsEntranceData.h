//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSEntranceData.h"

@class QSEntranceSportsInfo;

@interface QSSportsEntranceData : QSEntranceData
{
    _Bool _isDetailModeChanged;
    _Bool _isWinterOlympicsModeChanged;
    _Bool _isFirstLoadFinished;
    _Bool _needForceUpdate;
}

@property(nonatomic) _Bool needForceUpdate; // @synthesize needForceUpdate=_needForceUpdate;
@property(nonatomic) _Bool isFirstLoadFinished; // @synthesize isFirstLoadFinished=_isFirstLoadFinished;
@property(readonly, nonatomic) _Bool isWinterOlympicsModeChanged; // @synthesize isWinterOlympicsModeChanged=_isWinterOlympicsModeChanged;
@property(readonly, nonatomic) _Bool isDetailModeChanged; // @synthesize isDetailModeChanged=_isDetailModeChanged;
@property(readonly, nonatomic) _Bool isWinterOlympicsMode;
@property(readonly, nonatomic) _Bool isDetailMode;
- (void)resetWithModel:(id)arg1;
- (void)resetWithResponseModel:(id)arg1;
- (void)resetWithAutoRefreshModels:(id)arg1;
- (id)autoUpdateHttpURLComponents;
- (id)mids;
- (id)httpURLComponents;
- (void)updateData;
- (void)reloadDataWithCache:(_Bool)arg1;
- (_Bool)canUpdate;
- (double)updateTimeInterval;
@property(readonly, nonatomic) QSEntranceSportsInfo *model;
- (id)identifier;

@end
