//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableCollectionReusableView.h"

@class UIButton;

@interface QNSubMenuNoInCurrentLocalCollectionFooterView : QNThemableCollectionReusableView
{
    id <QNSubMenuNoInCurrentLocalCollectionFooterViewDelegate> _delegate;
    UIButton *_moreBtn;
}

+ (struct CGSize)getSubMenuNoInCurrentLocalCollectionViewFooterHeight;
+ (id)getReuseIdentifier;
@property(retain, nonatomic) UIButton *moreBtn; // @synthesize moreBtn=_moreBtn;
@property(nonatomic) __weak id <QNSubMenuNoInCurrentLocalCollectionFooterViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)moreBtnAction:(id)arg1;
- (void)_commonInit;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

