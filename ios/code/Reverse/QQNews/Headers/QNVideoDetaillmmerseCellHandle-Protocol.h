//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNVideoTagItem, UITableViewCell;

@protocol QNVideoDetaillmmerseCellHandle <NSObject>
- (_Bool)isJumpedToCommentViewControllerWithCell:(UITableViewCell *)arg1;
- (void)didShowTLAddedCommentViewWithCell:(UITableViewCell *)arg1;
- (void)didShowTLCommentViewWithCell:(UITableViewCell *)arg1;
- (void)didSwitchShowWithCell:(UITableViewCell *)arg1;
- (void)didClickVideoCommentWithCell:(UITableViewCell *)arg1;
- (void)didClickAttentionBtnWithCell:(UITableViewCell *)arg1;
- (void)didClickPersonButtonWithCell:(UITableViewCell *)arg1 btnType:(unsigned long long)arg2 didClickTag:(QNVideoTagItem *)arg3;
- (void)didClickLikeButtonWithCell:(UITableViewCell *)arg1;
- (void)didClickSharedButtonWithCell:(UITableViewCell *)arg1;
- (void)didClickCommentButtonWithCell:(UITableViewCell *)arg1;
@end
