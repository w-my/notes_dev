//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

@class QNNavigationBar, QNNavigationController, QNNavigationItem;

@interface UIViewController (QNNavigation)
- (id)p_parentViewController;
- (_Bool)qn_isPresentInsideTopViewController;
- (_Bool)qn_isDescendantOfController:(id)arg1;
- (id)qn_getControllerInNavigationStackOfClass:(Class)arg1;
- (_Bool)qn_previousNavigationStackContainsControllerOfClass:(Class)arg1;
- (_Bool)qn_isPushedFromFavoritesViewController;
- (_Bool)qn_isPushedFromOfflineViewController;
@property(readonly, nonatomic) QNNavigationItem *qn_navigationItem;
@property(nonatomic) __weak QNNavigationController *qn_navigationController; // @dynamic qn_navigationController;
@property(nonatomic) __weak QNNavigationBar *qn_navigationBar; // @dynamic qn_navigationBar;
@property(nonatomic) long long qn_animationType; // @dynamic qn_animationType;
- (id)navController;
@end
