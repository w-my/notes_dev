//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class WCStoryBubbleOrCommentAnimationView;

@protocol WCStoryBubbleOrCommentAnimationViewDelegate <NSObject>

@optional
- (void)onBubbleOrCommentShowAnimationDidClick:(WCStoryBubbleOrCommentAnimationView *)arg1 atIndex:(long long)arg2;
- (void)onBubbleOrCommentAnimationStartToPlayLastOneFirstTime:(WCStoryBubbleOrCommentAnimationView *)arg1;
- (void)onBubbleOrCommentAnimationViewHasPlayFirstReadedItem:(WCStoryBubbleOrCommentAnimationView *)arg1;
- (void)onBubbleOrCommentAnimationHasPlayOneTime:(WCStoryBubbleOrCommentAnimationView *)arg1;
@end

