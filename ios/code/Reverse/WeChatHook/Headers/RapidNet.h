//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class RapidNetCPU, RapidNetMetal;

@interface RapidNet : NSObject
{
    _Bool _hasLoadNetMetal;
    RapidNetCPU *_netCpu;
    RapidNetMetal *_netMetal;
}

+ (void)enableImageDebug;
+ (id)gpuLibraryPath;
+ (_Bool)isGPUDeviceAvailable;
@property(nonatomic) _Bool hasLoadNetMetal; // @synthesize hasLoadNetMetal=_hasLoadNetMetal;
@property(retain, nonatomic) RapidNetMetal *netMetal; // @synthesize netMetal=_netMetal;
@property(retain, nonatomic) RapidNetCPU *netCpu; // @synthesize netCpu=_netCpu;
- (void).cxx_destruct;
- (id)forwardWithCNNImage:(id)arg1 commandBuffer:(id)arg2 error:(id *)arg3;
- (struct Mat)forwardWithCvMat:(const struct Mat *)arg1 error:(id *)arg2;
- (void)preloadForDataDimension:(struct CNNDimension)arg1 netInputDimension:(struct CNNDimension)arg2;
- (id)loadGPUWithDevice:(id)arg1 library:(id)arg2;
- (id)loadGPU;
- (id)initWithProto:(id)arg1 model:(id)arg2;
- (Class)rapidNetMetalClass;
- (Class)rapidNetCPUClass;

@end

