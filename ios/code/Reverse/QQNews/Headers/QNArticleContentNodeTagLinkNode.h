//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CArticleContentNodeType.h"

#import "NSCoding.h"

@class NSArray, NSString, QNTagItem;

@interface QNArticleContentNodeTagLinkNode : CArticleContentNodeType <NSCoding>
{
    _Bool _visit;
    QNTagItem *_tagItem;
    NSString *_tagType;
    NSArray *_linkItems;
    NSString *_url;
    NSString *_extWording;
    long long _halfScreenHeight;
}

@property(nonatomic) _Bool visit; // @synthesize visit=_visit;
@property(nonatomic) long long halfScreenHeight; // @synthesize halfScreenHeight=_halfScreenHeight;
@property(copy, nonatomic) NSString *extWording; // @synthesize extWording=_extWording;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
@property(copy, nonatomic) NSArray *linkItems; // @synthesize linkItems=_linkItems;
@property(copy, nonatomic) NSString *tagType; // @synthesize tagType=_tagType;
@property(retain, nonatomic) QNTagItem *tagItem; // @synthesize tagItem=_tagItem;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithTagName:(id)arg1 tagId:(id)arg2 icon:(id)arg3 url:(id)arg4 linkItems:(id)arg5;
- (id)initWithInfo:(id)arg1;

@end
