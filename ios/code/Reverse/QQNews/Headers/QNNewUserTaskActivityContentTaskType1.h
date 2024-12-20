//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNNewUserActivityContentProtocol.h"
#import "QNNewUserTaskActivityPrizeUnitDelegate.h"

@class NSArray, NSString, QNTaskActivityModel;

@interface QNNewUserTaskActivityContentTaskType1 : UIView <QNNewUserActivityContentProtocol, QNNewUserTaskActivityPrizeUnitDelegate>
{
    QNTaskActivityModel *_activityModel;
    NSArray *_prizeUnitList;
}

@property(copy, nonatomic) NSArray *prizeUnitList; // @synthesize prizeUnitList=_prizeUnitList;
@property(retain, nonatomic) QNTaskActivityModel *activityModel; // @synthesize activityModel=_activityModel;
- (void).cxx_destruct;
- (void)setSelectedModel:(id)arg1;
- (id)getActivityView;
- (void)layoutWithActivityModel:(id)arg1;
- (void)setFrameWidth:(double)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

