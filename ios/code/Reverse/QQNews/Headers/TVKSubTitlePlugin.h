//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TVKMediaPlayerPlugin.h"

#import "TVKMediaPlayerInfoEventProtocol.h"
#import "TVKSubTitleParserDelegate.h"

@class NSObject<OS_dispatch_source>, NSString, NSThread, TVKSubTitleController, TVKSubTitleParser;

@interface TVKSubTitlePlugin : TVKMediaPlayerPlugin <TVKMediaPlayerInfoEventProtocol, TVKSubTitleParserDelegate>
{
    _Bool _subTitleLoaded;
    _Bool _subTitleLoading;
    NSThread *_subThread;
    NSObject<OS_dispatch_source> *_dispatchTimer;
    TVKSubTitleController *_controller;
    TVKSubTitleParser *_parser;
}

@property _Bool subTitleLoading; // @synthesize subTitleLoading=_subTitleLoading;
@property _Bool subTitleLoaded; // @synthesize subTitleLoaded=_subTitleLoaded;
@property(retain, nonatomic) TVKSubTitleParser *parser; // @synthesize parser=_parser;
@property(retain, nonatomic) TVKSubTitleController *controller; // @synthesize controller=_controller;
@property(retain) NSObject<OS_dispatch_source> *dispatchTimer; // @synthesize dispatchTimer=_dispatchTimer;
@property(retain, nonatomic) NSThread *subThread; // @synthesize subThread=_subThread;
- (void).cxx_destruct;
- (void)onOpenFailWithUrl:(id)arg1;
- (void)onOpenSuccWithUrl:(id)arg1;
- (void)updateSubTitle:(id)arg1;
- (void)onTimer;
- (void)stopTimer;
- (void)startTimer;
- (void)threadMain;
- (void)setThreadFlag;
- (void)stopThread;
- (void)startSubThread;
- (void)stopDisplay;
- (void)startDisplay;
- (void)closeSubTitle;
- (void)openSubTitle:(id)arg1;
- (void)unloadSubTitle;
- (void)loadSubTitle;
- (void)didVideoViewSizeChanged:(struct CGSize)arg1 videoSize:(struct CGSize)arg2;
- (void)didMediaPlayerInfoChanged:(int)arg1 userInfo:(id)arg2;
- (void)onContextUpdated:(id)arg1 key:(id)arg2;
- (void)unLoad;
- (void)load;
- (id)initWithContext:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

