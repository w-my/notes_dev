//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WXSpeechSynthesizerConnectionDelegate.h"

@class NSString, WXSpeechSynthesizerConnection;

@interface WXVoiceTTS : NSObject <WXSpeechSynthesizerConnectionDelegate>
{
    long long _speechFormat;
    float _speechVolumn;
    WXSpeechSynthesizerConnection *_connection;
    _Bool _isReady;
    _Bool _needCallbackCancel;
    id <WXVoiceTTSDelegate> _delegate;
}

+ (id)alloc;
+ (void)releaseWXVoiceTTS;
+ (id)sharedWXVoiceTTS;
@property(nonatomic) id <WXVoiceTTSDelegate> delegate; // @synthesize delegate=_delegate;
- (id)autorelease;
- (oneway void)release;
- (unsigned long long)retainCount;
- (id)retain;
- (int)byteFromChar16:(BOOL)arg1;
- (void)connectionDidCancel;
- (void)connectionResultSpeechData:(id)arg1 speechFormat:(int)arg2;
- (void)connectionErrorCode:(long long)arg1 andHttpStatus:(long long)arg2;
- (void)cancel;
- (_Bool)startWithText:(id)arg1;
- (void)setVolumn:(float)arg1;
- (void)setSpeechFormat:(int)arg1;
- (void)setAppID:(id)arg1;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
