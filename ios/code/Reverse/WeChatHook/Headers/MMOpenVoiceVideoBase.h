//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@interface MMOpenVoiceVideoBase : UIView
{
    unsigned int _videoId;
    int _memberId;
}

@property(nonatomic) int memberId; // @synthesize memberId=_memberId;
@property(nonatomic) unsigned int videoId; // @synthesize videoId=_videoId;
- (int)getMemberId;
- (_Bool)isCamera;
- (void)updateMemberId:(int)arg1;
- (void)uintView;
- (void)render:(char *)arg1 dataLen:(int)arg2 width:(int)arg3 height:(int)arg4;
- (int)updateView:(int)arg1 dic:(id)arg2;
- (int)initView:(int)arg1 dic:(id)arg2 queue:(id)arg3;
- (id)init;

@end

