//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface WXVoiceTRJsonParser : NSObject
{
    NSString *error;
    unsigned long long depth;
    unsigned long long maxDepth;
}

@property(copy) NSString *error; // @synthesize error;
@property unsigned long long maxDepth; // @synthesize maxDepth;
- (id)objectWithString:(id)arg1 error:(id *)arg2;
- (id)objectWithString:(id)arg1;
- (id)objectWithData:(id)arg1;
- (void)dealloc;
- (id)init;

@end

