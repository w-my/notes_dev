//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIControl.h"

@class NSDictionary, NSString;

@interface UIControl (QNFeedback)
- (void)qn_doFeedback;
- (void)qn_setFeedbackExtraParams:(CDUnknownBlockType)arg1;
@property(readonly, nonatomic) NSDictionary *qn_extraParams;
- (void)qn_setFeedbackID:(CDUnknownBlockType)arg1;
@property(readonly, copy, nonatomic) NSString *qn_feedbackID;
@property(copy, nonatomic) NSString *qn_feedbackModule;
@end

