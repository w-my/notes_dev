//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@protocol IClearDataMgrExt <NSObject>

@optional
- (void)onCleanCacheDone;
- (void)onInnerDeleteData;
- (void)onCleanedOver3MonthFileSize:(unsigned long long)arg1;
- (void)onReloadDataItem;
- (void)onLoadDataFinished;
@end
