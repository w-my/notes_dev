//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, NSString, TVKPlayerRetryModel;

@interface TVKPlayContext : NSObject
{
    _Bool _playRetry;
    _Bool _clipResourceLoader;
    unsigned long long _retryCgiCount;
    unsigned long long _errorType;
    TVKPlayerRetryModel *_retryModel;
    NSError *_error;
    NSString *_definition;
    unsigned long long _scene;
    double _startPosition;
}

+ (id)playContextWithSwitchDefinition:(_Bool)arg1 definition:(id)arg2 retry:(_Bool)arg3 airPlay:(_Bool)arg4 startPosition:(double)arg5;
@property(nonatomic) _Bool clipResourceLoader; // @synthesize clipResourceLoader=_clipResourceLoader;
@property(nonatomic) double startPosition; // @synthesize startPosition=_startPosition;
@property(nonatomic) unsigned long long scene; // @synthesize scene=_scene;
@property(copy, nonatomic) NSString *definition; // @synthesize definition=_definition;
@property(copy, nonatomic) NSError *error; // @synthesize error=_error;
@property(retain, nonatomic) TVKPlayerRetryModel *retryModel; // @synthesize retryModel=_retryModel;
@property(nonatomic) unsigned long long errorType; // @synthesize errorType=_errorType;
@property(nonatomic) unsigned long long retryCgiCount; // @synthesize retryCgiCount=_retryCgiCount;
@property(nonatomic) _Bool playRetry; // @synthesize playRetry=_playRetry;
- (void).cxx_destruct;
- (_Bool)isAirPlay;

@end
