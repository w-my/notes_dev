//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class NSString, QNAttributedLabel, QNBaseLabel, QNZhihuItem, UIImageView;

@interface QNSearchZhihuCell : QNThemableTableViewCell
{
    QNAttributedLabel *_titleLabel;
    QNAttributedLabel *_descLabel;
    QNBaseLabel *_sourceLabel;
    UIImageView *_bottomLine;
    QNZhihuItem *_zhihuItem;
    NSString *_keyWord;
}

+ (id)descAttributedString:(id)arg1;
+ (id)titleAttributedString:(id)arg1;
+ (double)cellHeightWithZhihuItem:(id)arg1 keyWord:(id)arg2;
+ (id)identifier;
@property(copy, nonatomic) NSString *keyWord; // @synthesize keyWord=_keyWord;
@property(retain, nonatomic) QNZhihuItem *zhihuItem; // @synthesize zhihuItem=_zhihuItem;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNBaseLabel *sourceLabel; // @synthesize sourceLabel=_sourceLabel;
@property(retain, nonatomic) QNAttributedLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) QNAttributedLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
- (void).cxx_destruct;
- (void)p_applyDefaultSelectedBackgroundView;
- (void)themeChanged:(long long)arg1;
- (void)layoutWithZhihuItem:(id)arg1 keyWord:(id)arg2 isLastRow:(_Bool)arg3;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

