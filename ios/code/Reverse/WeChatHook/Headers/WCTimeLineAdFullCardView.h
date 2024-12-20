//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCContentItemBaseView.h"

#import "WCSightViewDelegate.h"

@class CAShapeLayer, NSArray, NSMutableArray, NSString, UIBezierPath, UIButton, UIColor, UIImageView, UILabel, UIPanGestureRecognizer, WCGestureReportInfo;

@interface WCTimeLineAdFullCardView : WCContentItemBaseView <WCSightViewDelegate>
{
    UIImageView *weAppLogo;
    UILabel *weAppTips;
    unsigned long long m_uiGestureStartTime;
    unsigned long long m_uiGestureEndTime;
    double m_uiGestureDistance;
    NSArray *m_uiGestureTargetPoint;
    NSArray *m_uiGestureTargetPointReverse;
    UIColor *m_uiGestureColor;
    _Bool m_IsGestureAd;
    UIPanGestureRecognizer *m_uiPanGestureRecognizer;
    unsigned int m_sourceType;
    UIButton *_adTouchButton;
    CAShapeLayer *_slayer;
    UIBezierPath *_bPath;
    NSMutableArray *_sourcePoints;
    WCGestureReportInfo *_gestureReportInfo;
}

+ (double)heightForMedia:(id)arg1;
@property(retain, nonatomic) WCGestureReportInfo *gestureReportInfo; // @synthesize gestureReportInfo=_gestureReportInfo;
@property(retain, nonatomic) NSMutableArray *sourcePoints; // @synthesize sourcePoints=_sourcePoints;
@property(retain, nonatomic) UIBezierPath *bPath; // @synthesize bPath=_bPath;
@property(retain, nonatomic) CAShapeLayer *slayer; // @synthesize slayer=_slayer;
@property(retain, nonatomic) UIButton *adTouchButton; // @synthesize adTouchButton=_adTouchButton;
- (void).cxx_destruct;
- (void)onPlayEnd;
- (void)onPlaybackTimeUpdate:(double)arg1;
- (long long)getSamplingInterval:(long long)arg1;
- (void)onGestureEnd:(struct CGPoint)arg1;
- (void)unregisterUIPanGestureRecognizer;
- (void)registerUIPanGestureRecognizer;
- (void)onUIGesureEvent:(id)arg1;
- (void)startGestureWithoutWCPlayer;
- (void)initUIGesture:(id)arg1;
- (void)dealloc;
- (void)onClick:(_Bool)arg1;
- (void)delayClearTouchButtonColor;
- (void)delayClickAdTouchButton;
- (void)onClickAdTouchButton:(id)arg1 forEvent:(id)arg2;
- (void)addButtonForItem:(id)arg1;
- (id)genRichTextViewWithFont:(double)arg1 And:(id)arg2;
- (void)genWeAppLogoAndTip;
- (void)addTitleAndDescriptionForItem:(id)arg1;
- (void)addSightViewWithMediaItem:(id)arg1;
- (void)addImageViewWithMediaItem:(id)arg1;
- (void)addMediaViewForItem:(id)arg1;
- (void)initViewsWithWCDataItem:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

