//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

@class QNBaseLabel, UIImageView, UIView;

@interface QNListTopicRecommendCatCell : KBTableViewCell
{
    UIView *_contentBgView;
    QNBaseLabel *_titleLbl;
    QNBaseLabel *_descLbl;
    UIImageView *_indicateImageView;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(retain, nonatomic) UIImageView *indicateImageView; // @synthesize indicateImageView=_indicateImageView;
@property(retain, nonatomic) QNBaseLabel *descLbl; // @synthesize descLbl=_descLbl;
@property(retain, nonatomic) QNBaseLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) UIView *contentBgView; // @synthesize contentBgView=_contentBgView;
- (void).cxx_destruct;
- (id)p_randRecommend;
- (void)themeChanged:(long long)arg1;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
