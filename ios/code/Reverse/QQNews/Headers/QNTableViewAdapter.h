//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSMutableArray, NSMutableDictionary, NSOperationQueue, NSString, QNListTableView, QNTableViewAdapterProxy;

@interface QNTableViewAdapter : NSObject <UITableViewDelegate, UITableViewDataSource>
{
    struct QNPair *_previousModels;
    struct QNPair *_currentModels;
    NSOperationQueue *_asyncCalculateQueue;
    _Bool _inUpdates;
    id <QNTableViewAdapterDataSource> _adapterDataSource;
    id <QNTableViewAdapterDelegate> _adapterDelegate;
    id <UITableViewDelegate> _tableViewDelegate;
    QNListTableView *_tableView;
    QNTableViewAdapterProxy *_tableViewProxy;
    struct NSMutableDictionary *_cellModelCache;
    struct NSMutableArray *_cellClassRegistry;
    struct NSMutableArray *_cellModelClassRegistry;
    struct NSMutableDictionary *_asyncCalculatedCellModelCache;
    struct CGRect _referRect;
}

+ (id)adapterWithTableView:(id)arg1;
@property(retain, nonatomic) NSMutableDictionary *asyncCalculatedCellModelCache; // @synthesize asyncCalculatedCellModelCache=_asyncCalculatedCellModelCache;
@property(retain, nonatomic) NSMutableArray *cellModelClassRegistry; // @synthesize cellModelClassRegistry=_cellModelClassRegistry;
@property(retain, nonatomic) NSMutableArray *cellClassRegistry; // @synthesize cellClassRegistry=_cellClassRegistry;
@property(retain, nonatomic) NSMutableDictionary *cellModelCache; // @synthesize cellModelCache=_cellModelCache;
@property(nonatomic) _Bool inUpdates; // @synthesize inUpdates=_inUpdates;
@property(nonatomic) struct CGRect referRect; // @synthesize referRect=_referRect;
@property(retain, nonatomic) QNTableViewAdapterProxy *tableViewProxy; // @synthesize tableViewProxy=_tableViewProxy;
@property(nonatomic) __weak QNListTableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) __weak id <UITableViewDelegate> tableViewDelegate; // @synthesize tableViewDelegate=_tableViewDelegate;
@property(nonatomic) __weak id <QNTableViewAdapterDelegate> adapterDelegate; // @synthesize adapterDelegate=_adapterDelegate;
@property(nonatomic) __weak id <QNTableViewAdapterDataSource> adapterDataSource; // @synthesize adapterDataSource=_adapterDataSource;
- (void).cxx_destruct;
- (void)p_updateDataSource;
- (Class)p_cellModelClassForData:(id)arg1 layoutContext:(id)arg2;
- (id)p_cellReuseIdentifierForData:(id)arg1 layoutContext:(id)arg2;
- (id)p_dequeueReusableCellWithData:(id)arg1 layoutContext:(id)arg2 forIndexPath:(id)arg3;
- (id)p_layoutContextAtIndexPath:(id)arg1;
- (id)p_processedCellModelAtIndexPath:(id)arg1 layoutContext:(id)arg2;
- (void)p_reloadListWithAnimation:(long long)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)reloadListWithAnimation:(long long)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)reloadListWithCompletionBlock:(CDUnknownBlockType)arg1;
- (void)reloadList;
- (void)reloadListDirectlyWithCompletionBlock:(CDUnknownBlockType)arg1;
- (void)reloadListDirectly;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)unregisterAllCellModelClass;
- (void)unregisterCellModelClass:(Class)arg1;
- (void)registerCellModelClass:(Class)arg1 condition:(CDUnknownBlockType)arg2;
- (void)registerCellModelClass:(Class)arg1;
- (void)unregisterAllCellClass;
- (void)unregisterCellClass:(Class)arg1;
- (void)registerCellClass:(Class)arg1 reuseIdentifier:(id)arg2 condition:(CDUnknownBlockType)arg3;
- (void)registerCellClass:(Class)arg1 condition:(CDUnknownBlockType)arg2;
- (void)registerCellClass:(Class)arg1 reuseIdentifier:(id)arg2;
- (void)registerCellClass:(Class)arg1;
- (void)removeAllCellModelCache;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
