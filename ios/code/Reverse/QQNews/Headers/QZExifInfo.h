//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSDictionary, NSMutableDictionary, NSString;

@interface QZExifInfo : NSObject <NSCoding>
{
    NSString *_cameraMaker;
    NSString *_cameraModel;
    NSString *_exifTime;
    NSString *_latitudeRef;
    NSString *_latitude;
    NSString *_longitudeRef;
    NSString *_longitude;
    NSDictionary *_exifDic;
    NSMutableDictionary *_mapParams;
}

@property(retain, nonatomic) NSMutableDictionary *mapParams; // @synthesize mapParams=_mapParams;
@property(retain, nonatomic) NSDictionary *exifDic; // @synthesize exifDic=_exifDic;
@property(retain, nonatomic) NSString *longitude; // @synthesize longitude=_longitude;
@property(retain, nonatomic) NSString *longitudeRef; // @synthesize longitudeRef=_longitudeRef;
@property(retain, nonatomic) NSString *latitude; // @synthesize latitude=_latitude;
@property(retain, nonatomic) NSString *latitudeRef; // @synthesize latitudeRef=_latitudeRef;
@property(retain, nonatomic) NSString *exifTime; // @synthesize exifTime=_exifTime;
@property(retain, nonatomic) NSString *cameraModel; // @synthesize cameraModel=_cameraModel;
@property(retain, nonatomic) NSString *cameraMaker; // @synthesize cameraMaker=_cameraMaker;
- (void).cxx_destruct;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)dealloc;

@end

