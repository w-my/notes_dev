//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

@interface QNUserWeiboListApi : QNNetworkJSONDictionaryApi
{
}

- (id)p_buildItemsFromResponseDict:(id)arg1;
- (id)initWithUserType:(unsigned long long)arg1 coralUin:(id)arg2 coralUid:(id)arg3 chlId:(id)arg4 refItem:(id)arg5 last:(id)arg6;
- (id)initWithChlid:(id)arg1 refItem:(id)arg2 last:(id)arg3;
- (id)initWithCoralUin:(id)arg1 coralUid:(id)arg2 refItem:(id)arg3 last:(id)arg4;
- (id)initWithRefItem:(id)arg1 last:(id)arg2;
- (void)startWithSuccess:(CDUnknownBlockType)arg1 fail:(CDUnknownBlockType)arg2;
- (Class)callbackResultClass;

@end

