//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CArticleContentNodeType.h"

#import "NSCoding.h"

@class QNListNewsItem;

@interface CArticleRelateNodeType : CArticleContentNodeType <NSCoding>
{
    _Bool _visit;
    QNListNewsItem *_listItem;
}

@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property _Bool visit; // @synthesize visit=_visit;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
