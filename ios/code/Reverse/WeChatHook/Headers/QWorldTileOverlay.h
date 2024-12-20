//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QTileOverlay.h"

@class QWorldTileOverlayDataProvider;

@interface QWorldTileOverlay : QTileOverlay
{
    int _language;
    QWorldTileOverlayDataProvider *_provider;
}

@property(retain, nonatomic) QWorldTileOverlayDataProvider *provider; // @synthesize provider=_provider;
@property(nonatomic) int language; // @synthesize language=_language;
- (void).cxx_destruct;
- (id)init;
- (void)dealloc;
- (void)onWorldVesionCheck:(id)arg1;
- (void)saveTileData:(id)arg1 atPath:(CDStruct_cf57a58b)arg2;
- (id)loadTileImageAtPath:(CDStruct_cf57a58b)arg1;
- (id)URLForTilePath:(CDStruct_cf57a58b)arg1;

@end

