//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CSimpleImageView, QSTextLiveMatchAdItem;

@interface QSMatchTextLiveHeadAdView : UIView
{
    CSimpleImageView *_adImageView;
    QSTextLiveMatchAdItem *_adItem;
}

@property(retain, nonatomic) QSTextLiveMatchAdItem *adItem; // @synthesize adItem=_adItem;
@property(retain, nonatomic) CSimpleImageView *adImageView; // @synthesize adImageView=_adImageView;
- (void).cxx_destruct;
- (void)clickedAdBtn:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

