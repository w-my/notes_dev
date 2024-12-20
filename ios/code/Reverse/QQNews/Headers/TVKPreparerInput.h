//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSString, TVKMediaInfo, TVKPlayContext;

@interface TVKPreparerInput : NSObject
{
    _Bool _needCharge;
    _Bool _isDrm;
    _Bool _isFairPlay;
    _Bool _isDlna;
    _Bool _notAllowDomainVideoUrl;
    _Bool _useDolby;
    _Bool _allowDolbyVision;
    int _mediaType;
    int _hevcLevel;
    NSString *_vid;
    NSString *_cid;
    NSString *_format;
    NSDictionary *_extraParams;
    NSString *_freeFlowString;
    double _startPosition;
    double _skipEndPosition;
    TVKMediaInfo *_mediaInfo;
    TVKPlayContext *_playContext;
}

@property(retain, nonatomic) TVKPlayContext *playContext; // @synthesize playContext=_playContext;
@property(retain, nonatomic) TVKMediaInfo *mediaInfo; // @synthesize mediaInfo=_mediaInfo;
@property(nonatomic) _Bool allowDolbyVision; // @synthesize allowDolbyVision=_allowDolbyVision;
@property(nonatomic) _Bool useDolby; // @synthesize useDolby=_useDolby;
@property(nonatomic) _Bool notAllowDomainVideoUrl; // @synthesize notAllowDomainVideoUrl=_notAllowDomainVideoUrl;
@property(nonatomic) int hevcLevel; // @synthesize hevcLevel=_hevcLevel;
@property(nonatomic) _Bool isDlna; // @synthesize isDlna=_isDlna;
@property(nonatomic) double skipEndPosition; // @synthesize skipEndPosition=_skipEndPosition;
@property(nonatomic) double startPosition; // @synthesize startPosition=_startPosition;
@property(copy, nonatomic) NSString *freeFlowString; // @synthesize freeFlowString=_freeFlowString;
@property(retain, nonatomic) NSDictionary *extraParams; // @synthesize extraParams=_extraParams;
@property(nonatomic) _Bool isFairPlay; // @synthesize isFairPlay=_isFairPlay;
@property(nonatomic) _Bool isDrm; // @synthesize isDrm=_isDrm;
@property(nonatomic) _Bool needCharge; // @synthesize needCharge=_needCharge;
@property(nonatomic) int mediaType; // @synthesize mediaType=_mediaType;
@property(copy, nonatomic) NSString *format; // @synthesize format=_format;
@property(copy, nonatomic) NSString *cid; // @synthesize cid=_cid;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
- (void).cxx_destruct;
- (id)init;

@end

