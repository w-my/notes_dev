//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNTableViewCell.h"

#import "CAAnimationDelegate.h"
#import "QNCommonListVideoCellProtocol.h"
#import "QNListCellProtocol.h"
#import "QNTableViewCellReloadProtocol.h"

@class NSString, QNAvatarView, QNEnlargeHitTestButton, QNListSingleImageUnit, QNReportParam, QNTopicCellTitleUnit, QNTopicModuleFooterView, QNTopicModuleHeaderView, QNWeiboCellHeaderUnit, QNWeiboCellModel, QNWeiboDetailFooterView, QNWeiboDetailOriginalLinkView, QNWeiboLocationView, UIImageView;

@interface QNWeiboCell : QNTableViewCell <CAAnimationDelegate, QNListCellProtocol, QNCommonListVideoCellProtocol, QNTableViewCellReloadProtocol>
{
    id <QNWeiboCellActionDelegate> _actionDelegate;
    CDUnknownBlockType _subButtonBlock;
    QNReportParam *_reportParam;
    QNWeiboCellHeaderUnit *_headerUnit;
    QNTopicCellTitleUnit *_textUnit;
    QNListSingleImageUnit *_imageUnit;
    QNWeiboLocationView *_locationUnit;
    QNWeiboDetailFooterView *_toolbar;
    QNEnlargeHitTestButton *_locationButton;
    QNAvatarView *_secondAvatarView;
    QNWeiboDetailOriginalLinkView *_linkView;
    QNTopicModuleHeaderView *_moduleHeaderView;
    QNTopicModuleFooterView *_moduleFooterView;
    UIImageView *_saperatorView;
    QNWeiboCellModel *_cellModel;
}

@property(retain, nonatomic) QNWeiboCellModel *cellModel; // @synthesize cellModel=_cellModel;
@property(retain, nonatomic) UIImageView *saperatorView; // @synthesize saperatorView=_saperatorView;
@property(retain, nonatomic) QNTopicModuleFooterView *moduleFooterView; // @synthesize moduleFooterView=_moduleFooterView;
@property(retain, nonatomic) QNTopicModuleHeaderView *moduleHeaderView; // @synthesize moduleHeaderView=_moduleHeaderView;
@property(retain, nonatomic) QNWeiboDetailOriginalLinkView *linkView; // @synthesize linkView=_linkView;
@property(retain, nonatomic) QNAvatarView *secondAvatarView; // @synthesize secondAvatarView=_secondAvatarView;
@property(retain, nonatomic) QNEnlargeHitTestButton *locationButton; // @synthesize locationButton=_locationButton;
@property(retain, nonatomic) QNWeiboDetailFooterView *toolbar; // @synthesize toolbar=_toolbar;
@property(retain, nonatomic) QNWeiboLocationView *locationUnit; // @synthesize locationUnit=_locationUnit;
@property(retain, nonatomic) QNListSingleImageUnit *imageUnit; // @synthesize imageUnit=_imageUnit;
@property(retain, nonatomic) QNTopicCellTitleUnit *textUnit; // @synthesize textUnit=_textUnit;
@property(retain, nonatomic) QNWeiboCellHeaderUnit *headerUnit; // @synthesize headerUnit=_headerUnit;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(copy, nonatomic) CDUnknownBlockType subButtonBlock; // @synthesize subButtonBlock=_subButtonBlock;
@property(nonatomic) __weak id <QNWeiboCellActionDelegate> actionDelegate; // @synthesize actionDelegate=_actionDelegate;
- (void).cxx_destruct;
- (void)playVideoManual;
- (void)playVideo;
- (void)updateViews;
- (id)getAttachImage;
- (id)getAttachPlayerView;
- (id)getProtocolVideoContentView;
- (id)getProtocolListItem;
- (id)p_imageBroswerItem;
- (void)p_applyDefaultSelectedBackgroundView;
- (void)p_onConfigChanged;
- (void)p_viewLocation;
- (void)p_delete;
- (void)p_onTopic;
- (void)p_like;
- (void)p_share;
- (void)p_viewComment;
- (void)prepareForReuse;
- (void)setSubButtonHidden:(_Bool)arg1;
- (void)p_delyStartAnimation;
- (void)animationDidStop:(id)arg1 finished:(_Bool)arg2;
- (void)animationDidStart:(id)arg1;
- (void)p_buildSecondAvatarView;
- (void)p_startHeadImageViewAnimation;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (void)dealloc;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (id)commentItem;
- (void)setCommentItem:(id)arg1;
- (id)controller;
- (void)setController:(id)arg1;
- (CDUnknownBlockType)responseBlock;
- (void)setResponseBlock:(CDUnknownBlockType)arg1;
- (void)p_updateCommentItem:(id)arg1 withDeclareState:(long long)arg2 kbItem:(id)arg3;
- (id)p_optinalShareData:(id)arg1;
- (id)p_generateItemByCommentItem:(id)arg1;
- (id)getCustomShareInfo;
- (void)weiboCell:(id)arg1 actionToViewImage:(id)arg2;
- (void)weiboCell:(id)arg1 actionToDelete:(id)arg2;
- (void)weiboCell:(id)arg1 actionToResend:(id)arg2;
- (void)weiboCell:(id)arg1 actionToPlayVideo:(id)arg2 isAutoPlay:(_Bool)arg3;
- (void)weiboCell:(id)arg1 actionToViewDetail:(id)arg2 viewComment:(_Bool)arg3;
- (void)weiboCell:(id)arg1 actionToShare:(id)arg2;
- (void)weiboCell:(id)arg1 actionToViewTopic:(id)arg2;
- (void)weiboCell:(id)arg1 actionToLike:(id)arg2;
- (void)weiboCell:(id)arg1 actionToViewPersonalDetail:(id)arg2;
- (void)addActionHandlerWithCurrentController:(id)arg1 responseBlock:(CDUnknownBlockType)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
