//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVPanelEditComponent.h"

@class MVClipVideoBar, MVVideoClipModel, NSDictionary, UIImageView, UILabel;

@interface MVEditClipVideoComponent : MVPanelEditComponent
{
    UILabel *_wholeDurationLabel;
    UIImageView *_wholeDurationIcon;
    MVClipVideoBar *_clipVideoBar;
    NSDictionary *_channelEnabledMap;
    MVVideoClipModel *_originalVideoClipModel;
}

@property(retain, nonatomic) MVVideoClipModel *originalVideoClipModel; // @synthesize originalVideoClipModel=_originalVideoClipModel;
@property(retain, nonatomic) NSDictionary *channelEnabledMap; // @synthesize channelEnabledMap=_channelEnabledMap;
@property(nonatomic) __weak MVClipVideoBar *clipVideoBar; // @synthesize clipVideoBar=_clipVideoBar;
@property(nonatomic) __weak UIImageView *wholeDurationIcon; // @synthesize wholeDurationIcon=_wholeDurationIcon;
@property(nonatomic) __weak UILabel *wholeDurationLabel; // @synthesize wholeDurationLabel=_wholeDurationLabel;
- (void).cxx_destruct;
- (id)editPanelWithStyle:(long long)arg1;
- (struct CGRect)mediaDisplayingRect;
- (double)heightOfEditPanel;
- (void)willAppear;
- (void)finishEditingWithCancel:(_Bool)arg1;
- (void)beginEditing;
- (void)updateUIByDuration;
- (void)initDurationLabel;
- (void)initClipVideoBar;
- (id)init;

@end

