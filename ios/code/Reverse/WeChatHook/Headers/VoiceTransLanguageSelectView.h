//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MMTableViewInfo, NSString, UIPanGestureRecognizer;

@interface VoiceTransLanguageSelectView : UIView
{
    unsigned int _languageType;
    NSString *_chatUserName;
    id <VoiceTransLanguageSelectViewDelegate> _delegate;
    MMTableViewInfo *_tableViewInfo;
    UIView *_selectPanelView;
    UIPanGestureRecognizer *_panGestureRecognizer;
}

@property(retain, nonatomic) UIPanGestureRecognizer *panGestureRecognizer; // @synthesize panGestureRecognizer=_panGestureRecognizer;
@property(nonatomic) unsigned int languageType; // @synthesize languageType=_languageType;
@property(retain, nonatomic) UIView *selectPanelView; // @synthesize selectPanelView=_selectPanelView;
@property(retain, nonatomic) MMTableViewInfo *tableViewInfo; // @synthesize tableViewInfo=_tableViewInfo;
@property(nonatomic) __weak id <VoiceTransLanguageSelectViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSString *chatUserName; // @synthesize chatUserName=_chatUserName;
- (void).cxx_destruct;
- (void)onBackBtnClick;
- (void)onLanguageSelectd:(id)arg1;
- (void)updateSelectViewWithCurInputType:(unsigned int)arg1;
- (void)onPanGestureRecognizerAction:(id)arg1;
- (void)initPanGestureRecognizer;
- (void)addSubViews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
