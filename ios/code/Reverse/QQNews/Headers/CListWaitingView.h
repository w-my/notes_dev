//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CLoadingAnimationView, UIActivityIndicatorView, UIImageView;

@interface CListWaitingView : UIView
{
    UIActivityIndicatorView *_indicator;
    UIImageView *_backgroundImage;
    CLoadingAnimationView *_myAnimatedView;
}

@property(retain, nonatomic) CLoadingAnimationView *myAnimatedView; // @synthesize myAnimatedView=_myAnimatedView;
@property(retain, nonatomic) UIImageView *backgroundImage; // @synthesize backgroundImage=_backgroundImage;
@property(retain, nonatomic) UIActivityIndicatorView *indicator; // @synthesize indicator=_indicator;
- (void).cxx_destruct;
- (void)showLoadingFlower:(_Bool)arg1;
- (void)dealloc;
- (void)setFrame:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
