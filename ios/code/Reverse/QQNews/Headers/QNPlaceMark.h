//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface QNPlacemark : NSObject
{
    NSString *_city;
    NSString *_name;
    NSString *_address;
    NSString *_inaccuracyAddress;
    long long _sourceType;
    NSArray *_QNPoiInfoArray;
    NSString *_adcode;
    struct CLLocationCoordinate2D _coordinate;
    struct CLLocationCoordinate2D _origin;
}

@property(readonly, copy, nonatomic) NSString *adcode; // @synthesize adcode=_adcode;
@property(readonly, copy, nonatomic) NSArray *QNPoiInfoArray; // @synthesize QNPoiInfoArray=_QNPoiInfoArray;
@property(readonly, nonatomic) long long sourceType; // @synthesize sourceType=_sourceType;
@property(readonly, copy, nonatomic) NSString *inaccuracyAddress; // @synthesize inaccuracyAddress=_inaccuracyAddress;
@property(readonly, copy, nonatomic) NSString *address; // @synthesize address=_address;
@property(readonly, copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(readonly, copy, nonatomic) NSString *city; // @synthesize city=_city;
@property(readonly, nonatomic) struct CLLocationCoordinate2D origin; // @synthesize origin=_origin;
@property(readonly, nonatomic) struct CLLocationCoordinate2D coordinate; // @synthesize coordinate=_coordinate;
- (void).cxx_destruct;
- (id)description;
- (id)initWithCLPlacemark:(id)arg1 origin:(struct CLLocationCoordinate2D)arg2;
- (id)initWithQNPlacemark:(id)arg1 origin:(struct CLLocationCoordinate2D)arg2;

@end
