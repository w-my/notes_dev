//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString;

@interface CURLParser : NSObject
{
    NSMutableArray *_variables;
    NSString *_host;
    NSString *_fragment;
}

@property(copy, nonatomic) NSString *fragment; // @synthesize fragment=_fragment;
@property(copy, nonatomic) NSString *host; // @synthesize host=_host;
@property(retain, nonatomic) NSMutableArray *variables; // @synthesize variables=_variables;
- (void).cxx_destruct;
- (id)getURL;
- (id)getURLString;
- (void)addVariable:(id)arg1;
- (id)valueForVariable:(id)arg1 options:(unsigned long long)arg2;
- (id)valueForVariable:(id)arg1;
- (id)initWithURL:(id)arg1;
- (id)initWithURLString:(id)arg1;
- (void)initInternal:(id)arg1;

@end
