//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNativeWidgetView.h"

@class CSimpleImageView, UIImage, UILabel;

@interface QNImageHeaderView : QNNativeWidgetView
{
    UIImage *_defaultTopImage;
    CSimpleImageView *_topImageView;
    UILabel *_titleLabel;
}

+ (struct CGSize)sizeForViewWithData:(id)arg1 width:(double)arg2 isNoPicMode:(_Bool)arg3;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) CSimpleImageView *topImageView; // @synthesize topImageView=_topImageView;
@property(retain, nonatomic) UIImage *defaultTopImage; // @synthesize defaultTopImage=_defaultTopImage;
- (void).cxx_destruct;
- (long long)widgetViewType;
- (void)layoutViewWithData:(id)arg1;
- (id)initWidget;

@end

