//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class CChannelButton, NSMutableArray, NSString, QNBaseLabel, QNDetailContentContainer, QNListNewsItem, QNQuestionInfo;

@interface QNAnswerVipersView : QNThemableView <QNDetailContentElementProtocol>
{
    int _apiRetryTime;
    QNDetailContentContainer *_contentContainer;
    CDUnknownBlockType _subBlock;
    NSMutableArray *_avatarsArray;
    QNBaseLabel *_abstractLabel;
    CChannelButton *_subButton;
    QNListNewsItem *_listItem;
    QNQuestionInfo *_questionInfo;
}

@property(retain, nonatomic) QNQuestionInfo *questionInfo; // @synthesize questionInfo=_questionInfo;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(nonatomic) int apiRetryTime; // @synthesize apiRetryTime=_apiRetryTime;
@property(retain, nonatomic) CChannelButton *subButton; // @synthesize subButton=_subButton;
@property(retain, nonatomic) QNBaseLabel *abstractLabel; // @synthesize abstractLabel=_abstractLabel;
@property(retain, nonatomic) NSMutableArray *avatarsArray; // @synthesize avatarsArray=_avatarsArray;
@property(copy, nonatomic) CDUnknownBlockType subBlock; // @synthesize subBlock=_subBlock;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
- (void).cxx_destruct;
- (void)p_viewPersonalProfile:(id)arg1;
- (void)p_tapOnAvatarView:(id)arg1;
- (double)heightOfElementView;
- (void)p_showFailed;
- (void)p_startFollowRequest;
- (void)p_updateButtonState;
- (void)p_subButtonPressed:(id)arg1;
- (void)reloadWithListItem:(id)arg1 questionInfo:(id)arg2;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
