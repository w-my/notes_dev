//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCBaseInfoItem.h"

#import "TenpaySecureCtrlDelegate.h"
#import "WCPayLogicMgrExt.h"

@class NSString, TenpaySecureCtrl;

@interface WCPayTenpaySecureCtrlItem : WCBaseInfoItem <TenpaySecureCtrlDelegate, WCPayLogicMgrExt>
{
    TenpaySecureCtrl *m_textField;
    int m_eEncryptType;
    _Bool m_bTextFieldHasBecomeFirstResponder;
    NSString *m_nsUserCredType;
}

@property(retain, nonatomic) TenpaySecureCtrl *m_textField; // @synthesize m_textField;
@property(retain, nonatomic) NSString *m_nsUserCredType; // @synthesize m_nsUserCredType;
- (void).cxx_destruct;
- (void)onKeyboardDidHide;
- (void)resignFirstResponderWithCompletion:(CDUnknownBlockType)arg1;
- (void)setDefaultValue:(id)arg1;
- (void)autoRemarkKeyBoradType;
- (void)appendString:(id)arg1;
- (void)setMaxInputLen:(int)arg1;
- (_Bool)onError:(id)arg1;
- (void)tenpayCtrlShouldChange:(id)arg1;
- (void)tenpayCtrlShouldReturn:(id)arg1;
- (void)textFieldDidEndEditing:(id)arg1;
- (void)textFieldDidEndOnExit:(id)arg1;
- (void)textFieldDidBeginEditing:(id)arg1;
- (void)setFont:(id)arg1;
- (void)setSecureTextEntry:(_Bool)arg1;
- (void)setEncryptType:(int)arg1;
- (void)setClearButtonMode:(long long)arg1;
- (void)setReturnKeyType:(long long)arg1;
- (void)setKeyboardType:(long long)arg1;
- (void)dealloc;
- (id)initWithTitle:(id)arg1 tip:(id)arg2 key:(id)arg3;
- (void)onEndEditor;
- (void)_becomeFristResponderOnce;
- (void)becomeFirstResponderOnce;
- (void)resignFirstResponder;
- (void)becomeFirstResponder;
- (void)initView:(struct CGRect)arg1;
- (void)setEnable:(_Bool)arg1;
- (id)getValue;
- (id)getValueWithEncryptType:(int)arg1;
- (void)setKeyboardUseID:(_Bool)arg1;
- (void)setFormatBankCard;
- (_Bool)isUserIDNum:(unsigned int)arg1;
- (_Bool)isBankCardNum;
- (_Bool)isPhoneNum;
- (long long)getTextLength;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

