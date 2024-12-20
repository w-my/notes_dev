//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

#import "NSCopying.h"

@class NSArray, NSString;

@interface QNNewsListItemsApi : QNNetworkJSONDictionaryApi <NSCopying>
{
    NSString *_channelID;
    NSArray *_newsIDs;
}

+ (id)cgiNameForChannelID:(id)arg1;
@property(copy, nonatomic) NSArray *newsIDs; // @synthesize newsIDs=_newsIDs;
@property(copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
- (void).cxx_destruct;
- (id)_parseData:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithChannelID:(id)arg1 newsIDs:(id)arg2 changeInfoIDs:(id)arg3 isOffline:(_Bool)arg4 extraPostData:(id)arg5;

@end

