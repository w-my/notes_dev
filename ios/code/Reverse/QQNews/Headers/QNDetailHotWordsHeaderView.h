//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNBaseLabel, QNEnlargeHitTestButton, UIImageView;

@interface QNDetailHotWordsHeaderView : UIView
{
    UIImageView *_hotFire;
    QNBaseLabel *_textLabel;
    QNEnlargeHitTestButton *_moreSearchBtn;
    UIImageView *_hotMoreView;
    CDUnknownBlockType _headerBlock;
}

+ (double)heightOfHeaderView;
@property(copy, nonatomic) CDUnknownBlockType headerBlock; // @synthesize headerBlock=_headerBlock;
@property(retain, nonatomic) UIImageView *hotMoreView; // @synthesize hotMoreView=_hotMoreView;
@property(retain, nonatomic) QNEnlargeHitTestButton *moreSearchBtn; // @synthesize moreSearchBtn=_moreSearchBtn;
@property(retain, nonatomic) QNBaseLabel *textLabel; // @synthesize textLabel=_textLabel;
@property(retain, nonatomic) UIImageView *hotFire; // @synthesize hotFire=_hotFire;
- (void).cxx_destruct;
- (void)p_moreSearchBtnClick;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
