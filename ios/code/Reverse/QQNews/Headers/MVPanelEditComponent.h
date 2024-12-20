//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVEditComponent.h"

@class LKTouchThroughView, MVEditPanel, NSArray;

@interface MVPanelEditComponent : MVEditComponent
{
    MVEditPanel *_editPanel;
    LKTouchThroughView *_containerView;
    NSArray *_tabItems;
}

@property(retain, nonatomic) NSArray *tabItems; // @synthesize tabItems=_tabItems;
@property(retain, nonatomic) LKTouchThroughView *containerView; // @synthesize containerView=_containerView;
@property(retain, nonatomic) MVEditPanel *editPanel; // @synthesize editPanel=_editPanel;
- (void).cxx_destruct;
- (void)dismissEditPanel;
- (void)showEditPanel;
- (struct CGRect)changeMediaDisplayingToFullscreen:(_Bool)arg1;
- (id)editPanelWithStyle:(long long)arg1;
- (struct CGRect)mediaDisplayingRect;
- (double)heightOfEditPanel;
- (void)didDisappear;
- (void)willAppear;
- (void)finishEditingWithCancel:(_Bool)arg1;
- (void)beginEditing;
- (void)initEditPanel;
- (void)becomeActiveAnimated:(_Bool)arg1;
- (id)editingViewWithBoundingRect:(struct CGRect)arg1;

@end

