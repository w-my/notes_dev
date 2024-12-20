//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CALayer, NSMutableArray, QNWeiBoContentLayer, QNWeiBoListItem, UIImageView;

@interface QNWeiBoView : UIView
{
    _Bool _isNoPicMode;
    float _viewHeight;
    QNWeiBoListItem *_weiBoItem;
    NSMutableArray *_thumbnails;
    UIImageView *_moreImageIcon;
    CALayer *_bgLayer;
    QNWeiBoContentLayer *_contentLayer;
}

+ (double)expectedHeightWithItem:(id)arg1 isNoPicMode:(_Bool)arg2;
@property(retain, nonatomic) QNWeiBoContentLayer *contentLayer; // @synthesize contentLayer=_contentLayer;
@property(retain, nonatomic) CALayer *bgLayer; // @synthesize bgLayer=_bgLayer;
@property(nonatomic) _Bool isNoPicMode; // @synthesize isNoPicMode=_isNoPicMode;
@property(retain, nonatomic) UIImageView *moreImageIcon; // @synthesize moreImageIcon=_moreImageIcon;
@property(retain, nonatomic) NSMutableArray *thumbnails; // @synthesize thumbnails=_thumbnails;
@property(nonatomic) float viewHeight; // @synthesize viewHeight=_viewHeight;
@property(retain, nonatomic) QNWeiBoListItem *weiBoItem; // @synthesize weiBoItem=_weiBoItem;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)handleTapThumbnial:(id)arg1;
- (void)hiddenThumbnailsFromIndex:(long long)arg1;
- (void)resetThumbnailsLimitCount:(long long)arg1 startPoint:(struct CGPoint)arg2;
- (void)layoutView:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4 hasRead:(_Bool)arg5;
- (id)init;

@end

