//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CNewsAdDedaoBaseCell.h"

@class CSimpleImageView;

@interface CNewsAdDedaoAlbumCell : CNewsAdDedaoBaseCell
{
    CSimpleImageView *_arrowIcon;
}

+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3;
@property(retain, nonatomic) CSimpleImageView *arrowIcon; // @synthesize arrowIcon=_arrowIcon;
- (void).cxx_destruct;
- (void)layoutCell:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4 context:(id)arg5;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

