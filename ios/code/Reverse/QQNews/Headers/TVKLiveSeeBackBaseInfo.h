//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TVKLiveSeeBackBaseInfo : NSObject
{
    _Bool _isSeeBackState;
    _Bool _hasSeeBack;
    _Bool _isSeeBackRequest;
    long long _seeBackstartTime;
    long long _maxSeeBacktime;
    long long _serverTime;
    long long _userSeeBackTime;
    NSString *_liveUrl;
    NSString *_seeBackUrl;
}

+ (id)seeBackInfoWithDict:(id)arg1;
@property(nonatomic) _Bool isSeeBackRequest; // @synthesize isSeeBackRequest=_isSeeBackRequest;
@property(copy, nonatomic) NSString *seeBackUrl; // @synthesize seeBackUrl=_seeBackUrl;
@property(copy, nonatomic) NSString *liveUrl; // @synthesize liveUrl=_liveUrl;
@property(nonatomic) _Bool hasSeeBack; // @synthesize hasSeeBack=_hasSeeBack;
@property(nonatomic) long long userSeeBackTime; // @synthesize userSeeBackTime=_userSeeBackTime;
@property(nonatomic) _Bool isSeeBackState; // @synthesize isSeeBackState=_isSeeBackState;
@property(nonatomic) long long serverTime; // @synthesize serverTime=_serverTime;
@property(nonatomic) long long maxSeeBacktime; // @synthesize maxSeeBacktime=_maxSeeBacktime;
@property(nonatomic) long long seeBackstartTime; // @synthesize seeBackstartTime=_seeBackstartTime;
- (void).cxx_destruct;

@end
