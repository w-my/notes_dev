//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBasicListDataAdapter.h"

#import "QNAdVideoStreamWorkerDelegate.h"
#import "QNCommonListControllerDelegate.h"
#import "QNCommonListControllerProtocol.h"
#import "QNListDataAdapterSubclassProtocol.h"
#import "QNWebviewCellDelegate.h"

@class NSMutableDictionary, NSNotification, NSString, QNAdVideoStreamWorker;

@interface QNCommonListDataAdapter : QNBasicListDataAdapter <QNListDataAdapterSubclassProtocol, QNWebviewCellDelegate, QNCommonListControllerProtocol, QNCommonListControllerDelegate, QNAdVideoStreamWorkerDelegate>
{
    _Bool _hasVerticalCell;
    _Bool _hideVerticalCell;
    NSString *_verticalCellPackupText;
    NSNotification *_guideNotification;
    NSMutableDictionary *_cellFinishLoadFlag;
    NSMutableDictionary *_cellErrorFlag;
    NSMutableDictionary *_verticleCellDict;
    QNAdVideoStreamWorker *_adStreamWorker;
}

+ (_Bool)getHideVerticalCellInChannelID:(id)arg1;
+ (void)saveHideVerticalCell:(_Bool)arg1 channelID:(id)arg2;
+ (id)_keyForHideVerticalCell:(id)arg1;
+ (Class)classForListItem:(id)arg1 context:(id)arg2 channelID:(id)arg3;
@property(retain, nonatomic) QNAdVideoStreamWorker *adStreamWorker; // @synthesize adStreamWorker=_adStreamWorker;
@property(retain, nonatomic) NSMutableDictionary *verticleCellDict; // @synthesize verticleCellDict=_verticleCellDict;
@property(retain, nonatomic) NSMutableDictionary *cellErrorFlag; // @synthesize cellErrorFlag=_cellErrorFlag;
@property(retain, nonatomic) NSMutableDictionary *cellFinishLoadFlag; // @synthesize cellFinishLoadFlag=_cellFinishLoadFlag;
@property(retain, nonatomic) NSNotification *guideNotification; // @synthesize guideNotification=_guideNotification;
@property(copy, nonatomic) NSString *verticalCellPackupText; // @synthesize verticalCellPackupText=_verticalCellPackupText;
@property(nonatomic) _Bool hideVerticalCell; // @synthesize hideVerticalCell=_hideVerticalCell;
@property(nonatomic) _Bool hasVerticalCell; // @synthesize hasVerticalCell=_hasVerticalCell;
- (void).cxx_destruct;
- (void)_playVideoWithItem:(id)arg1 isContinuous:(_Bool)arg2 indexPath:(id)arg3;
- (void)resetHideVerticalCell:(_Bool)arg1 save:(_Bool)arg2;
- (void)showHelpViewForRecommendListViewAfterDelay;
- (void)p_checkFinalDislikeBtnPosition;
- (void)showHelpViewForRecommendListView;
- (_Bool)commonShowHelpVieAfterClickDislikeButton;
- (void)cellWillDisappear:(id)arg1;
- (void)adjustCellsWhenScrollEnded;
- (void)listViewWillDisappear;
- (void)listViewWillAppear;
- (void)_postLogicOnCellDidLoad:(id)arg1 indexPath:(id)arg2;
- (void)_reloadCell:(id)arg1;
- (void)_setDidFinishLoad:(_Bool)arg1 byId:(id)arg2;
- (void)packupVerticalCell:(_Bool)arg1 indexPath:(id)arg2;
- (void)showAlertViewForReduceSimilarRecommend;
- (void)deleteTableViewCell:(id)arg1 complete:(CDUnknownBlockType)arg2;
- (_Bool)webcellDidFinishLoadById:(id)arg1;
- (Class)classForListItem:(id)arg1 context:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (id)_verticleCellStoreKey:(id)arg1;
- (void)verticalCellDataUpdateFinished:(id)arg1;
- (void)_reloadVerticleCellsWithListItem:(id)arg1;
- (void)didOccurErrorInCell:(id)arg1;
- (void)webviewCell:(id)arg1 isReady:(_Bool)arg2;
- (void)listModeldidReplaceAllItems:(id)arg1 animated:(_Bool)arg2;
- (void)configureCellFactory;
- (void)configTableViewCellLayoutContext:(id)arg1 forData:(id)arg2 indexPath:(id)arg3;
- (void)dealloc;
- (void)dealWithInsertChannelsGuidanceNotification;
- (void)p_insertChannelsGuidanceCellItem:(id)arg1;
- (void)p_reloadRowsAtIndexPaths:(long long)arg1;
- (id)initAdapterWithController:(id)arg1 listModel:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
