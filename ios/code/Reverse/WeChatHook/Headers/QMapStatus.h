//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QMapStatus : NSObject
{
    _Bool _isNightStyle;
    int _zoomLevel;
    struct CLLocationCoordinate2D _centerCoordinate;
    CDStruct_02837cd9 _mapRect;
}

@property(nonatomic) _Bool isNightStyle; // @synthesize isNightStyle=_isNightStyle;
@property(nonatomic) struct CLLocationCoordinate2D centerCoordinate; // @synthesize centerCoordinate=_centerCoordinate;
@property(nonatomic) CDStruct_02837cd9 mapRect; // @synthesize mapRect=_mapRect;
@property(nonatomic) int zoomLevel; // @synthesize zoomLevel=_zoomLevel;

@end

