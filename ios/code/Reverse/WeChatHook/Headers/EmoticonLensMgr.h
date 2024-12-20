//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMKernelExt.h"
#import "MMResourceMgrExt.h"
#import "MMService.h"

@class EmoticonLensDataPB, NSOperationQueue, NSString;

@interface EmoticonLensMgr : MMService <MMResourceMgrExt, MMKernelExt, MMService>
{
    EmoticonLensDataPB *m_emoticonLensData;
    unsigned int m_lastCheckPackageTime;
    NSOperationQueue *m_updateResourceQueue;
    _Bool m_bHadCheckOrLoadEmoticonLensAllResouce;
    _Bool _m_bIsHadSelectedEmoticonLens;
}

@property(nonatomic) _Bool m_bIsHadSelectedEmoticonLens; // @synthesize m_bIsHadSelectedEmoticonLens=_m_bIsHadSelectedEmoticonLens;
- (void).cxx_destruct;
- (void)p_loadEmoticonLensInternal;
- (void)p_saveEmoticonLensToDataFileInternal;
- (id)p_getEmoticonLensDataFilePath;
- (id)p_getEmoticonLensResouceTempPath;
- (id)getEmoticonLensThumbnailFileFolderPathWithEmoticonLensItem:(id)arg1;
- (id)getEmoticonLensConfigFileFolderPath;
- (id)getEmoticonLensResoucePath;
- (id)getEmoticonLensItemFolderNameWithSubType:(unsigned int)arg1;
- (id)p_getEmoticonLensConfigFileFolderName;
- (id)p_getEmoticonLenItemResouceFilePrefix;
- (id)p_getEmoticonLenItemTempResoucePathWithSubType:(unsigned int)arg1;
- (id)getEmoticonLenItemResoucePathWithSubType:(unsigned int)arg1;
- (id)MMKVVersionKeyForEmoticonLensResWithSubType:(unsigned int)arg1;
- (void)doResUpdateWithSubResType:(unsigned int)arg1;
- (_Bool)upZipResourceUpdateWithSubResType:(unsigned int)arg1;
- (_Bool)checkEmoticonLensResouceNewestWithSubType:(unsigned int)arg1;
- (void)checkEmoticonLensAllResouce;
- (void)checkOrLoadEmoticonLensAllResouce;
- (void)onAuthOK;
- (_Bool)checkEmoticonLensResouceCompleteWithSubType:(unsigned int)arg1;
- (_Bool)checkEmoticonLensResouceVersion:(id)arg1;
- (_Bool)parseEmoticonLensResouceWithSubType:(unsigned int)arg1;
- (void)getSubFolders:(id)arg1 SubFiles:(id)arg2 fromFolderPath:(const char *)arg3;
- (void)parseEmoticonLensAllResouce;
- (id)p_getNodeLanguageStringDic:(struct XmlReaderNode_t *)arg1;
- (id)getNodeLanguageString:(struct XmlReaderNode_t *)arg1 andPrefix:(id)arg2 andEmoticonLensId:(id)arg3;
- (_Bool)parseEmoticonLensConfigPackage;
- (void)parsePackageFromBundle;
- (id)getEmoticonLensResouceTranslationString:(id)arg1 andEmoticonScenes:(unsigned int)arg2;
- (void)sortEmoticonLensList:(id)arg1 andScenes:(unsigned int)arg2;
- (id)getValidEmoticonLensListWithScenes:(unsigned int)arg1;
- (void)dealloc;
- (void)initRegister;
- (void)initData;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

