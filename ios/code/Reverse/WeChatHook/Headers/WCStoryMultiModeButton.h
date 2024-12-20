//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIButton.h"

@class UIActivityIndicatorView, UIImageView, UIView;

@interface WCStoryMultiModeButton : MMUIButton
{
    _Bool _loading;
    UIImageView *_crookIconView;
    UIView *_loadingView;
    UIActivityIndicatorView *_indicatorView;
}

@property(nonatomic) __weak UIActivityIndicatorView *indicatorView; // @synthesize indicatorView=_indicatorView;
@property(nonatomic) __weak UIView *loadingView; // @synthesize loadingView=_loadingView;
@property(nonatomic) __weak UIImageView *crookIconView; // @synthesize crookIconView=_crookIconView;
@property(nonatomic, getter=isLoading) _Bool loading; // @synthesize loading=_loading;
- (void).cxx_destruct;
- (void)updateButtonState;
- (void)setSelected:(_Bool)arg1;
- (void)setFrame:(struct CGRect)arg1;
- (void)setupSubviews;
- (void)setup;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;

@end

