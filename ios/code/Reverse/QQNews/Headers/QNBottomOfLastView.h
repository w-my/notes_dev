//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class KBNewsDetailDeclareApi, QNBaseLabel, QNEnlargeHitTestButton, QNListNewsItem, QNVideoDetailItem, QNVideoSupportHeartButton;

@interface QNBottomOfLastView : UIView
{
    _Bool _didSupported;
    id <QNVideoDetaillmmerseBarHandle> _bottomOfLastViewDegate;
    QNEnlargeHitTestButton *_commButton;
    QNBaseLabel *_commentCountLabel;
    QNVideoSupportHeartButton *_supportButton;
    QNEnlargeHitTestButton *_sharButton;
    KBNewsDetailDeclareApi *_declareInfoApi;
    QNListNewsItem *_listItem;
    QNVideoDetailItem *_detailItem;
}

@property(nonatomic) _Bool didSupported; // @synthesize didSupported=_didSupported;
@property(retain, nonatomic) QNVideoDetailItem *detailItem; // @synthesize detailItem=_detailItem;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) KBNewsDetailDeclareApi *declareInfoApi; // @synthesize declareInfoApi=_declareInfoApi;
@property(retain, nonatomic) QNEnlargeHitTestButton *sharButton; // @synthesize sharButton=_sharButton;
@property(retain, nonatomic) QNVideoSupportHeartButton *supportButton; // @synthesize supportButton=_supportButton;
@property(retain, nonatomic) QNBaseLabel *commentCountLabel; // @synthesize commentCountLabel=_commentCountLabel;
@property(retain, nonatomic) QNEnlargeHitTestButton *commButton; // @synthesize commButton=_commButton;
@property(nonatomic) __weak id <QNVideoDetaillmmerseBarHandle> bottomOfLastViewDegate; // @synthesize bottomOfLastViewDegate=_bottomOfLastViewDegate;
- (void).cxx_destruct;
- (void)p_doPraise:(_Bool)arg1;
- (void)p_praiseVideo:(_Bool)arg1;
- (void)p_likeBtnClicked;
- (void)p_handleMoreClick;
- (void)p_handleCommentClick;
- (void)p_initSupportLikeButtonView;
- (id)p_supportString;
- (void)p_updateSupportCount;
- (id)getAttribuedString;
- (struct CGSize)getSupportSize;
- (void)refreshBottomOfLastViewData:(id)arg1;
- (void)setSupportButtonEnable:(_Bool)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;

@end
