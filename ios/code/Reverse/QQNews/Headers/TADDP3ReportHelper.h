//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TADDP3ReportHelper : NSObject
{
}

+ (id)p_compressedStringArray:(id)arg1;
+ (void)logLandingDurationItem:(id)arg1 toDict:(id)arg2;
+ (id)generateDictionaryForDP3Item:(id)arg1;
+ (id)generateDictionaryForChannelPVForDict:(id)arg1;
+ (id)generateReportRecForDict:(id)arg1;
+ (void)sendItems:(id)arg1 withChannelPVDict:(id)arg2 netStatusArray:(id)arg3 landingViewDict:(id)arg4 toUrlStr:(id)arg5 reportRec:(id)arg6;

@end

