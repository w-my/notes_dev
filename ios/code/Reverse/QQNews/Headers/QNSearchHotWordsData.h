//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class QNListNewsItem, QNSearchHotWordsShowInfo, QNTopicItem;

@interface QNSearchHotWordsData : QNBaseModelObject <NSCopying, NSCoding>
{
    QNSearchHotWordsShowInfo *_hotWordsShowInfo;
    QNListNewsItem *_listItem;
    QNTopicItem *_topicItem;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNSearchHotWordsShowInfo *hotWordsShowInfo; // @synthesize hotWordsShowInfo=_hotWordsShowInfo;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
