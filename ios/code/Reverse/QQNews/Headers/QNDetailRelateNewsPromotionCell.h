//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CBaseCell.h"

#import "KBTableViewCellProtocol.h"

@class CSimpleImageView, NSString, QNBaseLabel;

@interface QNDetailRelateNewsPromotionCell : CBaseCell <KBTableViewCellProtocol>
{
    CSimpleImageView *_appPromotionIcon;
    QNBaseLabel *_flagLabel;
    QNBaseLabel *_promWodingLabel;
}

+ (struct UIEdgeInsets)do_cellInsets;
+ (struct CGSize)do_imageSize;
+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3;
+ (id)reuseIdentifierForData:(id)arg1;
@property(retain, nonatomic) QNBaseLabel *promWodingLabel; // @synthesize promWodingLabel=_promWodingLabel;
@property(retain, nonatomic) QNBaseLabel *flagLabel; // @synthesize flagLabel=_flagLabel;
@property(retain, nonatomic) CSimpleImageView *appPromotionIcon; // @synthesize appPromotionIcon=_appPromotionIcon;
- (void).cxx_destruct;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)themeChanged:(long long)arg1;
- (void)layoutCell:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4 context:(id)arg5;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

