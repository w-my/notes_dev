//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVExportVideoBaseTask.h"

@class MVAssetInverter, NSString;

@interface MVInvertVideoTask : MVExportVideoBaseTask
{
    NSString *_inputFile;
    NSString *_outputFile;
    MVAssetInverter *_videoInverter;
}

@property(retain, nonatomic) MVAssetInverter *videoInverter; // @synthesize videoInverter=_videoInverter;
@property(retain, nonatomic) NSString *outputFile; // @synthesize outputFile=_outputFile;
@property(retain, nonatomic) NSString *inputFile; // @synthesize inputFile=_inputFile;
- (void).cxx_destruct;
- (void)prepare;
- (void)run;

@end
