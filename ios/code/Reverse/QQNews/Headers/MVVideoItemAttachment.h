//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface MVVideoItemAttachment : NSObject <NSCoding, NSCopying>
{
    unsigned long long _source;
    long long _filterID;
    NSString *_motionID;
    long long _recordOrientation;
    long long _cameraPosition;
}

@property(nonatomic) long long cameraPosition; // @synthesize cameraPosition=_cameraPosition;
@property(nonatomic) long long recordOrientation; // @synthesize recordOrientation=_recordOrientation;
@property(retain, nonatomic) NSString *motionID; // @synthesize motionID=_motionID;
@property(nonatomic) long long filterID; // @synthesize filterID=_filterID;
@property(nonatomic) unsigned long long source; // @synthesize source=_source;
- (void).cxx_destruct;
- (id)debugInformation;
- (id)description;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end
