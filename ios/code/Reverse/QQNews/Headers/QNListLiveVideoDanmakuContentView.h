//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNListCellAnimationMonitorProtocol.h"

@class NSArray, NSString, NSTimer, QNListVideoDanmakuLbl;

@interface QNListLiveVideoDanmakuContentView : QNThemableView <QNListCellAnimationMonitorProtocol>
{
    NSArray *_messageList;
    long long _currentIndex;
    NSTimer *_timer;
    unsigned long long _animState;
    double _lastStartFireTime;
    QNListVideoDanmakuLbl *_danmakuLbl1;
    QNListVideoDanmakuLbl *_danmakuLbl2;
    QNListVideoDanmakuLbl *_currentDanmakuLbl;
}

+ (struct CGSize)danmakuContentViewSize;
@property(retain, nonatomic) QNListVideoDanmakuLbl *currentDanmakuLbl; // @synthesize currentDanmakuLbl=_currentDanmakuLbl;
@property(retain, nonatomic) QNListVideoDanmakuLbl *danmakuLbl2; // @synthesize danmakuLbl2=_danmakuLbl2;
@property(retain, nonatomic) QNListVideoDanmakuLbl *danmakuLbl1; // @synthesize danmakuLbl1=_danmakuLbl1;
@property(nonatomic) double lastStartFireTime; // @synthesize lastStartFireTime=_lastStartFireTime;
@property(nonatomic) unsigned long long animState; // @synthesize animState=_animState;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) long long currentIndex; // @synthesize currentIndex=_currentIndex;
@property(copy, nonatomic) NSArray *messageList; // @synthesize messageList=_messageList;
- (void).cxx_destruct;
- (void)p_doAnimating;
- (_Bool)canReuseCellWithListItem:(id)arg1;
- (void)resetCellAnimation;
- (void)stopCellAnimation;
- (void)startCellAnimation;
- (void)hideDanamaku;
- (void)showDanmakuWithMessage:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
