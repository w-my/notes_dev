//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "WCActionSheetDelegate.h"

@class BrandProfileReporter, CContact, MMTableViewInfo, NSString;

@interface BrandProfileSettingViewController : MMUIViewController <WCActionSheetDelegate>
{
    _Bool _isNewMessageNotifySwitchOn;
    _Bool _isReceiveMessageSwitchOn;
    _Bool _isProvideLocationSwitchOn;
    BrandProfileReporter *_reporter;
    MMTableViewInfo *_tableViewInfo;
    double _tableViewWidth;
    unsigned int _scene;
    unsigned int _profileEnterTimeStamps;
    id <BrandProfileSettingViewControllerDelegate> _delegate;
    CContact *_brandContact;
}

@property(nonatomic) unsigned int profileEnterTimeStamps; // @synthesize profileEnterTimeStamps=_profileEnterTimeStamps;
@property(nonatomic) unsigned int scene; // @synthesize scene=_scene;
@property(retain, nonatomic) CContact *brandContact; // @synthesize brandContact=_brandContact;
@property(nonatomic) __weak id <BrandProfileSettingViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)reportClearMessage;
- (void)clickClearMessageCell;
- (void)openWebView:(id)arg1;
- (void)clickComplaintCell;
- (void)onProvideLocationCancel;
- (void)onProvideLocationConfirm;
- (void)switchProvideLocationCell:(id)arg1;
- (void)switchReceiveMessageCell:(id)arg1;
- (void)switchNewMessageNotificationCell:(id)arg1;
- (void)reloadTableViewInfo;
- (void)viewDidLayoutSubviews;
- (void)initTableViewInfo;
- (void)viewWillBePoped:(_Bool)arg1;
- (id)init;
- (void)addLocalSystemMessageWhenReceiveMessageSwitchChanged;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
