//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNPlaceMark, QNReverseGeocoder;

@protocol QNReverseGeocoderDelegate <NSObject>
- (void)reverseGeocoder:(QNReverseGeocoder *)arg1 didFailWithError:(unsigned long long)arg2;
- (void)reverseGeocoder:(QNReverseGeocoder *)arg1 didFindPlacemark:(QNPlaceMark *)arg2;
@end

