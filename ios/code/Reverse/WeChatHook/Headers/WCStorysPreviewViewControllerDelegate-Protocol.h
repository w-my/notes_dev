//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class WCStorysPreviewViewController;

@protocol WCStorysPreviewViewControllerDelegate <NSObject>

@optional
- (void)storysPreviewViewControlleriCancelHideDataItem:(WCStorysPreviewViewController *)arg1;
- (void)storysPreviewViewControllerHideAllDataItem:(WCStorysPreviewViewController *)arg1;
- (void)WCStorysPreviewViewControllerDeleteAllDataItem:(WCStorysPreviewViewController *)arg1;
- (void)WCStorysPreviewViewControllerShowFrontViewWithAnimated:(_Bool)arg1;
- (void)WCStorysPreviewViewControllerDidPanInVerticalWithTouchPoint:(struct CGPoint)arg1 andState:(long long)arg2;
@end
