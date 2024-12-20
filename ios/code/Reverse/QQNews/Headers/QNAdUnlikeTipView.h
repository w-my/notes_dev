//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRecommendUnlikeTipViewBase.h"

@class KBListItem, QNColorButton, QNListNewsItem, UIButton, UIImageView, UIView;

@interface QNAdUnlikeTipView : QNRecommendUnlikeTipViewBase
{
    _Bool _unlikeTipShow;
    _Bool _useNightTheme;
    long long _type;
    QNColorButton *_complaintBtn;
    QNColorButton *_unlikeBtn;
    UIView *_backgroundContainer;
    QNListNewsItem *_listItem;
    KBListItem *_kbListItem;
    UIImageView *_sep;
    UIImageView *_arrowView;
    UIButton *_cancelBackground;
}

@property(retain, nonatomic) UIButton *cancelBackground; // @synthesize cancelBackground=_cancelBackground;
@property(nonatomic) _Bool useNightTheme; // @synthesize useNightTheme=_useNightTheme;
@property(retain, nonatomic) UIImageView *arrowView; // @synthesize arrowView=_arrowView;
@property(retain, nonatomic) UIImageView *sep; // @synthesize sep=_sep;
@property(nonatomic) _Bool unlikeTipShow; // @synthesize unlikeTipShow=_unlikeTipShow;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) UIView *backgroundContainer; // @synthesize backgroundContainer=_backgroundContainer;
@property(retain, nonatomic) QNColorButton *unlikeBtn; // @synthesize unlikeBtn=_unlikeBtn;
@property(retain, nonatomic) QNColorButton *complaintBtn; // @synthesize complaintBtn=_complaintBtn;
@property(nonatomic) long long type; // @synthesize type=_type;
- (void).cxx_destruct;
- (void)close;
- (void)p_receivedNotification:(id)arg1;
- (void)p_disappearWithUnlikeOperation:(long long)arg1;
- (void)p_unlike:(id)arg1;
- (void)p_cancel:(id)arg1;
- (void)p_complaint:(id)arg1;
- (void)showUnlikeTipsInTableViewCell:(id)arg1 position:(struct CGPoint)arg2 kbListItem:(id)arg3 completion:(CDUnknownBlockType)arg4;
- (void)showUnlikeTipsInTableViewCell:(id)arg1 position:(struct CGPoint)arg2 listItem:(id)arg3 completion:(CDUnknownBlockType)arg4;
- (void)dealloc;
- (void)p_configUnlikeBtn;
- (void)themeChanged:(long long)arg1;
- (void)p_cancel;
- (void)p_appear;
- (id)init;
- (id)initWithType:(long long)arg1 nightTheme:(_Bool)arg2;
- (id)initWithType:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

