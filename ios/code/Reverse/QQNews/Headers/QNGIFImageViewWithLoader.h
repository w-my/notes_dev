//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSDWebGIFImageView.h"

@class QNOneGifItem, UIImage, UIImageView, UITapGestureRecognizer, UIView;

@interface QNGIFImageViewWithLoader : QNSDWebGIFImageView
{
    _Bool _gifLoadingFinish;
    UIView *_parentView;
    UIImage *_placeholder;
    long long _placeHolderContentMode;
    long long _gifContentMode;
    CDUnknownBlockType _clickBroswerBlock;
    QNOneGifItem *_gifItem;
    UITapGestureRecognizer *_gestureRecognizer;
    UIImageView *_coverImage;
}

@property(retain, nonatomic) UIImageView *coverImage; // @synthesize coverImage=_coverImage;
@property(retain, nonatomic) UITapGestureRecognizer *gestureRecognizer; // @synthesize gestureRecognizer=_gestureRecognizer;
@property(nonatomic) _Bool gifLoadingFinish; // @synthesize gifLoadingFinish=_gifLoadingFinish;
@property(retain, nonatomic) QNOneGifItem *gifItem; // @synthesize gifItem=_gifItem;
@property(copy, nonatomic) CDUnknownBlockType clickBroswerBlock; // @synthesize clickBroswerBlock=_clickBroswerBlock;
@property(nonatomic) long long gifContentMode; // @synthesize gifContentMode=_gifContentMode;
@property(nonatomic) long long placeHolderContentMode; // @synthesize placeHolderContentMode=_placeHolderContentMode;
@property(retain, nonatomic) UIImage *placeholder; // @synthesize placeholder=_placeholder;
@property(nonatomic) __weak UIView *parentView; // @synthesize parentView=_parentView;
- (void).cxx_destruct;
- (void)prepareForReuse;
- (void)p_broswerGifFullScreen;
- (void)startLoadingGifImage;
- (void)p_startLoadingGifImage;
- (void)p_setImageWithGifItem:(id)arg1;
- (_Bool)p_isImageGifCached:(id)arg1;
- (void)gifDidFinishedLoading;
- (_Bool)gifDidStopLoading;
- (_Bool)gifDidStartLoading;
- (void)tryStartAnimating;
- (void)cancelGifImageDownLoad;
- (void)tryStopAnimating;
- (void)tryStartAnimatingOrStartLoadingGifImage;
- (void)layoutView:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
