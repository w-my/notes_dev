//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NWVideoRender.h"

@class NWAVReceiverOpen, UIView;

@interface NWVideoRenderOpen : NWVideoRender
{
    UIView *_renderView;
    NWAVReceiverOpen *_receiver;
}

@property(nonatomic) __weak NWAVReceiverOpen *receiver; // @synthesize receiver=_receiver;
@property(retain, nonatomic) UIView *renderView; // @synthesize renderView=_renderView;
- (void).cxx_destruct;
- (_Bool)GetRenderData:(struct _NWVideoRenderData *)arg1;
- (void)Destroy;
- (void)Resume;
- (void)Pause;
- (void)Draw:(struct _NWVideoRenderData *)arg1;
- (_Bool)Create:(struct _NWVideoRenderParameter *)arg1;

@end
