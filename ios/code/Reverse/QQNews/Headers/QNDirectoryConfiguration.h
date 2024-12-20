//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNDirectoryConfiguration : NSObject
{
}

+ (id)platform;
+ (id)getFormatWeixinSDKVersion;
+ (id)getVersion;
+ (id)sharedInstance;
- (id)p_shortcutPathForNews:(id)arg1 inTheme:(long long)arg2;
- (_Bool)p_addSkipBackupAttributeToItemAtURL:(id)arg1;
- (void)cleanShortcutCacheForNews:(id)arg1;
- (id)shortcutPathForNews:(id)arg1;
- (id)getArticleCacheDirectory:(id)arg1;
- (id)getAppLaunchImageFileName;
- (id)getQQNewsSportVoteCachePath;
- (id)getFilePathInQQNewsSecureLibrary:(id)arg1;
- (id)getFilePathInQQNewsCache:(id)arg1;
- (id)getFilePathInQQNewsDoc:(id)arg1;
- (id)getQQNewsSecureLibraryDirecttory;
- (id)getQQNewsAMRRadioCacheDirecttory;
- (id)getQQNewsDetailResourceDirectory;
- (id)normalArticleCacheDirectory;
- (id)getQQNewsCacheDirecttory;
- (id)getQQNewsDocumentDirecttory;
- (id)getFavoriteContentCachePath:(id)arg1;
- (id)getQQNewsFavoriteCacheDirectory;
- (id)getOfflineArticleCacheDirectory:(id)arg1;
- (id)getQQNewsOfflineArticleDirecttory;
- (id)getQQNewsOfflineCacheDirecttory;
- (id)getQQNewsOfflineDirectory;
- (id)getFilePathInMainBundle:(id)arg1;
- (id)getFilePathInDoc:(id)arg1;
- (id)getFullPath:(id)arg1 pathtype:(int)arg2;
- (id)getUniqueIDInfo;

@end

