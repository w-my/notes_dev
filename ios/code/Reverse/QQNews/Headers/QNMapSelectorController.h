//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "MKMapViewDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CLLocation, MKMapView, NSIndexPath, NSMutableArray, NSString, QNGeocoder, QNLocationItem, QNPoiData, UITableView, UIView;

@interface QNMapSelectorController : QNRootViewController <UITableViewDataSource, UITableViewDelegate, MKMapViewDelegate>
{
    _Bool _isLoadingMorePOI;
    _Bool _mkMapViewAdjustedZoomLevel;
    _Bool _showDefaultLocation;
    _Bool _regionChangedByPOISelection;
    MKMapView *_mkMapView;
    QNPoiData *_poiSearchData;
    QNGeocoder *_reverseGeocoder;
    CDUnknownBlockType _finishSelectBlock;
    CDUnknownBlockType _cancelSelectBlock;
    UITableView *_tableView;
    NSMutableArray *_locationList;
    UIView *_centerMarkView;
    QNLocationItem *_currentLocation;
    CLLocation *_lastMapCenterLocation;
    NSIndexPath *_lastSelectedIndexPath;
}

+ (void)presentMapSelectorWithController:(id)arg1 finishBlock:(CDUnknownBlockType)arg2 cancelBlock:(CDUnknownBlockType)arg3;
@property(nonatomic) _Bool regionChangedByPOISelection; // @synthesize regionChangedByPOISelection=_regionChangedByPOISelection;
@property(nonatomic) _Bool showDefaultLocation; // @synthesize showDefaultLocation=_showDefaultLocation;
@property(retain, nonatomic) NSIndexPath *lastSelectedIndexPath; // @synthesize lastSelectedIndexPath=_lastSelectedIndexPath;
@property(retain, nonatomic) CLLocation *lastMapCenterLocation; // @synthesize lastMapCenterLocation=_lastMapCenterLocation;
@property(retain, nonatomic) QNLocationItem *currentLocation; // @synthesize currentLocation=_currentLocation;
@property(retain, nonatomic) UIView *centerMarkView; // @synthesize centerMarkView=_centerMarkView;
@property(retain, nonatomic) NSMutableArray *locationList; // @synthesize locationList=_locationList;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(copy, nonatomic) CDUnknownBlockType cancelSelectBlock; // @synthesize cancelSelectBlock=_cancelSelectBlock;
@property(copy, nonatomic) CDUnknownBlockType finishSelectBlock; // @synthesize finishSelectBlock=_finishSelectBlock;
@property(retain, nonatomic) QNGeocoder *reverseGeocoder; // @synthesize reverseGeocoder=_reverseGeocoder;
@property(retain, nonatomic) QNPoiData *poiSearchData; // @synthesize poiSearchData=_poiSearchData;
@property(retain, nonatomic) MKMapView *mkMapView; // @synthesize mkMapView=_mkMapView;
- (void).cxx_destruct;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)runAnimationForCenterMark;
- (void)addCenterMarkViewToMapView:(id)arg1;
- (void)zoomToCurrentLocation;
- (void)addZoomButtonToMapView:(id)arg1;
- (void)p_handlePOISearchResult:(id)arg1;
- (void)searchMorePOI;
- (void)searchPOIForMapCenterLocation;
- (void)removeAllOverlay;
- (void)mapView:(id)arg1 regionDidChangeAnimated:(_Bool)arg2;
- (void)mapView:(id)arg1 regionWillChangeAnimated:(_Bool)arg2;
- (void)updateInfoForCurrentLocationCell;
- (void)mapView:(id)arg1 didUpdateUserLocation:(id)arg2;
- (void)mapView:(id)arg1 didFailToLocateUserWithError:(id)arg2;
- (void)loadMKMapView;
- (void)confirmSelectLocation;
- (void)cancelSelectLocation;
- (void)didReceiveMemoryWarning;
- (void)themeChanged:(long long)arg1;
- (void)viewDidLoad;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
