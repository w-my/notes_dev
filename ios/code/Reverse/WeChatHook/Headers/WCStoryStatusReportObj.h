//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface WCStoryStatusReportObj : NSObject
{
    NSString *_tid;
    unsigned long long _videoType;
    unsigned long long _previewEnterScene;
}

+ (void)reportChangeFeaturedWithTid:(id)arg1;
@property(nonatomic) unsigned long long previewEnterScene; // @synthesize previewEnterScene=_previewEnterScene;
@property(nonatomic) unsigned long long videoType; // @synthesize videoType=_videoType;
@property(copy, nonatomic) NSString *tid; // @synthesize tid=_tid;
- (void).cxx_destruct;
- (void)reportChangeFeaturedOrHiddenStatus;

@end
