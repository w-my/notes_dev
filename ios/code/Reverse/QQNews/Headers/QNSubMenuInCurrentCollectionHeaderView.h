//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionReusableView.h"

@class QNEnlargeHitTestButton, UILabel;

@interface QNSubMenuInCurrentCollectionHeaderView : UICollectionReusableView
{
    _Bool _isSelected;
    CDUnknownBlockType _editBtnBlock;
    UILabel *_leftMainLbl;
    UILabel *_leftSecendLbl;
    QNEnlargeHitTestButton *_rightBtn;
}

+ (struct CGSize)getSubMenuInCurrentCollectionViewHeaderHeight;
+ (id)getReuseIdentifier;
@property(nonatomic) _Bool isSelected; // @synthesize isSelected=_isSelected;
@property(retain, nonatomic) QNEnlargeHitTestButton *rightBtn; // @synthesize rightBtn=_rightBtn;
@property(retain, nonatomic) UILabel *leftSecendLbl; // @synthesize leftSecendLbl=_leftSecendLbl;
@property(retain, nonatomic) UILabel *leftMainLbl; // @synthesize leftMainLbl=_leftMainLbl;
@property(copy, nonatomic) CDUnknownBlockType editBtnBlock; // @synthesize editBtnBlock=_editBtnBlock;
- (void).cxx_destruct;
- (void)refreshHeaderViewIsSelect:(_Bool)arg1;
- (void)p_rightButtonDidTapped;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)layoutSubviews;
- (void)_commonInit;
- (void)setLeftSecendLblText:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

