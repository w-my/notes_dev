//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoWordingStyleElement.h"

@class MVVideoWordingAnimationFrameRange, MVVideoWordingTime, NSString;

@interface MVVideoWordingSpriteSheetItem : MVVideoWordingStyleElement
{
    MVVideoWordingAnimationFrameRange *_range;
    MVVideoWordingTime *_time;
    NSString *_frameName;
    NSString *_directory;
    struct CGPoint _position;
    struct CGPoint _anchor_point;
}

@property(retain, nonatomic) NSString *directory; // @synthesize directory=_directory;
@property(retain, nonatomic) NSString *frameName; // @synthesize frameName=_frameName;
@property(nonatomic) struct CGPoint anchor_point; // @synthesize anchor_point=_anchor_point;
@property(nonatomic) struct CGPoint position; // @synthesize position=_position;
@property(retain, nonatomic) MVVideoWordingTime *time; // @synthesize time=_time;
@property(retain, nonatomic) MVVideoWordingAnimationFrameRange *range; // @synthesize range=_range;
- (void).cxx_destruct;
- (id)imageAtPercent:(double)arg1;
- (id)imageAtTime:(double)arg1 ofPercent:(double)arg2;
- (void)removeImages;
- (void)loadImages;
- (id)initWithDataSource:(id)arg1;

@end
