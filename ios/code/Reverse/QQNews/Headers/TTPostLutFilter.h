//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MultiFilterConnect.h"

@class NSString;

@interface TTPostLutFilter : MultiFilterConnect
{
    NSString *_lutName;
    double _strength;
}

@property(nonatomic) double strength; // @synthesize strength=_strength;
@property(retain, nonatomic) NSString *lutName; // @synthesize lutName=_lutName;
- (void).cxx_destruct;
- (void)NewFilter;
- (id)initWithLutName:(id)arg1 andStrength:(double)arg2;
- (id)init;

@end

