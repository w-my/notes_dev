//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNVoteApi;

@interface QNVoteManager : NSObject
{
    QNVoteApi *_request;
}

+ (id)sharedManager;
@property(retain, nonatomic) QNVoteApi *request; // @synthesize request=_request;
- (void).cxx_destruct;
- (void)dealloc;
- (void)submitVoteData:(id)arg1;

@end
