//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSAttributedString, NSURL, QNListNewsItem, UIColor;

@interface QNQualityCourseMoreCellModel : NSObject
{
    _Bool _hideDiscountIcon;
    _Bool _bottomLineHidden;
    UIColor *_bgColor;
    QNListNewsItem *_listItem;
    NSURL *_avatorUrl;
    NSAttributedString *_title;
    NSAttributedString *_author;
    NSAttributedString *_desc;
    NSAttributedString *_price;
    NSAttributedString *_discount;
    UIColor *_bottomLineColor;
    struct CGSize _viewSize;
    struct CGRect _avatorViewRect;
    struct CGRect _titleRect;
    struct CGRect _authorRect;
    struct CGRect _descRect;
    struct CGRect _priceRect;
    struct CGRect _discountRect;
    struct CGRect _bottomLineRect;
}

@property(retain, nonatomic) UIColor *bottomLineColor; // @synthesize bottomLineColor=_bottomLineColor;
@property(nonatomic) struct CGRect bottomLineRect; // @synthesize bottomLineRect=_bottomLineRect;
@property(nonatomic) _Bool bottomLineHidden; // @synthesize bottomLineHidden=_bottomLineHidden;
@property(nonatomic) struct CGRect discountRect; // @synthesize discountRect=_discountRect;
@property(copy, nonatomic) NSAttributedString *discount; // @synthesize discount=_discount;
@property(nonatomic) _Bool hideDiscountIcon; // @synthesize hideDiscountIcon=_hideDiscountIcon;
@property(nonatomic) struct CGRect priceRect; // @synthesize priceRect=_priceRect;
@property(copy, nonatomic) NSAttributedString *price; // @synthesize price=_price;
@property(nonatomic) struct CGRect descRect; // @synthesize descRect=_descRect;
@property(copy, nonatomic) NSAttributedString *desc; // @synthesize desc=_desc;
@property(nonatomic) struct CGRect authorRect; // @synthesize authorRect=_authorRect;
@property(copy, nonatomic) NSAttributedString *author; // @synthesize author=_author;
@property(nonatomic) struct CGRect titleRect; // @synthesize titleRect=_titleRect;
@property(copy, nonatomic) NSAttributedString *title; // @synthesize title=_title;
@property(nonatomic) struct CGRect avatorViewRect; // @synthesize avatorViewRect=_avatorViewRect;
@property(retain, nonatomic) NSURL *avatorUrl; // @synthesize avatorUrl=_avatorUrl;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGSize viewSize; // @synthesize viewSize=_viewSize;
- (void).cxx_destruct;
- (void)calculateWithListItem:(id)arg1 context:(id)arg2;

@end
