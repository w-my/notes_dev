//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNPageViewContentViewProtocol.h"
#import "QNReusableObject.h"

@class CSimpleImageView, NSString, QNAttributedLabel, QNBaseLabel, QNListNewsItem, UIImageView;

@interface QNEntertainmentPageContentView : QNThemableView <QNPageViewContentViewProtocol, QNReusableObject>
{
    unsigned long long contentIndex;
    NSString *_reuseIdentifier;
    CSimpleImageView *_imageView;
    QNListNewsItem *_listItem;
    QNAttributedLabel *_titleLbl;
    QNBaseLabel *_timeLbel;
    UIImageView *_blackCoverView;
}

+ (id)p_generateTopicLabelAttributedString:(id)arg1;
@property(retain, nonatomic) UIImageView *blackCoverView; // @synthesize blackCoverView=_blackCoverView;
@property(retain, nonatomic) QNBaseLabel *timeLbel; // @synthesize timeLbel=_timeLbel;
@property(retain, nonatomic) QNAttributedLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) CSimpleImageView *imageView; // @synthesize imageView=_imageView;
@property(copy, nonatomic) NSString *reuseIdentifier; // @synthesize reuseIdentifier=_reuseIdentifier;
@property(nonatomic) unsigned long long contentIndex; // @synthesize contentIndex;
- (void).cxx_destruct;
- (void)layoutContentViewWithListItem:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

