//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface PaintEffectHandle : NSObject
{
    float bokeh_weight;
    float bokeh_threshold;
    float bokeh_parameter;
    struct CGRect _ROI;
}

+ (void)smoothBorder:(struct _Image *)arg1;
+ (void)blurMask:(struct _Image *)arg1;
@property(nonatomic) struct CGRect ROI; // @synthesize ROI=_ROI;
- (id)bokehPatternNameList;
- (id)bokehImage:(id)arg1 withPattern:(struct _Image *)arg2 mask:(struct _Image *)arg3;
- (id)patternAtIndex:(long long)arg1;
- (long long)patternCount;
- (void)setWeight:(float)arg1 threshold:(float)arg2 parameter:(float)arg3;
- (id)dofImage:(id)arg1 withMask:(struct _Image *)arg2;
- (id)init;

@end

