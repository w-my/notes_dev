//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray;

@interface WSRecommendColikeTempModel : NSObject
{
    _Bool _continueFlag;
    int _type;
    unsigned int _totalCount;
    unsigned int _updateFlag;
    NSMutableArray *_colikeList;
    unsigned long long _version;
}

@property(nonatomic) _Bool continueFlag; // @synthesize continueFlag=_continueFlag;
@property(nonatomic) unsigned long long version; // @synthesize version=_version;
@property(nonatomic) unsigned int updateFlag; // @synthesize updateFlag=_updateFlag;
@property(nonatomic) unsigned int totalCount; // @synthesize totalCount=_totalCount;
@property(nonatomic) int type; // @synthesize type=_type;
@property(retain, nonatomic) NSMutableArray *colikeList; // @synthesize colikeList=_colikeList;
- (void).cxx_destruct;

@end

