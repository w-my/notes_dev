//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface TADQNAppLinkDetector : NSObject
{
    NSArray *_appIdRegexList;
}

+ (id)sharedInstance;
@property(copy, nonatomic) NSArray *appIdRegexList; // @synthesize appIdRegexList=_appIdRegexList;
- (void).cxx_destruct;
- (id)appIdFromLink:(id)arg1;
- (id)init;

@end

