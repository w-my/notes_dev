//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSSportsMatchScheduleAttrView.h"

@class NSMutableArray;

@interface QSSportsMatchScheduleFootballEventView : QSSportsMatchScheduleAttrView
{
    NSMutableArray *_leftEventViews;
    NSMutableArray *_rightEventViews;
}

+ (double)fixedHeight;
@property(retain, nonatomic) NSMutableArray *rightEventViews; // @synthesize rightEventViews=_rightEventViews;
@property(retain, nonatomic) NSMutableArray *leftEventViews; // @synthesize leftEventViews=_leftEventViews;
- (void).cxx_destruct;
- (void)refreshWithScheduleItem:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
