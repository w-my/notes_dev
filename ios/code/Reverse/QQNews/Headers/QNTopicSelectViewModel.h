//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString, QNCategoryListLoader, QNTopicSearchApi;

@interface QNTopicSelectViewModel : NSObject
{
    _Bool _didHistoryListExposure;
    _Bool _didHotListExposure;
    _Bool _didSearchListExposure;
    NSString *_keyword;
    CDUnknownBlockType _topicDataChangedBlock;
    CDUnknownBlockType _noSearchResultBlock;
    QNCategoryListLoader *_hotTopicListLoader;
    QNTopicSearchApi *_topicSearchApi;
    NSMutableArray *_topicDataArray;
}

@property(nonatomic) _Bool didSearchListExposure; // @synthesize didSearchListExposure=_didSearchListExposure;
@property(nonatomic) _Bool didHotListExposure; // @synthesize didHotListExposure=_didHotListExposure;
@property(nonatomic) _Bool didHistoryListExposure; // @synthesize didHistoryListExposure=_didHistoryListExposure;
@property(retain, nonatomic) NSMutableArray *topicDataArray; // @synthesize topicDataArray=_topicDataArray;
@property(retain, nonatomic) QNTopicSearchApi *topicSearchApi; // @synthesize topicSearchApi=_topicSearchApi;
@property(retain, nonatomic) QNCategoryListLoader *hotTopicListLoader; // @synthesize hotTopicListLoader=_hotTopicListLoader;
@property(copy, nonatomic) CDUnknownBlockType noSearchResultBlock; // @synthesize noSearchResultBlock=_noSearchResultBlock;
@property(copy, nonatomic) CDUnknownBlockType topicDataChangedBlock; // @synthesize topicDataChangedBlock=_topicDataChangedBlock;
@property(copy, nonatomic) NSString *keyword; // @synthesize keyword=_keyword;
- (void).cxx_destruct;
- (void)p_setTopicList:(id)arg1 forSection:(unsigned long long)arg2;
- (void)cancelAllRequest;
- (void)keywordChanged:(id)arg1;
- (void)loadHotTopicDataWithSuccessBlock:(CDUnknownBlockType)arg1 failedBlock:(CDUnknownBlockType)arg2;
- (void)deleteHistoryTopic;
- (id)topicItemAtIndexPath:(id)arg1;
- (long long)numberOfRowsInSection:(long long)arg1;
- (long long)numberOfSections;
- (_Bool)hasValidData;
- (id)init;

@end

