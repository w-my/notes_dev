//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCFilter.h"

@interface TXCVEFLinearShadowFilter : TXCFilter
{
    unsigned int _enabledUniform;
    unsigned int _cUniform;
    unsigned int _modeUniform;
    unsigned int _widthUniform;
    unsigned int _strideUniform;
    unsigned int _alphaUniform;
    double _mode;
    double _alpha;
    double _offset;
    double _width;
    double _stride;
}

@property(nonatomic) double stride; // @synthesize stride=_stride;
@property(nonatomic) double width; // @synthesize width=_width;
@property(nonatomic) double offset; // @synthesize offset=_offset;
@property(nonatomic) double alpha; // @synthesize alpha=_alpha;
- (void)setupEnabled;
@property(nonatomic) unsigned long long mode;
- (id)init;

@end

