//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UIButton, UIImageView;

@interface CNewNativeAdNavBar : UIView
{
    id <CNewNativeAdNavBarDelegate> _delegate;
    UIImageView *_bgImageView;
    UIButton *_closeBtn;
    UIButton *_shareBtn;
}

@property(retain, nonatomic) UIButton *shareBtn; // @synthesize shareBtn=_shareBtn;
@property(retain, nonatomic) UIButton *closeBtn; // @synthesize closeBtn=_closeBtn;
@property(retain, nonatomic) UIImageView *bgImageView; // @synthesize bgImageView=_bgImageView;
@property(nonatomic) __weak id <CNewNativeAdNavBarDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)p_share:(id)arg1;
- (void)p_close:(id)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
