//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

@class UIImageView, UILabel, UIView;

@interface QSMatchDetailSectionHeaderCell : UITableViewCell
{
    UILabel *_titleLabel;
    UIView *_seperatorLine;
    UILabel *_moreDataLabel;
    UIImageView *_moreDataArrow;
}

+ (double)fixedCellHeight;
@property(retain, nonatomic) UIImageView *moreDataArrow; // @synthesize moreDataArrow=_moreDataArrow;
@property(retain, nonatomic) UILabel *moreDataLabel; // @synthesize moreDataLabel=_moreDataLabel;
@property(retain, nonatomic) UIView *seperatorLine; // @synthesize seperatorLine=_seperatorLine;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
- (void).cxx_destruct;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (void)refreshWithTitle:(id)arg1 detailTip:(id)arg2 showArrow:(_Bool)arg3;
- (void)refreshWithTitle:(id)arg1 showArrow:(_Bool)arg2;
- (void)refreshWithTitle:(id)arg1 detailTip:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
