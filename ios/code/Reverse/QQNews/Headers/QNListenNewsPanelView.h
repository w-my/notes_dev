//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNPanelButton;

@interface QNListenNewsPanelView : UIView
{
    UIView *_lineView;
    QNPanelButton *_rateButton;
    QNPanelButton *_timerButton;
    QNPanelButton *_shareButton;
    QNPanelButton *_listButton;
    _Bool _enable;
    CDUnknownBlockType _buttonAtcion;
}

@property(copy, nonatomic) CDUnknownBlockType buttonAtcion; // @synthesize buttonAtcion=_buttonAtcion;
@property(nonatomic) _Bool enable; // @synthesize enable=_enable;
- (void).cxx_destruct;
- (void)_remoteConfigRequestFinished;
- (void)_actionTapButton:(id)arg1;
- (void)_checkRemoteConfig;
- (void)updateRate;
- (void)updateTimer;
- (id)buttonWithImage:(id)arg1 title:(id)arg2 tag:(long long)arg3;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;

@end
