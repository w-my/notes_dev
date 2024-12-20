//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectCPUAction.h"

@class MVVideoEffectRepeatActionXMLItem, NSMutableArray;

@interface MVVideoEffectRepeatAction : MVVideoEffectCPUAction
{
    struct {
        long long index;
        long long times;
    } RepeatReserse;
    MVVideoEffectRepeatActionXMLItem *_repeatXMLItem;
    NSMutableArray *_frameBufferPool;
}

@property(retain, nonatomic) NSMutableArray *frameBufferPool; // @synthesize frameBufferPool=_frameBufferPool;
@property(retain, nonatomic) MVVideoEffectRepeatActionXMLItem *repeatXMLItem; // @synthesize repeatXMLItem=_repeatXMLItem;
- (void).cxx_destruct;
- (id)reversedFrameWithVideoTime:(double)arg1;
- (id)processFrameBuffer:(id)arg1 effectTime:(double)arg2;
- (_Bool)shouldProcessFrameAtTime:(double)arg1;
- (void)inputOneFrameBuffer:(id)arg1;
- (void)reset;
- (void)cleanAllBuffers;
- (id)initWithXMLItem:(id)arg1;

@end

