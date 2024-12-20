//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNScreenShotNotificationAlertViewDelegate.h"

@class NSMutableArray, NSString, QNScreenShotNotificationAlertView, QNWatermarkItem, UIImage, __QNScreenshotBossBackApi;

@interface QNScreenshotNotificationListener : NSObject <QNScreenShotNotificationAlertViewDelegate>
{
    NSMutableArray *_tipViews;
    QNWatermarkItem *_selectMarkItem;
    UIImage *_screenshotImage;
    __QNScreenshotBossBackApi *_screenshotBossBackApi;
    QNScreenShotNotificationAlertView *_screenShotAlertView;
}

+ (id)sharedInstance;
@property(retain, nonatomic) QNScreenShotNotificationAlertView *screenShotAlertView; // @synthesize screenShotAlertView=_screenShotAlertView;
@property(retain, nonatomic) __QNScreenshotBossBackApi *screenshotBossBackApi; // @synthesize screenshotBossBackApi=_screenshotBossBackApi;
@property(retain, nonatomic) UIImage *screenshotImage; // @synthesize screenshotImage=_screenshotImage;
- (void).cxx_destruct;
- (void)screenShotAlertViewClicked;
- (void)screenShotAlertViewDisappear:(id)arg1;
- (void)p_handleScreenShot:(id)arg1;
- (void)p_handleScreenShotNoitication:(id)arg1;
- (void)p_appearScreenshotTipView:(id)arg1;
- (id)p_scaleImage:(id)arg1 toScale:(float)arg2;
- (_Bool)p_canScreenShot;
- (void)p_handleScreenShotNoiticationToFeedBack;
- (void)p_disapearTipView:(id)arg1;
- (void)hideTipViews;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

