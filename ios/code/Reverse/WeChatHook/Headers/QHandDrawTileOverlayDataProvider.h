//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, QDataCacheHandDrawMap;

@interface QHandDrawTileOverlayDataProvider : NSObject
{
    NSString *_version;
    QDataCacheHandDrawMap *_dataCache;
}

@property(retain, nonatomic) QDataCacheHandDrawMap *dataCache; // @synthesize dataCache=_dataCache;
@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
- (void).cxx_destruct;
- (void)resetData;
- (int)tileType;
- (CDStruct_43274f37)tileForPath:(CDStruct_cf57a58b)arg1;
- (void)saveTileData:(id)arg1 atPath:(CDStruct_cf57a58b)arg2;
- (id)loadTileImageAtPath:(CDStruct_cf57a58b)arg1;
- (id)URLForTilePath:(CDStruct_cf57a58b)arg1;
- (id)init;

@end
