//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCWebSocketMgrExt.h"

@class NSMutableDictionary, NSObject<OS_dispatch_queue>, NSString, WAAppTask, WAWebSocketConfig;

@interface NewWAWebSocketHandler : NSObject <WCWebSocketMgrExt>
{
    NSString *_appID;
    WAAppTask *_appTask;
    NSObject<OS_dispatch_queue> *_workerQueue;
    WAWebSocketConfig *_webSocketConfig;
    unsigned int _appType;
    _Bool _tcpNoDelay;
    _Bool _perMessageDeflate;
    NSMutableDictionary *_dicTaskID2WCID;
    NSMutableDictionary *_dicWCID2TaskID;
}

- (void).cxx_destruct;
- (void)webSocket:(unsigned int)arg1 group:(id)arg2 didCloseWithCode:(long long)arg3 reason:(id)arg4;
- (void)webSocket:(unsigned int)arg1 group:(id)arg2 didOpenWithCode:(long long)arg3 success:(_Bool)arg4 headers:(id)arg5 msg:(id)arg6;
- (void)webSocket:(unsigned int)arg1 group:(id)arg2 didReceiveMessage:(id)arg3;
- (id)genNewSocketTaskID;
- (void)removeAllTask;
- (void)removeTask:(id)arg1;
- (void)addTask:(id)arg1 wcwssID:(id)arg2;
- (id)getAllTask;
- (id)getTaskIDWithWCID:(id)arg1;
- (id)getTaskWithTaskID:(id)arg1;
- (unsigned long long)getTaskCount;
- (_Bool)isReachMaxConcurrentCount;
- (void)closeAllTaskAndReleaseImmediately;
- (void)closeAllTaskWithReason:(id)arg1;
- (void)sendData:(id)arg1 taskID:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (void)sendString:(id)arg1 taskID:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (void)closeWithTaskID:(id)arg1 code:(long long)arg2 reason:(id)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (void)openWithTaskID:(id)arg1 url:(id)arg2 httpHeaders:(id)arg3 isIgnoreCheckDomain:(_Bool)arg4 subProtocols:(id)arg5 context:(id)arg6 completionHandler:(CDUnknownBlockType)arg7;
- (void)dealloc;
- (id)initWithAppID:(id)arg1 appVersion:(unsigned long long)arg2 appType:(unsigned int)arg3 workerQueue:(id)arg4 context:(id)arg5;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

