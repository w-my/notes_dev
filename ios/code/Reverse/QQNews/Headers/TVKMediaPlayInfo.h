//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableArray, NSString, TVKDrmModel, TVKFileInfo, TVKLiveSeeBackBaseInfo, TVKMediaInfo, TVKPlayContext, TVKWaterMarkModel;

@interface TVKMediaPlayInfo : NSObject
{
    _Bool _videoPlayInfoReady;
    _Bool _isP2PPlayMode;
    _Bool _isP2POfflinePlay;
    _Bool _isP2p;
    _Bool _needPay;
    _Bool _isUserPay;
    _Bool _hasVipResolution;
    _Bool _isHevc;
    _Bool _isCdnEncrypt;
    _Bool _isDolby;
    int _playType;
    int _speed;
    int _playId;
    unsigned int _fileSize;
    int _videoState;
    int _mediaState;
    int _chargeState;
    int _stream;
    int _live360;
    int _acode;
    int _vcode;
    int _hlsp2p;
    int _urlIndex;
    float _aspectRatio;
    int _mediaType;
    int _exem;
    NSString *_vid;
    NSString *_coverId;
    NSMutableArray *_videoUrlsArray;
    NSMutableArray *_offlineToOnlinevideoUrlsArray;
    NSMutableArray *_videoTimesArray;
    NSArray *_thumbInfoArray;
    long long _dltype;
    long long _videoType;
    long long _preDltype;
    double _initialPlayedTime;
    double _jumpEndPlayedTimeInterval;
    long long _currentIndex;
    double _livePreviewTime;
    long long _livePreviewCount;
    long long _liveRestPreviewCount;
    double _liveTotalPlayTime;
    long long _liveErroCode;
    long long _vkeyValidInterval;
    double _duration;
    NSString *_lnk;
    NSString *_tstId;
    TVKLiveSeeBackBaseInfo *_seeBackBaseInfo;
    NSString *_vInfoJson;
    double _vodPreviewStart;
    double _vodPreViewTime;
    long long _clip;
    long long _type;
    long long _rate;
    NSString *_ip;
    NSArray *_fiInfoArray;
    TVKFileInfo *_currentDefinition;
    TVKFileInfo *_preDefinition;
    long long _queueStatus;
    long long _queueRank;
    long long _queueVipJump;
    NSString *_queueSessionKey;
    TVKWaterMarkModel *_waterMarkModel;
    long long _programType;
    long long _businessType;
    NSString *_vt;
    NSString *_cdnIp;
    NSString *_cdnUIp;
    NSString *_currentPlayCDNUrl;
    long long _vr;
    NSArray *_subTitleModelArray;
    TVKMediaInfo *_mediaInfo;
    TVKPlayContext *_playContext;
    NSString *_flowId;
    TVKDrmModel *_drmModel;
    struct CGSize _videoSize;
}

