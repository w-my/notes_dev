//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCItemGpuImageFilterGroup.h"

@class MCAdvancedMeshElement, MCAdvancedMeshFilter, MCBaseFilter, MCCommonFilter, NSArray;

@interface MCAdvancedMeshFilterGroup : MCItemGpuImageFilterGroup
{
    MCAdvancedMeshElement *_element;
    MCBaseFilter *_meshFilter;
    NSArray *_cutoutFilters;
    MCCommonFilter *_commonFilter;
    MCAdvancedMeshFilter *_advMeshFilter;
}

@property(retain, nonatomic) MCAdvancedMeshFilter *advMeshFilter; // @synthesize advMeshFilter=_advMeshFilter;
@property(retain, nonatomic) MCCommonFilter *commonFilter; // @synthesize commonFilter=_commonFilter;
@property(retain, nonatomic) NSArray *cutoutFilters; // @synthesize cutoutFilters=_cutoutFilters;
@property(retain, nonatomic) MCBaseFilter *meshFilter; // @synthesize meshFilter=_meshFilter;
@property(retain, nonatomic) MCAdvancedMeshElement *element; // @synthesize element=_element;
- (void).cxx_destruct;
- (void)setHandBoxes:(id)arg1;
- (void)setFaceAnalyzers:(id)arg1;
- (void)setTmplItem:(id)arg1;
- (void)setupEnviroment;
- (void)cleanFilterChainTargets;
- (void)dealloc;
- (id)initWithMeshFilters:(id)arg1;

@end

