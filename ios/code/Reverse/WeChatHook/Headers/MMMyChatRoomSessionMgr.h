//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IMsgExt.h"
#import "MMService.h"

@class NSMutableDictionary, NSString;

@interface MMMyChatRoomSessionMgr : MMService <IMsgExt, MMService>
{
    _Bool _hasPreLoadCache;
    NSMutableDictionary *_dicMyChatTimeInfo;
}

@property(nonatomic) _Bool hasPreLoadCache; // @synthesize hasPreLoadCache=_hasPreLoadCache;
@property(retain, nonatomic) NSMutableDictionary *dicMyChatTimeInfo; // @synthesize dicMyChatTimeInfo=_dicMyChatTimeInfo;
- (void).cxx_destruct;
- (void)OnAddMsg:(id)arg1 MsgWrap:(id)arg2;
- (_Bool)hasLoaded;
- (void)loadMyChatTimeIfNeeded;
- (_Bool)onServiceMemoryWarning;
- (void)onServiceClearData;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

