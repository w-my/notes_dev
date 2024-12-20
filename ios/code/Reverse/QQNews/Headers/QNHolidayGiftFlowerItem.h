//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class CImageLoader, NSString, UIImage;

@interface QNHolidayGiftFlowerItem : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_full;
    NSString *_fullMd5;
    unsigned long long _count;
    double _scaleWidth;
    double _startTime;
    double _endTime;
    double _imageScale;
    long long _tryCount;
    UIImage *_image;
    CImageLoader *_loader;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(retain, nonatomic) CImageLoader *loader; // @synthesize loader=_loader;
@property(retain, nonatomic) UIImage *image; // @synthesize image=_image;
@property(nonatomic) long long tryCount; // @synthesize tryCount=_tryCount;
@property(nonatomic) double imageScale; // @synthesize imageScale=_imageScale;
@property(nonatomic) double endTime; // @synthesize endTime=_endTime;
@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
@property(nonatomic) double scaleWidth; // @synthesize scaleWidth=_scaleWidth;
@property(nonatomic) unsigned long long count; // @synthesize count=_count;
@property(copy, nonatomic) NSString *fullMd5; // @synthesize fullMd5=_fullMd5;
@property(copy, nonatomic) NSString *full; // @synthesize full=_full;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (void)cancel;
- (void)loadImage;
- (void)checkNeedLoadData;
- (void)prepareData;
- (int)checkDataState:(long long)arg1;

@end

