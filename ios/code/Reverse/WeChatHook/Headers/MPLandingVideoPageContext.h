//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MPLandingPageOpenParameter, MPLandingPageRespInitParam, MPLandingVideoErrorInfo, MPLandingVideoInfo, NSString, UIImage;

@interface MPLandingVideoPageContext : NSObject
{
    _Bool _hasHandlePageInitParam;
    _Bool _isIngoreOversize;
    _Bool _isPlayAuto;
    _Bool _isStartPlay;
    _Bool _isVideoBeginPlay;
    _Bool _isVideoStartPlayFail;
    _Bool _isPlayingBeforeShowOversizeTips;
    unsigned int _enterId;
    unsigned int _sessionId;
    NSString *_originalUrl;
    MPLandingPageOpenParameter *_openParam;
    MPLandingPageRespInitParam *_respInitParam;
    MPLandingVideoInfo *_videoInfo;
}

@property(nonatomic) _Bool isPlayingBeforeShowOversizeTips; // @synthesize isPlayingBeforeShowOversizeTips=_isPlayingBeforeShowOversizeTips;
@property(nonatomic) _Bool isVideoStartPlayFail; // @synthesize isVideoStartPlayFail=_isVideoStartPlayFail;
@property(nonatomic) _Bool isVideoBeginPlay; // @synthesize isVideoBeginPlay=_isVideoBeginPlay;
@property(nonatomic) _Bool isStartPlay; // @synthesize isStartPlay=_isStartPlay;
@property(nonatomic) _Bool isPlayAuto; // @synthesize isPlayAuto=_isPlayAuto;
@property(nonatomic) _Bool isIngoreOversize; // @synthesize isIngoreOversize=_isIngoreOversize;
@property(nonatomic) unsigned int sessionId; // @synthesize sessionId=_sessionId;
@property(nonatomic) unsigned int enterId; // @synthesize enterId=_enterId;
@property(retain, nonatomic) MPLandingVideoInfo *videoInfo; // @synthesize videoInfo=_videoInfo;
@property(nonatomic) _Bool hasHandlePageInitParam; // @synthesize hasHandlePageInitParam=_hasHandlePageInitParam;
@property(retain, nonatomic) MPLandingPageRespInitParam *respInitParam; // @synthesize respInitParam=_respInitParam;
@property(retain, nonatomic) MPLandingPageOpenParameter *openParam; // @synthesize openParam=_openParam;
@property(copy, nonatomic) NSString *originalUrl; // @synthesize originalUrl=_originalUrl;
- (void).cxx_destruct;
@property(readonly, nonatomic) MPLandingVideoErrorInfo *videoErroInfo;
@property(readonly, nonatomic) NSString *redirectUrl;
@property(readonly, nonatomic) _Bool shouldAutoPlay;
@property(readonly, nonatomic) _Bool isSvrRetOversize;
@property(readonly, nonatomic) _Bool isVerticalVideo;
@property(readonly, nonatomic) double thumbImageAspectRatio;
@property(readonly, nonatomic) double videoAspectRatio;
@property(readonly, nonatomic) NSString *videoUrl;
@property(readonly, nonatomic) NSString *title;
@property(readonly, nonatomic) struct CGRect thumbOriginRect;
@property(readonly, nonatomic) UIImage *thumbImage;
- (void)updateWithOpenParam:(id)arg1;
- (id)initWithOpenParam:(id)arg1 enterId:(unsigned int)arg2 sessionId:(unsigned int)arg3;

@end

