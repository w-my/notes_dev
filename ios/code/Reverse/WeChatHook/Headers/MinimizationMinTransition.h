//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "UIViewControllerAnimatedTransitioning.h"

@class NSString;

@interface MinimizationMinTransition : NSObject <UIViewControllerAnimatedTransitioning>
{
    NSString *_taskBizName;
    NSString *_taskBizKey;
    id <MinimizeTransitionInterface> _transitionDelegate;
}

@property(nonatomic) __weak id <MinimizeTransitionInterface> transitionDelegate; // @synthesize transitionDelegate=_transitionDelegate;
@property(copy, nonatomic) NSString *taskBizKey; // @synthesize taskBizKey=_taskBizKey;
@property(copy, nonatomic) NSString *taskBizName; // @synthesize taskBizName=_taskBizName;
- (void).cxx_destruct;
- (void)animateTransition:(id)arg1;
- (double)transitionDuration:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

