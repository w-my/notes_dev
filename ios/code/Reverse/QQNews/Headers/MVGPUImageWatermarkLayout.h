//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MVGPUImageWatermarkLayout : NSObject
{
    _Bool _normalized;
    long long _horizontalAlignment;
    long long _verticalAlignment;
    long long _sizeFit;
    double _normalizedSize;
    struct CGPoint _padding;
}

+ (id)defaultLayout;
@property(nonatomic) double normalizedSize; // @synthesize normalizedSize=_normalizedSize;
@property(nonatomic) struct CGPoint padding; // @synthesize padding=_padding;
@property(nonatomic) long long sizeFit; // @synthesize sizeFit=_sizeFit;
@property(nonatomic) _Bool normalized; // @synthesize normalized=_normalized;
@property(nonatomic) long long verticalAlignment; // @synthesize verticalAlignment=_verticalAlignment;
@property(nonatomic) long long horizontalAlignment; // @synthesize horizontalAlignment=_horizontalAlignment;

@end

