//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "TLNModelProtocol.h"

@class NSArray, NSDictionary, NSString;

@interface TLNModelBase : NSObject <TLNModelProtocol>
{
    _Bool _isLandscape;
    _Bool _shouldExtendEdge;
    float _designWidth;
    float _designHeight;
    NSArray *_subviewModels;
    NSString *_modelName;
    NSDictionary *_custom;
    double _originX;
    double _originY;
    double _originWidth;
    double _originHeight;
    double _realX;
    double _realY;
    double _realWidth;
    double _realHeight;
    double _ratio;
    NSString *_bgColorString;
    NSString *_themeBgColorString;
    double _topPadding;
    double _leftPadding;
    long long _pageNum;
}

+ (id)modelFromDictionary:(id)arg1 header:(id)arg2;
@property(nonatomic) long long pageNum; // @synthesize pageNum=_pageNum;
@property(nonatomic) _Bool shouldExtendEdge; // @synthesize shouldExtendEdge=_shouldExtendEdge;
@property(nonatomic) double leftPadding; // @synthesize leftPadding=_leftPadding;
@property(nonatomic) double topPadding; // @synthesize topPadding=_topPadding;
@property(nonatomic) _Bool isLandscape; // @synthesize isLandscape=_isLandscape;
@property(copy, nonatomic) NSString *themeBgColorString; // @synthesize themeBgColorString=_themeBgColorString;
@property(copy, nonatomic) NSString *bgColorString; // @synthesize bgColorString=_bgColorString;
@property(nonatomic) double ratio; // @synthesize ratio=_ratio;
@property(nonatomic) double realHeight; // @synthesize realHeight=_realHeight;
@property(nonatomic) double realWidth; // @synthesize realWidth=_realWidth;
@property(nonatomic) double realY; // @synthesize realY=_realY;
@property(nonatomic) double realX; // @synthesize realX=_realX;
@property(nonatomic) double originHeight; // @synthesize originHeight=_originHeight;
@property(nonatomic) double originWidth; // @synthesize originWidth=_originWidth;
@property(nonatomic) double originY; // @synthesize originY=_originY;
@property(nonatomic) double originX; // @synthesize originX=_originX;
@property(retain, nonatomic) NSDictionary *custom; // @synthesize custom=_custom;
@property(copy, nonatomic) NSString *modelName; // @synthesize modelName=_modelName;
@property(retain, nonatomic) NSArray *subviewModels; // @synthesize subviewModels=_subviewModels;
@property(nonatomic) float designHeight; // @synthesize designHeight=_designHeight;
@property(nonatomic) float designWidth; // @synthesize designWidth=_designWidth;
- (void).cxx_destruct;
- (id)preloadItemsWithPageNum:(unsigned long long)arg1;
- (id)initWithDictionary:(id)arg1 header:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

