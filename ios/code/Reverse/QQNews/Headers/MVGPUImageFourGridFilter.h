//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageFourInputFilter.h"

@interface MVGPUImageFourGridFilter : GPUImageFourInputFilter
{
    int _highlightedAreaUniform;
    long long _highlightedArea;
}

+ (id)clearFramebufferWithSize:(struct CGSize)arg1;
+ (id)highlightedFilter;
+ (id)filter;
@property(nonatomic) int highlightedAreaUniform; // @synthesize highlightedAreaUniform=_highlightedAreaUniform;
@property(nonatomic) long long highlightedArea; // @synthesize highlightedArea=_highlightedArea;

@end
