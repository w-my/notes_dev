//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, TopStoryPluginPostCommentRequest, TopStoryPluginPostCommentResponse, TopStoryPluginSetCommentResponse;

@protocol ITopStoryPluginMsgExt <NSObject>

@optional
- (void)onRequestSetCommontEnd:(TopStoryPluginSetCommentResponse *)arg1 requestOpType:(unsigned int)arg2;
- (void)onRequestPostCommentEnd:(TopStoryPluginPostCommentResponse *)arg1 oriRequest:(TopStoryPluginPostCommentRequest *)arg2 docId:(NSString *)arg3;
@end

