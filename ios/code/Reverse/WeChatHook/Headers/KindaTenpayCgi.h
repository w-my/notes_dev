//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MMTenpayCgi.h"

@class NSMutableDictionary, NSString;

@interface KindaTenpayCgi : NSObject <MMTenpayCgi>
{
    NSMutableDictionary *_runningCgiMap;
}

@property(retain, nonatomic) NSMutableDictionary *runningCgiMap; // @synthesize runningCgiMap=_runningCgiMap;
- (void).cxx_destruct;
- (void)request:(int)arg1 reqText:(id)arg2 reqTextWx:(id)arg3 callback:(id)arg4;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
