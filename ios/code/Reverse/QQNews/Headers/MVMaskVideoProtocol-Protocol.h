//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@protocol MVMaskVideoProtocol <NSObject>
- (void)prepareForReadingWithCompletion:(void (^)(void))arg1;
- (void)resumeReadingMask;
- (void)pauseReadingMask;
- (void)endReadingMask;
- (void)beginReadingMask;
- (void)resetMask;
@end
