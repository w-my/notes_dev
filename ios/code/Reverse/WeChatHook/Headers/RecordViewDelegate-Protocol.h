//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AudioRecorderUserData, MMUIViewController, NSString;

@protocol RecordViewDelegate <NSObject>
- (MMUIViewController *)GetCurrentViewController;
- (double)getRecordButtonResponseY;
- (void)toRecordStautsIdle;
- (void)cancelSendMsg;
- (void)sendMsgWithText:(NSString *)arg1;
- (AudioRecorderUserData *)cancelRecordingAndTransVoiceWithLanguage:(unsigned int)arg1;
- (void)cancelRecording;
- (void)stopRecording;
@end
