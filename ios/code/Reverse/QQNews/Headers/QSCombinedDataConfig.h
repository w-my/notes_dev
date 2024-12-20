//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError;

@interface QSCombinedDataConfig : NSObject
{
    _Bool _useCache;
    _Bool _needUpdate;
    _Bool _isCacheReady;
    _Bool _isAllReady;
    _Bool _isUpdating;
    NSError *_error;
}

+ (id)combinedDataConfigWithCache:(_Bool)arg1 needUpdate:(_Bool)arg2;
@property(retain, nonatomic) NSError *error; // @synthesize error=_error;
@property(nonatomic) _Bool isUpdating; // @synthesize isUpdating=_isUpdating;
@property(nonatomic) _Bool isAllReady; // @synthesize isAllReady=_isAllReady;
@property(nonatomic) _Bool isCacheReady; // @synthesize isCacheReady=_isCacheReady;
@property(nonatomic) _Bool needUpdate; // @synthesize needUpdate=_needUpdate;
@property(nonatomic) _Bool useCache; // @synthesize useCache=_useCache;
- (void).cxx_destruct;

@end

