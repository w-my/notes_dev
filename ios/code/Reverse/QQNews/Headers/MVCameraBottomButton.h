//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MarqueeLabel, NSString, UIColor, UIImage, UIImageView, UITapGestureRecognizer;

@interface MVCameraBottomButton : UIView
{
    _Bool _disable;
    _Bool _selected;
    UIImage *_image;
    UIImage *_selectedImage;
    UIImage *_backImage;
    NSString *_title;
    UIColor *_titleColor;
    UIColor *_dotColor;
    CDUnknownBlockType _onTapAction;
    UIImageView *_imageView;
    UIImageView *_backImgView;
    MarqueeLabel *_titleLabel;
    UIView *_dotView;
    UITapGestureRecognizer *_tapGesture;
    struct UIEdgeInsets _backImageInset;
}

+ (id)instantiate;
@property(retain, nonatomic) UITapGestureRecognizer *tapGesture; // @synthesize tapGesture=_tapGesture;
@property(retain, nonatomic) UIView *dotView; // @synthesize dotView=_dotView;
@property(retain, nonatomic) MarqueeLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) UIImageView *backImgView; // @synthesize backImgView=_backImgView;
@property(retain, nonatomic) UIImageView *imageView; // @synthesize imageView=_imageView;
@property(copy, nonatomic) CDUnknownBlockType onTapAction; // @synthesize onTapAction=_onTapAction;
@property(nonatomic) _Bool selected; // @synthesize selected=_selected;
@property(nonatomic) _Bool disable; // @synthesize disable=_disable;
@property(retain, nonatomic) UIColor *dotColor; // @synthesize dotColor=_dotColor;
@property(retain, nonatomic) UIColor *titleColor; // @synthesize titleColor=_titleColor;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
@property(nonatomic) struct UIEdgeInsets backImageInset; // @synthesize backImageInset=_backImageInset;
@property(retain, nonatomic) UIImage *backImage; // @synthesize backImage=_backImage;
@property(retain, nonatomic) UIImage *selectedImage; // @synthesize selectedImage=_selectedImage;
@property(retain, nonatomic) UIImage *image; // @synthesize image=_image;
- (void).cxx_destruct;
- (void)hideDot;
- (void)showDot;
@property(readonly, nonatomic) _Bool isShowingDot;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)setAlpha:(double)arg1;
- (void)layoutBackImageView;
- (void)handleTapGesture:(id)arg1;
- (void)setupView;
- (id)initWithFrame:(struct CGRect)arg1;

@end

