//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSearchBarResultCell.h"

@class QNEnlargeHitTestButton, UIView;

@interface QNDeleteAllSearchBarResultCell : QNSearchBarResultCell
{
    CDUnknownBlockType _cleanAllBlock;
    QNEnlargeHitTestButton *_cleanAllBtn;
    UIView *_leftLine;
}

+ (double)getDeleteAllSearchCellHeight;
@property(retain, nonatomic) UIView *leftLine; // @synthesize leftLine=_leftLine;
@property(retain, nonatomic) QNEnlargeHitTestButton *cleanAllBtn; // @synthesize cleanAllBtn=_cleanAllBtn;
@property(copy, nonatomic) CDUnknownBlockType cleanAllBlock; // @synthesize cleanAllBlock=_cleanAllBlock;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (void)cleanupBtnAction:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

