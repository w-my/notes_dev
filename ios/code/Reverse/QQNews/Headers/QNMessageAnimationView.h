//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSMutableArray, NSTimer, QNCache, QNMyMessageModel, QNRemindBadge;

@interface QNMessageAnimationView : QNThemableView
{
    _Bool _isAnimation;
    QNRemindBadge *_remindBadgeView;
    NSMutableArray *_imageViews;
    QNMyMessageModel *_messageModel;
    QNCache *_imageCache;
    NSTimer *_animationTimer;
    struct CGPoint _leftCenter;
    struct CGPoint _rightCenter;
    struct CGPoint _hideCenter;
}

@property(nonatomic) _Bool isAnimation; // @synthesize isAnimation=_isAnimation;
@property(retain, nonatomic) NSTimer *animationTimer; // @synthesize animationTimer=_animationTimer;
@property(retain, nonatomic) QNCache *imageCache; // @synthesize imageCache=_imageCache;
@property(nonatomic) struct CGPoint hideCenter; // @synthesize hideCenter=_hideCenter;
@property(nonatomic) struct CGPoint rightCenter; // @synthesize rightCenter=_rightCenter;
@property(nonatomic) struct CGPoint leftCenter; // @synthesize leftCenter=_leftCenter;
@property(retain, nonatomic) QNMyMessageModel *messageModel; // @synthesize messageModel=_messageModel;
@property(retain, nonatomic) NSMutableArray *imageViews; // @synthesize imageViews=_imageViews;
@property(nonatomic) __weak QNRemindBadge *remindBadgeView; // @synthesize remindBadgeView=_remindBadgeView;
- (void).cxx_destruct;
- (void)p_setImageView:(id)arg1 imageWithUrl:(id)arg2;
- (void)layoutWithMessageModel:(id)arg1;
- (void)p_animationTimerHandleAction;
- (void)p_stopTimer;
- (void)p_startTimerIfNeeded;
- (void)setupImageViewAtIndex:(unsigned long long)arg1;
- (void)setupImages;
- (void)layoutBadgeValueWithImageView:(id)arg1;
- (void)moreMessagesAnimatedLayout;
- (void)singleMessageLayout;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

