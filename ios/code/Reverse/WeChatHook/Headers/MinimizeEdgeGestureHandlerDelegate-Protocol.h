//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MinimizeEdgeGestureHandler;

@protocol MinimizeEdgeGestureHandlerDelegate <NSObject>
- (void)onEdgeInteractiveTransitionDidEnd:(MinimizeEdgeGestureHandler *)arg1 isComplete:(_Bool)arg2;
- (void)onEdgeInteractiveTransitionWillEnd:(MinimizeEdgeGestureHandler *)arg1 isComplete:(_Bool)arg2;
- (void)onEdgeInteractiveTransitionChanged:(MinimizeEdgeGestureHandler *)arg1 progress:(double)arg2;
- (void)onEdgeInteractiveTransitionBegin:(MinimizeEdgeGestureHandler *)arg1;
@end

