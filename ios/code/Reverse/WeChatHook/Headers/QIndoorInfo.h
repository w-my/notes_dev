//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QIndoorInfo : NSObject
{
    NSString *_buildUid;
    NSString *_levelName;
}

@property(readonly, copy, nonatomic) NSString *levelName; // @synthesize levelName=_levelName;
@property(readonly, copy, nonatomic) NSString *buildUid; // @synthesize buildUid=_buildUid;
- (void).cxx_destruct;
- (id)initWithBuildUid:(id)arg1 levelName:(id)arg2;

@end

