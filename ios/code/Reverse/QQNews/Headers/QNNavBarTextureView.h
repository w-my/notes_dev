//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class CSimpleImageView, UIImage;

@interface QNNavBarTextureView : QNThemableView
{
    UIImage *_image;
    CSimpleImageView *_backgroundTextureViewUp;
    CSimpleImageView *_backgroundTextureViewDown;
}

@property(retain, nonatomic) CSimpleImageView *backgroundTextureViewDown; // @synthesize backgroundTextureViewDown=_backgroundTextureViewDown;
@property(retain, nonatomic) CSimpleImageView *backgroundTextureViewUp; // @synthesize backgroundTextureViewUp=_backgroundTextureViewUp;
@property(retain, nonatomic) UIImage *image; // @synthesize image=_image;
- (void).cxx_destruct;
- (void)setBackgroundUpTextureHidden:(_Bool)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

