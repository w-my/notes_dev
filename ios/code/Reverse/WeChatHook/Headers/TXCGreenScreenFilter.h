//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCFilter.h"

@class NSString;

@interface TXCGreenScreenFilter : TXCFilter
{
    _Bool _mirror;
    long long _fillMode;
    NSString *_greenPath;
}

@property(retain, nonatomic) NSString *greenPath; // @synthesize greenPath=_greenPath;
@property(nonatomic) long long fillMode; // @synthesize fillMode=_fillMode;
@property(nonatomic) _Bool mirror; // @synthesize mirror=_mirror;
- (void).cxx_destruct;
- (id)initWithPath:(id)arg1;

@end

