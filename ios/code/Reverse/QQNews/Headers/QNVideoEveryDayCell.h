//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "QNCommonCellAssistantViewDelegate.h"
#import "QNCommonListVideoCellProtocol.h"

@class CSimpleImageView, KBListItem, KBTableViewCellLayoutContext, NSString, QNCommonCellAssistantView, QNListNewsItem, QNListVideoEveryDayView, UIButton, UIImageView, UILabel, UIView;

@interface QNVideoEveryDayCell : KBTableViewCell <QNCommonCellAssistantViewDelegate, QNCommonListVideoCellProtocol>
{
    CDUnknownBlockType _clickBlock;
    NSString *_ownerChannelId;
    QNListNewsItem *_listItem;
    KBListItem *_kbListItem;
    KBTableViewCellLayoutContext *_context;
    CDUnknownBlockType _playVideoBlock;
    UIView *_topView;
    CSimpleImageView *_titleImageView;
    UILabel *_leftTitle;
    UIButton *_openBtn;
    QNListVideoEveryDayView *_playerView;
    UIView *_bgView;
    QNCommonCellAssistantView *_assistantView;
    UIImageView *_bottomLine;
    NSString *_channelId;
}

+ (double)p_topViewHeight;
+ (struct CGSize)p_playViewSize;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(copy, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNCommonCellAssistantView *assistantView; // @synthesize assistantView=_assistantView;
@property(retain, nonatomic) UIView *bgView; // @synthesize bgView=_bgView;
@property(retain, nonatomic) QNListVideoEveryDayView *playerView; // @synthesize playerView=_playerView;
@property(retain, nonatomic) UIButton *openBtn; // @synthesize openBtn=_openBtn;
@property(retain, nonatomic) UILabel *leftTitle; // @synthesize leftTitle=_leftTitle;
@property(retain, nonatomic) CSimpleImageView *titleImageView; // @synthesize titleImageView=_titleImageView;
@property(retain, nonatomic) UIView *topView; // @synthesize topView=_topView;
@property(copy, nonatomic) CDUnknownBlockType playVideoBlock; // @synthesize playVideoBlock=_playVideoBlock;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) NSString *ownerChannelId; // @synthesize ownerChannelId=_ownerChannelId;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
- (void).cxx_destruct;
- (void)p_openBtnClick;
- (void)p_handleTapGesture;
- (void)p_resetBottomView;
- (void)p_resetMiddelView;
- (void)p_resetTopView;
- (id)subTitleColor;
- (void)p_layoutBottomView;
- (void)p_layoutMiddleView;
- (void)p_layoutTopView;
- (void)p_setupBottomView;
- (void)p_setupMiddleView;
- (void)p_setupTopView;
- (void)playVideo;
- (_Bool)shouldAutoPlayVideo;
- (void)updateViews;
- (id)getAttachImage;
- (id)getAttachPlayerView;
- (id)getProtocolVideoContentView;
- (id)getProtocolListItem;
- (void)assistantView:(id)arg1 onButtonClick:(id)arg2;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)layoutSubviews;
- (void)themeChanged:(long long)arg1;
- (void)p_resetViews;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

