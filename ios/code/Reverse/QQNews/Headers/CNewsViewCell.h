//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CBaseCell.h"

#import "CSimpleImageViewDelegate.h"
#import "KBTableViewCellProtocol.h"

@class CFlagView, CSimpleImageView, NSString, QNAdItem, QNBaseLabel, UIImageView;

@interface CNewsViewCell : CBaseCell <CSimpleImageViewDelegate, KBTableViewCellProtocol>
{
    CFlagView *_flagView;
    QNAdItem *_adItem;
    UIImageView *_videoFlag;
    CSimpleImageView *_simpleImageView;
    QNBaseLabel *_sourceLabel;
    long long _titleNumberOfLines;
}

+ (id)_titleAttributedStringForThreeLines:(id)arg1;
+ (_Bool)isTitleThreeLines:(id)arg1 titleWidth:(double)arg2;
+ (double)_getTitleWidthWithNoPicMode:(_Bool)arg1;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (id)reuseIdentifierForData:(id)arg1;
+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3;
@property(nonatomic) long long titleNumberOfLines; // @synthesize titleNumberOfLines=_titleNumberOfLines;
@property(retain, nonatomic) QNBaseLabel *sourceLabel; // @synthesize sourceLabel=_sourceLabel;
@property(retain, nonatomic) CSimpleImageView *simpleImageView; // @synthesize simpleImageView=_simpleImageView;
@property(retain, nonatomic) UIImageView *videoFlag; // @synthesize videoFlag=_videoFlag;
@property(retain, nonatomic) QNAdItem *adItem; // @synthesize adItem=_adItem;
@property(retain, nonatomic) CFlagView *flagView; // @synthesize flagView=_flagView;
- (void).cxx_destruct;
- (void)_configTitleAndSummary:(id)arg1;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)setImageCompletedWithImageView:(id)arg1 image:(id)arg2;
- (void)themeChanged:(long long)arg1;
- (void)dealloc;
- (double)_getMaxSourceLabelWidthWithIsTitleThreeLines:(_Bool)arg1 needShowPics:(_Bool)arg2;
- (void)layoutCellByLeftPic:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4;
- (void)layoutCell:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4 context:(id)arg5;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
