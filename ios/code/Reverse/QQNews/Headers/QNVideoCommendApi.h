//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

#import "NSCopying.h"

@class NSString;

@interface QNVideoCommendApi : QNNetworkJSONDictionaryApi <NSCopying>
{
    NSString *_currentChannel;
    NSString *_vid;
    long long _commendType;
    long long _num;
}

@property(nonatomic) long long num; // @synthesize num=_num;
@property(nonatomic) long long commendType; // @synthesize commendType=_commendType;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(copy, nonatomic) NSString *currentChannel; // @synthesize currentChannel=_currentChannel;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithIDStr:(id)arg1 num:(unsigned long long)arg2 exposedids:(id)arg3;
- (id)p_handleResponse:(id)arg1;
- (id)initWithVid:(id)arg1 commendType:(long long)arg2 num:(long long)arg3 alginfo:(id)arg4 scence:(long long)arg5 channelID:(id)arg6;

@end

