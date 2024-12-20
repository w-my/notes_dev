//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

@class NSTimer, TVKTimeCountView;

@interface TVKSpotViewController : UIViewController
{
    NSTimer *_countTimer;
    CDUnknownBlockType _callback;
    TVKTimeCountView *_timeCountDownView;
}

@property(retain, nonatomic) TVKTimeCountView *timeCountDownView; // @synthesize timeCountDownView=_timeCountDownView;
- (void).cxx_destruct;
- (void)updateTime:(id)arg1;
- (void)timerInvalidate;
- (void)timerStart;
- (void)startTimerWithCompletion:(CDUnknownBlockType)arg1;
- (void)applicationDidBecomeActive;
- (void)applicationWillResignActive;
- (_Bool)interfaceIsFullScreen;
- (void)didReceiveMemoryWarning;
- (void)viewWillLayoutSubviews;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)dealloc;

@end

