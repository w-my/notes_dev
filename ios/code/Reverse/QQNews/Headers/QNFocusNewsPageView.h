//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNListCellAnimationMonitorProtocol.h"
#import "QNPageViewContentViewProtocol.h"
#import "QNReusableObject.h"

@class NSString, QNAttributedLabel, QNCommonCellContentTypeView, QNCommonGIFImageView, QNListNewsItem, UIImageView, UIView;

@interface QNFocusNewsPageView : QNThemableView <QNReusableObject, QNPageViewContentViewProtocol, QNListCellAnimationMonitorProtocol>
{
    _Bool _isAdvertisement;
    unsigned long long contentIndex;
    QNCommonGIFImageView *_simpleImageView;
    UIImageView *_imageBlackCoverView;
    QNAttributedLabel *_titleLbl;
    NSString *_reuseIdentifier;
    id _item;
    id <QNFocusNewsPageViewDelegate> _delegate;
    UIView *_imageBackView;
    QNCommonCellContentTypeView *_typeView;
    QNListNewsItem *_cListItem;
    unsigned long long _animState;
    unsigned long long _type;
}

+ (id)_titleAttributedString:(id)arg1;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3 type:(unsigned long long)arg4;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (id)reuseIdentifierForItem:(id)arg1;
@property(nonatomic) unsigned long long type; // @synthesize type=_type;
@property(nonatomic) unsigned long long animState; // @synthesize animState=_animState;
@property(retain, nonatomic) QNListNewsItem *cListItem; // @synthesize cListItem=_cListItem;
@property(retain, nonatomic) QNCommonCellContentTypeView *typeView; // @synthesize typeView=_typeView;
@property(retain, nonatomic) UIView *imageBackView; // @synthesize imageBackView=_imageBackView;
@property(nonatomic) __weak id <QNFocusNewsPageViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) id item; // @synthesize item=_item;
@property(nonatomic) _Bool isAdvertisement; // @synthesize isAdvertisement=_isAdvertisement;
@property(copy, nonatomic) NSString *reuseIdentifier; // @synthesize reuseIdentifier=_reuseIdentifier;
@property(retain, nonatomic) QNAttributedLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) UIImageView *imageBlackCoverView; // @synthesize imageBlackCoverView=_imageBlackCoverView;
@property(retain, nonatomic) QNCommonGIFImageView *simpleImageView; // @synthesize simpleImageView=_simpleImageView;
@property(nonatomic) unsigned long long contentIndex; // @synthesize contentIndex;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)resetCellAnimation;
- (_Bool)canReuseCellWithListItem:(id)arg1;
- (void)stopCellAnimation;
- (void)startCellAnimation;
- (void)p_startImageAnimation;
- (void)p_readyStartImageAnimation;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)copyViewsFrameFromFocusPageView:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1 type:(unsigned long long)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
