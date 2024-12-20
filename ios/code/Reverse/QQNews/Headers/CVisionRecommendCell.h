//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

@class CSimpleImageView, NSArray, QNAttributedLabel;

@interface CVisionRecommendCell : KBTableViewCell
{
    CDUnknownBlockType _clickBlock;
    CSimpleImageView *_leftSimpleImageView;
    QNAttributedLabel *_leftTitleLbl;
    QNAttributedLabel *_leftPictureCountLabel;
    CSimpleImageView *_rightSimpleImageView;
    QNAttributedLabel *_rightTitleLbl;
    QNAttributedLabel *_rightPictureCountLabel;
    NSArray *_items;
}

+ (id)_titleAttributedStringForPictureCountLabel:(id)arg1;
+ (id)_titleAttributedStringForThreeLines:(id)arg1;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (struct UIEdgeInsets)cellInsets;
@property(retain, nonatomic) NSArray *items; // @synthesize items=_items;
@property(retain, nonatomic) QNAttributedLabel *rightPictureCountLabel; // @synthesize rightPictureCountLabel=_rightPictureCountLabel;
@property(retain, nonatomic) QNAttributedLabel *rightTitleLbl; // @synthesize rightTitleLbl=_rightTitleLbl;
@property(retain, nonatomic) CSimpleImageView *rightSimpleImageView; // @synthesize rightSimpleImageView=_rightSimpleImageView;
@property(retain, nonatomic) QNAttributedLabel *leftPictureCountLabel; // @synthesize leftPictureCountLabel=_leftPictureCountLabel;
@property(retain, nonatomic) QNAttributedLabel *leftTitleLbl; // @synthesize leftTitleLbl=_leftTitleLbl;
@property(retain, nonatomic) CSimpleImageView *leftSimpleImageView; // @synthesize leftSimpleImageView=_leftSimpleImageView;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
- (void).cxx_destruct;
- (void)layoutWithData:(id)arg1 context:(id)arg2 type:(long long)arg3;
- (void)layoutWithDatas:(id)arg1 context:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

