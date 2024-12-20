//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "TVKIPlayerViewBase.h"

@class NSString, TVKSelfPlayerViewImpl;

@interface TVKSelfPlayerView : UIView <TVKIPlayerViewBase>
{
    int _videoWidth;
    int _videoHeight;
    int _dstVideoWidth;
    int _dstVideoHeight;
    long long _pixfmt;
    long long _pictype;
    TVKSelfPlayerViewImpl *_playerViewImpl;
    _Bool _isVRSupport;
    _Bool _isDuringCreating;
    long long _videoGravity;
    long long _VRMode;
    long long _VRInteractiveType;
}

@property _Bool isDuringCreating; // @synthesize isDuringCreating=_isDuringCreating;
@property(nonatomic, setter=setVRInteractiveType:) long long VRInteractiveType; // @synthesize VRInteractiveType=_VRInteractiveType;
@property(nonatomic, setter=setVRMode:) long long VRMode; // @synthesize VRMode=_VRMode;
@property(readonly, nonatomic) _Bool isVRSupport; // @synthesize isVRSupport=_isVRSupport;
@property(nonatomic) long long videoGravity; // @synthesize videoGravity=_videoGravity;
- (void).cxx_destruct;
- (void)dealloc;
- (void)removeAllSubviews;
- (void)removePlayerViewImplInternal;
- (void)createPlayerViewImplInternal:(id)arg1;
- (void)doRotateWithAngleX:(float)arg1 angleY:(float)arg2 angleZ:(float)arg3;
- (void)flush;
- (id)snapshot;
- (int)drawPicture:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

