//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNHotSpotSpecialEntranceCell.h"

@class QNPageView;

@interface QNHotSpotSpecialLargeEntranceCell : QNHotSpotSpecialEntranceCell
{
    QNPageView *_containerView;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(retain, nonatomic) QNPageView *containerView; // @synthesize containerView=_containerView;
- (void).cxx_destruct;
- (double)heightOfDragView;
- (id)pageView:(id)arg1 contentForPage:(unsigned long long)arg2;
- (void)updateReadCountInPageView:(id)arg1 atPage:(unsigned long long)arg2;

@end
