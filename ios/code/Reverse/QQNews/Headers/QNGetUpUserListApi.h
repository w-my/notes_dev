//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

@interface QNGetUpUserListApi : QNNetworkJSONDictionaryApi
{
}

- (id)p_parseResponseInfo:(id)arg1;
- (id)initWithCommentId:(id)arg1 replyId:(id)arg2 last:(unsigned long long)arg3 tipsType:(unsigned long long)arg4;
- (id)initWithCommentId:(id)arg1 replyId:(id)arg2 tipsType:(unsigned long long)arg3;
- (void)startWithSuccess:(CDUnknownBlockType)arg1 fail:(CDUnknownBlockType)arg2;
- (Class)callbackResultClass;

@end

