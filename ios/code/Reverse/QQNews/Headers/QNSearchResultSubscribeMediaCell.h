//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

#import "CSimpleImageViewDelegate.h"

@class CSimpleImageViewEx, CSubscribeListItemNode, NSString, QNBaseLabel, QNSubscribeButton, QNTagItem, UIImageView;

@interface QNSearchResultSubscribeMediaCell : QNThemableTableViewCell <CSimpleImageViewDelegate>
{
    QNBaseLabel *_logoLabel;
    QNBaseLabel *_nameLabel;
    CSimpleImageViewEx *_logoView;
    UIImageView *_mediaFlagIcon;
    QNSubscribeButton *_subButton;
    CSubscribeListItemNode *_subNode;
    QNTagItem *_tagItem;
}

+ (double)getSearchResultSubscribeMediaCellHeight;
@property(retain, nonatomic) QNTagItem *tagItem; // @synthesize tagItem=_tagItem;
@property(retain, nonatomic) CSubscribeListItemNode *subNode; // @synthesize subNode=_subNode;
@property(retain, nonatomic) QNSubscribeButton *subButton; // @synthesize subButton=_subButton;
@property(retain, nonatomic) UIImageView *mediaFlagIcon; // @synthesize mediaFlagIcon=_mediaFlagIcon;
@property(retain, nonatomic) CSimpleImageViewEx *logoView; // @synthesize logoView=_logoView;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) QNBaseLabel *logoLabel; // @synthesize logoLabel=_logoLabel;
- (void).cxx_destruct;
- (void)updateSubscribeStatues:(_Bool)arg1;
- (void)layoutWithTag:(id)arg1;
- (void)layoutWithNode:(id)arg1;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)setSubButtonCallBack:(CDUnknownBlockType)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
