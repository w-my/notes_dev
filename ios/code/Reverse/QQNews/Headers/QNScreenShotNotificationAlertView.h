//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIWindow.h"

#import "UIScrollViewDelegate.h"

@class NSString, QNBaseLabel, UIImageView, UIScrollView, UITapGestureRecognizer, UIView;

@interface QNScreenShotNotificationAlertView : UIWindow <UIScrollViewDelegate>
{
    id <QNScreenShotNotificationAlertViewDelegate> _alertViewDelegate;
    UIImageView *_screenShotImage;
    QNBaseLabel *_remindLbl;
    UITapGestureRecognizer *_tapGesture;
    UIView *_backgroundView;
    UIScrollView *_scrollView;
    struct CGSize _qnFrameSize;
}

@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(retain, nonatomic) UIView *backgroundView; // @synthesize backgroundView=_backgroundView;
@property(nonatomic) struct CGSize qnFrameSize; // @synthesize qnFrameSize=_qnFrameSize;
@property(retain, nonatomic) UITapGestureRecognizer *tapGesture; // @synthesize tapGesture=_tapGesture;
@property(retain, nonatomic) QNBaseLabel *remindLbl; // @synthesize remindLbl=_remindLbl;
@property(retain, nonatomic) UIImageView *screenShotImage; // @synthesize screenShotImage=_screenShotImage;
@property(nonatomic) __weak id <QNScreenShotNotificationAlertViewDelegate> alertViewDelegate; // @synthesize alertViewDelegate=_alertViewDelegate;
- (void).cxx_destruct;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)_handleOrientationChanged;
- (void)_dismissScreenShotAlertViewAfterWhile;
- (void)_handleTapGesture:(id)arg1;
- (void)dissmissScreenShotAlertViewWithAnimation:(_Bool)arg1;
- (void)showScreenShotAlertViewWithScreenShotImage:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

