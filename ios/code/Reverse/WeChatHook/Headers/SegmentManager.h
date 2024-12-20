//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, RPNSegmenter;

@interface SegmentManager : NSObject
{
    _Bool modelDidLoad;
    int modelSetupCount;
    NSString *_bundlePath;
    RPNSegmenter *_segmenter;
}

+ (void)setCNNMinLength:(int)arg1;
+ (int)CNNMinLength;
+ (id)sharedManager;
@property(retain, nonatomic) RPNSegmenter *segmenter; // @synthesize segmenter=_segmenter;
@property(retain, nonatomic) NSString *bundlePath; // @synthesize bundlePath=_bundlePath;
- (void).cxx_destruct;
- (void)setFrameDimension:(struct CNNDimension)arg1;
- (void)unloadSegmentModel;
- (void)loadSegmentModel:(id)arg1 proto:(id)arg2;
- (void)loadSegmentModel;
- (id)rpnSegmenter;
- (id)init;

@end

