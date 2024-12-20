//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVExportVideoBaseTask.h"

@class MVEffectCompositor, MVWatermarkItem, NSString;

@interface MVComposeVideoTask : MVExportVideoBaseTask
{
    NSString *_outputFile;
    MVWatermarkItem *_watermark;
    MVEffectCompositor *_compositor;
    double _composingStartTime;
}

@property(nonatomic) double composingStartTime; // @synthesize composingStartTime=_composingStartTime;
@property(retain, nonatomic) MVEffectCompositor *compositor; // @synthesize compositor=_compositor;
@property(retain, nonatomic) MVWatermarkItem *watermark; // @synthesize watermark=_watermark;
@property(retain, nonatomic) NSString *outputFile; // @synthesize outputFile=_outputFile;
- (void).cxx_destruct;
- (void)reportVideoCompositionTimeWithError:(id)arg1;
- (void)compositorDidCompleteWithFile:(id)arg1 error:(id)arg2;
- (id)makeCompositor;
- (void)prepare;
- (void)cancel;
- (void)resume;
- (void)pause;
- (void)run;

@end

