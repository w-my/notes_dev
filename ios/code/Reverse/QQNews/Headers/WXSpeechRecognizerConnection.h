//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WXVoiceConnectionDelegate.h"

@class NSConditionLock, NSData, NSMutableArray, NSMutableData, NSString, WXVoiceConnection, WXVoiceCountDictionary;

@interface WXSpeechRecognizerConnection : NSObject <WXVoiceConnectionDelegate>
{
    long long _state;
    WXVoiceConnection *_connection;
    long long _timestampErrorCount;
    _Bool _isConnected;
    long long _timeOffset;
    NSMutableArray *_encodeVoiceDataArray;
    _Bool _isCompleted;
    long long _packageType;
    long long _offset;
    struct _TRSpeexEncodeContex _speexEncodeContex;
    _Bool _speexHasInit;
    char *_encodeBuffer;
    struct AMREncodeFloat *_amrEncode;
    long long _endOffset;
    long long _startOffset;
    _Bool _needSendCount;
    _Bool _isSendingCount;
    char *_sendingVoiceBuffer;
    long long _sendingEncodeVoiceDataLength;
    long long _sendingVoiceLength;
    long long _sendingIsEndPackage;
    NSMutableData *_saveencodebuffer;
    NSMutableData *_testData;
    int _testCount;
    struct TRSILK _silkEncoder;
    _Bool _isSilkInit;
    _Bool continuousMode;
    int language_type;
    int _domain;
    id <WXSpeechRecognizerConnectionDelegate> _delegate;
    long long _netType;
    long long _maxResultCount;
    long long _resultType;
    NSString *_grammarID;
    NSString *_appID;
    NSData *_key;
    NSString *_voice_id;
    NSString *_device_info;
    NSString *_guid;
    NSString *_systemVersion;
    NSString *_siginfo;
    WXVoiceCountDictionary *_countDictionary;
    NSData *_sendingGrammarData;
    long long _sendingGrammarType;
    NSString *_defaultServer;
    long long _defaultPort;
    NSString *_defaultAppUrl;
    long long _mapReturnType;
    NSString *_urlParameter;
    NSConditionLock *_encodeArrayLock;
}

@property(nonatomic) NSConditionLock *encodeArrayLock; // @synthesize encodeArrayLock=_encodeArrayLock;
@property(retain, nonatomic) NSString *urlParameter; // @synthesize urlParameter=_urlParameter;
@property(nonatomic) long long mapReturnType; // @synthesize mapReturnType=_mapReturnType;
@property(retain, nonatomic) NSString *defaultAppUrl; // @synthesize defaultAppUrl=_defaultAppUrl;
@property(nonatomic) long long defaultPort; // @synthesize defaultPort=_defaultPort;
@property(retain, nonatomic) NSString *defaultServer; // @synthesize defaultServer=_defaultServer;
@property(nonatomic) long long sendingGrammarType; // @synthesize sendingGrammarType=_sendingGrammarType;
@property(retain, nonatomic) NSData *sendingGrammarData; // @synthesize sendingGrammarData=_sendingGrammarData;
@property(retain, nonatomic) WXVoiceCountDictionary *countDictionary; // @synthesize countDictionary=_countDictionary;
@property(retain, nonatomic) NSString *siginfo; // @synthesize siginfo=_siginfo;
@property(retain, nonatomic) NSString *systemVersion; // @synthesize systemVersion=_systemVersion;
@property(retain, nonatomic) NSString *guid; // @synthesize guid=_guid;
@property(retain, nonatomic) NSString *device_info; // @synthesize device_info=_device_info;
@property(retain, nonatomic) NSString *voice_id; // @synthesize voice_id=_voice_id;
@property(retain, nonatomic) NSData *key; // @synthesize key=_key;
@property(retain, nonatomic) NSString *appID; // @synthesize appID=_appID;
@property(nonatomic) int domain; // @synthesize domain=_domain;
@property(nonatomic) int language_type; // @synthesize language_type;
@property(nonatomic) _Bool continuousMode; // @synthesize continuousMode;
@property(retain, nonatomic) NSString *grammarID; // @synthesize grammarID=_grammarID;
@property(nonatomic) long long resultType; // @synthesize resultType=_resultType;
@property(nonatomic) long long maxResultCount; // @synthesize maxResultCount=_maxResultCount;
@property(nonatomic) long long netType; // @synthesize netType=_netType;
@property(nonatomic) id <WXSpeechRecognizerConnectionDelegate> delegate; // @synthesize delegate=_delegate;
- (id).cxx_construct;
- (void).cxx_destruct;
- (_Bool)shouldSendData:(id)arg1 withUrlArgs:(id)arg2 delegate:(id)arg3;
- (_Bool)loadTimeOffset;
- (void)saveTimeOffset;
- (_Bool)voiceEncodepInput:(char *)arg1 nInputSize:(int)arg2 pOutput:(char *)arg3 pOutputSize:(int *)arg4 isFirst:(_Bool)arg5;
- (void)reSet;
- (void)voiceConnectionDidCancel;
- (void)voiceConnectionError:(long long)arg1 andHttpStatus:(long long)arg2;
- (void)voiceConnectionReceiveBytes:(char *)arg1 length:(long long)arg2;
- (id)makeQueryArgsForSendGrammar;
- (id)makeQueryArgs;
- (id)urlAppendOther;
- (id)makeUrlOfSendGrammarData;
- (id)makeUrlOfSendData;
- (void)connection;
- (void)sendNext;
- (void)changeCountDictionaryWithResultKind:(_Bool)arg1;
- (void)cancel;
- (void)sendFinishWithUselessLength:(long long)arg1;
- (_Bool)sendVoiceBytes:(void *)arg1 length:(unsigned int)arg2 isSegEnd:(_Bool)arg3 startOffset:(long long)arg4 endOffset:(long long)arg5 uselessLength:(long long)arg6;
- (void)setGrammarString:(id)arg1 type:(int)arg2;
- (void)setAppID:(id)arg1 andKey:(id)arg2;
- (id)init;
- (void)dealloc;
- (void)openAuth;
- (void)setReturnTypeForMap:(long long)arg1;
- (void)setAppendUrlString:(id)arg1;
- (void)setHostName:(id)arg1;
- (void)setServer:(id)arg1 andPort:(long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

