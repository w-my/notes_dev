//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNScrollViewDelegateRelayViewController;

@protocol QNScrollViewDelegateRelayViewControllerObserver <NSObject>
- (void)triggerPullToRefreshOfController:(QNScrollViewDelegateRelayViewController *)arg1;
- (void)adjustContentOffsetIfNeeded:(QNScrollViewDelegateRelayViewController *)arg1 animated:(_Bool)arg2;
- (void)adjustContentOffsetIfNeeded:(QNScrollViewDelegateRelayViewController *)arg1;
@end
