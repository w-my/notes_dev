//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CAEAGLLayer, DisplayLinkProxy, EAGLContext, NSDictionary, NSMutableDictionary, NSString, UIImageView;

@interface WASkiaCanvasView : UIView
{
    CAEAGLLayer *_eaglLayer;
    struct BindingApp *_app;
    unsigned int _framebuffer;
    unsigned int _renderbuffer;
    float _contentScale;
    DisplayLinkProxy *_proxy;
    long long _touchId;
    NSMutableDictionary *_touches;
    NSDictionary *_longpressParam;
    _Bool _touched;
    struct CGSize _size;
    UIImageView *_snapshotImageView;
    unsigned int _canvasId;
    int _gestureMode;
    struct HTMLCanvasView *_canvasView;
    id <WASkiaViewDelegate> _delegate;
    NSString *_userData;
    EAGLContext *_context;
}

+ (Class)layerClass;
@property(retain, nonatomic) EAGLContext *context; // @synthesize context=_context;
@property(nonatomic) int gestureMode; // @synthesize gestureMode=_gestureMode;
@property(nonatomic) unsigned int canvasId; // @synthesize canvasId=_canvasId;
@property(retain, nonatomic) NSString *userData; // @synthesize userData=_userData;
@property(nonatomic) __weak id <WASkiaViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) struct HTMLCanvasView *canvasView; // @synthesize canvasView=_canvasView;
- (void).cxx_destruct;
- (void)setFileDelegate:(id)arg1;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)onLongPress:(id)arg1;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (long long)getTouchID:(id)arg1 remove:(_Bool)arg2;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)snapshotEnd;
- (void)snapshotBegin;
- (id)getImage;
- (void)setBindingApp:(struct BindingApp *)arg1 canvasId:(unsigned int)arg2;
- (void)present;
- (void)makeCurrentContext;
- (struct CGSize)getFrameBufferSize;
- (unsigned int)getFrameBufferId;
- (void)layoutSubviews;
- (void)initSkia:(unsigned int)arg1 size:(struct CGSize)arg2;
- (void)drawFrame:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 contentScale:(float)arg2;

@end
