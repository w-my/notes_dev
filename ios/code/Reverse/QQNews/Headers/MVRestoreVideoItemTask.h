//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVExportVideoBaseTask.h"

@class MVVideoItem;

@interface MVRestoreVideoItemTask : MVExportVideoBaseTask
{
    _Bool _usingOriginalVideo;
    MVVideoItem *_videoItem;
}

+ (id)taskWithVideoItem:(id)arg1;
@property(nonatomic) _Bool usingOriginalVideo; // @synthesize usingOriginalVideo=_usingOriginalVideo;
@property(retain, nonatomic) MVVideoItem *videoItem; // @synthesize videoItem=_videoItem;
- (void).cxx_destruct;
- (void)restoreVideo;
- (void)prepare;
- (void)run;

@end
