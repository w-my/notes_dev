//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

@interface QNSecondLevelReplyListApi : QNNetworkJSONDictionaryApi
{
}

+ (id)p_parseResponseInfo:(id)arg1 rootComment:(id)arg2;
- (id)initWithListItem:(id)arg1 rootComment:(id)arg2;
- (void)startWithSuccess:(CDUnknownBlockType)arg1 fail:(CDUnknownBlockType)arg2;
- (Class)callbackResultClass;

@end

