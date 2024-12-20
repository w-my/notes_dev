//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "QNAccountQACellAssistantViewDelegate.h"

@class CSimpleImageView, KBListItem, KBTableViewCellLayoutContext, NSString, QNAccountQACellAssistantView, QNAccountQACellResponderView, QNAttributedLabel, UIImageView;

@interface QNAccountQACell : KBTableViewCell <QNAccountQACellAssistantViewDelegate>
{
    QNAccountQACellResponderView *_responderView;
    QNAccountQACellAssistantView *_assistantView;
    QNAttributedLabel *_questionTitle;
    QNAttributedLabel *_answerContent;
    CSimpleImageView *_simpleImageView;
    UIImageView *_bottomLine;
    KBListItem *_kbListItem;
    KBTableViewCellLayoutContext *_context;
}

+ (double)_noPicCellHeight:(id)arg1;
+ (double)_showPicCellHeight:(id)arg1;
+ (struct UIEdgeInsets)do_cellInsets;
+ (id)answerContentAttributedString:(id)arg1;
+ (id)questionTitleAttributedString:(id)arg1;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (struct CGSize)do_imageSize;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) CSimpleImageView *simpleImageView; // @synthesize simpleImageView=_simpleImageView;
@property(retain, nonatomic) QNAttributedLabel *answerContent; // @synthesize answerContent=_answerContent;
@property(retain, nonatomic) QNAttributedLabel *questionTitle; // @synthesize questionTitle=_questionTitle;
@property(retain, nonatomic) QNAccountQACellAssistantView *assistantView; // @synthesize assistantView=_assistantView;
@property(retain, nonatomic) QNAccountQACellResponderView *responderView; // @synthesize responderView=_responderView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)_resetViewsColor;
- (void)assistantView:(id)arg1 onButtonClick:(id)arg2;
- (void)p_resetViewsColor;
- (void)layoutForRecommendViewWithData:(id)arg1 context:(id)arg2;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

