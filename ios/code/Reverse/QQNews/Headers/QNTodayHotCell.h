//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class NSString, QNBaseLabel, UIImageView;

@interface QNTodayHotCell : QNThemableTableViewCell
{
    QNBaseLabel *_numberLabel;
    QNBaseLabel *_hotTextLabel;
    QNBaseLabel *_hotLabel;
    UIImageView *_bottomLine;
    NSString *_hotWordTag;
    long long _indexOfCell;
}

+ (id)identifier;
@property(nonatomic) long long indexOfCell; // @synthesize indexOfCell=_indexOfCell;
@property(copy, nonatomic) NSString *hotWordTag; // @synthesize hotWordTag=_hotWordTag;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNBaseLabel *hotLabel; // @synthesize hotLabel=_hotLabel;
@property(retain, nonatomic) QNBaseLabel *hotTextLabel; // @synthesize hotTextLabel=_hotTextLabel;
@property(retain, nonatomic) QNBaseLabel *numberLabel; // @synthesize numberLabel=_numberLabel;
- (void).cxx_destruct;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)themeChanged:(long long)arg1;
- (void)p_setHotLabelStyle;
- (void)layoutRankCellWithShowInfo:(id)arg1 indexPathRow:(long long)arg2;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
