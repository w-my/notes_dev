//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray;

@interface WCDBTableInfo : NSObject
{
    NSMutableArray *_schemas;
    NSMutableArray *_sequences;
}

- (void).cxx_destruct;
- (id)description;
- (void)addSequence:(id)arg1;
- (void)addSchema:(id)arg1;

@end
