//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class NSString, QNAvatarView, QNBaseLabel, QNDetailContentContainer, QNEnlargeHitTestButton, QNListNewsItem, QNReportParam, QNSubscribeButton, UIImageView;

@interface QNTopicCommonUserView : QNThemableView <QNDetailContentElementProtocol>
{
    _Bool _followButtonHidden;
    QNAvatarView *_avatarView;
    QNSubscribeButton *_subButton;
    QNDetailContentContainer *_contentContainer;
    CDUnknownBlockType _clickOnAvatarBlock;
    CDUnknownBlockType _onDeleteBlock;
    QNReportParam *_reportParam;
    QNListNewsItem *_listItem;
    QNBaseLabel *_nameLabel;
    QNBaseLabel *_descAttrLabel;
    UIImageView *_editorView;
    QNEnlargeHitTestButton *_deleteButton;
}

@property(nonatomic) _Bool followButtonHidden; // @synthesize followButtonHidden=_followButtonHidden;
@property(retain, nonatomic) QNEnlargeHitTestButton *deleteButton; // @synthesize deleteButton=_deleteButton;
@property(retain, nonatomic) UIImageView *editorView; // @synthesize editorView=_editorView;
@property(retain, nonatomic) QNBaseLabel *descAttrLabel; // @synthesize descAttrLabel=_descAttrLabel;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(copy, nonatomic) CDUnknownBlockType onDeleteBlock; // @synthesize onDeleteBlock=_onDeleteBlock;
@property(copy, nonatomic) CDUnknownBlockType clickOnAvatarBlock; // @synthesize clickOnAvatarBlock=_clickOnAvatarBlock;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
@property(retain, nonatomic) QNSubscribeButton *subButton; // @synthesize subButton=_subButton;
@property(retain, nonatomic) QNAvatarView *avatarView; // @synthesize avatarView=_avatarView;
- (void).cxx_destruct;
- (double)heightOfElementView;
- (void)p_delete;
- (id)p_descAttributeStrWithListItem:(id)arg1;
- (void)p_tapOnAvatarView:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)setSubButtonHidden:(_Bool)arg1;
- (void)updateAlpha:(double)arg1;
- (void)reloadData;
- (void)reloadDataWithListItem:(id)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1 listItem:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