+ (id)nameOfMediaType:(int)arg1;
@property(retain, nonatomic) TVKDrmModel *drmModel; // @synthesize drmModel=_drmModel;
@property(nonatomic) int exem; // @synthesize exem=_exem;
@property(copy, nonatomic) NSString *flowId; // @synthesize flowId=_flowId;
@property(retain, nonatomic) TVKPlayContext *playContext; // @synthesize playContext=_playContext;
@property(nonatomic) int mediaType; // @synthesize mediaType=_mediaType;
@property(retain, nonatomic) TVKMediaInfo *mediaInfo; // @synthesize mediaInfo=_mediaInfo;
@property(retain, nonatomic) NSArray *subTitleModelArray; // @synthesize subTitleModelArray=_subTitleModelArray;
@property(nonatomic) struct CGSize videoSize; // @synthesize videoSize=_videoSize;
@property(nonatomic) float aspectRatio; // @synthesize aspectRatio=_aspectRatio;
@property(nonatomic) long long vr; // @synthesize vr=_vr;
@property(nonatomic) _Bool isDolby; // @synthesize isDolby=_isDolby;
@property(copy) NSString *currentPlayCDNUrl; // @synthesize currentPlayCDNUrl=_currentPlayCDNUrl;
@property int urlIndex; // @synthesize urlIndex=_urlIndex;
@property(copy) NSString *cdnUIp; // @synthesize cdnUIp=_cdnUIp;
@property(copy) NSString *cdnIp; // @synthesize cdnIp=_cdnIp;
@property(nonatomic) _Bool isCdnEncrypt; // @synthesize isCdnEncrypt=_isCdnEncrypt;
@property(copy) NSString *vt; // @synthesize vt=_vt;
@property(nonatomic) long long businessType; // @synthesize businessType=_businessType;
@property(nonatomic) long long programType; // @synthesize programType=_programType;
@property(nonatomic) _Bool isHevc; // @synthesize isHevc=_isHevc;
@property(retain, nonatomic) TVKWaterMarkModel *waterMarkModel; // @synthesize waterMarkModel=_waterMarkModel;
@property(nonatomic) int hlsp2p; // @synthesize hlsp2p=_hlsp2p;
@property(nonatomic) int vcode; // @synthesize vcode=_vcode;
@property(nonatomic) int acode; // @synthesize acode=_acode;
@property(nonatomic) int live360; // @synthesize live360=_live360;
@property(nonatomic) int stream; // @synthesize stream=_stream;
@property(copy, nonatomic) NSString *queueSessionKey; // @synthesize queueSessionKey=_queueSessionKey;
@property(nonatomic) long long queueVipJump; // @synthesize queueVipJump=_queueVipJump;
@property(nonatomic) long long queueRank; // @synthesize queueRank=_queueRank;
@property(nonatomic) long long queueStatus; // @synthesize queueStatus=_queueStatus;
@property(nonatomic) int chargeState; // @synthesize chargeState=_chargeState;
@property(retain, nonatomic) TVKFileInfo *preDefinition; // @synthesize preDefinition=_preDefinition;
@property(retain, nonatomic) TVKFileInfo *currentDefinition; // @synthesize currentDefinition=_currentDefinition;
@property(retain) NSArray *fiInfoArray; // @synthesize fiInfoArray=_fiInfoArray;
@property(copy) NSString *ip; // @synthesize ip=_ip;
@property(nonatomic) int mediaState; // @synthesize mediaState=_mediaState;
@property(nonatomic) int videoState; // @synthesize videoState=_videoState;
@property(nonatomic) long long rate; // @synthesize rate=_rate;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(nonatomic) long long clip; // @synthesize clip=_clip;
@property(nonatomic) double vodPreViewTime; // @synthesize vodPreViewTime=_vodPreViewTime;
@property(nonatomic) double vodPreviewStart; // @synthesize vodPreviewStart=_vodPreviewStart;
@property(copy, nonatomic) NSString *vInfoJson; // @synthesize vInfoJson=_vInfoJson;
@property(retain, nonatomic) TVKLiveSeeBackBaseInfo *seeBackBaseInfo; // @synthesize seeBackBaseInfo=_seeBackBaseInfo;
@property(copy) NSString *tstId; // @synthesize tstId=_tstId;
@property(copy, nonatomic) NSString *lnk; // @synthesize lnk=_lnk;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(nonatomic) long long vkeyValidInterval; // @synthesize vkeyValidInterval=_vkeyValidInterval;
@property(nonatomic) unsigned int fileSize; // @synthesize fileSize=_fileSize;
@property(nonatomic) _Bool hasVipResolution; // @synthesize hasVipResolution=_hasVipResolution;
@property(nonatomic) long long liveErroCode; // @synthesize liveErroCode=_liveErroCode;
@property(nonatomic) double liveTotalPlayTime; // @synthesize liveTotalPlayTime=_liveTotalPlayTime;
@property(nonatomic) long long liveRestPreviewCount; // @synthesize liveRestPreviewCount=_liveRestPreviewCount;
@property(nonatomic) long long livePreviewCount; // @synthesize livePreviewCount=_livePreviewCount;
@property(nonatomic) double livePreviewTime; // @synthesize livePreviewTime=_livePreviewTime;
@property(nonatomic) _Bool isUserPay; // @synthesize isUserPay=_isUserPay;
@property(nonatomic) _Bool needPay; // @synthesize needPay=_needPay;
@property(nonatomic) int playId; // @synthesize playId=_playId;
@property(nonatomic) int speed; // @synthesize speed=_speed;
@property _Bool isP2p; // @synthesize isP2p=_isP2p;
@property(nonatomic) _Bool isP2POfflinePlay; // @synthesize isP2POfflinePlay=_isP2POfflinePlay;
@property(nonatomic) _Bool isP2PPlayMode; // @synthesize isP2PPlayMode=_isP2PPlayMode;
@property(nonatomic) _Bool videoPlayInfoReady; // @synthesize videoPlayInfoReady=_videoPlayInfoReady;
@property(nonatomic) long long currentIndex; // @synthesize currentIndex=_currentIndex;
@property(nonatomic) double jumpEndPlayedTimeInterval; // @synthesize jumpEndPlayedTimeInterval=_jumpEndPlayedTimeInterval;
@property(nonatomic) double initialPlayedTime; // @synthesize initialPlayedTime=_initialPlayedTime;
@property long long preDltype; // @synthesize preDltype=_preDltype;
@property long long videoType; // @synthesize videoType=_videoType;
@property long long dltype; // @synthesize dltype=_dltype;
@property(retain) NSArray *thumbInfoArray; // @synthesize thumbInfoArray=_thumbInfoArray;
@property(retain) NSMutableArray *videoTimesArray; // @synthesize videoTimesArray=_videoTimesArray;
@property(retain) NSMutableArray *offlineToOnlinevideoUrlsArray; // @synthesize offlineToOnlinevideoUrlsArray=_offlineToOnlinevideoUrlsArray;
@property(retain) NSMutableArray *videoUrlsArray; // @synthesize videoUrlsArray=_videoUrlsArray;
@property(nonatomic) int playType; // @synthesize playType=_playType;
@property(copy) NSString *coverId; // @synthesize coverId=_coverId;
@property(copy) NSString *vid; // @synthesize vid=_vid;
- (void).cxx_destruct;
@property(readonly, nonatomic) unsigned long long bizType;
- (_Bool)isAudioOnly;
- (_Bool)isHLS;
- (_Bool)isMp4;
- (void)checkIPv6AndUpdateUrl;
- (id)arrayOfSortedDefinition;
- (id)nextDefinition;
- (id)nextDefinitionName;
@property(readonly, nonatomic) _Bool isPreWatch;
@property(readonly, nonatomic) double vodPreViewEnd;
- (long long)countMP4Order:(double)arg1;
- (void)resetMediaPlayInfo;
- (void)resetCurVideoReleatedPlayInfoOnly;
- (void)resetPlayMediaInfo;
- (void)resetSearchLocal;
- (void)dealloc;
- (id)init;

@end

