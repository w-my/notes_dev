//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

@interface QNExclusiveColumnApi : QNNetworkJSONDictionaryApi
{
}

- (id)p_buildItemsFromResponseDict:(id)arg1;
- (id)initWithParameters:(long long)arg1 mediaIds:(id)arg2;
- (void)startWithSuccess:(CDUnknownBlockType)arg1 fail:(CDUnknownBlockType)arg2;
- (Class)callbackResultClass;

@end
