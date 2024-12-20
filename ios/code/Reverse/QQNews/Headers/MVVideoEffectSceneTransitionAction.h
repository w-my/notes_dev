//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectGPUAction.h"

@class MVSceneTransitionFilter, MVVideoEffectSceneTransitionActionXMLItem;

@interface MVVideoEffectSceneTransitionAction : MVVideoEffectGPUAction
{
    MVVideoEffectSceneTransitionActionXMLItem *_sceneTransitionXMLItem;
    MVSceneTransitionFilter *_sceneTransitionFilter;
}

@property(retain, nonatomic) MVSceneTransitionFilter *sceneTransitionFilter; // @synthesize sceneTransitionFilter=_sceneTransitionFilter;
@property(retain, nonatomic) MVVideoEffectSceneTransitionActionXMLItem *sceneTransitionXMLItem; // @synthesize sceneTransitionXMLItem=_sceneTransitionXMLItem;
- (void).cxx_destruct;
- (void)setVideoTime:(double)arg1;
- (void)prepareForProcessing;
- (void)createFilter;
- (_Bool)needRandomAccess;
- (void)reset;
- (void)dealloc;
- (id)outputFilter;
- (void)removeAllTargets;
- (id)initWithXMLItem:(id)arg1;

@end

