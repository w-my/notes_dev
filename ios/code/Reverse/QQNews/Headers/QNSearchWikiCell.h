//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class QNAttributedLabel, QNBaseLabel, QNSearchWikiCellWordsView, UIImageView;

@interface QNSearchWikiCell : QNThemableTableViewCell
{
    CDUnknownBlockType _wordsBlock;
    UIImageView *_wikiPicView;
    QNAttributedLabel *_titleLabel;
    QNAttributedLabel *_descLabel;
    QNBaseLabel *_sourceLabel;
    QNSearchWikiCellWordsView *_wordsView;
}

+ (id)p_guessAbstractAttributedString:(id)arg1;
+ (id)p_guessTitleAttributedString:(id)arg1;
+ (_Bool)p_isTextMode;
+ (double)p_maxContentWidth;
+ (double)cellHeightWithWikiItem:(id)arg1;
+ (id)identifier;
@property(retain, nonatomic) QNSearchWikiCellWordsView *wordsView; // @synthesize wordsView=_wordsView;
@property(retain, nonatomic) QNBaseLabel *sourceLabel; // @synthesize sourceLabel=_sourceLabel;
@property(retain, nonatomic) QNAttributedLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) QNAttributedLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) UIImageView *wikiPicView; // @synthesize wikiPicView=_wikiPicView;
@property(copy, nonatomic) CDUnknownBlockType wordsBlock; // @synthesize wordsBlock=_wordsBlock;
- (void).cxx_destruct;
- (void)layoutWithWikiItem:(id)arg1 keyWord:(id)arg2;
- (void)p_resetViews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

