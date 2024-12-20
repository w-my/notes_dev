//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class UIImageView, UILabel;

@interface QSComListLeftCell : QNThemableTableViewCell
{
    _Bool _isSelected;
    UILabel *_titleLabel;
    UIImageView *_officialImageView;
}

+ (double)heightWithName:(id)arg1;
@property(retain, nonatomic) UIImageView *officialImageView; // @synthesize officialImageView=_officialImageView;
@property(nonatomic) _Bool isSelected; // @synthesize isSelected=_isSelected;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
- (void).cxx_destruct;
- (void)updateWithName:(id)arg1;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (void)layoutNBA;
- (void)layoutSubviews;
- (void)themeChanged:(long long)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

