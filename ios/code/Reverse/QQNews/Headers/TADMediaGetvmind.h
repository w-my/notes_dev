//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface TADMediaGetvmind : NSObject
{
    NSMutableDictionary *_blockMap;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSMutableDictionary *blockMap; // @synthesize blockMap=_blockMap;
- (void).cxx_destruct;
- (_Bool)isValidAdURLString:(id)arg1;
- (void)callbackWith:(id)arg1 items:(id)arg2 error:(id)arg3;
- (void)loadVideoSourceFailed:(id)arg1;
- (void)loadVideoSourceFinished:(id)arg1 data:(id)arg2;
- (id)vidToUrlWith:(id)arg1 videoInfo:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)cancelTask:(id)arg1;
- (id)init;

@end
