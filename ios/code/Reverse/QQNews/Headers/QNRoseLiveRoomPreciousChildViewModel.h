//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomChildViewModel.h"

@class NSMutableArray;

@interface QNRoseLiveRoomPreciousChildViewModel : QNRoseLiveRoomChildViewModel
{
    NSMutableArray *_messages;
}

@property(retain, nonatomic) NSMutableArray *messages; // @synthesize messages=_messages;
- (void).cxx_destruct;
- (id)allPresentationData;
- (id)messageAtIndex:(long long)arg1 inSection:(long long)arg2;
- (long long)numberOfMessagesInSection:(long long)arg1;
- (_Bool)checkDataValid;
- (id)init;

@end
