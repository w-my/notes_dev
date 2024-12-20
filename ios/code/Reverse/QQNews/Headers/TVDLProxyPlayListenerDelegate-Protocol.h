//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, TVDLProxyPlayData;

@protocol TVDLProxyPlayListenerDelegate <NSObject>

@optional
- (int)OnPlayerAdRemainTimeUpdated:(int)arg1;
- (int)OnPlayerCurrentPlayPosition:(int)arg1;
- (int)OnPlayerPlayableBufferUpdated:(int)arg1;
- (void)OnPlayEnterBackgroundWillTerminate:(int)arg1;
- (void)OnPlayEnterForeground:(int)arg1;
- (void)OnPlayError:(int)arg1 withPlayError:(NSString *)arg2;
- (void)OnPlayInfoError:(int)arg1 withPlayInfoError:(NSString *)arg2;
- (void)OnPlayInfoSuccess:(int)arg1 withPlayInfo:(TVDLProxyPlayData *)arg2;
@end

