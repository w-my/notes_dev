//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

#import "NSCopying.h"

@class NSString, QNNewsListIndexMetadata;

@interface QNNewsListIndexItemsApi : QNNetworkJSONDictionaryApi <NSCopying>
{
    NSString *_channelID;
    QNNewsListIndexMetadata *_previousData;
}

+ (id)cgiNameForChannelID:(id)arg1;
@property(retain, nonatomic) QNNewsListIndexMetadata *previousData; // @synthesize previousData=_previousData;
@property(copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
- (void).cxx_destruct;
- (id)_parseData:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithChannelID:(id)arg1 previousData:(id)arg2 cachedIDS:(id)arg3 isOffline:(_Bool)arg4 extraPostData:(id)arg5;

@end
