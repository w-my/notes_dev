//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSArray;

@interface QNSearchWikiCellWordsView : QNThemableView
{
    NSArray *_wordsList;
    CDUnknownBlockType _wordsBlock;
}

+ (double)p_maxWordWidth;
@property(copy, nonatomic) CDUnknownBlockType wordsBlock; // @synthesize wordsBlock=_wordsBlock;
@property(copy, nonatomic) NSArray *wordsList; // @synthesize wordsList=_wordsList;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_wordLabelClicked:(id)arg1;
- (void)layoutWithWordsList:(id)arg1;

@end

