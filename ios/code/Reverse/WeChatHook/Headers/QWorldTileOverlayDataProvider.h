//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString, QDataCacheWorldMap;

@interface QWorldTileOverlayDataProvider : NSObject
{
    NSString *_styleId;
    NSString *_scene;
    NSString *_version;
    NSString *_urlTemplate;
    QDataCacheWorldMap *_dataCache;
    NSArray *_langCandidates;
}

@property(retain, nonatomic) NSArray *langCandidates; // @synthesize langCandidates=_langCandidates;
@property(retain, nonatomic) QDataCacheWorldMap *dataCache; // @synthesize dataCache=_dataCache;
@property(copy, nonatomic) NSString *urlTemplate; // @synthesize urlTemplate=_urlTemplate;
@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
@property(copy, nonatomic) NSString *scene; // @synthesize scene=_scene;
@property(copy, nonatomic) NSString *styleId; // @synthesize styleId=_styleId;
- (void).cxx_destruct;
- (id)generateUrl:(id)arg1;
- (void)resetData;
- (int)tileType;
- (CDStruct_43274f37)tileForPath:(CDStruct_cf57a58b)arg1;
- (void)saveTileData:(id)arg1 atPath:(CDStruct_cf57a58b)arg2;
- (id)loadTileImageAtPath:(CDStruct_cf57a58b)arg1;
- (id)URLForTilePath:(CDStruct_cf57a58b)arg1;
- (id)languageString:(int)arg1;
- (id)init;

@end

