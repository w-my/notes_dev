//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSTimer;

@interface MatrixTester : NSObject
{
    NSTimer *_runloopTimer;
    NSTimer *_runloop2Timer;
}

@property(retain, nonatomic) NSTimer *runloop2Timer; // @synthesize runloop2Timer=_runloop2Timer;
@property(retain, nonatomic) NSTimer *runloopTimer; // @synthesize runloopTimer=_runloopTimer;
- (void).cxx_destruct;
- (void)costCPUALot;
- (void)runloop2Selector;
- (void)runloop1Selector;
- (void)testSpecialSceneOfLag;
- (void)generateMainThreadBlockToBeKilledLog;
- (void)generateMainThreadLagLog;
- (void)fooo:(char *)arg1;
- (void)foo;
- (void)overflowCrash;
- (void)childNsexceptionCrash;
- (void)cppToNsExceptionCrash;
- (void)cppexceptionCrash;
- (void)nsexceptionCrash;
- (void)deadSignalCrash;
- (void)wrongFormatCrash;
- (void)notFoundSelectorCrash;

@end
