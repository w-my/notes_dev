//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class NSMutableArray;

@interface QNNetworkResponseHandlerList : NSObject <NSCopying>
{
    NSMutableArray *_handlers;
}

@property(retain, nonatomic) NSMutableArray *handlers; // @synthesize handlers=_handlers;
- (void).cxx_destruct;
- (id)handleResponse:(id)arg1 request:(id)arg2;
- (void)removeAllHandlers;
- (void)removeHandlerWithName:(id)arg1;
- (void)addHandlerWithName:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)addHandler:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;

@end

