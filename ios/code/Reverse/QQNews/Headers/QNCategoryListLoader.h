//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNCategoryListLoader : NSObject
{
}

- (void)p_asyncWriteDataToDisk:(id)arg1;
- (id)p_loadDataFromDisk;
- (id)p_cachePath;
- (void)loadCategoryListDataFromServer:(CDUnknownBlockType)arg1 pageType:(unsigned long long)arg2;
- (void)loadMediaCategoryListCompletion:(CDUnknownBlockType)arg1 pageType:(unsigned long long)arg2;

@end
