//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMTableViewCell.h"

@class CardHomePageTopCell, MMBadgeView, MMUILabel, UIImageView, UIView, WCPayWebImageView;

@interface WCMktTicketAndCertEntryCell : MMTableViewCell
{
    WCPayWebImageView *_iconImgView;
    MMUILabel *_leftLabel;
    MMUILabel *_rightLabel;
    UIImageView *_rightArrowImgView;
    UIView *_seplineView;
    MMBadgeView *_badgeView;
    UIImageView *_redDotImageView;
    CardHomePageTopCell *_topCellData;
}

@property(retain, nonatomic) CardHomePageTopCell *topCellData; // @synthesize topCellData=_topCellData;
@property(retain, nonatomic) UIImageView *redDotImageView; // @synthesize redDotImageView=_redDotImageView;
@property(retain, nonatomic) MMBadgeView *badgeView; // @synthesize badgeView=_badgeView;
@property(retain, nonatomic) UIView *seplineView; // @synthesize seplineView=_seplineView;
@property(retain, nonatomic) UIImageView *rightArrowImgView; // @synthesize rightArrowImgView=_rightArrowImgView;
@property(retain, nonatomic) MMUILabel *rightLabel; // @synthesize rightLabel=_rightLabel;
@property(retain, nonatomic) MMUILabel *leftLabel; // @synthesize leftLabel=_leftLabel;
@property(retain, nonatomic) WCPayWebImageView *iconImgView; // @synthesize iconImgView=_iconImgView;
- (void).cxx_destruct;
- (void)updateContentWithData:(id)arg1 hasSepline:(_Bool)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

