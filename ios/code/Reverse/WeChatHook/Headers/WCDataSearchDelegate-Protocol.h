//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSIndexPath, NSString, UITableView, UITableViewCell, UIView;

@protocol WCDataSearchDelegate <NSObject>

@optional
- (_Bool)shouldHighlightRowAtIndexPath:(NSIndexPath *)arg1;
- (UIView *)viewForFooterInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (double)heightForFooterInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (NSString *)titleForFooterInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (NSString *)titleForHeaderInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (UIView *)viewForHeaderInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (double)heightForHeaderInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (long long)numberOfRowsInSection:(long long)arg1 ForSearchViewTable:(UITableView *)arg2;
- (long long)numberOfSectionsForSearchViewTable:(UITableView *)arg1;
- (UITableViewCell *)cellForIndex:(NSIndexPath *)arg1 ForSearchViewTable:(UITableView *)arg2;
- (void)didSearchViewTableSelect:(NSIndexPath *)arg1;
- (double)heightForSearchViewTable:(NSIndexPath *)arg1;
- (UITableViewCell *)cellForSearchViewTable:(UITableViewCell *)arg1 index:(NSIndexPath *)arg2;
- (void)cancelSearch;
- (void)doSearch:(NSString *)arg1 Pre:(_Bool)arg2;
@end

