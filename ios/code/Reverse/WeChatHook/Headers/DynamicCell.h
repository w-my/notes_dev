//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionViewCell.h"

@class EmoticonLensItemPB, MMUILabel, UIImageView, UIView;

@interface DynamicCell : UICollectionViewCell
{
    UIView *m_iconView;
    MMUILabel *m_descLabel;
    EmoticonLensItemPB *_emoticonLensItem;
    UIImageView *_icon;
    UIImageView *_iconSelected;
    UIImageView *_iconDownload;
    unsigned long long _scenes;
}

+ (struct CGSize)getCellSize;
+ (id)identifier;
@property(nonatomic) unsigned long long scenes; // @synthesize scenes=_scenes;
@property(retain, nonatomic) UIImageView *iconDownload; // @synthesize iconDownload=_iconDownload;
@property(retain, nonatomic) UIImageView *iconSelected; // @synthesize iconSelected=_iconSelected;
@property(retain, nonatomic) UIImageView *icon; // @synthesize icon=_icon;
@property(retain, nonatomic) EmoticonLensItemPB *emoticonLensItem; // @synthesize emoticonLensItem=_emoticonLensItem;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;

@end
