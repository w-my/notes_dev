//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNVideoChannelCellBase.h"

#import "QNVideoAlbumBottomViewHandle.h"
#import "QNVideoDetaillmmerseBarHandle.h"

@class KBTableViewCellLayoutContext, NSString, QNRecommendUnlikeTipView, QNVideoAlbumBottomView, QNVideoCellBottomBar, QNVideoCellMiddleContent, QNVideoDetailItem, UIImageView;

@interface QNVideoChannelCellV2 : QNVideoChannelCellBase <QNVideoDetaillmmerseBarHandle, QNVideoAlbumBottomViewHandle>
{
    int _cellState;
    QNVideoCellMiddleContent *_middleContentView;
    QNVideoCellBottomBar *_bottomBar;
    QNVideoAlbumBottomView *_albumBottomView;
    id <QNVideoDetaillmmerseCellHandle> _cellHandleDegate;
    QNVideoDetailItem *_detailItem;
    QNRecommendUnlikeTipView *_unlikeTipView;
    UIImageView *_bottomLine;
    NSString *_channelId;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(retain, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
@property(nonatomic) int cellState; // @synthesize cellState=_cellState;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNRecommendUnlikeTipView *unlikeTipView; // @synthesize unlikeTipView=_unlikeTipView;
@property(retain, nonatomic) QNVideoDetailItem *detailItem; // @synthesize detailItem=_detailItem;
@property(nonatomic) __weak id <QNVideoDetaillmmerseCellHandle> cellHandleDegate; // @synthesize cellHandleDegate=_cellHandleDegate;
@property(retain, nonatomic) QNVideoAlbumBottomView *albumBottomView; // @synthesize albumBottomView=_albumBottomView;
@property(retain, nonatomic) QNVideoCellBottomBar *bottomBar; // @synthesize bottomBar=_bottomBar;
@property(retain, nonatomic) QNVideoCellMiddleContent *middleContentView; // @synthesize middleContentView=_middleContentView;
- (void).cxx_destruct;
- (void)hideBottomLine:(_Bool)arg1;
- (id)getMoreButton;
- (id)getSupportButton;
- (struct CGRect)videoDisplayRect;
- (_Bool)attachPlayer:(id)arg1;
- (void)showShareButtonWithAnimation:(_Bool)arg1;
- (id)getAttachImage;
- (id)getAttachPlayerView;
- (double)getPlayAndStopPos;
- (id)getProtocolVideoContentView;
- (void)didClickLikeButton:(id)arg1;
- (void)didClickSharedButton:(id)arg1;
- (void)didClickCommentButton:(id)arg1;
- (void)didClickAlbumShareButton:(id)arg1;
- (void)didClickAlbumCommentButton:(id)arg1;
- (void)didClickAlbumSharedButton:(id)arg1;
- (void)didClickAlbumLikeButton:(id)arg1;
- (void)p_clickOM:(id)arg1;
- (_Bool)isPlayOnMine;
- (_Bool)isPlaying;
- (void)resetPosterView;
- (void)addPlayCount;
- (void)_unlikeThisNews:(id)arg1;
- (void)switchToCellState:(unsigned long long)arg1;
- (void)setTopBarCellType:(unsigned long long)arg1;
- (void)updateViews;
- (void)setupAlbumBottomView;
- (void)setupBottomBar;
- (void)_setupMiddleContent;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)updateCellWithVideoDetailitem:(id)arg1 type:(long long)arg2;
- (_Bool)shouldAutoPlayVideo;
- (void)layoutWithData:(id)arg1 context:(id)arg2;

// Remaining properties
@property(retain, nonatomic) KBTableViewCellLayoutContext *context;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
