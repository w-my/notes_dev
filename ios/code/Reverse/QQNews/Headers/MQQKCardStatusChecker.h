//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MQQHttpRequest, NSString;

@interface MQQKCardStatusChecker : NSObject
{
    _Bool _isChecking;
    id <MQQKCardStatusCheckerDelegate> _delegate;
    long long _checkingType;
    NSString *_phoneNumber;
    MQQHttpRequest *_request;
}

@property(retain, nonatomic) MQQHttpRequest *request; // @synthesize request=_request;
@property(copy, nonatomic) NSString *phoneNumber; // @synthesize phoneNumber=_phoneNumber;
@property(nonatomic) long long checkingType; // @synthesize checkingType=_checkingType;
@property(nonatomic) _Bool isChecking; // @synthesize isChecking=_isChecking;
@property(nonatomic) id <MQQKCardStatusCheckerDelegate> delegate; // @synthesize delegate=_delegate;
- (void)httpRequestDidFail:(id)arg1;
- (void)httpRequestDidFinish:(id)arg1;
- (void)_reportWithInfo:(id)arg1;
- (void)_didFinishWithResult:(id)arg1 error:(id)arg2;
- (void)cancelChecking;
- (_Bool)checkKCardStatusWithPhoneNumber:(id)arg1 signCode:(id)arg2 signKey:(id)arg3;
- (void)dealloc;

@end
