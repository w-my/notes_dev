//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UILabel;

@interface QNRelatedVideoView : UIView
{
    _Bool _isUsedInAlbum;
    int _cellState;
    UIView *_leftLineView;
    UIView *_rightLineView;
    UILabel *_relatedVideoTitleLabel;
}

+ (id)titleAttributedString:(id)arg1 font:(id)arg2 color:(id)arg3;
@property(nonatomic) _Bool isUsedInAlbum; // @synthesize isUsedInAlbum=_isUsedInAlbum;
@property(readonly, nonatomic) int cellState; // @synthesize cellState=_cellState;
@property(retain, nonatomic) UILabel *relatedVideoTitleLabel; // @synthesize relatedVideoTitleLabel=_relatedVideoTitleLabel;
@property(retain, nonatomic) UIView *rightLineView; // @synthesize rightLineView=_rightLineView;
@property(retain, nonatomic) UIView *leftLineView; // @synthesize leftLineView=_leftLineView;
- (void).cxx_destruct;
- (void)p_setLineViewAlpha:(double)arg1;
- (void)switchToCellState:(int)arg1;
- (void)darkWithAlpha:(double)arg1;
- (void)updataTitleView:(id)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
