//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSTimer, UIImage, UIView<QNGIFDisplayTarget>;

@interface QNGIFTicker : NSObject
{
    _Bool _autoPauseIfNeeded;
    id <QNGIFDataSourceProtocol> _dataSource;
    UIView<QNGIFDisplayTarget> *_displayTarget;
    unsigned long long _currentFrame;
    unsigned long long _maxLoopCount;
    unsigned long long _currentLoop;
    NSTimer *_timer;
    UIImage *_gifImage;
    UIImage *_nextFrameImage;
}

@property(retain, nonatomic) UIImage *nextFrameImage; // @synthesize nextFrameImage=_nextFrameImage;
@property(retain, nonatomic) UIImage *gifImage; // @synthesize gifImage=_gifImage;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) _Bool autoPauseIfNeeded; // @synthesize autoPauseIfNeeded=_autoPauseIfNeeded;
@property(nonatomic) unsigned long long currentLoop; // @synthesize currentLoop=_currentLoop;
@property(nonatomic) unsigned long long maxLoopCount; // @synthesize maxLoopCount=_maxLoopCount;
@property(readonly, nonatomic) unsigned long long currentFrame; // @synthesize currentFrame=_currentFrame;
@property(readonly, nonatomic) __weak UIView<QNGIFDisplayTarget> *displayTarget; // @synthesize displayTarget=_displayTarget;
@property(readonly, nonatomic) id <QNGIFDataSourceProtocol> dataSource; // @synthesize dataSource=_dataSource;
- (void).cxx_destruct;
- (void)p_delayedStopAnimating;
- (void)p_timerFired:(id)arg1;
- (void)p_advanceToNextFrame;
- (_Bool)p_shouldAdvanceToNextFrame;
- (void)resetAndStopAnimating;
- (void)stopAnimatingWithDelay;
- (void)stopAnimating;
- (void)startAnimating;
- (_Bool)isAnimating;
- (void)dealloc;
- (id)initWithGIFImage:(id)arg1 displayTarget:(id)arg2;

@end
