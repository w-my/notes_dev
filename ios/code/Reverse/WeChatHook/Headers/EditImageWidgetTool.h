//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "EditImageUIView.h"

#import "UIGestureRecognizerDelegate.h"

@class EditImageBorderView, EditImageModView, NSString, UILongPressGestureRecognizer, UIPanGestureRecognizer, UIPinchGestureRecognizer, UIRotationGestureRecognizer, UITapGestureRecognizer;

@interface EditImageWidgetTool : EditImageUIView <UIGestureRecognizerDelegate>
{
    _Bool _activeTouches;
    unsigned int _gestureMonitor;
    _Bool _isPressing;
    double _swipeLength;
    double _viewScale;
    struct CGPoint _startPanGesturePoint;
    _Bool _hasSaveAttr;
    _Bool _isMoveToTop;
    EditImageModView *_saveView;
    _Bool _hasAddView;
    double _viewBorder;
    double _maxFrameScaleWhileSelect;
    _Bool _hasPreClicked;
    _Bool _isSpecialPaning;
    _Bool _isSelected;
    unsigned int _viewArrayIndex;
    id <EditImageWidgetToolDelegate> _delegate;
    EditImageBorderView *_borderView;
    double _screenScale;
    double _viewAngle;
    double _widgetScale;
    double _zoomScale;
    UIPanGestureRecognizer *_panGesture;
    UITapGestureRecognizer *_tapGesture;
    UIPinchGestureRecognizer *_pinchGesture;
    UIRotationGestureRecognizer *_rotateGesture;
    UILongPressGestureRecognizer *_longPressGesture;
}

@property(retain, nonatomic) UILongPressGestureRecognizer *_longPressGesture; // @synthesize _longPressGesture;
@property(retain, nonatomic) UIRotationGestureRecognizer *_rotateGesture; // @synthesize _rotateGesture;
@property(retain, nonatomic) UIPinchGestureRecognizer *_pinchGesture; // @synthesize _pinchGesture;
@property(retain, nonatomic) UITapGestureRecognizer *_tapGesture; // @synthesize _tapGesture;
@property(retain, nonatomic) UIPanGestureRecognizer *_panGesture; // @synthesize _panGesture;
@property(nonatomic) double _zoomScale; // @synthesize _zoomScale;
@property(nonatomic) double _widgetScale; // @synthesize _widgetScale;
@property(nonatomic) double _viewAngle; // @synthesize _viewAngle;
@property(nonatomic) double _screenScale; // @synthesize _screenScale;
@property(nonatomic) unsigned int _viewArrayIndex; // @synthesize _viewArrayIndex;
@property(retain, nonatomic) EditImageBorderView *_borderView; // @synthesize _borderView;
@property(nonatomic) double _viewScale; // @synthesize _viewScale;
@property(nonatomic) _Bool _isSelected; // @synthesize _isSelected;
@property(nonatomic) id <EditImageWidgetToolDelegate> _delegate; // @synthesize _delegate;
- (void).cxx_destruct;
- (void)dealloc;
- (void)onWidgitDeleted;
- (id)exportAnimatedLayer;
- (void)setScreenCenter:(struct CGPoint)arg1;
- (_Bool)needHighQuality;
- (void)subclassReloadFrame;
- (void)subclassLargeTouchFrame;
- (double)widgetViewBorder;
- (double)widgetHeight;
- (double)widgetWidth;
- (_Bool)startEditingText;
- (double)maxFrameScaleWhileSelect;
- (double)maxScaleFactor;
- (double)originalScaleFactor;
- (void)judgeFromDeleteBar:(id)arg1;
- (void)reloadFrameWithZoomScale:(double)arg1;
- (void)reloadFrame;
- (void)largeTouchFrame;
- (void)hideBorderView;
- (void)showBorderView;
- (void)sendShowNilTextToolBorderViewToDelegate;
- (void)sendShowSelectedTextToolBorderViewToDelegate;
- (void)sendEndGestureToDelegate;
- (void)sendStartGestureToDelegate;
- (void)saveAttr;
- (void)endGesture;
- (void)startGesture;
- (void)forceCancelGesture;
- (void)handleRotateGesture:(id)arg1;
- (void)handlePanGesture:(id)arg1;
- (void)handlePinchGesture:(id)arg1;
- (void)handleTapGesture:(id)arg1;
- (void)initBorderView;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

