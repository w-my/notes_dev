//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNEnlargeHitTestButton.h"

@class CAShapeLayer;

@interface QNDeDaoMiniPlayerButton : QNEnlargeHitTestButton
{
    CAShapeLayer *_progressPath;
    CAShapeLayer *_progressCircle;
}

@property(retain, nonatomic) CAShapeLayer *progressCircle; // @synthesize progressCircle=_progressCircle;
@property(retain, nonatomic) CAShapeLayer *progressPath; // @synthesize progressPath=_progressPath;
- (void).cxx_destruct;
- (double)currentProgress;
- (void)updateProgress:(double)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

