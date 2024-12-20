//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WXOMTAEvent.h"

#import "WXOMTAEventProtocol.h"

@class NSString;

@interface WXOMTATestSpeedEvent : WXOMTAEvent <WXOMTAEventProtocol>
{
    NSString *_sp;
    NSString *_op;
    NSString *_cn;
}

@property(copy, nonatomic) NSString *cn; // @synthesize cn=_cn;
@property(copy, nonatomic) NSString *op; // @synthesize op=_op;
@property(copy, nonatomic) NSString *sp; // @synthesize sp=_sp;
- (void).cxx_destruct;
- (id)init;
- (void)encode:(id)arg1;
- (int)getType;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

