//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMWindowViewController.h"

#import "WCActionSheetDelegate.h"

@class MMUILabel, NSArray, NSString, UIButton;

@interface WCDBSpecifiedRecoverViewController : MMWindowViewController <WCActionSheetDelegate>
{
    NSArray *_infos;
    MMUILabel *m_tipLabel;
    MMUILabel *m_commentLabel;
    UIButton *m_button;
    UIButton *m_clear;
    double _progress;
    _Bool _isManuallyRestore;
}

@property(nonatomic) _Bool isManuallyRestore; // @synthesize isManuallyRestore=_isManuallyRestore;
- (void).cxx_destruct;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)updateProgressWithIncrementFromSingleRecover:(double)arg1;
- (void)askForConfirmClear;
- (void)clear;
- (void)recover;
- (void)didRecover:(_Bool)arg1;
- (_Bool)doRecover;
- (void)onConfirm;
- (void)viewDidLoad;
- (void)onDoubleTapThreeTimes;
- (id)initWithInfos:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
