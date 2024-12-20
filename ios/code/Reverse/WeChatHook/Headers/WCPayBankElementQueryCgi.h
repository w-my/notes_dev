//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCPayGetBankResourceCgiDelegate.h"
#import "WCPayLogicMgrExt.h"

@class NSArray, NSError, NSString, WCPayCardBinInfo, WCPayGetBankResourceCgi, WCPayGetUserExInfoCgiResponse;

@interface WCPayBankElementQueryCgi : NSObject <WCPayGetBankResourceCgiDelegate, WCPayLogicMgrExt>
{
    id <WCPayBankElementQueryCgiDelegate> m_delegate;
    _Bool _fromRealname;
    WCPayGetBankResourceCgi *_m_getBankResourceCgi;
    WCPayCardBinInfo *_m_selecteCardBinInfo;
    NSArray *_m_availableBankArray;
    WCPayGetUserExInfoCgiResponse *_m_userInfoResponse;
    NSError *_m_error;
}

@property(retain, nonatomic) NSError *m_error; // @synthesize m_error=_m_error;
@property(retain, nonatomic) WCPayGetUserExInfoCgiResponse *m_userInfoResponse; // @synthesize m_userInfoResponse=_m_userInfoResponse;
@property(retain, nonatomic) NSArray *m_availableBankArray; // @synthesize m_availableBankArray=_m_availableBankArray;
@property(retain, nonatomic) WCPayCardBinInfo *m_selecteCardBinInfo; // @synthesize m_selecteCardBinInfo=_m_selecteCardBinInfo;
@property(retain, nonatomic) WCPayGetBankResourceCgi *m_getBankResourceCgi; // @synthesize m_getBankResourceCgi=_m_getBankResourceCgi;
@property _Bool fromRealname; // @synthesize fromRealname=_fromRealname;
- (void).cxx_destruct;
- (void)OnGetBankResourceResponseError:(id)arg1 errorCode:(unsigned int)arg2;
- (void)OnGetBankResourceResponseOK:(id)arg1;
- (void)clearResponse;
- (void)GetCardBinAndAvailableBank:(id)arg1 scene:(int)arg2;
- (void)OnGetBindingCardBin:(id)arg1 AvailableBank:(id)arg2 userExInfoResponse:(id)arg3 Error:(id)arg4;
- (void)dealloc;
- (id)initWitDelegate:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

