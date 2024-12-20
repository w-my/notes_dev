//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNListHelper : NSObject
{
}

+ (void)clearListItemDatabase;
+ (id)paramsForReportsForItem:(id)arg1;
+ (void)packupCell:(id)arg1 currentController:(id)arg2 withItem:(id)arg3;
+ (id)generateSpecialFlagImageForItem:(id)arg1;
+ (id)flagNameForTitleLineFlagType:(long long)arg1;
+ (_Bool)p_shouldShowFlagWithName:(id)arg1 isTextMode:(_Bool)arg2 withItem:(id)arg3;
+ (_Bool)p_shouldShowYuanchuangFlagWithTextMode:(_Bool)arg1 withItem:(id)arg2;
+ (_Bool)p_shouldShowPayFlagWithTextMode:(_Bool)arg1 withItem:(id)arg2;
+ (_Bool)p_shouldShowZhuantiFlagWithTextMode:(_Bool)arg1 withItem:(id)arg2;
+ (_Bool)p_shouldShowDujiaFlagWithTextMode:(_Bool)arg1 withItem:(id)arg2;
+ (long long)titleLineFlagTypeWithTextMode:(_Bool)arg1 isInModuleBlock:(_Bool)arg2 withItem:(id)arg3;
+ (id)cellTipStringForItem:(id)arg1;
+ (id)p_filterListItems:(id)arg1 flagType:(id)arg2 includeType:(_Bool)arg3;
+ (id)filterListItems:(id)arg1 withoutFlagType:(id)arg2;
+ (id)p_filterListItems:(id)arg1 articleTypes:(id)arg2 includeType:(_Bool)arg3;
+ (id)filterListItems:(id)arg1 withArticleTypes:(id)arg2;
+ (_Bool)checkDuplicatedItemInArray:(id)arg1;
+ (id)getAllIndexString:(id)arg1;
+ (id)getNewIndexs:(id)arg1;
+ (void)p_parseChangeInfoRelationRecommendList:(id)arg1 channel:(id)arg2;
+ (void)p_parseChangeInfoCommon:(id)arg1;
+ (void)p_parseChangeInfoRecommendList:(id)arg1;
+ (void)p_parseChangeInfoPhotoList:(id)arg1;
+ (void)parseChangeInfo:(id)arg1 channel:(id)arg2 isFromIndexLoader:(_Bool)arg3;
+ (void)mergeListItems:(id)arg1 withKankanInfo:(id)arg2;
+ (void)mergeListItems:(id)arg1 withChangeInfo:(id)arg2;
+ (void)mergeListItems:(id)arg1 withIndexItems:(id)arg2;
+ (id)parseIndexs:(id)arg1;
+ (id)parseListItems:(id)arg1 channel:(id)arg2;
+ (id)parseListItem:(id)arg1 channel:(id)arg2;

@end

