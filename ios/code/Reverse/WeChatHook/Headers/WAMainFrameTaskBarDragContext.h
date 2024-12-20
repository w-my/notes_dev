//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSIndexPath, NSMutableArray, WAAppItemData;

@interface WAMainFrameTaskBarDragContext : NSObject
{
    _Bool _dragToDelete;
    NSMutableArray *_dragBeginTaskItems;
    NSMutableArray *_dragBeginStarItems;
    NSIndexPath *_dragBeginIndexPath;
    NSIndexPath *_dragEndIndexPath;
    WAAppItemData *_dragReadyItem;
    unsigned long long _dragType;
}

@property(nonatomic) unsigned long long dragType; // @synthesize dragType=_dragType;
@property(retain, nonatomic) WAAppItemData *dragReadyItem; // @synthesize dragReadyItem=_dragReadyItem;
@property(nonatomic) _Bool dragToDelete; // @synthesize dragToDelete=_dragToDelete;
@property(retain, nonatomic) NSIndexPath *dragEndIndexPath; // @synthesize dragEndIndexPath=_dragEndIndexPath;
@property(retain, nonatomic) NSIndexPath *dragBeginIndexPath; // @synthesize dragBeginIndexPath=_dragBeginIndexPath;
@property(retain, nonatomic) NSMutableArray *dragBeginStarItems; // @synthesize dragBeginStarItems=_dragBeginStarItems;
@property(retain, nonatomic) NSMutableArray *dragBeginTaskItems; // @synthesize dragBeginTaskItems=_dragBeginTaskItems;
- (void).cxx_destruct;

@end

