//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSString;

@interface QNOneGifItem : QNAutoCodingCopyingObject
{
    _Bool _isLoading;
    NSString *_imageUrl;
    NSString *_thumbnailUrl;
    long long _imageSize;
    double _loadingProgress;
    NSString *_imageIndex;
    struct CGSize _size;
}

@property(copy, nonatomic) NSString *imageIndex; // @synthesize imageIndex=_imageIndex;
@property(nonatomic) double loadingProgress; // @synthesize loadingProgress=_loadingProgress;
@property(nonatomic) _Bool isLoading; // @synthesize isLoading=_isLoading;
@property(nonatomic) long long imageSize; // @synthesize imageSize=_imageSize;
@property(nonatomic) struct CGSize size; // @synthesize size=_size;
@property(copy, nonatomic) NSString *thumbnailUrl; // @synthesize thumbnailUrl=_thumbnailUrl;
@property(copy, nonatomic) NSString *imageUrl; // @synthesize imageUrl=_imageUrl;
- (void).cxx_destruct;
- (id)initWithInfo:(id)arg1;

@end

