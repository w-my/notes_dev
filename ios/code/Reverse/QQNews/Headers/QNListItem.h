//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "KBListItemInstancePotocol.h"
#import "NSCoding.h"
#import "NSCopying.h"
#import "QNModelProtocol.h"

@class CCardNodeType, NSArray, NSDate, NSObject<NSCoding>, NSString, QNListLabelImageItem, QNListRecommendFlagItem, QNUserItem;

@interface QNListItem : QNBaseModelObject <QNModelProtocol, KBListItemInstancePotocol, NSCopying, NSCoding>
{
    _Bool _isGifPlay;
    _Bool _showLongTitle;
    _Bool _showSource;
    _Bool _useOriginalUrl;
    _Bool _isDeleteArticle;
    _Bool _isHotRecommendNews;
    _Bool _isCrossArticle;
    _Bool _isPushNewsItem;
    _Bool _isHotNews;
    _Bool _isInsertedByRecommend;
    _Bool _openDetailClickRecommend;
    _Bool _isSensitive;
    _Bool _noNeedJs;
    _Bool _withGesture;
    _Bool _forceNotCached;
    _Bool _openBigImage;
    _Bool _emojiSwitch;
    _Bool _emojiRelatedSwitch;
    _Bool _commentGifSwitch;
    _Bool _enableCommentPic;
    _Bool _disableDelete;
    _Bool _disableDeclare;
    _Bool _disableDanmu;
    _Bool _disableCommentDislike;
    _Bool _forbidRedPacket;
    _Bool _forbidShowCommentNum;
    _Bool _forbidShowReadCount;
    _Bool _forbidFocus;
    _Bool _forbidExprAttitude;
    _Bool _forbidOriginalLink;
    _Bool _isVideoViaMVSDK;
    _Bool _enableCommentSyncWeibo;
    _Bool _enableCoverGifForAuto;
    _Bool _enableCoverGifForNonAuto;
    _Bool _enableGifRelatedSwitch;
    _Bool _isRelateRecomm;
    _Bool _smartPush;
    NSString *_idStr;
    NSString *_commentID;
    NSString *_articleVersion;
    NSString *_qishu;
    NSString *_title;
    NSString *_longTitle;
    NSString *_summary;
    NSString *_articleSource;
    NSString *_shortUrl;
    NSString *_origUrl;
    NSString *_time;
    double _timeStamp;
    double _pushTimestamp;
    long long _articleType;
    NSString *_extraArticleType;
    long long _picShowType;
    long long _articlePosition;
    NSString *_channel;
    NSString *_shareTitle;
    NSString *_shareContent;
    NSString *_pageJumpShareTitle;
    NSString *_pageJumpShareContent;
    unsigned long long _pageJumpType;
    NSString *_expid;
    NSArray *_thumbnails;
    NSArray *_landscapeThumbnails;
    NSArray *_thumbnailsBigPhoto;
    NSArray *_imageItemList;
    long long _imageCount;
    NSString *_photoShowType;
    NSString *_newsPicGifBig;
    NSString *_newsPicGifSmall;
    QNListRecommendFlagItem *_flagItem;
    NSArray *_flagItems;
    NSArray *_upFlagItems;
    QNListLabelImageItem *_labelImageItem;
    NSArray *_keywords;
    NSString *_flag;
    NSString *_dynamicDesc;
    NSString *_miniProgramWXShareUrl;
    long long _commentCount;
    NSDate *_readDate;
    NSString *_authorName;
    NSString *_authorID;
    NSString *_chlId;
    NSString *_chlName;
    NSString *_chlIcon;
    NSString *_openId;
    NSString *_omChlid;
    NSString *_originalMediaID;
    QNUserItem *_userItem;
    CCardNodeType *_omCard;
    NSObject<NSCoding> *_pluginData;
    long long _alg_version;
    NSString *_seq_no;
    NSString *_transparam;
    NSString *_reason;
    NSString *_recommendReason;
    NSString *_bucketId;
    NSArray *_dislikeOptions;
    long long _readState;
    long long _relateNewsTotalCount;
    long long _relateNewsExposeCount;
    NSString *_keyExposeChannel;
    NSString *_pageContextType;
    NSString *_pageAlgVersion;
    NSString *_pageArticleID;
    NSString *_pageArticleType;
    NSString *_pagePicShowType;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *pagePicShowType; // @synthesize pagePicShowType=_pagePicShowType;
@property(copy, nonatomic) NSString *pageArticleType; // @synthesize pageArticleType=_pageArticleType;
@property(copy, nonatomic) NSString *pageArticleID; // @synthesize pageArticleID=_pageArticleID;
@property(copy, nonatomic) NSString *pageAlgVersion; // @synthesize pageAlgVersion=_pageAlgVersion;
@property(copy, nonatomic) NSString *pageContextType; // @synthesize pageContextType=_pageContextType;
@property(copy, nonatomic) NSString *keyExposeChannel; // @synthesize keyExposeChannel=_keyExposeChannel;
@property(nonatomic) long long relateNewsExposeCount; // @synthesize relateNewsExposeCount=_relateNewsExposeCount;
@property(nonatomic) long long relateNewsTotalCount; // @synthesize relateNewsTotalCount=_relateNewsTotalCount;
@property(nonatomic) long long readState; // @synthesize readState=_readState;
@property(copy, nonatomic) NSArray *dislikeOptions; // @synthesize dislikeOptions=_dislikeOptions;
@property(copy, nonatomic) NSString *bucketId; // @synthesize bucketId=_bucketId;
@property(nonatomic) _Bool smartPush; // @synthesize smartPush=_smartPush;
@property(nonatomic) _Bool isRelateRecomm; // @synthesize isRelateRecomm=_isRelateRecomm;
@property(copy, nonatomic) NSString *recommendReason; // @synthesize recommendReason=_recommendReason;
@property(copy, nonatomic) NSString *reason; // @synthesize reason=_reason;
@property(copy, nonatomic) NSString *transparam; // @synthesize transparam=_transparam;
@property(copy, nonatomic) NSString *seq_no; // @synthesize seq_no=_seq_no;
@property(nonatomic) long long alg_version; // @synthesize alg_version=_alg_version;
@property(retain, nonatomic) NSObject<NSCoding> *pluginData; // @synthesize pluginData=_pluginData;
@property(retain, nonatomic) CCardNodeType *omCard; // @synthesize omCard=_omCard;
@property(retain, nonatomic) QNUserItem *userItem; // @synthesize userItem=_userItem;
@property(copy, nonatomic) NSString *originalMediaID; // @synthesize originalMediaID=_originalMediaID;
@property(copy, nonatomic) NSString *omChlid; // @synthesize omChlid=_omChlid;
@property(copy, nonatomic) NSString *openId; // @synthesize openId=_openId;
@property(copy, nonatomic) NSString *chlIcon; // @synthesize chlIcon=_chlIcon;
@property(copy, nonatomic) NSString *chlName; // @synthesize chlName=_chlName;
@property(copy, nonatomic) NSString *chlId; // @synthesize chlId=_chlId;
@property(copy, nonatomic) NSString *authorID; // @synthesize authorID=_authorID;
@property(copy, nonatomic) NSString *authorName; // @synthesize authorName=_authorName;
@property(nonatomic) _Bool enableGifRelatedSwitch; // @synthesize enableGifRelatedSwitch=_enableGifRelatedSwitch;
@property(nonatomic) _Bool enableCoverGifForNonAuto; // @synthesize enableCoverGifForNonAuto=_enableCoverGifForNonAuto;
@property(nonatomic) _Bool enableCoverGifForAuto; // @synthesize enableCoverGifForAuto=_enableCoverGifForAuto;
@property(nonatomic) _Bool enableCommentSyncWeibo; // @synthesize enableCommentSyncWeibo=_enableCommentSyncWeibo;
@property(nonatomic) _Bool isVideoViaMVSDK; // @synthesize isVideoViaMVSDK=_isVideoViaMVSDK;
@property(nonatomic) _Bool forbidOriginalLink; // @synthesize forbidOriginalLink=_forbidOriginalLink;
@property(nonatomic) _Bool forbidExprAttitude; // @synthesize forbidExprAttitude=_forbidExprAttitude;
@property(nonatomic) _Bool forbidFocus; // @synthesize forbidFocus=_forbidFocus;
@property(nonatomic) _Bool forbidShowReadCount; // @synthesize forbidShowReadCount=_forbidShowReadCount;
@property(nonatomic) _Bool forbidShowCommentNum; // @synthesize forbidShowCommentNum=_forbidShowCommentNum;
@property(nonatomic) _Bool forbidRedPacket; // @synthesize forbidRedPacket=_forbidRedPacket;
@property(nonatomic) _Bool disableCommentDislike; // @synthesize disableCommentDislike=_disableCommentDislike;
@property(nonatomic) _Bool disableDanmu; // @synthesize disableDanmu=_disableDanmu;
@property(nonatomic) _Bool disableDeclare; // @synthesize disableDeclare=_disableDeclare;
@property(nonatomic) _Bool disableDelete; // @synthesize disableDelete=_disableDelete;
@property(nonatomic) _Bool enableCommentPic; // @synthesize enableCommentPic=_enableCommentPic;
@property(nonatomic) _Bool commentGifSwitch; // @synthesize commentGifSwitch=_commentGifSwitch;
@property(nonatomic) _Bool emojiRelatedSwitch; // @synthesize emojiRelatedSwitch=_emojiRelatedSwitch;
@property(nonatomic) _Bool emojiSwitch; // @synthesize emojiSwitch=_emojiSwitch;
@property(nonatomic) _Bool openBigImage; // @synthesize openBigImage=_openBigImage;
@property(nonatomic) _Bool forceNotCached; // @synthesize forceNotCached=_forceNotCached;
@property(nonatomic) _Bool withGesture; // @synthesize withGesture=_withGesture;
@property(nonatomic) _Bool noNeedJs; // @synthesize noNeedJs=_noNeedJs;
@property(nonatomic) _Bool isSensitive; // @synthesize isSensitive=_isSensitive;
@property(nonatomic) _Bool openDetailClickRecommend; // @synthesize openDetailClickRecommend=_openDetailClickRecommend;
@property(nonatomic) _Bool isInsertedByRecommend; // @synthesize isInsertedByRecommend=_isInsertedByRecommend;
@property(nonatomic) _Bool isHotNews; // @synthesize isHotNews=_isHotNews;
@property(nonatomic) _Bool isPushNewsItem; // @synthesize isPushNewsItem=_isPushNewsItem;
@property(nonatomic) _Bool isCrossArticle; // @synthesize isCrossArticle=_isCrossArticle;
@property(nonatomic) _Bool isHotRecommendNews; // @synthesize isHotRecommendNews=_isHotRecommendNews;
@property(nonatomic) _Bool isDeleteArticle; // @synthesize isDeleteArticle=_isDeleteArticle;
@property(nonatomic) _Bool useOriginalUrl; // @synthesize useOriginalUrl=_useOriginalUrl;
@property(nonatomic) _Bool showSource; // @synthesize showSource=_showSource;
@property(nonatomic) _Bool showLongTitle; // @synthesize showLongTitle=_showLongTitle;
@property(retain, nonatomic) NSDate *readDate; // @synthesize readDate=_readDate;
@property(nonatomic) _Bool isGifPlay; // @synthesize isGifPlay=_isGifPlay;
@property(nonatomic) long long commentCount; // @synthesize commentCount=_commentCount;
@property(copy, nonatomic) NSString *miniProgramWXShareUrl; // @synthesize miniProgramWXShareUrl=_miniProgramWXShareUrl;
@property(copy, nonatomic) NSString *dynamicDesc; // @synthesize dynamicDesc=_dynamicDesc;
@property(copy, nonatomic) NSString *flag; // @synthesize flag=_flag;
@property(copy, nonatomic) NSArray *keywords; // @synthesize keywords=_keywords;
@property(retain, nonatomic) QNListLabelImageItem *labelImageItem; // @synthesize labelImageItem=_labelImageItem;
@property(copy, nonatomic) NSArray *upFlagItems; // @synthesize upFlagItems=_upFlagItems;
@property(copy, nonatomic) NSArray *flagItems; // @synthesize flagItems=_flagItems;
@property(retain, nonatomic) QNListRecommendFlagItem *flagItem; // @synthesize flagItem=_flagItem;
@property(copy, nonatomic) NSString *newsPicGifSmall; // @synthesize newsPicGifSmall=_newsPicGifSmall;
@property(copy, nonatomic) NSString *newsPicGifBig; // @synthesize newsPicGifBig=_newsPicGifBig;
@property(copy, nonatomic) NSString *photoShowType; // @synthesize photoShowType=_photoShowType;
@property(nonatomic) long long imageCount; // @synthesize imageCount=_imageCount;
@property(copy, nonatomic) NSArray *imageItemList; // @synthesize imageItemList=_imageItemList;
@property(copy, nonatomic) NSArray *thumbnailsBigPhoto; // @synthesize thumbnailsBigPhoto=_thumbnailsBigPhoto;
@property(copy, nonatomic) NSArray *landscapeThumbnails; // @synthesize landscapeThumbnails=_landscapeThumbnails;
@property(copy, nonatomic) NSArray *thumbnails; // @synthesize thumbnails=_thumbnails;
@property(copy, nonatomic) NSString *expid; // @synthesize expid=_expid;
@property(nonatomic) unsigned long long pageJumpType; // @synthesize pageJumpType=_pageJumpType;
@property(copy, nonatomic) NSString *pageJumpShareContent; // @synthesize pageJumpShareContent=_pageJumpShareContent;
@property(copy, nonatomic) NSString *pageJumpShareTitle; // @synthesize pageJumpShareTitle=_pageJumpShareTitle;
@property(copy, nonatomic) NSString *shareContent; // @synthesize shareContent=_shareContent;
@property(copy, nonatomic) NSString *shareTitle; // @synthesize shareTitle=_shareTitle;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
@property(nonatomic) long long articlePosition; // @synthesize articlePosition=_articlePosition;
@property(nonatomic) long long picShowType; // @synthesize picShowType=_picShowType;
@property(copy, nonatomic) NSString *extraArticleType; // @synthesize extraArticleType=_extraArticleType;
@property(nonatomic) long long articleType; // @synthesize articleType=_articleType;
@property(nonatomic) double pushTimestamp; // @synthesize pushTimestamp=_pushTimestamp;
@property(nonatomic) double timeStamp; // @synthesize timeStamp=_timeStamp;
@property(copy, nonatomic) NSString *time; // @synthesize time=_time;
@property(copy, nonatomic) NSString *origUrl; // @synthesize origUrl=_origUrl;
@property(copy, nonatomic) NSString *shortUrl; // @synthesize shortUrl=_shortUrl;
@property(copy, nonatomic) NSString *articleSource; // @synthesize articleSource=_articleSource;
@property(copy, nonatomic) NSString *summary; // @synthesize summary=_summary;
@property(copy, nonatomic) NSString *longTitle; // @synthesize longTitle=_longTitle;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *qishu; // @synthesize qishu=_qishu;
@property(copy, nonatomic) NSString *articleVersion; // @synthesize articleVersion=_articleVersion;
@property(copy, nonatomic) NSString *commentID; // @synthesize commentID=_commentID;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
- (void).cxx_destruct;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
- (_Bool)isEqual:(id)arg1;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
@property(readonly, nonatomic) long long pushDislikeType; // @dynamic pushDislikeType;
@property(readonly, nonatomic) _Bool isStickTop; // @dynamic isStickTop;
@property(nonatomic) long long readCount; // @dynamic readCount;
@property(nonatomic) long long shareCount; // @dynamic shareCount;
@property(nonatomic) long long followCount; // @dynamic followCount;
- (id)supportString;
@property(nonatomic) long long supportCount;
@property(nonatomic) _Bool supported; // @dynamic supported;
- (void)loadHasReadState;
- (_Bool)p_canPushToHistory;
@property(nonatomic) _Bool hasRead; // @dynamic hasRead;
- (id)modelId;
- (_Bool)isGameVertical;
- (_Bool)isAdvertisement;
- (_Bool)isTAD;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end
