//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVEditComponent.h"

@class MVEditFilterView, MVFilterPicker, NSTimer, UIView;

@interface MVEditFilterComponent : MVEditComponent
{
    _Bool _ignoreFilterView;
    UIView *_containerView;
    MVEditFilterView *_filterView;
    MVFilterPicker *_currentFilterPicker;
    NSTimer *_autoSaveTimer;
}

@property(retain, nonatomic) NSTimer *autoSaveTimer; // @synthesize autoSaveTimer=_autoSaveTimer;
@property(nonatomic) _Bool ignoreFilterView; // @synthesize ignoreFilterView=_ignoreFilterView;
@property(retain, nonatomic) MVFilterPicker *currentFilterPicker; // @synthesize currentFilterPicker=_currentFilterPicker;
@property(retain, nonatomic) MVEditFilterView *filterView; // @synthesize filterView=_filterView;
@property(retain, nonatomic) UIView *containerView; // @synthesize containerView=_containerView;
- (void).cxx_destruct;
- (void)dismissFilterView;
- (void)showFilterView;
- (void)onAutoSaveTimer;
- (void)cancelAutoSaveTimer;
- (void)restartAutoSaveTimerIfNeeded;
- (void)revertToOriginFilter;
- (_Bool)isUsingMultiFilters;
- (void)alertShouldApplyFilterIfNeed:(long long)arg1;
- (id)filterViewWithFrame:(struct CGRect)arg1;
- (void)installFilterPickerToHandlerView:(id)arg1;
- (void)initFilterPicker;
- (void)lostFocus;
- (void)willUnload;
- (void)setGestureView:(id)arg1;
- (void)becomeActiveAnimated:(_Bool)arg1;
- (id)editingViewWithBoundingRect:(struct CGRect)arg1;
- (void)applyFilterWithFilterID:(long long)arg1;
@property(readonly, nonatomic) MVFilterPicker *filterPicker;
- (void)dealloc;
- (id)init;

@end

