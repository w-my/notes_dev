//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class NSArray, NSString, QNListNewsItem;

@interface QNQADetailReplyInfoParams : NSObject <NSCopying>
{
    _Bool _canLoadModel;
    _Bool _didAnswer;
    QNListNewsItem *_listItem;
    NSArray *_viewList;
    long long _currentIndex;
    NSString *_commentId;
    NSString *_answerArticleId;
    NSString *_questionArticleId;
    NSString *_channel;
    NSString *_origId;
    NSString *_coralUid;
    NSString *_coralUin;
    NSString *_coralscore;
    NSString *_replyId;
    long long _allCommentsCount;
    NSString *_fromPage;
    NSString *_tipstime;
    NSString *_pubtime;
    NSString *_mediaId;
    NSString *_mediaOpenId;
    NSString *_selectedItemReplyId;
}

+ (id)getNextQNQADetailReplyInfoParams:(id)arg1 index:(long long)arg2;
+ (id)buildQADetailReplyInfoParams:(id)arg1;
@property(copy, nonatomic) NSString *selectedItemReplyId; // @synthesize selectedItemReplyId=_selectedItemReplyId;
@property(copy, nonatomic) NSString *mediaOpenId; // @synthesize mediaOpenId=_mediaOpenId;
@property(copy, nonatomic) NSString *mediaId; // @synthesize mediaId=_mediaId;
@property(nonatomic) _Bool didAnswer; // @synthesize didAnswer=_didAnswer;
@property(copy, nonatomic) NSString *pubtime; // @synthesize pubtime=_pubtime;
@property(copy, nonatomic) NSString *tipstime; // @synthesize tipstime=_tipstime;
@property(copy, nonatomic) NSString *fromPage; // @synthesize fromPage=_fromPage;
@property(nonatomic) long long allCommentsCount; // @synthesize allCommentsCount=_allCommentsCount;
@property(copy, nonatomic) NSString *replyId; // @synthesize replyId=_replyId;
@property(copy, nonatomic) NSString *coralscore; // @synthesize coralscore=_coralscore;
@property(nonatomic) _Bool canLoadModel; // @synthesize canLoadModel=_canLoadModel;
@property(copy, nonatomic) NSString *coralUin; // @synthesize coralUin=_coralUin;
@property(copy, nonatomic) NSString *coralUid; // @synthesize coralUid=_coralUid;
@property(copy, nonatomic) NSString *origId; // @synthesize origId=_origId;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
@property(copy, nonatomic) NSString *questionArticleId; // @synthesize questionArticleId=_questionArticleId;
@property(copy, nonatomic) NSString *answerArticleId; // @synthesize answerArticleId=_answerArticleId;
@property(copy, nonatomic) NSString *commentId; // @synthesize commentId=_commentId;
@property(nonatomic) long long currentIndex; // @synthesize currentIndex=_currentIndex;
@property(copy, nonatomic) NSArray *viewList; // @synthesize viewList=_viewList;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

