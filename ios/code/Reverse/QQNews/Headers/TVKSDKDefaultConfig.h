//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, NSString;

@interface TVKSDKDefaultConfig : NSObject
{
    NSMutableDictionary *_configDict;
    NSString *_defaultPlistPath;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (void)removeValueForKey:(id)arg1;
- (id)arrayValueForKey:(id)arg1;
- (id)dictValueForKey:(id)arg1;
- (_Bool)boolValueForKey:(id)arg1;
- (int)intValueForKey:(id)arg1;
- (_Bool)hasValueForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (void)setInt:(int)arg1 forKey:(id)arg2;
- (void)setBool:(_Bool)arg1 forKey:(id)arg2;
- (void)createDefaultPlist;
- (id)defaultPlistPath;
- (void)readDefaultConfig;
- (id)init;

@end

