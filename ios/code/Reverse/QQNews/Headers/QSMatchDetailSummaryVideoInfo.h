//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, NSString, QSMatchDetailAdvertiseLinkModel, QSMatchDetailAfterVideosItem;

@interface QSMatchDetailSummaryVideoInfo : NSObject
{
    _Bool _dynamicDisplayType;
    QSMatchDetailAfterVideosItem *_afterVideos;
    QSMatchDetailAfterVideosItem *_afterRecord;
    QSMatchDetailAdvertiseLinkModel *_advertiseLink;
    long long _currentPlayVideoType;
    NSString *_currentPlayVideoVid;
    long long _displayVideoType;
    NSMutableDictionary *_videoTypeOffsets;
}

@property(retain, nonatomic) NSMutableDictionary *videoTypeOffsets; // @synthesize videoTypeOffsets=_videoTypeOffsets;
@property(nonatomic) _Bool dynamicDisplayType; // @synthesize dynamicDisplayType=_dynamicDisplayType;
@property(nonatomic) long long displayVideoType; // @synthesize displayVideoType=_displayVideoType;
@property(copy, nonatomic) NSString *currentPlayVideoVid; // @synthesize currentPlayVideoVid=_currentPlayVideoVid;
@property(nonatomic) long long currentPlayVideoType; // @synthesize currentPlayVideoType=_currentPlayVideoType;
@property(retain, nonatomic) QSMatchDetailAdvertiseLinkModel *advertiseLink; // @synthesize advertiseLink=_advertiseLink;
@property(retain, nonatomic) QSMatchDetailAfterVideosItem *afterRecord; // @synthesize afterRecord=_afterRecord;
@property(retain, nonatomic) QSMatchDetailAfterVideosItem *afterVideos; // @synthesize afterVideos=_afterVideos;
- (void).cxx_destruct;
- (struct CGPoint)displayVideoTypeOffset;
- (void)setOffset:(struct CGPoint)arg1 withType:(long long)arg2;
- (id)playNextVideo;
- (long long)indexOfCurrentPlayVideo;
- (id)currentPlayVideo;
- (id)currentDisplayVideos;
@property(readonly, nonatomic) _Bool hasVideo; // @dynamic hasVideo;
- (void)videosDidUpdate;
- (id)init;

@end
