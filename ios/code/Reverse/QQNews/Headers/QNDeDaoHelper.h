//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNDeDaoHelper : NSObject
{
}

+ (void)p_showBuySuccessTip;
+ (void)p_realBuyCourse:(id)arg1 articleId:(id)arg2 orderId:(id)arg3 finishBlock:(CDUnknownBlockType)arg4;
+ (void)buyCourse:(id)arg1 articleId:(id)arg2 orderId:(id)arg3 finishBlock:(CDUnknownBlockType)arg4;
+ (void)detachCurrentScrollView;
+ (void)showMiniPlayer:(_Bool)arg1;
+ (void)adjustMiniPlayerWithBottomInset:(double)arg1;
+ (void)updateMiniPlayerAttachedScrollView:(id)arg1 bottomInset:(double)arg2;
+ (void)updateMiniPlayerAttachedScrollView:(id)arg1;
+ (void)p_saveLessonKey:(id)arg1;
+ (void)downloadLessonAudio:(id)arg1 finishBlock:(CDUnknownBlockType)arg2;
+ (void)clearLocalData;
+ (id)audioFilePath:(id)arg1;
+ (id)folderForData;

@end
