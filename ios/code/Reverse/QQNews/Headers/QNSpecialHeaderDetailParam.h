//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString, QNArticleContentEventTimeLineNode, QNListNewsItem, QNTopicItem;

@interface QNSpecialHeaderDetailParam : NSObject
{
    QNListNewsItem *_listItem;
    NSString *_title;
    NSString *_abstract;
    NSString *_imageUrl;
    QNTopicItem *_topicItem;
    long long _readCount;
    long long _followCount;
    NSArray *_headerActItems;
    QNArticleContentEventTimeLineNode *_timeLineNode;
}

@property(retain, nonatomic) QNArticleContentEventTimeLineNode *timeLineNode; // @synthesize timeLineNode=_timeLineNode;
@property(copy, nonatomic) NSArray *headerActItems; // @synthesize headerActItems=_headerActItems;
@property(nonatomic) long long followCount; // @synthesize followCount=_followCount;
@property(nonatomic) long long readCount; // @synthesize readCount=_readCount;
@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(copy, nonatomic) NSString *imageUrl; // @synthesize imageUrl=_imageUrl;
@property(copy, nonatomic) NSString *abstract; // @synthesize abstract=_abstract;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;

@end
