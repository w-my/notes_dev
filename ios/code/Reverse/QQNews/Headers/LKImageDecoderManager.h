//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSOperationQueue;

@interface LKImageDecoderManager : NSObject
{
    _Bool _continueTryToDecodeWhenFailed;
    NSMutableArray *_decoderList;
    NSOperationQueue *_queue;
}

+ (id)defaultManager;
@property(retain, nonatomic) NSOperationQueue *queue; // @synthesize queue=_queue;
@property(retain, nonatomic) NSMutableArray *decoderList; // @synthesize decoderList=_decoderList;
@property(nonatomic) _Bool continueTryToDecodeWhenFailed; // @synthesize continueTryToDecodeWhenFailed=_continueTryToDecodeWhenFailed;
- (void).cxx_destruct;
- (void)decodeImageFromData:(id)arg1 request:(id)arg2 complete:(CDUnknownBlockType)arg3;
- (void)_decodeImageFromData:(id)arg1 request:(id)arg2 complete:(CDUnknownBlockType)arg3;
- (void)unregisterAllDecoder;
- (void)unregisterDecoder:(id)arg1;
- (void)registerDecoder:(id)arg1;
- (id)initWithDecoderList:(id)arg1;
- (id)init;

@end
