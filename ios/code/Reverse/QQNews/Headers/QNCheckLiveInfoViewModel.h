//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSTimer, QNCheckLiveInfoApi, QNListNewsItem, QNWeakArray;

@interface QNCheckLiveInfoViewModel : NSObject
{
    QNListNewsItem *_listItem;
    QNCheckLiveInfoApi *_checkRequest;
    NSTimer *_timer;
    QNWeakArray *_listeners;
    long long _cachedLikes;
}

@property(nonatomic) long long cachedLikes; // @synthesize cachedLikes=_cachedLikes;
@property(retain, nonatomic) QNWeakArray *listeners; // @synthesize listeners=_listeners;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(retain, nonatomic) QNCheckLiveInfoApi *checkRequest; // @synthesize checkRequest=_checkRequest;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)p_updateLiveInfo;
- (void)addLiveInfoLikeCount:(long long)arg1;
- (void)stopUpdate;
- (void)startUpdate;
- (void)addListener:(id)arg1;
- (void)dealloc;
- (id)initWithListItem:(id)arg1;

@end

