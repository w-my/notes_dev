//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNNowLiveViewController;

@interface QNNowLiveManager : NSObject
{
    QNNowLiveViewController *_ctl;
}

+ (void)setNowLiveLoginData;
+ (void)registerAppInfo;
@property(nonatomic) __weak QNNowLiveViewController *ctl; // @synthesize ctl=_ctl;
- (void).cxx_destruct;
- (void)openNowLiveRoomWithRoomId:(id)arg1 listItem:(id)arg2 fromController:(id)arg3 from:(id)arg4;

@end
