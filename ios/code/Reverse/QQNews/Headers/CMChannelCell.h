//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class CSubMenuItem, QNEnlargeHitTestButton, UIButton, UIImageView, UILabel, UIView;

@interface CMChannelCell : QNThemableTableViewCell
{
    UIImageView *_remindIcoView;
    UILabel *_label;
    QNEnlargeHitTestButton *_btn;
    CSubMenuItem *_dataItem;
    UIView *_bottomLine;
    UILabel *_addedDescLable;
    UIButton *_addedSpaceBtn;
    CSubMenuItem *_data;
    unsigned long long _cellType;
    CDUnknownBlockType _btnBlock;
    CDUnknownBlockType _delBtnBlock;
}

+ (id)getReusableCellId;
@property(copy, nonatomic) CDUnknownBlockType delBtnBlock; // @synthesize delBtnBlock=_delBtnBlock;
@property(copy, nonatomic) CDUnknownBlockType btnBlock; // @synthesize btnBlock=_btnBlock;
@property(nonatomic) unsigned long long cellType; // @synthesize cellType=_cellType;
@property(retain, nonatomic) CSubMenuItem *data; // @synthesize data=_data;
- (void).cxx_destruct;
- (void)p_pressedButton:(id)arg1;
- (void)dealloc;
- (void)themeChanged:(long long)arg1;
- (void)layoutChannelCellWithItem:(id)arg1 isLast:(_Bool)arg2;
- (void)layoutChannelCellWithItem:(id)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
