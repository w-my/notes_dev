//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

#import "QNAdEntity.h"

@class NSArray, NSNumber, NSString, QNTADVideoItemInfo, TADDP3ReportItem, TADGDTPageLoadingItem, TADItemInfo;

@interface QNAdItem : QNAutoCodingCopyingObject <QNAdEntity>
{
    _Bool _isEmpty;
    _Bool _showUnlikeBtn;
    _Bool _isFullScreenClick;
    _Bool _hideShareBtn;
    _Bool _isGDTItem;
    _Bool _posBeyondNewslist;
    _Bool _isSpecialAd;
    NSString *_type;
    NSString *_articleSource;
    NSString *_text;
    NSString *_imageUrlString;
    NSString *_channel;
    NSString *_title;
    NSString *_longTitle;
    NSString *_shareTitle;
    NSString *_abstract;
    NSString *_uoid;
    NSString *_oid;
    NSString *_cid;
    NSString *_soid;
    NSString *_locationId;
    NSString *_navTitle;
    NSString *_thumbnail;
    NSString *_iconStr;
    NSString *_downloadIcon;
    NSString *_adIcon;
    NSString *_vid;
    NSString *_h5Url;
    double _duration;
    long long _seq;
    long long _section;
    long long _flowDirection;
    long long _landPageType;
    long long _index;
    TADDP3ReportItem *_reportItem;
    long long _adSubType;
    double _videoMargin;
    double _videoCoverWidth;
    double _videoVolume;
    QNTADVideoItemInfo *_videoInfo;
    NSArray *_videoStatusReportUrls;
    TADItemInfo *_tadItem;
    NSString *_uuid;
    double _imageWidth;
    double _imageHeight;
    NSString *_gifUrl;
    NSNumber *_gifSize;
    unsigned long long _actType;
    NSString *_mediaId;
    NSArray *_imgUrlList;
    NSString *_openScheme;
    NSString *_anchorId;
    NSString *_commentId;
    NSString *_commentSum;
    NSNumber *_commentEnabled;
    NSString *_newsID;
    NSString *_crnewsID;
    NSString *_dspName;
    double _margin;
    NSNumber *_adSponsorId;
    NSNumber *_productId;
    NSNumber *_productType;
    NSNumber *_industryId;
    NSNumber *_replaceType;
    NSNumber *_refreshType;
    long long _articleType;
    NSString *_extraReportUrl;
    long long _playerType;
    TADGDTPageLoadingItem *_imageLoadingItem;
}

