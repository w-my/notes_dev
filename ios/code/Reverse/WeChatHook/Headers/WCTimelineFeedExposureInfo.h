//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSString;

@interface WCTimelineFeedExposureInfo : MMObject
{
    int _likeCount;
    int _commentCount;
    NSString *_feedId;
    double _exposurePosiY;
    double _exposureHeight;
    double _originPosiY;
    double _originHeight;
    double _realScreenHeight;
}

@property(nonatomic) int commentCount; // @synthesize commentCount=_commentCount;
@property(nonatomic) int likeCount; // @synthesize likeCount=_likeCount;
@property(nonatomic) double realScreenHeight; // @synthesize realScreenHeight=_realScreenHeight;
@property(nonatomic) double originHeight; // @synthesize originHeight=_originHeight;
@property(nonatomic) double originPosiY; // @synthesize originPosiY=_originPosiY;
@property(nonatomic) double exposureHeight; // @synthesize exposureHeight=_exposureHeight;
@property(nonatomic) double exposurePosiY; // @synthesize exposurePosiY=_exposurePosiY;
@property(retain, nonatomic) NSString *feedId; // @synthesize feedId=_feedId;
- (void).cxx_destruct;
- (double)getScreenExposurePercent;
- (double)getSelfExposurePercent;
- (id)toString;

@end

