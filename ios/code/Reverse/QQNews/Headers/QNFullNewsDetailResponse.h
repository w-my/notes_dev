//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CArticleContentType, NSArray, NSString;

@interface QNFullNewsDetailResponse : NSObject
{
    NSArray *_listItems;
    CArticleContentType *_articleContent;
    NSArray *_autoPushNewsList;
    NSString *_traceID;
}

@property(copy, nonatomic) NSString *traceID; // @synthesize traceID=_traceID;
@property(copy, nonatomic) NSArray *autoPushNewsList; // @synthesize autoPushNewsList=_autoPushNewsList;
@property(retain, nonatomic) CArticleContentType *articleContent; // @synthesize articleContent=_articleContent;
@property(copy, nonatomic) NSArray *listItems; // @synthesize listItems=_listItems;
- (void).cxx_destruct;

@end
