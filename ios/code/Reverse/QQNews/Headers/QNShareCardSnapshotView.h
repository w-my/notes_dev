//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSObject<OS_dispatch_semaphore>, QNBaseLabel, QNShareCardEditorView, QNShareCardModel, QNShareCardNumbersView, QNShareCardQRCodeContentView, QNShareCardVipInfoView, UIImage, UIImageView;

@interface QNShareCardSnapshotView : UIView
{
    QNShareCardModel *_cardModel;
    UIImage *_snapshotImage;
    UIImageView *_logoView;
    UIView *_cardBgView;
    UIView *_cardShadowView;
    UIImageView *_avatarView;
    QNBaseLabel *_nameLabel;
    QNShareCardEditorView *_editorView;
    QNShareCardVipInfoView *_vipInfoView;
    QNShareCardNumbersView *_numbersView;
    QNShareCardQRCodeContentView *_qrcodeContentView;
    QNBaseLabel *_descLabel;
    NSObject<OS_dispatch_semaphore> *_snapshot_lock;
}

@property(retain, nonatomic) NSObject<OS_dispatch_semaphore> *snapshot_lock; // @synthesize snapshot_lock=_snapshot_lock;
@property(nonatomic) __weak QNBaseLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(nonatomic) __weak QNShareCardQRCodeContentView *qrcodeContentView; // @synthesize qrcodeContentView=_qrcodeContentView;
@property(nonatomic) __weak QNShareCardNumbersView *numbersView; // @synthesize numbersView=_numbersView;
@property(nonatomic) __weak QNShareCardVipInfoView *vipInfoView; // @synthesize vipInfoView=_vipInfoView;
@property(nonatomic) __weak QNShareCardEditorView *editorView; // @synthesize editorView=_editorView;
@property(nonatomic) __weak QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(nonatomic) __weak UIImageView *avatarView; // @synthesize avatarView=_avatarView;
@property(nonatomic) __weak UIView *cardShadowView; // @synthesize cardShadowView=_cardShadowView;
@property(nonatomic) __weak UIView *cardBgView; // @synthesize cardBgView=_cardBgView;
@property(nonatomic) __weak UIImageView *logoView; // @synthesize logoView=_logoView;
@property(readonly, nonatomic) UIImage *snapshotImage; // @synthesize snapshotImage=_snapshotImage;
@property(retain, nonatomic) QNShareCardModel *cardModel; // @synthesize cardModel=_cardModel;
- (void).cxx_destruct;
- (void)snapshotCardViewWithCompletion:(CDUnknownBlockType)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
