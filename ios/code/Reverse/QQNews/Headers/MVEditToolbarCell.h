//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionViewCell.h"

@class MVEditToolbarItem, UIImageView, UILabel;

@interface MVEditToolbarCell : UICollectionViewCell
{
    UILabel *_titleLabel;
    UIImageView *_iconView;
    long long _style;
    MVEditToolbarItem *_item;
    id <MVEditToolbarCellDelegate> _delegate;
}

+ (struct CGSize)preferredSizeWithStyle:(long long)arg1;
@property(nonatomic) __weak id <MVEditToolbarCellDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) MVEditToolbarItem *item; // @synthesize item=_item;
@property(nonatomic) long long style; // @synthesize style=_style;
@property(nonatomic) __weak UIImageView *iconView; // @synthesize iconView=_iconView;
@property(nonatomic) __weak UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
- (void).cxx_destruct;
- (void)update;
- (void)setSelected:(_Bool)arg1;
- (id)initWithFrame:(struct CGRect)arg1 style:(long long)arg2;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)handleTapGesture;
- (void)initIconView;
- (void)initTitleLabel;

@end

