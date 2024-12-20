//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDate, NSString;

@interface BLYConsoleLog : NSObject
{
    _Bool _enableReport;
    NSDate *_date;
    NSString *_sender;
    NSString *_messageText;
    long long _messageID;
    NSString *_PID;
}

+ (id)logContent:(id)arg1;
+ (id)logMessageFromASLMessage:(struct __asl_object_s *)arg1;
+ (id)allLogMessagesForCurrentProcess;
+ (id)logs;
+ (id)sharedInstance;
@property(copy, nonatomic) NSString *PID; // @synthesize PID=_PID;
@property(nonatomic) long long messageID; // @synthesize messageID=_messageID;
@property(copy, nonatomic) NSString *messageText; // @synthesize messageText=_messageText;
@property(copy, nonatomic) NSString *sender; // @synthesize sender=_sender;
@property(retain, nonatomic) NSDate *date; // @synthesize date=_date;
@property(nonatomic, getter=isReportEnable) _Bool enableReport; // @synthesize enableReport=_enableReport;
- (void).cxx_destruct;
- (id)searchResultOfLog:(id)arg1;
- (id)init;

@end

