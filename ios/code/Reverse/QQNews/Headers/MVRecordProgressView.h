//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CAShapeLayer, NSArray, UIBezierPath, UIColor;

@interface MVRecordProgressView : UIView
{
    UIBezierPath *recordedPath;
    UIBezierPath *lastSectionPath;
    CAShapeLayer *deletingLayer;
    double lastPathRight;
    _Bool _isDeleting;
    double _maxTime;
    NSArray *_recordedTimes;
    double _currSectionTime;
    UIColor *_progressColor;
    UIColor *_deletingSegColor;
    UIColor *_recordingSegColor;
}

+ (Class)layerClass;
@property(retain, nonatomic) UIColor *recordingSegColor; // @synthesize recordingSegColor=_recordingSegColor;
@property(retain, nonatomic) UIColor *deletingSegColor; // @synthesize deletingSegColor=_deletingSegColor;
@property(retain, nonatomic) UIColor *progressColor; // @synthesize progressColor=_progressColor;
@property(nonatomic) _Bool isDeleting; // @synthesize isDeleting=_isDeleting;
@property(nonatomic) double currSectionTime; // @synthesize currSectionTime=_currSectionTime;
@property(retain, nonatomic) NSArray *recordedTimes; // @synthesize recordedTimes=_recordedTimes;
@property(nonatomic) double maxTime; // @synthesize maxTime=_maxTime;
- (void).cxx_destruct;
- (void)setBounds:(struct CGRect)arg1;
- (void)createDeletingLayerIfNeed;
- (void)caculatePaths;
- (void)drawProgress;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, nonatomic) CAShapeLayer *layer; // @dynamic layer;

@end

