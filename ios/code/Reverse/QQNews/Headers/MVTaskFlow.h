//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MVTaskObserver.h"

@class MVTask, NSArray, NSMutableArray, NSMutableDictionary, NSString;

@interface MVTaskFlow : NSObject <MVTaskObserver>
{
    float _progress;
    float _totalProgressOfCompletedTasks;
    long long _state;
    CDUnknownBlockType _didUpdateProgress;
    CDUnknownBlockType _didCompleteTask;
    CDUnknownBlockType _didComplete;
    NSMutableArray *_allTasks;
    NSMutableDictionary *_taskDetails;
    long long _nextTaskIndex;
    MVTask *_currentInvokingTask;
    NSMutableArray *_runningTasks;
    NSMutableArray *_blockRunningTasks;
}

+ (id)taskFlowWithTasks:(id)arg1;
@property(nonatomic) float totalProgressOfCompletedTasks; // @synthesize totalProgressOfCompletedTasks=_totalProgressOfCompletedTasks;
@property(retain, nonatomic) NSMutableArray *blockRunningTasks; // @synthesize blockRunningTasks=_blockRunningTasks;
@property(retain, nonatomic) NSMutableArray *runningTasks; // @synthesize runningTasks=_runningTasks;
@property(retain, nonatomic) MVTask *currentInvokingTask; // @synthesize currentInvokingTask=_currentInvokingTask;
@property(nonatomic) long long nextTaskIndex; // @synthesize nextTaskIndex=_nextTaskIndex;
@property(retain, nonatomic) NSMutableDictionary *taskDetails; // @synthesize taskDetails=_taskDetails;
@property(retain, nonatomic) NSMutableArray *allTasks; // @synthesize allTasks=_allTasks;
@property(copy, nonatomic) CDUnknownBlockType didComplete; // @synthesize didComplete=_didComplete;
@property(copy, nonatomic) CDUnknownBlockType didCompleteTask; // @synthesize didCompleteTask=_didCompleteTask;
@property(copy, nonatomic) CDUnknownBlockType didUpdateProgress; // @synthesize didUpdateProgress=_didUpdateProgress;
@property(nonatomic) long long state; // @synthesize state=_state;
@property(nonatomic) float progress; // @synthesize progress=_progress;
- (void).cxx_destruct;
- (void)cancel;
- (void)resume;
- (void)pause;
- (void)start;
@property(retain, nonatomic) NSArray *tasks;
- (id)init;
- (void)taskDidUnblock:(id)arg1;
- (void)task:(id)arg1 didUpdateProgress:(float)arg2;
- (void)task:(id)arg1 didCompleteWithError:(id)arg2;
- (void)reset;
- (void)updateProgress;
- (void)completeWithError:(id)arg1;
- (_Bool)runTask:(id)arg1;
- (void)attamptToRunTasks;
- (void)runTasks;
- (_Bool)isAllTasksCompleted;
- (void)analyzeProgressWeightsForAllTasks;
- (_Bool)changeState:(long long)arg1 forTask:(id)arg2;
- (void)setState:(long long)arg1 forTask:(id)arg2;
- (long long)stateOfTask:(id)arg1;
- (void)removeTasks:(id)arg1;
- (void)addTasks:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
