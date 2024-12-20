//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NLWebViewController.h"

#import "NLWebVCProtocol.h"

@class NSString;

@interface NLRoomWebViewController : NLWebViewController <NLWebVCProtocol>
{
    id <NLWebVCDelegate> _delegate;
}

@property(nonatomic) __weak id <NLWebVCDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)onJSCall:(id)arg1 sel:(SEL)arg2 info:(id)arg3;
- (void)setStatusBarStyle:(long long)arg1;
- (void)setWebScrollEnabled:(_Bool)arg1;
- (void)setBackgroundTransparent;
- (void)setFullScreenMode:(_Bool)arg1;
- (void)exeJsScript:(id)arg1;
- (void)setTitle:(id)arg1;
- (void)setUrl:(id)arg1;
- (id)getViewController;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

