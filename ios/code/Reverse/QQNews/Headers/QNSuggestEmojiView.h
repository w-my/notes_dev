//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIScrollView.h"

@class NSArray, QNBaseLabel;

@interface QNSuggestEmojiView : UIScrollView
{
    CDUnknownBlockType _clickBlock;
    QNBaseLabel *_textLabel;
    long long _type;
    NSArray *_emojiList;
}

+ (id)viewWithType:(long long)arg1;
@property(copy, nonatomic) NSArray *emojiList; // @synthesize emojiList=_emojiList;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(retain, nonatomic) QNBaseLabel *textLabel; // @synthesize textLabel=_textLabel;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
- (void).cxx_destruct;
- (id)p_emojiViewAtPoint:(struct CGPoint)arg1 index:(long long *)arg2;
- (void)p_tapped:(id)arg1;
- (struct UIEdgeInsets)p_edgeInsets;
- (struct CGSize)p_emojiSize;
- (double)p_emojiSpace;
- (double)p_widthWithEmojiCount:(unsigned long long)arg1;
- (void)reset;
- (void)updateWithEmojiItems:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
