//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageFilter.h"

@interface MVImageMirrorFilter : GPUImageFilter
{
    _Bool _horizontally;
    _Bool _vertically;
}

@property(readonly, nonatomic) _Bool vertically; // @synthesize vertically=_vertically;
@property(readonly, nonatomic) _Bool horizontally; // @synthesize horizontally=_horizontally;
- (id)initWithHorizontally:(_Bool)arg1 vertically:(_Bool)arg2;

@end

