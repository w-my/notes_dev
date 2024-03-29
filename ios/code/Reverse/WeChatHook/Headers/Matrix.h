//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MatrixBuilder;

@interface Matrix : NSObject
{
    MatrixBuilder *_builder;
}

+ (id)sharedInstance;
@property(retain, nonatomic) MatrixBuilder *builder; // @synthesize builder=_builder;
- (void).cxx_destruct;
- (void)notifyAppWillSuspend;
- (void)notifyAppBackgroundFetch;
- (_Bool)isAfterLastLaunchUserRebootDevice;
- (id)userSceneOfLastRun;
- (void)setUserScene:(id)arg1;
- (unsigned long long)lastAppLaunchTime;
- (unsigned long long)appLaunchTime;
- (unsigned long long)lastRebootType;
- (void)reportIssueComplete:(id)arg1 success:(_Bool)arg2;
- (id)getPluginWithTag:(id)arg1;
- (id)getPlugins;
- (void)stopPlugins;
- (void)startPlugins;
- (void)addMatrixBuilder:(id)arg1;
- (id)init;

@end

