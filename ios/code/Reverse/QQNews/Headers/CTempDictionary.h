//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface CTempDictionary : NSObject
{
    NSMutableDictionary *_dataDictionary;
}

+ (id)sharedTempDictionary;
@property(retain, nonatomic) NSMutableDictionary *dataDictionary; // @synthesize dataDictionary=_dataDictionary;
- (void).cxx_destruct;
- (id)objectForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (void)removeObjectForKey:(id)arg1;
- (void)writeToLocal;
- (void)readFromLocal;
- (id)p_tempDictioanryPath;
- (id)init;

@end

