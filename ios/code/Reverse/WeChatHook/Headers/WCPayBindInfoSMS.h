//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface WCPayBindInfoSMS : NSObject
{
    unsigned int m_flag;
    NSString *m_payPassword;
    NSString *m_SMSMsg;
    NSString *m_retKey;
    _Bool m_canPassPwd;
    NSString *m_usertoken;
    _Bool _m_canPassPwd;
    NSString *_bank_type;
    NSString *_autoDeductBankType;
    NSString *_autoDeductBankSerial;
    NSString *_m_usertoken;
}

@property(retain, nonatomic) NSString *m_usertoken; // @synthesize m_usertoken=_m_usertoken;
@property(nonatomic) _Bool m_canPassPwd; // @synthesize m_canPassPwd=_m_canPassPwd;
@property(copy, nonatomic) NSString *autoDeductBankSerial; // @synthesize autoDeductBankSerial=_autoDeductBankSerial;
@property(copy, nonatomic) NSString *autoDeductBankType; // @synthesize autoDeductBankType=_autoDeductBankType;
@property(retain, nonatomic) NSString *bank_type; // @synthesize bank_type=_bank_type;
@property(retain, nonatomic) NSString *m_SMSMsg; // @synthesize m_SMSMsg;
@property(retain, nonatomic) NSString *m_retKey; // @synthesize m_retKey;
@property(retain, nonatomic) NSString *m_payPassword; // @synthesize m_payPassword;
@property(nonatomic) unsigned int m_flag; // @synthesize m_flag;
- (void).cxx_destruct;
- (void)dealloc;

@end

