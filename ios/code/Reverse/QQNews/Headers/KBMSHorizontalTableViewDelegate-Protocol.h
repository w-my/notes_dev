//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIScrollViewDelegate.h"

@class KBMSCellView, KBMinShengHorizontalTableView;

@protocol KBMSHorizontalTableViewDelegate <UIScrollViewDelegate>
- (KBMSCellView *)tableView:(KBMinShengHorizontalTableView *)arg1 cellForRowAtIndex:(unsigned long long)arg2;
- (double)tableView:(KBMinShengHorizontalTableView *)arg1 widthForRowAtIndex:(unsigned long long)arg2;
- (unsigned long long)numberOfRowsInTableView:(KBMinShengHorizontalTableView *)arg1;

@optional
- (void)tableView:(KBMinShengHorizontalTableView *)arg1 willRemoveCell:(KBMSCellView *)arg2;
@end
