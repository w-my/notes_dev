//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@interface TSAInfoButton : UIView
{
    CDUnknownBlockType _touchedHandleBlock;
    unsigned long long _movePoints;
    struct CGPoint _touchedPoint;
}

@property(nonatomic) unsigned long long movePoints; // @synthesize movePoints=_movePoints;
@property(copy, nonatomic) CDUnknownBlockType touchedHandleBlock; // @synthesize touchedHandleBlock=_touchedHandleBlock;
@property(readonly, nonatomic) struct CGPoint touchedPoint; // @synthesize touchedPoint=_touchedPoint;
- (void).cxx_destruct;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1 touchedHandle:(CDUnknownBlockType)arg2;

@end