@property(retain, nonatomic) TADGDTPageLoadingItem *imageLoadingItem; // @synthesize imageLoadingItem=_imageLoadingItem;
@property(nonatomic) long long playerType; // @synthesize playerType=_playerType;
@property(nonatomic) _Bool isSpecialAd; // @synthesize isSpecialAd=_isSpecialAd;
@property(copy, nonatomic) NSString *extraReportUrl; // @synthesize extraReportUrl=_extraReportUrl;
@property(nonatomic) long long articleType; // @synthesize articleType=_articleType;
@property(nonatomic) _Bool posBeyondNewslist; // @synthesize posBeyondNewslist=_posBeyondNewslist;
@property(retain, nonatomic) NSNumber *refreshType; // @synthesize refreshType=_refreshType;
@property(retain, nonatomic) NSNumber *replaceType; // @synthesize replaceType=_replaceType;
@property(nonatomic) _Bool isGDTItem; // @synthesize isGDTItem=_isGDTItem;
@property(retain, nonatomic) NSNumber *industryId; // @synthesize industryId=_industryId;
@property(retain, nonatomic) NSNumber *productType; // @synthesize productType=_productType;
@property(retain, nonatomic) NSNumber *productId; // @synthesize productId=_productId;
@property(retain, nonatomic) NSNumber *adSponsorId; // @synthesize adSponsorId=_adSponsorId;
@property(nonatomic) _Bool hideShareBtn; // @synthesize hideShareBtn=_hideShareBtn;
@property(nonatomic) double margin; // @synthesize margin=_margin;
@property(copy, nonatomic) NSString *dspName; // @synthesize dspName=_dspName;
@property(copy, nonatomic) NSString *crnewsID; // @synthesize crnewsID=_crnewsID;
@property(copy, nonatomic) NSString *newsID; // @synthesize newsID=_newsID;
@property(copy, nonatomic) NSNumber *commentEnabled; // @synthesize commentEnabled=_commentEnabled;
@property(copy, nonatomic) NSString *commentSum; // @synthesize commentSum=_commentSum;
@property(copy, nonatomic) NSString *commentId; // @synthesize commentId=_commentId;
@property(copy, nonatomic) NSString *anchorId; // @synthesize anchorId=_anchorId;
@property(nonatomic) _Bool isFullScreenClick; // @synthesize isFullScreenClick=_isFullScreenClick;
@property(copy, nonatomic) NSString *openScheme; // @synthesize openScheme=_openScheme;
@property(retain, nonatomic) NSArray *imgUrlList; // @synthesize imgUrlList=_imgUrlList;
@property(copy, nonatomic) NSString *mediaId; // @synthesize mediaId=_mediaId;
@property(nonatomic) unsigned long long actType; // @synthesize actType=_actType;
@property(retain, nonatomic) NSNumber *gifSize; // @synthesize gifSize=_gifSize;
@property(copy, nonatomic) NSString *gifUrl; // @synthesize gifUrl=_gifUrl;
@property(nonatomic) double imageHeight; // @synthesize imageHeight=_imageHeight;
@property(nonatomic) double imageWidth; // @synthesize imageWidth=_imageWidth;
@property(copy, nonatomic) NSString *uuid; // @synthesize uuid=_uuid;
@property(retain, nonatomic) TADItemInfo *tadItem; // @synthesize tadItem=_tadItem;
@property(retain, nonatomic) NSArray *videoStatusReportUrls; // @synthesize videoStatusReportUrls=_videoStatusReportUrls;
@property(nonatomic) _Bool showUnlikeBtn; // @synthesize showUnlikeBtn=_showUnlikeBtn;
@property(retain, nonatomic) QNTADVideoItemInfo *videoInfo; // @synthesize videoInfo=_videoInfo;
@property(nonatomic) double videoVolume; // @synthesize videoVolume=_videoVolume;
@property(nonatomic) double videoCoverWidth; // @synthesize videoCoverWidth=_videoCoverWidth;
@property(nonatomic) double videoMargin; // @synthesize videoMargin=_videoMargin;
@property(nonatomic) long long adSubType; // @synthesize adSubType=_adSubType;
@property(retain, nonatomic) TADDP3ReportItem *reportItem; // @synthesize reportItem=_reportItem;
@property(nonatomic) long long index; // @synthesize index=_index;
@property(nonatomic) _Bool isEmpty; // @synthesize isEmpty=_isEmpty;
@property(nonatomic) long long landPageType; // @synthesize landPageType=_landPageType;
@property(nonatomic) long long flowDirection; // @synthesize flowDirection=_flowDirection;
@property(nonatomic) long long section; // @synthesize section=_section;
@property(nonatomic) long long seq; // @synthesize seq=_seq;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(copy, nonatomic) NSString *h5Url; // @synthesize h5Url=_h5Url;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(copy, nonatomic) NSString *adIcon; // @synthesize adIcon=_adIcon;
@property(copy, nonatomic) NSString *downloadIcon; // @synthesize downloadIcon=_downloadIcon;
@property(copy, nonatomic) NSString *iconStr; // @synthesize iconStr=_iconStr;
@property(copy, nonatomic) NSString *thumbnail; // @synthesize thumbnail=_thumbnail;
@property(copy, nonatomic) NSString *navTitle; // @synthesize navTitle=_navTitle;
@property(copy, nonatomic) NSString *locationId; // @synthesize locationId=_locationId;
@property(copy, nonatomic) NSString *soid; // @synthesize soid=_soid;
@property(copy, nonatomic) NSString *cid; // @synthesize cid=_cid;
@property(copy, nonatomic) NSString *oid; // @synthesize oid=_oid;
@property(copy, nonatomic) NSString *uoid; // @synthesize uoid=_uoid;
@property(copy, nonatomic) NSString *abstract; // @synthesize abstract=_abstract;
@property(copy, nonatomic) NSString *shareTitle; // @synthesize shareTitle=_shareTitle;
@property(copy, nonatomic) NSString *longTitle; // @synthesize longTitle=_longTitle;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
- (void).cxx_destruct;
- (id)videoItem;
- (id)imageNode;
- (id)getCustomShareInfo;
@property(readonly, copy, nonatomic) NSString *abtestString;
- (void)calcualteRelateMatchForIdstrs:(id)arg1;
- (_Bool)isClickForSchemeOpen;
- (id)traceAdShareSourceUrl:(id)arg1 shareActivityType:(long long)arg2;
- (long long)openAppStatus;
- (_Bool)openInLandingView;
- (_Bool)canOpenMiniProgramAd;
- (_Bool)isMiniProgramAd;
- (_Bool)isWXDirectLinkAd;
- (_Bool)useVideoImmersePage;
- (_Bool)isCanvasAd;
- (_Bool)isNativeAd;
- (_Bool)isCMPOrder;
@property(nonatomic) _Bool isSSPItem;
- (_Bool)p_isInWhiteList;
- (_Bool)p_isOpenSchemeInstalled;
- (_Bool)p_isOpenSchemeIgnored;
- (_Bool)p_isOpenSchemeSupported;
- (_Bool)isOpenSchemeInLandingAd;
- (_Bool)isOpenSchemeAd;
- (_Bool)isDownloadAd;
- (struct CGSize)scaledImageSizeForOriginSize:(struct CGSize)arg1;
- (void)refreshWithCurrentTADItem;
@property(readonly) unsigned long long hash;
- (_Bool)isEqual:(id)arg1;
- (_Bool)isEqualToAdItem:(id)arg1;
- (void)modifyType:(id)arg1;
- (void)modifyArticleSource:(id)arg1;
@property(readonly, copy, nonatomic) NSString *articleSource; // @synthesize articleSource=_articleSource;
@property(readonly, copy, nonatomic) NSString *type; // @synthesize type=_type;
@property(readonly, copy, nonatomic) NSString *text; // @synthesize text=_text;
@property(readonly, copy, nonatomic) NSString *imageUrlString; // @synthesize imageUrlString=_imageUrlString;
- (id)listItem;
@property(readonly, nonatomic) long long entityType;
- (id)splashItem;
- (_Bool)isOrderValid;
- (_Bool)isDataValid;
- (void)configWithAdDict:(id)arg1;
- (id)initWithInfo:(id)arg1;
- (id)adItemForClickType:(long long)arg1;
- (_Bool)p_need200Return;
- (void)initClickUrl;
- (id)gdtClickUrlForUrlType:(long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end
