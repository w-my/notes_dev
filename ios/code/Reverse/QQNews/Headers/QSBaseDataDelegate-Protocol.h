//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, QSBaseData;

@protocol QSBaseDataDelegate <NSObject>
- (void)data:(QSBaseData *)arg1 didFinishLoadWithError:(NSError *)arg2;
- (void)dataWillStartLoad:(QSBaseData *)arg1;
@end

