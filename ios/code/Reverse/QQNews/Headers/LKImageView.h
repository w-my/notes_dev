//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class LKImageManager, LKImageRequest, LKImageViewEffect, NSArray, NSString, NSTimer, UIImage, UIImageView;

@interface LKImageView : UIView
{
    _Bool _delayLoadingImage;
    _Bool _predrawEnabled;
    _Bool _isAnimating;
    _Bool _shouldAutoPlay;
    UIImageView *_imageView;
    id <LKImageViewDelegate> _delegate;
    unsigned long long _scaleMode;
    LKImageRequest *_loadingImageRequest;
    LKImageRequest *_failureImageRequest;
    UIImage *_presentationImage;
    LKImageRequest *_request;
    unsigned long long _fadeMode;
    LKImageViewEffect *_effect;
    double _frameDuration;
    unsigned long long _animationRepeatCount;
    unsigned long long _frameIndex;
    unsigned long long _animationMode;
    LKImageManager *_imageManager;
    NSTimer *_timer;
    unsigned long long _animationIndex;
    LKImageRequest *_currentRequest;
    struct CGPoint _anchorPoint;
    struct CGSize _oldSize;
}

@property(retain, nonatomic) LKImageRequest *currentRequest; // @synthesize currentRequest=_currentRequest;
@property(nonatomic) unsigned long long animationIndex; // @synthesize animationIndex=_animationIndex;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) struct CGSize oldSize; // @synthesize oldSize=_oldSize;
@property(retain, nonatomic) LKImageManager *imageManager; // @synthesize imageManager=_imageManager;
@property(nonatomic) unsigned long long animationMode; // @synthesize animationMode=_animationMode;
@property(nonatomic) unsigned long long frameIndex; // @synthesize frameIndex=_frameIndex;
@property(nonatomic) _Bool shouldAutoPlay; // @synthesize shouldAutoPlay=_shouldAutoPlay;
@property(nonatomic) _Bool isAnimating; // @synthesize isAnimating=_isAnimating;
@property(nonatomic) unsigned long long animationRepeatCount; // @synthesize animationRepeatCount=_animationRepeatCount;
@property(nonatomic) double frameDuration; // @synthesize frameDuration=_frameDuration;
@property(readonly, nonatomic) LKImageViewEffect *effect; // @synthesize effect=_effect;
@property(nonatomic) unsigned long long fadeMode; // @synthesize fadeMode=_fadeMode;
@property(retain, nonatomic) LKImageRequest *request; // @synthesize request=_request;
@property(readonly, nonatomic) UIImage *presentationImage; // @synthesize presentationImage=_presentationImage;
@property(retain, nonatomic) LKImageRequest *failureImageRequest; // @synthesize failureImageRequest=_failureImageRequest;
@property(retain, nonatomic) LKImageRequest *loadingImageRequest; // @synthesize loadingImageRequest=_loadingImageRequest;
@property(nonatomic) _Bool predrawEnabled; // @synthesize predrawEnabled=_predrawEnabled;
@property(nonatomic) _Bool delayLoadingImage; // @synthesize delayLoadingImage=_delayLoadingImage;
@property(nonatomic) struct CGPoint anchorPoint; // @synthesize anchorPoint=_anchorPoint;
@property(nonatomic) unsigned long long scaleMode; // @synthesize scaleMode=_scaleMode;
@property(nonatomic) __weak id <LKImageViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) UIImageView *imageView; // @synthesize imageView=_imageView;
- (void).cxx_destruct;
- (void)sizeToFit;
- (void)setContentMode:(long long)arg1;
- (void)playFadeAnimation;
- (void)handleAnimation;
- (void)resetTimer;
- (id)processorList;
- (void)internalSetImage:(id)arg1 withRequest:(id)arg2;
- (void)layoutSubviews;
- (void)handleRequestFinish:(id)arg1 image:(id)arg2 isFromSyncCache:(_Bool)arg3;
- (void)layoutAndLoad;
- (void)dealWithRequest:(id)arg1;
- (struct CGSize)size;
- (void)layoutImageView;
- (void)setup;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)stopAnimating;
- (void)startAnimating;
- (void)setURL:(id)arg1 andKey:(id)arg2;
@property(retain, nonatomic) NSString *failureURL;
@property(retain, nonatomic) NSString *loadingURL;
@property(retain, nonatomic) NSString *URL;
@property(retain, nonatomic) NSArray *images;
@property(retain, nonatomic) UIImage *failureImage;
@property(retain, nonatomic) UIImage *loadingImage;
@property(retain, nonatomic) UIImage *image;
@property(retain, nonatomic) UIImage *defaultImage;

@end

