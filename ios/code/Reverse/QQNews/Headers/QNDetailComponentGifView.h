//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSDWebGIFImageView.h"

#import "QNDetailComponentViewProtocol.h"

@class CArticleContentImageNodeType, QNArticleImageProgressView, QNBaseLabel, UIImageView;

@interface QNDetailComponentGifView : QNSDWebGIFImageView <QNDetailComponentViewProtocol>
{
    _Bool _gifLoaded;
    CArticleContentImageNodeType *_gifNode;
    CDUnknownBlockType _clickBlock;
    CDUnknownBlockType _finishLoadBlock;
    UIImageView *_coverImage;
    QNBaseLabel *_gifTipLabel;
    QNArticleImageProgressView *_progressView;
}

@property(nonatomic) _Bool gifLoaded; // @synthesize gifLoaded=_gifLoaded;
@property(retain, nonatomic) QNArticleImageProgressView *progressView; // @synthesize progressView=_progressView;
@property(retain, nonatomic) QNBaseLabel *gifTipLabel; // @synthesize gifTipLabel=_gifTipLabel;
@property(retain, nonatomic) UIImageView *coverImage; // @synthesize coverImage=_coverImage;
@property(copy, nonatomic) CDUnknownBlockType finishLoadBlock; // @synthesize finishLoadBlock=_finishLoadBlock;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
@property(retain, nonatomic) CArticleContentImageNodeType *gifNode; // @synthesize gifNode=_gifNode;
- (void).cxx_destruct;
- (void)cancelGifImageDownLoad;
- (void)tryStopAnimating;
- (void)tryStartAnimatingOrStartLoadingGifImage;
- (void)startAnimatingIfLoaded;
- (void)layoutWithGifNode:(id)arg1 clickBlock:(CDUnknownBlockType)arg2 finishLoadBlock:(CDUnknownBlockType)arg3;
- (void)viewWillEnterRecyclePool;
- (void)viewWillLeaveRecyclePool;
- (void)_handleClickGifImage;
- (_Bool)shouldAutoPlayGif;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;

@end
