//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QOverlayPathView.h"

@class QPolygon;

@interface QPolygonView : QOverlayPathView
{
}

- (void)setFillColor:(id)arg1;
- (void)setLineWidth:(double)arg1;
- (void)setStrokeColor:(id)arg1;
@property(readonly, nonatomic) QPolygon *polygon;
- (id)initWithPolygon:(id)arg1;

@end

