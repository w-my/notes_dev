//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListCellModelProtocol.h"

@class NSAttributedString, NSString, UIColor, UIImage;

@interface QNTopicProgressTextCellModel : NSObject <QNListCellModelProtocol>
{
    id <QNListModelProtocol> _data;
    UIColor *_bgColor;
    UIImage *_quoteImage;
    NSAttributedString *_attrStr;
    UIImage *_headerImage;
    UIImage *_footerImage;
    UIColor *_containerBgColor;
    struct CGRect _rect;
    struct CGRect _quoteRect;
    struct CGRect _descRect;
    struct CGRect _headerImageRect;
    struct CGRect _footerImageRect;
    struct CGRect _containerRect;
}

@property(readonly, nonatomic) UIColor *containerBgColor; // @synthesize containerBgColor=_containerBgColor;
@property(readonly, nonatomic) struct CGRect containerRect; // @synthesize containerRect=_containerRect;
@property(readonly, nonatomic) struct CGRect footerImageRect; // @synthesize footerImageRect=_footerImageRect;
@property(readonly, nonatomic) struct CGRect headerImageRect; // @synthesize headerImageRect=_headerImageRect;
@property(readonly, nonatomic) UIImage *footerImage; // @synthesize footerImage=_footerImage;
@property(readonly, nonatomic) UIImage *headerImage; // @synthesize headerImage=_headerImage;
@property(readonly, copy, nonatomic) NSAttributedString *attrStr; // @synthesize attrStr=_attrStr;
@property(readonly, nonatomic) UIImage *quoteImage; // @synthesize quoteImage=_quoteImage;
@property(readonly, nonatomic) struct CGRect descRect; // @synthesize descRect=_descRect;
@property(readonly, nonatomic) struct CGRect quoteRect; // @synthesize quoteRect=_quoteRect;
@property(readonly, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(readonly, nonatomic) struct CGRect rect; // @synthesize rect=_rect;
@property(readonly, nonatomic) id <QNListModelProtocol> data; // @synthesize data=_data;
- (void).cxx_destruct;
- (id)p_generateAttributeString:(id)arg1;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
