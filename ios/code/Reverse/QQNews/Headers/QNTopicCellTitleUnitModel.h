//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListUnitModelProtocol.h"

@class NSAttributedString, NSString, QNListNewsItem, UIColor;

@interface QNTopicCellTitleUnitModel : NSObject <QNListUnitModelProtocol>
{
    _Bool _hasOrigialLink;
    QNListNewsItem *_listItem;
    UIColor *_bgColor;
    NSString *_articalTitle;
    NSAttributedString *_content;
    unsigned long long _numberOfLines;
    struct CGRect _rect;
    struct CGRect _contentRect;
    struct CGRect _contentLastLineRect;
    struct CGRect _topicLastLineRect;
}

@property(nonatomic) struct CGRect topicLastLineRect; // @synthesize topicLastLineRect=_topicLastLineRect;
@property(nonatomic) _Bool hasOrigialLink; // @synthesize hasOrigialLink=_hasOrigialLink;
@property(nonatomic) unsigned long long numberOfLines; // @synthesize numberOfLines=_numberOfLines;
@property(nonatomic) struct CGRect contentLastLineRect; // @synthesize contentLastLineRect=_contentLastLineRect;
@property(nonatomic) struct CGRect contentRect; // @synthesize contentRect=_contentRect;
@property(copy, nonatomic) NSAttributedString *content; // @synthesize content=_content;
@property(copy, nonatomic) NSString *articalTitle; // @synthesize articalTitle=_articalTitle;
@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGRect rect; // @synthesize rect=_rect;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (id)p_generateAttributeStringWithlistItem:(id)arg1 context:(id)arg2;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
