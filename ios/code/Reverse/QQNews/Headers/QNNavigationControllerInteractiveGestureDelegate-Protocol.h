//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNNavigationController, UIGestureRecognizer, UIViewController;

@protocol QNNavigationControllerInteractiveGestureDelegate <NSObject>
- (_Bool)qnNavigationController:(QNNavigationController *)arg1 shouldInteractiveGestureRecognizerBegin:(UIGestureRecognizer *)arg2;

@optional
- (void)qnNavigationController:(QNNavigationController *)arg1 controllerWillBeSwipedOut:(UIViewController *)arg2;
- (_Bool)qnNavigationControllerShouldInvokeLeftControlWhenSwipeOut:(QNNavigationController *)arg1;
- (void)qnNavigationController:(QNNavigationController *)arg1 interactionDidEnd:(_Bool)arg2;
- (void)qnNavigationController:(QNNavigationController *)arg1 interactionWillEnd:(_Bool)arg2;
- (void)qnNavigationController:(QNNavigationController *)arg1 interactionDidBegin:(_Bool)arg2;
- (void)qnNavigationController:(QNNavigationController *)arg1 interactionWillBegin:(_Bool)arg2;
@end
