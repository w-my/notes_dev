//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class KBListItem, UITableViewCell;

@protocol QNCommonListControllerDelegate <NSObject>

@optional
- (void)commonListContollerInsertCell:(UITableViewCell *)arg1 listItem:(KBListItem *)arg2;
- (void)commonListContollerPackupCell:(UITableViewCell *)arg1 packup:(_Bool)arg2 listItem:(KBListItem *)arg3;
- (void)commonListContollerRefreshCell:(UITableViewCell *)arg1 listItem:(KBListItem *)arg2 animation:(long long)arg3;
- (void)commonListContollerDeleteCell:(UITableViewCell *)arg1 listItem:(KBListItem *)arg2;
@end
