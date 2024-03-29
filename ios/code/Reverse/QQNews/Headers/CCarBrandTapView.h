//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CCarBrandItem, CSimpleImageView, UILabel;

@interface CCarBrandTapView : UIView
{
    id <CCarBrandTapViewDelegate> _delegate;
    CCarBrandItem *_brandItem;
    CSimpleImageView *_brandPic;
    UILabel *_brandName;
}

@property(retain, nonatomic) UILabel *brandName; // @synthesize brandName=_brandName;
@property(retain, nonatomic) CSimpleImageView *brandPic; // @synthesize brandPic=_brandPic;
@property(retain, nonatomic) CCarBrandItem *brandItem; // @synthesize brandItem=_brandItem;
@property(nonatomic) __weak id <CCarBrandTapViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)didClickBrandView:(id)arg1;
- (id)initWithOriginX:(double)arg1 andOriginY:(double)arg2 andBrandItem:(id)arg3;

@end

