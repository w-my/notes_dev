//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class KBListItem, NSIndexPath, QNTopicSubListViewModel;

@protocol QNTopicSubListViewModelDelegate <NSObject>
- (void)qn_topicViewModel:(QNTopicSubListViewModel *)arg1 replaceItem:(KBListItem *)arg2 atIndexPath:(NSIndexPath *)arg3;
@end

