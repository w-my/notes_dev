//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSString, QNListNewsItem, QNReportParam;

@interface QNNewsDetailLoaderParams : NSObject
{
    _Bool _appendDefaultPostValues;
    _Bool _isFromRemoteNews;
    _Bool _isBackground;
    NSString *_requestUrl;
    NSString *_channelID;
    NSString *_newsID;
    QNListNewsItem *_listItem;
    NSDictionary *_postValues;
    NSDictionary *_queryValues;
    QNReportParam *_reportParam;
    unsigned long long _cachePolicy;
}

+ (id)defaultPostValuesWithChannelId:(id)arg1 listItem:(id)arg2 commonParam:(id)arg3 reportParam:(id)arg4;
@property(nonatomic) unsigned long long cachePolicy; // @synthesize cachePolicy=_cachePolicy;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(nonatomic) _Bool isBackground; // @synthesize isBackground=_isBackground;
@property(nonatomic) _Bool isFromRemoteNews; // @synthesize isFromRemoteNews=_isFromRemoteNews;
@property(nonatomic) _Bool appendDefaultPostValues; // @synthesize appendDefaultPostValues=_appendDefaultPostValues;
@property(copy, nonatomic) NSDictionary *queryValues; // @synthesize queryValues=_queryValues;
@property(copy, nonatomic) NSDictionary *postValues; // @synthesize postValues=_postValues;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(copy, nonatomic) NSString *newsID; // @synthesize newsID=_newsID;
@property(copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
@property(copy, nonatomic) NSString *requestUrl; // @synthesize requestUrl=_requestUrl;
- (void).cxx_destruct;
- (id)init;

@end

