//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CArticleSection.h"

#import "CPictViewDelegate.h"
#import "QNDetailImageProgressUnitViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class CArticleContentImageNodeType, CArticleContentVideoExtendNode, CPictView, MTLabel, NSString, QNDetailImageProgressUnitView, UILabel, UIScrollView;

@interface CMultiPicsArticleSection : CArticleSection <UIScrollViewDelegate, CPictViewDelegate, QNDetailImageProgressUnitViewDelegate>
{
    MTLabel *_desc;
    _Bool _useNativeView;
    _Bool _isImageInTruth;
    _Bool _isImageInTimeLine;
    CPictView *_pic;
    UIScrollView *_scroll;
    UILabel *_text;
    CArticleContentVideoExtendNode *_videoNode;
    CArticleContentImageNodeType *_imageNode;
    long long _picPosStatus;
    QNDetailImageProgressUnitView *_progressView;
    struct CGPoint _picOffset;
}

@property(retain, nonatomic) QNDetailImageProgressUnitView *progressView; // @synthesize progressView=_progressView;
@property(nonatomic) _Bool isImageInTimeLine; // @synthesize isImageInTimeLine=_isImageInTimeLine;
@property(nonatomic) _Bool isImageInTruth; // @synthesize isImageInTruth=_isImageInTruth;
@property(nonatomic) _Bool useNativeView; // @synthesize useNativeView=_useNativeView;
@property(nonatomic) long long picPosStatus; // @synthesize picPosStatus=_picPosStatus;
@property(nonatomic) struct CGPoint picOffset; // @synthesize picOffset=_picOffset;
@property(retain, nonatomic) CArticleContentImageNodeType *imageNode; // @synthesize imageNode=_imageNode;
@property(retain, nonatomic) CArticleContentVideoExtendNode *videoNode; // @synthesize videoNode=_videoNode;
@property(readonly, nonatomic) UILabel *text; // @synthesize text=_text;
@property(readonly, nonatomic) UIScrollView *scroll; // @synthesize scroll=_scroll;
@property(readonly, nonatomic) CPictView *pic; // @synthesize pic=_pic;
- (void).cxx_destruct;
- (void)_reCenterPic;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (id)viewForZoomingInScrollView:(id)arg1;
- (void)dealloc;
- (void)onCancelButtonTaped:(id)arg1;
- (void)originalImageLoadIsFailed:(id)arg1;
- (void)originalImageLoadIsFinished:(id)arg1;
- (void)normalImageLoadIsFailed:(id)arg1;
- (void)normalImageLoadIsFinished:(id)arg1;
- (void)pictImageIsReplaced:(id)arg1;
- (void)pictView:(id)arg1 loadProgressChangedCurrent:(long long)arg2 total:(long long)arg3;
- (void)p_handleTapToLoad:(id)arg1;
- (void)p_dismissTapToLoadView;
- (void)p_showTapToLoadView;
- (void)p_dismissProgressView;
- (void)p_showProgressView:(_Bool)arg1;
- (void)p_showProgressView;
- (void)setFrame:(struct CGRect)arg1;
- (void)p_validPictLayout;
- (id)imageUrl;
- (_Bool)couldLoadOriginalImage;
- (_Bool)isLoadingOriginalImage;
- (void)loadOriginalImage;
- (void)loadImage;
- (void)disableScale:(_Bool)arg1;
- (_Bool)isSetText;
- (void)clearTextContent;
- (void)skinModeChanged;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

