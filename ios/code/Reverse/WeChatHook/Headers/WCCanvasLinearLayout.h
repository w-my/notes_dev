//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCCanvasComponent.h"

#import "WCCanvasComponentDelegate.h"

@class NSMutableDictionary, NSString;

@interface WCCanvasLinearLayout : WCCanvasComponent <WCCanvasComponentDelegate>
{
    _Bool _needRelayout;
    NSMutableDictionary *_viewContainer;
}

+ (struct CGSize)calcSizeForCanvasItem:(id)arg1 dataItem:(id)arg2 orientation:(long long)arg3;
@property(nonatomic) _Bool needRelayout; // @synthesize needRelayout=_needRelayout;
@property(retain, nonatomic) NSMutableDictionary *viewContainer; // @synthesize viewContainer=_viewContainer;
- (void).cxx_destruct;
- (_Bool)getUseSnsCdnDownloadMode:(id)arg1;
- (void)onFavProductReturn:(unsigned int)arg1 errMsg:(id)arg2;
- (void)onComponentBeClicked:(id)arg1;
- (_Bool)shouldVideoLayerRasterize;
- (_Bool)isCurSectionBlackMoreThanWhite:(long long)arg1;
- (id)getBackGroundColorWhenLoading:(long long)arg1;
- (void)hideDownArrowIcon;
- (_Bool)secionHasShowDownArrow:(long long)arg1;
- (void)tryShowDownArrowAnimate:(long long)arg1;
- (void)jumpToWeAppBizTempSessionWithInfo:(id)arg1;
- (void)hideActionSheet;
- (void)showActionSheet:(id)arg1 body:(id)arg2 withIcon:(id)arg3 hideHeader:(_Bool)arg4 showCancelAction:(_Bool)arg5;
- (void)jumpToLocationPage:(id)arg1;
- (void)jumpToPhonePage:(id)arg1;
- (void)onBtnComponentClick:(long long)arg1;
- (void)canvasComponent:(id)arg1 shouldForceHideArrowDownImage:(_Bool)arg2;
- (id)getReportMgr;
- (id)tryAppendAdParamsForWeappPath:(id)arg1;
- (id)getWeAppSceneNoteForComponent:(id)arg1;
- (id)getAdUxInfo;
- (_Bool)isSearchCanvas;
- (id)getCurrentViewController;
- (void)getCanvasScene:(int *)arg1;
- (void)setLoading:(_Bool)arg1;
- (void)canvasComponent:(id)arg1 willJumpToCanvas:(id)arg2 canvasId:(id)arg3;
- (void)canvasComponent:(id)arg1 willShowViewController:(id)arg2;
- (void)canvasComponent:(id)arg1 willAddViewController:(id)arg2;
- (void)canvasComponent:(id)arg1 willExistAndJumpUrl:(id)arg2;
- (void)updateVoteAdInfo:(id)arg1 rightVoteInfo:(id)arg2;
- (void)resetSightViewAudioState:(_Bool)arg1;
- (void)componentWillStopState:(_Bool)arg1;
- (void)componentDidFullyApperaInMainScreen:(_Bool)arg1;
- (void)componentDidEnterBackground;
- (void)componentWillEnterForeground;
- (void)componentWillResumeState:(_Bool)arg1;
- (void)componentWillDisappearInMainScreen:(_Bool)arg1;
- (void)componentWillApperaInMainScreen:(_Bool)arg1;
- (void)configureWithCanvasItem:(id)arg1 dataItem:(id)arg2 orientation:(long long)arg3;
- (void)layoutSubviews;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

