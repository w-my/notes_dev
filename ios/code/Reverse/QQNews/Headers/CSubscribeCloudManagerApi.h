//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

#import "NSCopying.h"

@class NSDictionary;

@interface CSubscribeCloudManagerApi : QNNetworkJSONDictionaryApi <NSCopying>
{
    NSDictionary *_userInfo;
}

@property(copy, nonatomic) NSDictionary *userInfo; // @synthesize userInfo=_userInfo;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithURLString:(id)arg1 params:(id)arg2;

@end

