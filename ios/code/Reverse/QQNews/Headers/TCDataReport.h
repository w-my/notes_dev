//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TCDataReport : NSObject
{
}

+ (void)reportCheck:(id)arg1 ret:(int)arg2 code:(int)arg3 detail:(id)arg4;
+ (void)cgiStatisticReport:(int)arg1 reporttype:(int)arg2;
+ (void)cgiShareReport:(int)arg1 type:(int)arg2 totype:(int)arg3 acttype:(int)arg4 touin:(int)arg5 reporttype:(int)arg6 callsource:(int)arg7;
+ (void)cgiOauthReportWithOpenId:(id)arg1;
+ (void)cgiLoginReport:(int)arg1 reporttype:(int)arg2;
+ (id)commParamValue;

@end

