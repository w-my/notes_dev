//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSArray, NSMutableArray;

@interface QSMatchDetailVideoSegmentedView : UIView
{
    NSArray *_segmentItems;
    long long _selectedIndex;
    CDUnknownBlockType _didSelectedBlock;
    NSMutableArray *_segmentControls;
}

@property(retain, nonatomic) NSMutableArray *segmentControls; // @synthesize segmentControls=_segmentControls;
@property(copy, nonatomic) CDUnknownBlockType didSelectedBlock; // @synthesize didSelectedBlock=_didSelectedBlock;
@property(nonatomic) long long selectedIndex; // @synthesize selectedIndex=_selectedIndex;
@property(copy, nonatomic) NSArray *segmentItems; // @synthesize segmentItems=_segmentItems;
- (void).cxx_destruct;
- (void)segmentViewPressed:(id)arg1;
- (void)updateAllSegmentsFrame;
- (void)reloadData;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
