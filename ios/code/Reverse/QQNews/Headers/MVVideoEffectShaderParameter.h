//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TTObject.h"

#import "NSCoding.h"

@class NSString;

@interface MVVideoEffectShaderParameter : TTObject <NSCoding>
{
    NSString *_name;
    double _value_begin;
    double _value_end;
}

@property(nonatomic) double value_end; // @synthesize value_end=_value_end;
@property(nonatomic) double value_begin; // @synthesize value_begin=_value_begin;
@property(retain, nonatomic) NSString *name; // @synthesize name=_name;
- (void).cxx_destruct;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end
