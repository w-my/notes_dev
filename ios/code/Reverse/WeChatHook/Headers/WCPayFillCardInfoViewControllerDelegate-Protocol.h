//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class WCPayControlData, WCPayRealnameAuthenReq;

@protocol WCPayFillCardInfoViewControllerDelegate <NSObject>
- (WCPayRealnameAuthenReq *)FillCardInfoRealnameReq;
- (void)FillCardInfoReadAgreement;
- (void)FillCardInfoNext:(WCPayControlData *)arg1;
- (void)FillCardInfoCancel;
- (_Bool)NeedShowServiceAppInfo;
@end
