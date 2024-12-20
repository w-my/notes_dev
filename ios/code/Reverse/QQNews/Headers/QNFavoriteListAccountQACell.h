//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNEditCell.h"

#import "QNAccountQACellAssistantViewDelegate.h"

@class CSimpleImageView, KBTableViewCellLayoutContext, NSString, QNAccountQACellAssistantView, QNAccountQACellResponderView, QNAttributedLabel, QNListNewsItem;

@interface QNFavoriteListAccountQACell : QNEditCell <QNAccountQACellAssistantViewDelegate>
{
    QNAccountQACellResponderView *_responderView;
    QNAttributedLabel *_questionTitle;
    QNAttributedLabel *_answerContent;
    CSimpleImageView *_simpleImageView;
    QNAccountQACellAssistantView *_assistantView;
    QNListNewsItem *_listItem;
    KBTableViewCellLayoutContext *_context;
    struct CGSize _questionTitleSize;
    struct CGSize _answerContentSize;
}

+ (double)_getAnswerWidthWithNoPicMode:(_Bool)arg1;
+ (double)_getTitleWidthWithNoPicMode;
+ (double)_noPicCellHeight:(id)arg1;
+ (double)_showPicCellHeight:(id)arg1 context:(id)arg2;
+ (id)_answerContentAttributedString:(id)arg1;
+ (id)_questionTitleAttributedString:(id)arg1 context:(id)arg2;
+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3;
+ (struct CGSize)imageSize;
@property(nonatomic) struct CGSize answerContentSize; // @synthesize answerContentSize=_answerContentSize;
@property(nonatomic) struct CGSize questionTitleSize; // @synthesize questionTitleSize=_questionTitleSize;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNAccountQACellAssistantView *assistantView; // @synthesize assistantView=_assistantView;
@property(retain, nonatomic) CSimpleImageView *simpleImageView; // @synthesize simpleImageView=_simpleImageView;
@property(retain, nonatomic) QNAttributedLabel *answerContent; // @synthesize answerContent=_answerContent;
@property(retain, nonatomic) QNAttributedLabel *questionTitle; // @synthesize questionTitle=_questionTitle;
@property(retain, nonatomic) QNAccountQACellResponderView *responderView; // @synthesize responderView=_responderView;
- (void).cxx_destruct;
- (void)_resetSubViewsFrameWithEditing:(_Bool)arg1 animation:(_Bool)arg2;
- (void)assistantView:(id)arg1 onButtonClick:(id)arg2;
- (void)layoutCell:(id)arg1 context:(id)arg2;
- (void)markEditing:(_Bool)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

