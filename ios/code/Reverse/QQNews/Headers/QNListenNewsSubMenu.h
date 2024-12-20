//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListViewModelDelegate.h"

@class CSubMenuItemLoader, CSubMenuList, NSMutableDictionary, NSString;

@interface QNListenNewsSubMenu : NSObject <QNListViewModelDelegate>
{
    CSubMenuItemLoader *_loader;
    CSubMenuList *_localData;
    CDUnknownBlockType _callBack;
    NSMutableDictionary *_viewModelMap;
}

+ (id)allocWithZone:(struct _NSZone *)arg1;
+ (id)sharedInstance;
@property(retain, nonatomic) NSMutableDictionary *viewModelMap; // @synthesize viewModelMap=_viewModelMap;
@property(copy, nonatomic) CDUnknownBlockType callBack; // @synthesize callBack=_callBack;
@property(retain, nonatomic) CSubMenuList *localData; // @synthesize localData=_localData;
@property(retain, nonatomic) CSubMenuItemLoader *loader; // @synthesize loader=_loader;
- (void).cxx_destruct;
- (void)willAppendListItemsWithDirection:(unsigned long long)arg1 viewModel:(id)arg2;
- (void)willReplaceAllListItems:(id)arg1;
- (id)listenNewsListViewModelForChannelID:(id)arg1;
- (void)removeAllViewModel;
- (void)p_removeViewModelWhenUpdateSubChannels;
- (void)resetSubMenu;
- (id)getListenNewsSubMenu;
- (void)checkAndLoadSubMenuWithCallBack:(CDUnknownBlockType)arg1;
- (void)p_checkAndLoadSubMenuInBackgroundTask;
- (void)p_updateSubChannelsCompleted:(id)arg1;
- (void)p_updateFromNet;
- (void)p_loadFromDisk;
- (id)p_listensNewsChannelID;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

