//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "CSimpleImageViewDelegate.h"

@class CSimpleImageViewEx, NSString, QNBaseLabel, QNListNewsItem, QNSubscribeButton, UIButton, UIScrollView;

@interface QNLiveDetailDescriptionView : UIView <CSimpleImageViewDelegate>
{
    CDUnknownBlockType _dismissBlock;
    long long _type;
    QNListNewsItem *_listItem;
    UIView *_headerView;
    UIButton *_closeButton;
    UIScrollView *_scrollView;
    CSimpleImageViewEx *_logoView;
    QNBaseLabel *_nameLabel;
    QNBaseLabel *_pubLabel;
    QNBaseLabel *_subLabel;
    QNBaseLabel *_descLabel;
    QNSubscribeButton *_subButton;
    UIView *_seperatorLine;
    QNBaseLabel *_liveDesc;
    CSimpleImageViewEx *_liveMap;
}

@property(retain, nonatomic) CSimpleImageViewEx *liveMap; // @synthesize liveMap=_liveMap;
@property(retain, nonatomic) QNBaseLabel *liveDesc; // @synthesize liveDesc=_liveDesc;
@property(retain, nonatomic) UIView *seperatorLine; // @synthesize seperatorLine=_seperatorLine;
@property(retain, nonatomic) QNSubscribeButton *subButton; // @synthesize subButton=_subButton;
@property(retain, nonatomic) QNBaseLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) QNBaseLabel *subLabel; // @synthesize subLabel=_subLabel;
@property(retain, nonatomic) QNBaseLabel *pubLabel; // @synthesize pubLabel=_pubLabel;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) CSimpleImageViewEx *logoView; // @synthesize logoView=_logoView;
@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(retain, nonatomic) UIButton *closeButton; // @synthesize closeButton=_closeButton;
@property(retain, nonatomic) UIView *headerView; // @synthesize headerView=_headerView;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(copy, nonatomic) CDUnknownBlockType dismissBlock; // @synthesize dismissBlock=_dismissBlock;
- (void).cxx_destruct;
- (void)setImageCompletedWithImageView:(id)arg1 image:(id)arg2;
- (void)p_onCloseButtonClicked;
- (void)p_handleUserLabelClick;
- (void)p_navigateToMedia;
- (void)handleOrientationChanged:(id)arg1;
- (void)dismissDescriptionView;
- (void)showDescriptionView;
- (void)dealloc;
- (void)p_handleBackgroundClick;
- (id)initWithFrame:(struct CGRect)arg1 listItem:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
