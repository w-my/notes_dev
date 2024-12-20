//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MVCameraBottomBar, MVCameraBottomButton, MVFilterItem, MVMusicItem, UIGestureRecognizer;

@protocol MVCameraBottomBarDelegate <NSObject>
- (void)bottomBar:(MVCameraBottomBar *)arg1 didSelectMusicItem:(MVMusicItem *)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 handleZoomGesture:(UIGestureRecognizer *)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 onFilterPannelShowed:(_Bool)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 didUpdateBeautyType:(unsigned long long)arg2 strength:(double)arg3;
- (void)bottomBar:(MVCameraBottomBar *)arg1 onSelectSpeedRate:(double)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 didSelectFilter:(MVFilterItem *)arg2;
- (_Bool)bottomBar:(MVCameraBottomBar *)arg1 shouldSelectFilter:(MVFilterItem *)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 onTapMusicBtn:(MVCameraBottomButton *)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 onTapAlbumBtn:(MVCameraBottomButton *)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 onTapDoneBtn:(MVCameraBottomButton *)arg2;
- (void)bottomBar:(MVCameraBottomBar *)arg1 recordDidChangeFromState:(unsigned long long)arg2 toState:(unsigned long long)arg3;
- (void)bottomBar:(MVCameraBottomBar *)arg1 willChangeRecordStateTo:(unsigned long long)arg2;
- (_Bool)bottomBar:(MVCameraBottomBar *)arg1 shouldChangeRecordStateTo:(unsigned long long)arg2;
@end

