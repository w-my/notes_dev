//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableControl.h"

@class NSString, QNBaseLabel, UIImage, UIImageView;

@interface QNEnlargeHitTestControl : QNThemableControl
{
    QNBaseLabel *_textLbl;
    UIImageView *_imgView;
    NSString *_title;
    UIImage *_image;
    struct UIEdgeInsets _enlargeHitTestInsets;
}

@property(nonatomic) struct UIEdgeInsets enlargeHitTestInsets; // @synthesize enlargeHitTestInsets=_enlargeHitTestInsets;
@property(retain, nonatomic) UIImage *image; // @synthesize image=_image;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) UIImageView *imgView; // @synthesize imgView=_imgView;
@property(retain, nonatomic) QNBaseLabel *textLbl; // @synthesize textLbl=_textLbl;
- (void).cxx_destruct;
- (void)setEnlargeHitTestInsetSize:(struct CGSize)arg1;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)_layoutSubViewsFrame;
- (void)setFrame:(struct CGRect)arg1;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
