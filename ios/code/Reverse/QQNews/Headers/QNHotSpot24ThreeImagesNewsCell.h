//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "QNCommonCellAssistantViewDelegate.h"

@class CSimpleImageView, KBListItem, KBTableViewCellLayoutContext, NSString, QNBaseLabel, QNCommonCellAssistantView, QNCommonCellTitleView, QNHotSpot24CommonCellHeaderView, UIImageView;

@interface QNHotSpot24ThreeImagesNewsCell : KBTableViewCell <QNCommonCellAssistantViewDelegate>
{
    KBListItem *_kbListItem;
    KBTableViewCellLayoutContext *_context;
    QNHotSpot24CommonCellHeaderView *_headerView;
    QNCommonCellTitleView *_titleView;
    CSimpleImageView *_firstImageView;
    CSimpleImageView *_secondImageView;
    CSimpleImageView *_thirdImageView;
    QNCommonCellAssistantView *_assistantView;
    QNBaseLabel *_imageCountLabel;
    UIImageView *_bottomLine;
}

+ (double)p_getCurrentCellHeightWithItem:(id)arg1 context:(id)arg2;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (id)reuseIdentifierForData:(id)arg1;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNBaseLabel *imageCountLabel; // @synthesize imageCountLabel=_imageCountLabel;
@property(retain, nonatomic) QNCommonCellAssistantView *assistantView; // @synthesize assistantView=_assistantView;
@property(retain, nonatomic) CSimpleImageView *thirdImageView; // @synthesize thirdImageView=_thirdImageView;
@property(retain, nonatomic) CSimpleImageView *secondImageView; // @synthesize secondImageView=_secondImageView;
@property(retain, nonatomic) CSimpleImageView *firstImageView; // @synthesize firstImageView=_firstImageView;
@property(retain, nonatomic) QNCommonCellTitleView *titleView; // @synthesize titleView=_titleView;
@property(retain, nonatomic) QNHotSpot24CommonCellHeaderView *headerView; // @synthesize headerView=_headerView;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
