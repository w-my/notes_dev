//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "LKImageProcessor.h"

@interface LKImagePredrawProcessor : LKImageProcessor
{
    unsigned long long _scaleMode;
    struct CGSize _size;
    struct CGPoint _anchorPoint;
}

@property(nonatomic) struct CGPoint anchorPoint; // @synthesize anchorPoint=_anchorPoint;
@property(nonatomic) struct CGSize size; // @synthesize size=_size;
@property(nonatomic) unsigned long long scaleMode; // @synthesize scaleMode=_scaleMode;
- (void)process:(id)arg1 request:(id)arg2 complete:(CDUnknownBlockType)arg3;
- (id)identify;

@end

