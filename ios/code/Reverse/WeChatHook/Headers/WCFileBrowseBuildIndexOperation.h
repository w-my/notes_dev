//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSOperation.h"

@class WCFileBrowseInfoDB;

@interface WCFileBrowseBuildIndexOperation : NSOperation
{
    WCFileBrowseInfoDB *_browseInfoDB;
    CDUnknownBlockType _buildIndexCompletion;
}

@property(copy) CDUnknownBlockType buildIndexCompletion; // @synthesize buildIndexCompletion=_buildIndexCompletion;
@property(retain, nonatomic) WCFileBrowseInfoDB *browseInfoDB; // @synthesize browseInfoDB=_browseInfoDB;
- (void).cxx_destruct;
- (void)p_buildFileBrowseWithDataInfo:(id)arg1 withType:(unsigned long long)arg2;
- (id)p_getTaskInfo;
- (void)buildAllFileIntoFileBrowse;
- (void)start;
- (id)initWithCompletion:(CDUnknownBlockType)arg1;

@end
