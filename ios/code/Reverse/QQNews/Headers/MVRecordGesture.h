//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIGestureRecognizer.h"

@interface MVRecordGesture : UIGestureRecognizer
{
    unsigned long long _type;
    double _beginTime;
}

@property(nonatomic) double beginTime; // @synthesize beginTime=_beginTime;
@property(nonatomic) unsigned long long type; // @synthesize type=_type;
- (void)cancelGesture;
- (void)touchesEstimatedPropertiesUpdated:(id)arg1;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;

@end
