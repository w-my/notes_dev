//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class CAShapeLayer, NSArray;

@interface QNNewUserSignInActivityContent : QNThemableView
{
    CAShapeLayer *_progressBack;
    CAShapeLayer *_progressLayer;
    CAShapeLayer *_progressOval;
    NSArray *_dayItems;
    unsigned long long _currentSignInDayCount;
}

@property(nonatomic) unsigned long long currentSignInDayCount; // @synthesize currentSignInDayCount=_currentSignInDayCount;
@property(copy, nonatomic) NSArray *dayItems; // @synthesize dayItems=_dayItems;
@property(nonatomic) __weak CAShapeLayer *progressOval; // @synthesize progressOval=_progressOval;
@property(nonatomic) __weak CAShapeLayer *progressLayer; // @synthesize progressLayer=_progressLayer;
@property(nonatomic) __weak CAShapeLayer *progressBack; // @synthesize progressBack=_progressBack;
- (void).cxx_destruct;
- (id)p_titleWithUnSignInDayIndex:(unsigned long long)arg1 signInCount:(unsigned long long)arg2;
- (void)layoutWithSignInDayCount:(unsigned long long)arg1 todayHasSignIn:(_Bool)arg2;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

