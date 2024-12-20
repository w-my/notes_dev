//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IMMImagePickerManagerExt.h"
#import "IWSVideoExt.h"
#import "MMKernelExt.h"
#import "MMService.h"
#import "MMSightCameraExtention.h"
#import "MMUIViewControllerExt.h"
#import "MinimizeTaskDataSource.h"
#import "MinimizeTransitionInterface.h"
#import "MinimizeWindowDelegate.h"
#import "WAPluginEventExt.h"
#import "WCStoryPreviewStatusExt.h"

@class MinimizationWindow, MinimizeTaskData, NSMutableArray, NSMutableDictionary, NSString, UIView, UIViewController;

@interface MinimizeTaskMgr : MMService <MinimizeWindowDelegate, MMUIViewControllerExt, IMMImagePickerManagerExt, MMKernelExt, WAPluginEventExt, IWSVideoExt, WCStoryPreviewStatusExt, MMSightCameraExtention, MMService, MinimizeTransitionInterface, MinimizeTaskDataSource>
{
    _Bool _isMainWindowResignKeyWindow;
    _Bool _isFullScreenPlaying;
    _Bool _isWillShowImagePicker;
    int _currentTransitionType;
    int _gestureMode;
    NSMutableDictionary *_dicTaskKey2NotifyDelegate;
    NSString *_lastAdsorbFloatingViewSessionId;
    unsigned long long _lastAdsorbFloatingViewCreateTime;
    NSMutableArray *_normalTaskList;
    NSMutableArray *_passiveStateTaskList;
    NSMutableArray *_tmpSnapshotViewListWhenSwitchTask;
    MinimizationWindow *_minimizeWindow;
    unsigned long long _minimizeWindowState;
    MinimizeTaskData *_currentTransitioningTaskData;
    UIView *_currentTransitionFloatingView;
    NSMutableDictionary *_dictTaskTansitionController;
    NSString *_taskKeyWithGesture;
    UIViewController *_prevNeedHideWindowViewControllerWhenShowImagePicker;
    struct CGPoint _lastAdsorbFloatingViewPosition;
}

