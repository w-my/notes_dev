//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSString;

@interface QNAdDetailOnOffControlItem : QNAutoCodingCopyingObject
{
    _Bool _openPicAds;
    _Bool _openAdsText;
    _Bool _openAdsPhotos;
    _Bool _openAdsRelated;
    _Bool _openAdsComment;
    _Bool _openSubAdsText;
    NSString *_idStr;
    NSString *_channelId;
    NSString *_commentPlacementId;
    NSString *_subAdsPlacementId;
}

@property(copy, nonatomic) NSString *subAdsPlacementId; // @synthesize subAdsPlacementId=_subAdsPlacementId;
@property(nonatomic) _Bool openSubAdsText; // @synthesize openSubAdsText=_openSubAdsText;
@property(copy, nonatomic) NSString *commentPlacementId; // @synthesize commentPlacementId=_commentPlacementId;
@property(nonatomic) _Bool openAdsComment; // @synthesize openAdsComment=_openAdsComment;
@property(nonatomic) _Bool openAdsRelated; // @synthesize openAdsRelated=_openAdsRelated;
@property(nonatomic) _Bool openAdsPhotos; // @synthesize openAdsPhotos=_openAdsPhotos;
@property(nonatomic) _Bool openAdsText; // @synthesize openAdsText=_openAdsText;
@property(nonatomic) _Bool openPicAds; // @synthesize openPicAds=_openPicAds;
@property(copy, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
- (void).cxx_destruct;
- (id)initWithArticleId:(id)arg1 channelId:(id)arg2 Info:(id)arg3;

@end

