//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayControlLogic.h"

#import "IWCPayControlLogicExt.h"
#import "WCPaySelectVerifyTypeViewControllerDelegate.h"

@class MMVoidCallback, NSString;

@interface WCPaySelectVerifyTypeLogic : WCPayControlLogic <WCPaySelectVerifyTypeViewControllerDelegate, IWCPayControlLogicExt>
{
    _Bool _hasStartAddCard;
    int _scene;
    MMVoidCallback *_successCallback;
    MMVoidCallback *_cancelCallback;
}

@property _Bool hasStartAddCard; // @synthesize hasStartAddCard=_hasStartAddCard;
@property(retain, nonatomic) MMVoidCallback *cancelCallback; // @synthesize cancelCallback=_cancelCallback;
@property(retain, nonatomic) MMVoidCallback *successCallback; // @synthesize successCallback=_successCallback;
@property(nonatomic) int scene; // @synthesize scene=_scene;
- (void).cxx_destruct;
- (void)OnRealnameVerfitySuccessNotification:(id)arg1;
- (void)OnFinishedWCPayLogic:(id)arg1 CompleteStatus:(int)arg2;
- (void)DirectBindCard;
- (void)OnBack;
- (void)OnSelectBindCardVerify;
- (void)OnSelectRealnameVerify:(id)arg1;
- (void)OnSelectBindCard;
- (void)startLogic;
- (void)dealloc;
- (id)initWithData:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
