//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UIActivityIndicatorView, UIButton, UIImageView, UILabel;

@interface ACReaderLoadingView : UIView
{
    UILabel *_reloadLabel;
    UIButton *_reloadButton;
    UIImageView *_logo;
    UIActivityIndicatorView *_indicatorView;
    id <ACReaderLoadingViewDelegate> _delegate;
}

@property(nonatomic) __weak id <ACReaderLoadingViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) UIActivityIndicatorView *indicatorView; // @synthesize indicatorView=_indicatorView;
@property(retain, nonatomic) UIImageView *logo; // @synthesize logo=_logo;
@property(retain, nonatomic) UIButton *reloadButton; // @synthesize reloadButton=_reloadButton;
@property(retain, nonatomic) UILabel *reloadLabel; // @synthesize reloadLabel=_reloadLabel;
- (void).cxx_destruct;
- (void)reloadAction:(id)arg1;
- (void)loadFinishWithError:(id)arg1;
- (void)loadSubviews;
- (id)initWithDelegate:(id)arg1;

@end