@property(nonatomic) __weak UIViewController *prevNeedHideWindowViewControllerWhenShowImagePicker; // @synthesize prevNeedHideWindowViewControllerWhenShowImagePicker=_prevNeedHideWindowViewControllerWhenShowImagePicker;
@property(nonatomic) _Bool isWillShowImagePicker; // @synthesize isWillShowImagePicker=_isWillShowImagePicker;
@property(nonatomic) _Bool isFullScreenPlaying; // @synthesize isFullScreenPlaying=_isFullScreenPlaying;
@property(nonatomic) _Bool isMainWindowResignKeyWindow; // @synthesize isMainWindowResignKeyWindow=_isMainWindowResignKeyWindow;
@property(nonatomic) int gestureMode; // @synthesize gestureMode=_gestureMode;
@property(retain, nonatomic) NSString *taskKeyWithGesture; // @synthesize taskKeyWithGesture=_taskKeyWithGesture;
@property(retain, nonatomic) NSMutableDictionary *dictTaskTansitionController; // @synthesize dictTaskTansitionController=_dictTaskTansitionController;
@property(retain, nonatomic) UIView *currentTransitionFloatingView; // @synthesize currentTransitionFloatingView=_currentTransitionFloatingView;
@property(nonatomic) int currentTransitionType; // @synthesize currentTransitionType=_currentTransitionType;
@property(retain, nonatomic) MinimizeTaskData *currentTransitioningTaskData; // @synthesize currentTransitioningTaskData=_currentTransitioningTaskData;
@property(nonatomic) unsigned long long minimizeWindowState; // @synthesize minimizeWindowState=_minimizeWindowState;
@property(retain, nonatomic) MinimizationWindow *minimizeWindow; // @synthesize minimizeWindow=_minimizeWindow;
@property(retain, nonatomic) NSMutableArray *tmpSnapshotViewListWhenSwitchTask; // @synthesize tmpSnapshotViewListWhenSwitchTask=_tmpSnapshotViewListWhenSwitchTask;
@property(retain, nonatomic) NSMutableArray *passiveStateTaskList; // @synthesize passiveStateTaskList=_passiveStateTaskList;
@property(retain, nonatomic) NSMutableArray *normalTaskList; // @synthesize normalTaskList=_normalTaskList;
@property(nonatomic) unsigned long long lastAdsorbFloatingViewCreateTime; // @synthesize lastAdsorbFloatingViewCreateTime=_lastAdsorbFloatingViewCreateTime;
@property(retain, nonatomic) NSString *lastAdsorbFloatingViewSessionId; // @synthesize lastAdsorbFloatingViewSessionId=_lastAdsorbFloatingViewSessionId;
@property(nonatomic) struct CGPoint lastAdsorbFloatingViewPosition; // @synthesize lastAdsorbFloatingViewPosition=_lastAdsorbFloatingViewPosition;
@property(retain, nonatomic) NSMutableDictionary *dicTaskKey2NotifyDelegate; // @synthesize dicTaskKey2NotifyDelegate=_dicTaskKey2NotifyDelegate;
- (void).cxx_destruct;
- (void)onWSVideoPlayFullScreen:(_Bool)arg1;
- (void)onWAVideoPlayFullScreen:(_Bool)arg1;
- (void)UIWindowDidBecomeKeyNotification:(id)arg1;
- (_Bool)isViewControllerNeedHideMinimization:(id)arg1;
- (void)MMUIViewControllerDidBeRemoved:(id)arg1;
- (void)MMUIViewControllerWillDisppear:(id)arg1;
- (void)MMUIViewControllerWillAppear:(id)arg1;
- (void)onMMImagePickerManagerShow;
- (void)onMMImagePickerManagerFinish;
- (void)markImagePicking:(_Bool)arg1;
- (void)MMSightCameraWillBePoped;
- (void)MMSightCameraWillBePushed;
- (void)MMSightCameraWillBeDismissed;
- (void)MMSightCameraWillBePresent;
- (void)onStoryPreviewStatusShow;
- (void)onStoryPreviewStatusHide;
- (void)onLoginOK;
- (void)onManulLoginOK;
- (void)setWindowMinimizationState:(unsigned long long)arg1;
- (void)clearGestureRelatedData;
- (void)endPopBackGesture:(id)arg1 isComplete:(_Bool)arg2;
- (void)endPopBackGesture:(id)arg1 TaskBizKey:(id)arg2 isComplete:(_Bool)arg3;
- (_Bool)updatePopBackGesture:(id)arg1 Progress:(double)arg2 TouchPoint:(struct CGPoint)arg3 ShouldCancel:(_Bool *)arg4;
- (_Bool)updatePopBackGesture:(id)arg1 TaskBizKey:(id)arg2 Progress:(double)arg3 TouchPoint:(struct CGPoint)arg4 ShouldCancel:(_Bool *)arg5;
- (void)beginPopBackGesture:(id)arg1;
- (void)beginPopBackGesture:(id)arg1 TaskBizKey:(id)arg2;
- (_Bool)canAddNormalTask;
- (_Bool)needShowMinimizeWindow;
- (void)onUpdateAbsorbFloatingViewLastPosition:(struct CGPoint)arg1;
- (void)onPositiveTaskCloseBtnClick:(id)arg1 CloseFromState:(_Bool)arg2;
- (void)onFloatingViewMoveToTrash:(id)arg1;
- (_Bool)tryDeleteTaskRelatedData:(id)arg1;
- (_Bool)tryDeleteTaskFromList:(id)arg1;
- (void)realEnterTask:(id)arg1 FromFloatingView:(id)arg2 EnterTaskScene:(int)arg3;
- (void)onFloatingViewTap:(id)arg1 FromFloatingView:(id)arg2 WillEnterBackgroundTaskKey:(id)arg3 EnterTaskScene:(int)arg4;
- (void)markWidgetFullScreen:(_Bool)arg1;
- (id)getAllBackgroundTaskList;
- (id)getAllTaskList;
- (id)getTask:(id)arg1;
- (_Bool)removeTask:(id)arg1 TaskBizKey:(id)arg2;
- (_Bool)tryAdjustTaskListOrderIfNeed:(id)arg1 NewTaskData:(id)arg2 OrderChanged:(_Bool *)arg3;
- (_Bool)replaceTask:(id)arg1 TaskList:(id)arg2;
- (_Bool)replaceTask:(id)arg1;
- (_Bool)updateTaskState:(id)arg1 NewTaskData:(id)arg2 TaskListOrderChanged:(_Bool *)arg3;
- (_Bool)updateTask:(id)arg1 WithTaskData:(id)arg2;
- (_Bool)tryUpdateTaskText:(id)arg1 NewTaskData:(id)arg2;
- (_Bool)hasTask:(id)arg1;
- (_Bool)hasTask:(id)arg1 TaskBizKey:(id)arg2;
- (id)getTask:(id)arg1 TaskBizKey:(id)arg2;
- (_Bool)tryAddTask:(id)arg1;
- (_Bool)tryAddTaskAndMinimize:(id)arg1 NotiDelegate:(id)arg2;
- (_Bool)maximizeTask:(id)arg1 TaskBizKey:(id)arg2;
- (_Bool)canAddTask:(id)arg1;
- (_Bool)checkTaskMaxCountOrShowTipsBeforeAdd:(id)arg1;
- (_Bool)canShowMinimizeOperation;
- (void)delayRemoveTmpSnapShotViews;
- (void)onMinimizeAnimationEnd:(id)arg1;
- (void)onMinimizeAnimationEnd:(id)arg1 TaskBizKey:(id)arg2;
- (void)onMinimizeAnimationBegin:(id)arg1 FromFrame:(struct CGRect)arg2 toFrame:(struct CGRect)arg3 duration:(double)arg4;
- (void)onMinimizeAnimationBegin:(id)arg1 TaskBizKey:(id)arg2 FromFrame:(struct CGRect)arg3 toFrame:(struct CGRect)arg4 duration:(double)arg5;
- (struct CGRect)getConvertedVisibleFrame;
- (id)getCurrentMaskPathConvertedToCurrentScreenCoordinates;
- (id)getTransitionFloatingView:(id)arg1;
- (id)getTransitionFloatingView:(id)arg1 TaskBizKey:(id)arg2;
- (void)onServiceClearData;
- (void)loadTaskListFromFileAndShowAbsorbFloatingView;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)dealloc;
- (id)init;
- (id)transitionControllerForTaskKey:(id)arg1 TaskBizKey:(id)arg2;
- (_Bool)recoverNotifyDelegate:(id)arg1;
- (_Bool)recoverAllNormalTaskListFromFile;
- (_Bool)checkIfTaskValid:(id)arg1;
- (_Bool)saveAllNormalTaskListToFile;
- (id)recoverLastAdsorbFloatingViewInfo;
- (_Bool)saveLastAdsorbFloatingViewInfo:(struct CGPoint)arg1 AggreSessionId:(id)arg2;
- (_Bool)saveLastAdsorbFloatingViewSessionId:(id)arg1;
- (_Bool)saveLastAdsorbFloatingViewPosition:(struct CGPoint)arg1;
- (void)tryRecoverLastNormalTaskList;
- (void)tryReportRemovePassiveStateTaskOperation:(id)arg1 UserTrigger:(_Bool)arg2;
- (int)opTypeFromMaximizeScene:(int)arg1;
- (void)tryReportRemoveTaskOperation:(id)arg1 IsLastTask:(_Bool)arg2 FromCloseButtonInListPage:(_Bool)arg3;
- (void)fillOperationCommonInfo:(id)arg1 Task:(id)arg2;
- (void)tryReportMinimizeOperation:(id)arg1 OpType:(int)arg2;
- (void)reportMaximizeOperation:(id)arg1 EnterTaskScene:(int)arg2;
- (void)onExitTaskListPage:(unsigned long long)arg1 ExitType:(int)arg2;
- (id)trySaveAggreSessionId:(_Bool)arg1;
- (int)getReportState:(id)arg1;
- (long long)getIndexFromTaskList:(id)arg1 CurrentTask:(id)arg2;
- (long long)getTaskOrder:(id)arg1;
- (void)tryReportWhenUpdateTask:(id)arg1 NewTask:(id)arg2;
- (void)tryGenExtInfoAndReportNewTask:(id)arg1;
- (void)genExtInfoAndReportNewTask:(id)arg1;
- (unsigned long long)getTotalTaskCount;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

