//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CNewsTitleCell.h"

@class CSimpleImageView, UIImageView, UILabel;

@interface CNewsSingleImageCell : CNewsTitleCell
{
    CSimpleImageView *_firstImageView;
    UILabel *_picCountLabel;
    UIImageView *_picCountIcon;
}

+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3;
@property(retain) UIImageView *picCountIcon; // @synthesize picCountIcon=_picCountIcon;
@property(retain) UILabel *picCountLabel; // @synthesize picCountLabel=_picCountLabel;
@property(retain) CSimpleImageView *firstImageView; // @synthesize firstImageView=_firstImageView;
- (void).cxx_destruct;
- (void)layoutCell:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4 context:(id)arg5;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
