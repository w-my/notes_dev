//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MQQSharkGuidCertifier, NSError;

@protocol MQQSharkGuidCertifierDelegate <NSObject>
- (void)guidCertifierDidFailInRSAVerification:(MQQSharkGuidCertifier *)arg1;
- (void)guidCertifier:(MQQSharkGuidCertifier *)arg1 didRegistWithError:(NSError *)arg2;
@end
