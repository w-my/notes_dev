//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommonListDataAdapter.h"

@class QNListNewsItem;

@interface QNHotSpot24HoursListDataAdapter : QNCommonListDataAdapter
{
    _Bool _isUsedInChannel;
    QNListNewsItem *_listItem;
}

@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(nonatomic) _Bool isUsedInChannel; // @synthesize isUsedInChannel=_isUsedInChannel;
- (void).cxx_destruct;
- (void)listModeldidReplaceAllItems:(id)arg1 animated:(_Bool)arg2;
- (void)_playVideoWithItem:(id)arg1 isContinuous:(_Bool)arg2 indexPath:(id)arg3;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)configTableViewCellLayoutContext:(id)arg1 forData:(id)arg2 indexPath:(id)arg3;
- (void)configureCellFactory;

@end
