//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class EAGLContext, NSMutableArray, NSString, QEngineResourceManager, QGraphicsTool, QStatisticer, TBImagePool, TBIndoorBuilding;

@interface QMapContext : NSObject
{
    void *_pWorld;
    struct _opaque_pthread_t *_backgroundThread;
    _Bool _backgroundThreadCancelled;
    _Bool _indoorMaxZoomEnable;
    _Bool _internalIndoorEnabled;
    _Bool _internalRoadEventEnabled;
    EAGLContext *_context;
    double _minZoomLevel;
    double _maxZoomLevel;
    QGraphicsTool *_graphicsTool;
    TBImagePool *_imagePool;
    NSMutableArray *_multiDelegates;
    NSMutableArray *_tileOverlayContextes;
    QEngineResourceManager *_resourceManager;
    NSString *_latestErrorLog;
    QStatisticer *_statistics;
}

+ (CDStruct_02837cd9)QMapRectForMapRectD:(struct MapRectD)arg1;
+ (struct MapRectD)MapRectDForCGRect:(struct CGRect)arg1;
+ (struct MapRectD)MapRectDForQMapRect:(CDStruct_02837cd9)arg1;
+ (id)constructKeyForUIImage:(id)arg1;
+ (id)extractKeyFromImageInstruction:(id)arg1;
+ (id)constructImageInstructionWithKey:(id)arg1;
@property(nonatomic) __weak QStatisticer *statistics; // @synthesize statistics=_statistics;
@property(retain, nonatomic) NSString *latestErrorLog; // @synthesize latestErrorLog=_latestErrorLog;
@property(retain, nonatomic) QEngineResourceManager *resourceManager; // @synthesize resourceManager=_resourceManager;
@property(nonatomic) _Bool internalRoadEventEnabled; // @synthesize internalRoadEventEnabled=_internalRoadEventEnabled;
@property(nonatomic) _Bool internalIndoorEnabled; // @synthesize internalIndoorEnabled=_internalIndoorEnabled;
@property(retain, nonatomic) NSMutableArray *tileOverlayContextes; // @synthesize tileOverlayContextes=_tileOverlayContextes;
@property(retain, nonatomic) NSMutableArray *multiDelegates; // @synthesize multiDelegates=_multiDelegates;
@property(retain, nonatomic) TBImagePool *imagePool; // @synthesize imagePool=_imagePool;
@property(retain, nonatomic) QGraphicsTool *graphicsTool; // @synthesize graphicsTool=_graphicsTool;
@property(nonatomic) _Bool indoorMaxZoomEnable; // @synthesize indoorMaxZoomEnable=_indoorMaxZoomEnable;
@property(nonatomic) double maxZoomLevel; // @synthesize maxZoomLevel=_maxZoomLevel;
@property(nonatomic) double minZoomLevel; // @synthesize minZoomLevel=_minZoomLevel;
@property(retain, nonatomic) EAGLContext *context; // @synthesize context=_context;
- (void).cxx_destruct;
- (void)dealloc;
- (id)initWithResourceManager:(id)arg1;
- (void)setupWorld;
- (void)setupCompass;
- (void)setupEAGLContext;
- (void)destroy;
- (id)getPoisOnScreen;
- (id)checkClickInfoAtPoint:(struct CGPoint)arg1;
- (void)updatePathViewStyleFrom:(id)arg1 to:(struct MapPrimitive *)arg2 stroke:(_Bool)arg3;
- (void)updateCircleViewFrom:(id)arg1 to:(struct MapCircleInfo *)arg2;
- (unsigned int)TMColorForUIColor:(id)arg1;
- (union MapVector4ub)vectorColorForUIColor:(id)arg1;
- (double)scale;
- (void)configPolylineSegmentColor:(struct _MapRouteInfo *)arg1 polylineView:(id)arg2 scale:(int)arg3 styleParam:(struct _RGBAColorLineExtraParam *)arg4;
- (void)configPolylineDashParam:(struct _RGBADashedLineExtraParam *)arg1 polylineView:(id)arg2 scale:(int)arg3;
- (void)configPolylineArrow:(const struct _MapRouteInfo *)arg1 polylineView:(id)arg2 scale:(int)arg3 visible:(_Bool)arg4;
- (void)updateLevel:(int)arg1 forOverlay:(int)arg2;
- (void)updateCircleDisplayLevel:(id)arg1 level:(int)arg2;
- (void)updateCircle:(id)arg1 data:(id)arg2;
- (void)updatePolygonDisplayLevel:(id)arg1 level:(int)arg2;
- (void)updatePolygon:(id)arg1 style:(id)arg2 stroke:(_Bool)arg3;
- (void)updatePolylineDisplayLevel:(id)arg1 level:(int)arg2;
- (void)updatePolyline:(id)arg1 turnArrowColor:(id)arg2 borderColor:(id)arg3;
- (void)updatePolyline:(id)arg1 turnArrowIndex:(int)arg2;
- (void)updatePolyline:(id)arg1 passpointStyle:(id)arg2;
- (void)updatePolyline:(id)arg1 segmentColor:(id)arg2;
- (void)updatePolyline:(id)arg1 RGBAColorStyle:(id)arg2;
- (void)updatePolyline:(id)arg1 segmentStyle:(id)arg2;
- (void)configPolylineTextureStyle:(struct _MapRouteInfo *)arg1 polylineView:(id)arg2;
- (void)removeCircle:(id)arg1;
- (void)removePolygon:(id)arg1;
- (void)removePolyline:(id)arg1;
- (void)setHiddenForOverlayView:(id)arg1 hidden:(_Bool)arg2;
- (id)addCircle:(id)arg1;
- (id)addPolygon:(id)arg1;
- (id)addPolyline:(id)arg1;
- (void)updateLocationWithHeading:(double)arg1;
- (void)updateLocationWithMapPoint:(CDStruct_c3b9c2ee)arg1 course:(double)arg2 horizontalAccuracy:(double)arg3;
- (void)setLocationHidden:(_Bool)arg1;
- (id)updateLocationMarkerWithImage:(id)arg1 circleFillColor:(id)arg2 coordinate:(struct CLLocationCoordinate2D)arg3;
- (id)constructLocationMarker;
- (void)notifyMapLoadFinish;
- (void)notifyDidChangeActiveBuilding:(id)arg1;
- (void)notifySaveTileData:(id)arg1 withUrl:(id)arg2;
- (void)notifyDownloadTileWithUrl:(id)arg1;
- (void)notifyMapStatusChange:(int)arg1;
- (void)notifyDidMapStatusChangedAfterDraw;
- (void)notifyDidMapStatusChangedBeforeDraw;
- (void)unregisterDelegate:(id)arg1;
- (void)registerDelegate:(id)arg1;
- (void)removeDelegate:(id)arg1;
- (void)addDelegate:(id)arg1;
- (id)wrapperForDelegate:(id)arg1;
- (void)setupMulitDelegates;
- (int)saveTrafficData:(id)arg1;
- (id)checkTrafficUpdateWithRect:(CDStruct_02837cd9)arg1 dataLevel:(int)arg2;
- (void)setShowsTraffic:(_Bool)arg1;
- (void)reloadConfig;
- (id)satelliteCacheFolder;
- (void)saveVectorData:(id)arg1 forUrl:(id)arg2;
@property(nonatomic) long long mapStyle;
- (void)handleMapLoadFinish;
- (void)handleEngineRuntimeError:(id)arg1;
- (void *)handleEngineGetContext;
- (struct _TMBitmapContext *)handleEngineLoadGlyphWithText:(unsigned short)arg1 fontSize:(int)arg2 bold:(_Bool)arg3 rect:(struct MapRectF *)arg4 context:(void *)arg5;
- (void)handleEngineWriteWithFileName:(const char *)arg1 data:(const void *)arg2 dataSize:(int)arg3;
- (void)handleEngineDrawTextToBitmap:(struct _TMBitmapContext *)arg1 text:(unsigned short *)arg2 count:(int)arg3 fontSize:(int)arg4 bold:(_Bool)arg5 density:(float)arg6;
- (struct _TMSize)handleEngineCalcTextSizeWithText:(unsigned short *)arg1 count:(int)arg2 fontSize:(int)arg3 bold:(_Bool)arg4;
- (void)handleEngineDownloadWithURLString:(const char *)arg1;
- (struct _TMBitmapContext *)handleEngineLoadImageWithFileName:(const char *)arg1 code:(int)arg2 anchorPointX1:(float *)arg3 anchorPointY1:(float *)arg4;
- (void)handleEngineEventWithType:(int)arg1 param0:(const void *)arg2 param1:(const void *)arg3;
- (void)stopBackgroundThread;
- (void)startBackgroundThread;
- (void)backgroundThreadEntry;
- (CDStruct_02837cd9)convertToMapRectFromScreenRect:(struct CGRect)arg1;
- (struct CGRect)convertToScreenRectFromMapRect:(CDStruct_02837cd9)arg1;
- (CDStruct_c3b9c2ee)convertToMapPointFromScreenPoint:(struct CGPoint)arg1;
- (struct CGPoint)convertToScreenPointFromMapPoint:(CDStruct_c3b9c2ee)arg1;
- (CDStruct_c3b9c2ee)mapSizeForOffsetRange:(struct CGSize)arg1;
- (void)reloadWorld;
- (_Bool)isLoadingFinished;
- (void)zoomLevelFitsMapRect:(CDStruct_02837cd9)arg1 screenRect:(struct CGRect)arg2 outZoomLevel:(double *)arg3 outCenterMapPoint:(CDStruct_c3b9c2ee *)arg4;
@property(nonatomic) struct CGPoint centerOffset; // @dynamic centerOffset;
@property(readonly, nonatomic) double maxOverlooking;
@property(readonly, nonatomic) double minOverlooking;
@property(nonatomic) double overlooking; // @dynamic overlooking;
@property(nonatomic) double rotation; // @dynamic rotation;
- (void)setMinZoomLevel:(double)arg1 maxZoomLevel:(double)arg2;
@property(nonatomic) int scaleLevel; // @dynamic scaleLevel;
@property(nonatomic) double zoomLevel; // @dynamic zoomLevel;
@property(nonatomic) struct CLLocationCoordinate2D centerCoordinate;
@property(nonatomic) CDStruct_c3b9c2ee centerMapPoint; // @dynamic centerMapPoint;
- (double)internalScaleForZoomLevel:(double)arg1;
- (double)zoomLevelForInternalScale:(double)arg1;
- (double)normalizeZoomLevel:(double)arg1;
- (double)normalizeOverlooking:(double)arg1;
- (double)normalizeRotation:(double)arg1;
- (void)setupMinMaxZoomLevel;
- (double)availableMaxZoomLevel;
- (void)setIndoorMaxLevelEnable:(_Bool)arg1;
- (void)onMemoryWarning;
- (void)renderEntry;
- (void)updateDuration:(float)arg1;
- (void)setViewport:(struct CGRect)arg1;
@property(nonatomic) _Bool dirty; // @dynamic dirty;
- (id)internalDebugStatus;
- (id)getDataEngineVersion;
- (id)getMapEngineVersion;
- (id)loadImageWithInstruction:(id)arg1;
- (int)priorityForPayload:(id)arg1;
- (void)setPriority:(int)arg1 forPayload:(id)arg2;
- (_Bool)isAllTileOverlayEnabled;
- (void)setAllTileOverlayEnabled:(_Bool)arg1;
- (void)reloadPayload:(id)arg1;
- (void)removePayload:(id)arg1;
- (id)addTileOverlay:(id)arg1 WithLoadTileBlock:(CDUnknownBlockType)arg2 writeTileBlock:(CDUnknownBlockType)arg3;
- (void)reloadWorld;
- (void)enableMaploadCallbackEventOnce;
- (_Bool)isLoadingFinished;
- (void)setBaseMapHidden:(_Bool)arg1;
- (void)setPoiHidden:(_Bool)arg1;
- (void)setSatelliteEnabled:(_Bool)arg1;
- (void)setShowsBuilding3D:(_Bool)arg1;
- (_Bool)showsBuilding3D;
- (void)setShowsBuildings:(_Bool)arg1;
- (void)setShowsCompass:(_Bool)arg1;
- (void)setActiveBuildsFilter:(id)arg1;
- (double)getIndoorOutlineZoom:(id)arg1;
- (void)setActiveIndoorWithBuildId:(id)arg1 floor:(id)arg2;
@property(readonly, nonatomic) TBIndoorBuilding *activeIndoorBuilding;
- (_Bool)setLevelIndex:(unsigned long long)arg1;
@property(nonatomic) _Bool indoorEnabled;
- (_Bool)getFloorBoundingMapRect:(CDStruct_02837cd9 *)arg1;
- (_Bool)getCurrentFloorIndex:(int *)arg1;
- (id)getFloorNamesWithCount:(int)arg1;
- (_Bool)getFloorCount:(int *)arg1;
- (void)initStatistics:(id)arg1;
- (id)getStatistics;

@end

