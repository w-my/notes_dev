//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNAttributedLabel, QNExpressionGIFView, QNListNewsItem, UIImageView, UILabel;

@interface QNVideoRecommendItemView : UIView
{
    QNAttributedLabel *_titleLbl;
    QNExpressionGIFView *_simpleImageView;
    UILabel *_durationLabel;
    UIImageView *_iconImage;
    UILabel *_countLabel;
    QNListNewsItem *_listItem;
    UILabel *_recommendReasonLabel;
}

+ (double)cellHeight;
+ (struct CGSize)do_imageSize;
+ (double)_getTitleWidthWithNoPicMode:(_Bool)arg1;
+ (struct UIEdgeInsets)do_cellInsets;
@property(retain, nonatomic) UILabel *recommendReasonLabel; // @synthesize recommendReasonLabel=_recommendReasonLabel;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) UILabel *countLabel; // @synthesize countLabel=_countLabel;
@property(retain, nonatomic) UIImageView *iconImage; // @synthesize iconImage=_iconImage;
@property(retain, nonatomic) UILabel *durationLabel; // @synthesize durationLabel=_durationLabel;
@property(retain, nonatomic) QNExpressionGIFView *simpleImageView; // @synthesize simpleImageView=_simpleImageView;
@property(retain, nonatomic) QNAttributedLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
- (void).cxx_destruct;
- (id)recommendReasonStr;
- (id)titleAttributedString:(id)arg1;
- (void)updateViewsWithItem:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
