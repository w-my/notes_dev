//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface MVFilterFactory : NSObject
{
    NSArray *_allFilters;
    NSArray *_filtersForCamera;
    NSArray *_filtersForAlbum;
}

+ (id)filterWithFilterID:(long long)arg1;
+ (id)sharedFactory;
@property(retain, nonatomic) NSArray *filtersForAlbum; // @synthesize filtersForAlbum=_filtersForAlbum;
@property(retain, nonatomic) NSArray *filtersForCamera; // @synthesize filtersForCamera=_filtersForCamera;
@property(retain, nonatomic) NSArray *allFilters; // @synthesize allFilters=_allFilters;
- (void).cxx_destruct;
- (id)makeAllFilters;
- (void)initFiltersForAlbum;
- (void)initFiltersForCamera;
- (id)init;

@end
