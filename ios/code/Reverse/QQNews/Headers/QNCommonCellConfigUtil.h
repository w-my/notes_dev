//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNCommonCellConfigUtil : NSObject
{
}

+ (id)moduleConfigStringWithModuleItem:(id)arg1;
+ (id)moduleChlidItemReportInfoWith:(id)arg1 channel:(id)arg2 index:(long long)arg3 listItem:(id)arg4;
+ (id)moduleItemReportInfoWith:(id)arg1 channel:(id)arg2 index:(long long)arg3 newsID:(id)arg4;
+ (id)p_getShowStrWithListItem:(id)arg1 isComment:(_Bool)arg2;
+ (id)showStrForHotSpotCellWithListItem:(id)arg1 typeArray:(id)arg2 isSpecial:(_Bool)arg3;
+ (id)showStrForMainHotSpotCellWithListItem:(id)arg1 typeArray:(id)arg2;
+ (id)showFlagStrStrWithListItem:(id)arg1 typeArray:(id)arg2;
+ (void)updateAttributeStringTagImageWithListItem:(id)arg1 attributeStr:(id)arg2 context:(id)arg3;
+ (struct CGSize)commonVideoCellImageSize;
+ (struct CGSize)commonVideoCellImageSize_old;
+ (struct CGSize)commonCellFocusImageSize;
+ (struct CGSize)commonCellFocusImageSize_old;
+ (struct CGSize)commonCellThreeImageSize;
+ (struct CGSize)commonCellThreeImageSize_old;
+ (struct CGSize)commonCellSingleImageSize;
+ (struct CGSize)commonCellSingleImageSize_old;
+ (double)commonCellSingleImageWidth;
+ (double)commonCellSingleImageWidth_old;
+ (double)commonCellMaxContentWidth;
+ (double)commonCellMaxContentWidth_old;

@end

