//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBaseLabel, QNLoadingShimmerView, QNShareCardChannelsView, QNShareCardEditorView, QNShareCardModel, QNShareCardNumbersView, QNShareCardVipInfoView, UIImageView;

@interface QNShareCardContentView : QNThemableView
{
    QNShareCardModel *_cardModel;
    id <QNShareCardContentViewDelegate> _delegate;
    UIImageView *_avatarView;
    QNBaseLabel *_nameLabel;
    QNShareCardEditorView *_editorView;
    QNShareCardVipInfoView *_vipInfoView;
    QNShareCardNumbersView *_numbersView;
    UIImageView *_qrcodeView;
    QNShareCardChannelsView *_channelsView;
    QNLoadingShimmerView *_loadingView;
}

@property(nonatomic) __weak QNLoadingShimmerView *loadingView; // @synthesize loadingView=_loadingView;
@property(nonatomic) __weak QNShareCardChannelsView *channelsView; // @synthesize channelsView=_channelsView;
@property(nonatomic) __weak UIImageView *qrcodeView; // @synthesize qrcodeView=_qrcodeView;
@property(nonatomic) __weak QNShareCardNumbersView *numbersView; // @synthesize numbersView=_numbersView;
@property(nonatomic) __weak QNShareCardVipInfoView *vipInfoView; // @synthesize vipInfoView=_vipInfoView;
@property(nonatomic) __weak QNShareCardEditorView *editorView; // @synthesize editorView=_editorView;
@property(nonatomic) __weak QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(nonatomic) __weak UIImageView *avatarView; // @synthesize avatarView=_avatarView;
@property(nonatomic) __weak id <QNShareCardContentViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) QNShareCardModel *cardModel; // @synthesize cardModel=_cardModel;
- (void).cxx_destruct;
- (void)p_shareButtonsAction:(id)arg1;
- (void)p_processBorderWithImage:(id)arg1;
- (void)p_setAvatarWithUrl:(id)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

