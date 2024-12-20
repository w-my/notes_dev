//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class UIPanGestureRecognizer, UIPinchGestureRecognizer, UITapGestureRecognizer;

@protocol MVCameraControllerGestureDelegate <NSObject>
- (_Bool)handleDoublePanGesture:(UIPanGestureRecognizer *)arg1;
- (_Bool)handleSinglePanGesture:(UIPanGestureRecognizer *)arg1;
- (_Bool)handlePinchGesture:(UIPinchGestureRecognizer *)arg1;
- (_Bool)handleDoubleTapGesture:(UITapGestureRecognizer *)arg1;
- (_Bool)handleSingleTapGesture:(UITapGestureRecognizer *)arg1;
@end

