//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMKView.h"

@class MMBoolCallback, MMI64Callback, MMKPoint, MMKSizeCallback, MMKViewLayoutCallback, MMStringCallback, MMVoidCallback, MMVoidKViewLayoutCallback, NSString;

@protocol MMKCollectionView <MMKView>
- (_Bool)getPagingEnabled;
- (void)setPagingEnabled:(_Bool)arg1;
- (_Bool)getAlwaysBounceHorizontal;
- (void)setAlwaysBounceHorizontal:(_Bool)arg1;
- (_Bool)getAlwaysBounceVertical;
- (void)setAlwaysBounceVertical:(_Bool)arg1;
- (_Bool)getBounces;
- (void)setBounces:(_Bool)arg1;
- (_Bool)getShowsVerticalIndicator;
- (void)setShowsVerticalIndicator:(_Bool)arg1;
- (_Bool)getShowsHorizontalIndicator;
- (void)setShowsHorizontalIndicator:(_Bool)arg1;
- (_Bool)getScrollToTop;
- (void)setScrollToTop:(_Bool)arg1;
- (_Bool)getScrollEnabled;
- (void)setScrollEnabled:(_Bool)arg1;
- (void)footerRefreshImpl:(MMVoidKViewLayoutCallback *)arg1;
- (void)headerRefreshImpl:(MMVoidKViewLayoutCallback *)arg1;
- (void)cellRefreshImpl:(MMVoidKViewLayoutCallback *)arg1;
- (void)registerFooterType:(NSString *)arg1;
- (void)registerHeaderType:(NSString *)arg1;
- (void)registerItemType:(NSString *)arg1;
- (void)footerForSectionImpl:(MMKViewLayoutCallback *)arg1;
- (void)headerForSectionImpl:(MMKViewLayoutCallback *)arg1;
- (void)itemForPositionImpl:(MMKViewLayoutCallback *)arg1;
- (void)numberOfRowsAtSectionImpl:(MMI64Callback *)arg1;
- (void)numberOfSectionsImpl:(MMI64Callback *)arg1;
- (void)didUnHighlightItemImpl:(MMVoidCallback *)arg1;
- (void)didHighlightItemImpl:(MMVoidCallback *)arg1;
- (void)shouldHighlightItemImpl:(MMBoolCallback *)arg1;
- (void)didSelectedItemImpl:(MMVoidCallback *)arg1;
- (void)typeForFooterImpl:(MMStringCallback *)arg1;
- (void)typeForHeaderImpl:(MMStringCallback *)arg1;
- (void)typeForItemImpl:(MMStringCallback *)arg1;
- (void)sizeForFooterImpl:(MMKSizeCallback *)arg1;
- (void)sizeForHeaderImpl:(MMKSizeCallback *)arg1;
- (void)sizeForItemImpl:(MMKSizeCallback *)arg1;
- (void)reloadItemAtSection:(long long)arg1 row:(long long)arg2;
- (void)reloadSection:(long long)arg1;
- (void)reloadData;
- (NSString *)footerType;
- (NSString *)headerType;
- (NSString *)itemType;
- (long long)row;
- (long long)section;
- (MMKPoint *)getContentOffset;
- (void)setContentOffset:(MMKPoint *)arg1 animated:(_Bool)arg2;
@end

