//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class UIView;

@interface QNBarButtonItem : NSObject
{
    UIView *_customView;
    double _leftSpacing;
    double _rightSpacing;
}

@property(nonatomic) double rightSpacing; // @synthesize rightSpacing=_rightSpacing;
@property(nonatomic) double leftSpacing; // @synthesize leftSpacing=_leftSpacing;
@property(retain, nonatomic) UIView *customView; // @synthesize customView=_customView;
- (void).cxx_destruct;
- (id)initWithCustomView:(id)arg1;

@end

