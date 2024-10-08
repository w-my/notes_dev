//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSearchResultCellBase.h"

@class CSimpleImageView, QNAttributedLabel, UIImageView, UILabel;

@interface QNSearchResultWeiboCell : QNSearchResultCellBase
{
    QNAttributedLabel *_title;
    UIImageView *_vipIco;
    CSimpleImageView *_headerIco;
    QNAttributedLabel *_desc;
    CSimpleImageView *_descImg;
    CSimpleImageView *_weiboIco;
    UILabel *_weiboName;
    UILabel *_time;
}

@property(retain, nonatomic) UILabel *time; // @synthesize time=_time;
@property(retain, nonatomic) UILabel *weiboName; // @synthesize weiboName=_weiboName;
@property(retain, nonatomic) CSimpleImageView *weiboIco; // @synthesize weiboIco=_weiboIco;
@property(retain, nonatomic) CSimpleImageView *descImg; // @synthesize descImg=_descImg;
@property(retain, nonatomic) QNAttributedLabel *desc; // @synthesize desc=_desc;
@property(retain, nonatomic) CSimpleImageView *headerIco; // @synthesize headerIco=_headerIco;
@property(retain, nonatomic) UIImageView *vipIco; // @synthesize vipIco=_vipIco;
@property(retain, nonatomic) QNAttributedLabel *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (void)handleTapCommentImage:(id)arg1;
- (void)qn_layoutSubviews;
- (void)themeChanged:(long long)arg1;
- (void)layoutWithCell;
- (id)p_descAttributedString:(id)arg1 keyWords:(id)arg2 keyWordFont:(id)arg3 numberOfLines:(long long)arg4;
- (id)p_titleAttributedString:(id)arg1 keyWords:(id)arg2 keyWordFont:(id)arg3;
- (void)layoutWithSearchItem:(id)arg1 withKeyWords:(id)arg2;

@end

