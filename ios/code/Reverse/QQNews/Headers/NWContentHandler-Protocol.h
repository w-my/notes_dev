//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData;

@protocol NWContentHandler <NSObject>

@optional
- (void)onCompleted:(int)arg1;
- (int)onReceiveData:(NSData *)arg1;
- (_Bool)onPrepared:(int)arg1;
@end
