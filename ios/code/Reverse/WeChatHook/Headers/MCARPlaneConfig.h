//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface MCARPlaneConfig : NSObject
{
    _Bool _isClickAddModel;
    _Bool _hasMaterialAnimation;
    double _boundingBoxMaxLength;
    unsigned long long _animationRepeatTimes;
    unsigned long long _materialType;
    unsigned long long _locationType;
    NSArray *_materialList;
}

@property(retain, nonatomic) NSArray *materialList; // @synthesize materialList=_materialList;
@property(nonatomic) unsigned long long locationType; // @synthesize locationType=_locationType;
@property(nonatomic) unsigned long long materialType; // @synthesize materialType=_materialType;
@property(nonatomic) unsigned long long animationRepeatTimes; // @synthesize animationRepeatTimes=_animationRepeatTimes;
@property(nonatomic) double boundingBoxMaxLength; // @synthesize boundingBoxMaxLength=_boundingBoxMaxLength;
@property(nonatomic) _Bool hasMaterialAnimation; // @synthesize hasMaterialAnimation=_hasMaterialAnimation;
@property(nonatomic) _Bool isClickAddModel; // @synthesize isClickAddModel=_isClickAddModel;
- (void).cxx_destruct;
- (id)initWithDictionary:(id)arg1 item:(id)arg2 folderName:(id)arg3;

@end

