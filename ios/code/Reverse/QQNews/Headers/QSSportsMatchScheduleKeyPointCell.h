//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSSportsMatchScheduleBaseCell.h"

@class QSSportsMatchScheduleKeyPointView;

@interface QSSportsMatchScheduleKeyPointCell : QSSportsMatchScheduleBaseCell
{
    QSSportsMatchScheduleKeyPointView *_keyPointView;
}

+ (double)fixedContentDetailHeight;
@property(retain, nonatomic) QSSportsMatchScheduleKeyPointView *keyPointView; // @synthesize keyPointView=_keyPointView;
- (void).cxx_destruct;
- (void)refreshWithScheduleItem:(id)arg1 showSeperatorLine:(_Bool)arg2 isHotColumn:(_Bool)arg3 contentTopOffset:(double)arg4;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

