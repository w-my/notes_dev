//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSNumber, NSString, TADDP3ReportItem;

@interface TADHttpRequestItem : NSObject
{
    NSArray *_channels;
    NSArray *_loids;
    NSNumber *_loadType;
    NSNumber *_timeoutSeconds;
    NSArray *_loidStrs;
    TADDP3ReportItem *_dp3Item;
    NSString *_mediaId;
    NSString *_articleId;
}

+ (id)itemWithChannels:(id)arg1 loids:(id)arg2;
@property(copy, nonatomic) NSString *articleId; // @synthesize articleId=_articleId;
@property(copy, nonatomic) NSString *mediaId; // @synthesize mediaId=_mediaId;
@property(retain, nonatomic) TADDP3ReportItem *dp3Item; // @synthesize dp3Item=_dp3Item;
@property(retain, nonatomic) NSArray *loidStrs; // @synthesize loidStrs=_loidStrs;
@property(retain, nonatomic) NSNumber *timeoutSeconds; // @synthesize timeoutSeconds=_timeoutSeconds;
@property(retain, nonatomic) NSNumber *loadType; // @synthesize loadType=_loadType;
@property(retain, nonatomic) NSArray *loids; // @synthesize loids=_loids;
@property(retain, nonatomic) NSArray *channels; // @synthesize channels=_channels;
- (void).cxx_destruct;
- (id)paramsForRequest;

@end
