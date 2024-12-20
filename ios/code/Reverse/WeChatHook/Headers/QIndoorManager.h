//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QIndoorPickerDelegate.h"
#import "QMapContextDelegate.h"

@class NSString, QIndoorBuilding, QIndoorLevel, QIndoorMapData, QIndoorPicker, QMapContext, UIView;

@interface QIndoorManager : NSObject <QMapContextDelegate, QIndoorPickerDelegate>
{
    _Bool _indoorEnabled;
    _Bool _indoorPrevilege;
    _Bool _indoorPickerEnabled;
    id <QIndoorManagerDelegate> _delegate;
    UIView *_hostView;
    QIndoorBuilding *_activeBuilding;
    long long _keyType;
    QMapContext *_mapContext;
    QIndoorPicker *_picker;
    unsigned long long _activeLevelIndex;
    QIndoorMapData *_indoorMapData;
    NSString *_businessKey;
    NSString *_configDirectoryPath;
    NSString *_indoorPlistPath;
    struct CGPoint _indoorPickerOffset;
}

@property(copy, nonatomic) NSString *indoorPlistPath; // @synthesize indoorPlistPath=_indoorPlistPath;
@property(copy, nonatomic) NSString *configDirectoryPath; // @synthesize configDirectoryPath=_configDirectoryPath;
@property(copy, nonatomic) NSString *businessKey; // @synthesize businessKey=_businessKey;
@property(retain, nonatomic) QIndoorMapData *indoorMapData; // @synthesize indoorMapData=_indoorMapData;
@property(nonatomic) unsigned long long activeLevelIndex; // @synthesize activeLevelIndex=_activeLevelIndex;
@property(retain, nonatomic) QIndoorPicker *picker; // @synthesize picker=_picker;
@property(nonatomic) __weak QMapContext *mapContext; // @synthesize mapContext=_mapContext;
@property(nonatomic) long long keyType; // @synthesize keyType=_keyType;
@property(retain, nonatomic) QIndoorBuilding *activeBuilding; // @synthesize activeBuilding=_activeBuilding;
@property(nonatomic) struct CGPoint indoorPickerOffset; // @synthesize indoorPickerOffset=_indoorPickerOffset;
@property(nonatomic) _Bool indoorPickerEnabled; // @synthesize indoorPickerEnabled=_indoorPickerEnabled;
@property(nonatomic) _Bool indoorPrevilege; // @synthesize indoorPrevilege=_indoorPrevilege;
@property(nonatomic, getter=isIndoorEnabled) _Bool indoorEnabled; // @synthesize indoorEnabled=_indoorEnabled;
@property(nonatomic) __weak UIView *hostView; // @synthesize hostView=_hostView;
@property(nonatomic) __weak id <QIndoorManagerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)dealloc;
- (void)reloadCurrentState;
- (void)setupIndoorMapData;
- (void)setupIndoorPlist;
- (id)initWithContext:(id)arg1 configPreference:(id)arg2;
- (void)setActiveBuildsFilter:(id)arg1;
- (double)getIndoorOutlineZoom:(id)arg1;
- (void)setActiveIndoorInfo:(id)arg1;
- (void)reloadIndoorMap;
- (void)resetIndoorMapData;
- (void)updateIndoorMapData:(id)arg1;
@property(retain, nonatomic) QIndoorLevel *activeLevel;
- (void)mapContext:(id)arg1 didChangeActiveBuilding:(id)arg2;
- (void)indoorPicker:(id)arg1 didSelectLevelIndex:(unsigned long long)arg2;
- (void)updatePicker;
- (_Bool)IsIndoorValid;
- (void)callDelegateDidChangeActiveLevel:(id)arg1;
- (void)callDelegateDidChangeActiveBuilding:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

