//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@protocol UploadStreamVoiceDataMgrDelegate <NSObject>

@optional
- (void)onVoiceTransTimeout:(unsigned int)arg1;
- (void)onEndVoiceTrans:(unsigned int)arg1;
- (void)onNetworkError:(unsigned int)arg1;
- (void)onLocalFileOperationError;
- (void)onGetText:(NSArray *)arg1;
@end

