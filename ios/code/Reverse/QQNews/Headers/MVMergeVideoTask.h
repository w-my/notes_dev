//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVExportVideoBaseTask.h"

@class MVAVAssetExportSession, NSString;

@interface MVMergeVideoTask : MVExportVideoBaseTask
{
    NSString *_outputFile;
    MVAVAssetExportSession *_exportSession;
}

+ (id)defaultVideoSettingsForMedia:(id)arg1;
@property(retain, nonatomic) MVAVAssetExportSession *exportSession; // @synthesize exportSession=_exportSession;
@property(retain, nonatomic) NSString *outputFile; // @synthesize outputFile=_outputFile;
- (void).cxx_destruct;
- (void)exportVideoWithOutputFile:(id)arg1;
- (void)prepare;
- (void)run;

@end
