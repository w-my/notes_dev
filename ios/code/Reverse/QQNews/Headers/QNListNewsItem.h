//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListItem.h"

#import "NSCoding.h"
#import "NSCopying.h"
#import "QNShareableAudio.h"
#import "QNShareableNews.h"
#import "QNShareableText.h"

@class NSArray, NSMutableDictionary, NSObject<NSCoding>, NSString, QNActivityItem, QNAudioInfoItem, QNCommentItem, QNDeDaoCourseModel, QNExclusiveListItem, QNListModuleItem, QNListWeiboItem, QNLiveVideoItem, QNLiveVideoSpecialEntranceItem, QNModuleDocumentaryList, QNMyNewsCellSpecialInfo, QNNowLiveItem, QNRadioInfoItem, QNTopicItem, QNVideoItem, QNWeiboRelationItem;

@interface QNListNewsItem : QNListItem <QNShareableText, QNShareableNews, QNShareableAudio, NSCopying, NSCoding>
{
    _Bool _listCellHtmlUseJson;
    _Bool _firstPage;
    _Bool _isLive;
    _Bool _hasVideo;
    _Bool _isSupportVR;
    _Bool _showCommentView;
    _Bool _roseRoomWebTabexist;
    _Bool _isPay;
    _Bool _hasAudio;
    _Bool _showLiveLike;
    _Bool _haveTrailer;
    _Bool _havePlayBackVideo;
    _Bool _isLiveVideoHasPlayed;
    _Bool _isExist;
    _Bool _specialLayout;
    _Bool _isTitleThreeLinesCalculated;
    _Bool _isTitleThreeLines;
    _Bool _isOverlengthAssistantViewCalculated;
    _Bool _isOverlengthAssistantView;
    double _listCellHeight;
    NSString *_listCellHtmlStr;
    NSString *_listCellHtmlUrl;
    NSArray *_tag;
    NSString *_adTitle;
    NSString *_linkDesc;
    NSString *_groupId;
    NSString *_focusNewsId;
    NSString *_hideWording;
    unsigned long long _ballotId;
    unsigned long long _ballotOpinionCount;
    NSString *_topicArticleDesc;
    long long _videoNumOfAlbum;
    NSString *_albumTitle;
    NSString *_videoTime;
    NSString *_fadcid;
    NSString *_videoCategory;
    NSString *_demoVideoName;
    NSString *_graphicLiveID;
    NSString *_titleHeadWords;
    QNVideoItem *_videoItem;
    QNNowLiveItem *_nowLiveItem;
    QNModuleDocumentaryList *_documentary;
    QNLiveVideoItem *_liveVideoItem;
    QNLiveVideoSpecialEntranceItem *_liveVideoSpecialEntranceItem;
    NSArray *_videoCommentItems;
    NSString *_roseLiveID;
    NSString *_roseLiveType;
    NSString *_roseLiveVideoID;
    long long _roseBannerType;
    QNAudioInfoItem *_audioInfo;
    QNRadioInfoItem *_radioInfoItem;
    QNTopicItem *_topicItem;
    NSString *_topicTitle;
    NSArray *_topicList;
    QNListWeiboItem *_weiboItem;
    QNWeiboRelationItem *_relationItem;
    NSString *_specialID;
    NSString *_origSpecialID;
    long long _specialCount;
    QNCommentItem *_answerItem;
    QNCommentItem *_firstComment;
    NSString *_expertWording;
    NSArray *_expertList;
    NSArray *_matchList;
    NSString *_sportsTargetId;
    NSString *_sportsExt;
    NSString *_worldCupExt;
    unsigned long long _verticalCellType;
    NSArray *_circleItems;
    QNMyNewsCellSpecialInfo *_myNewsCellInfo;
    QNListModuleItem *_moduleItem;
    NSArray *_userInterestItems;
    QNExclusiveListItem *_exclusiveListItem;
    QNActivityItem *_activityItem;
    QNDeDaoCourseModel *_course;
    NSArray *_nestItems;
    NSArray *_omDataList;
    long long _articlePage;
    NSString *_topicTag;
    NSString *_hotWord;
    NSString *_hotWordEnterFrom;
    double _recommendIconWidth;
    long long _videoHitCount;
    NSString *_recommendIconDay;
    NSString *_recommendIconNight;
    NSObject<NSCoding> *_extendObj;
    NSMutableDictionary *_addtionData;
    NSString *_dataSourceType;
    double _recvTime;
    long long _privateTag;
    QNListModuleItem *_parentModuleItem;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) __weak QNListModuleItem *parentModuleItem; // @synthesize parentModuleItem=_parentModuleItem;
@property(nonatomic) long long privateTag; // @synthesize privateTag=_privateTag;
@property(nonatomic) double recvTime; // @synthesize recvTime=_recvTime;
@property(copy, nonatomic) NSString *dataSourceType; // @synthesize dataSourceType=_dataSourceType;
@property(retain, nonatomic) NSMutableDictionary *addtionData; // @synthesize addtionData=_addtionData;
@property(retain, nonatomic) NSObject<NSCoding> *extendObj; // @synthesize extendObj=_extendObj;
@property(nonatomic) _Bool isOverlengthAssistantView; // @synthesize isOverlengthAssistantView=_isOverlengthAssistantView;
@property(nonatomic) _Bool isOverlengthAssistantViewCalculated; // @synthesize isOverlengthAssistantViewCalculated=_isOverlengthAssistantViewCalculated;
@property(nonatomic) _Bool isTitleThreeLines; // @synthesize isTitleThreeLines=_isTitleThreeLines;
@property(nonatomic) _Bool isTitleThreeLinesCalculated; // @synthesize isTitleThreeLinesCalculated=_isTitleThreeLinesCalculated;
@property(copy, nonatomic) NSString *recommendIconNight; // @synthesize recommendIconNight=_recommendIconNight;
@property(copy, nonatomic) NSString *recommendIconDay; // @synthesize recommendIconDay=_recommendIconDay;
@property(nonatomic) _Bool specialLayout; // @synthesize specialLayout=_specialLayout;
@property(nonatomic) _Bool isExist; // @synthesize isExist=_isExist;
@property(nonatomic) _Bool isLiveVideoHasPlayed; // @synthesize isLiveVideoHasPlayed=_isLiveVideoHasPlayed;
@property(nonatomic) long long videoHitCount; // @synthesize videoHitCount=_videoHitCount;
@property(nonatomic) _Bool havePlayBackVideo; // @synthesize havePlayBackVideo=_havePlayBackVideo;
@property(nonatomic) _Bool haveTrailer; // @synthesize haveTrailer=_haveTrailer;
@property(nonatomic) _Bool showLiveLike; // @synthesize showLiveLike=_showLiveLike;
@property(nonatomic) double recommendIconWidth; // @synthesize recommendIconWidth=_recommendIconWidth;
@property(copy, nonatomic) NSString *hotWordEnterFrom; // @synthesize hotWordEnterFrom=_hotWordEnterFrom;
@property(copy, nonatomic) NSString *hotWord; // @synthesize hotWord=_hotWord;
@property(copy, nonatomic) NSString *topicTag; // @synthesize topicTag=_topicTag;
@property(nonatomic) long long articlePage; // @synthesize articlePage=_articlePage;
@property(copy, nonatomic) NSArray *omDataList; // @synthesize omDataList=_omDataList;
@property(copy, nonatomic) NSArray *nestItems; // @synthesize nestItems=_nestItems;
@property(retain, nonatomic) QNDeDaoCourseModel *course; // @synthesize course=_course;
@property(retain, nonatomic) QNActivityItem *activityItem; // @synthesize activityItem=_activityItem;
@property(retain, nonatomic) QNExclusiveListItem *exclusiveListItem; // @synthesize exclusiveListItem=_exclusiveListItem;
@property(copy, nonatomic) NSArray *userInterestItems; // @synthesize userInterestItems=_userInterestItems;
@property(retain, nonatomic) QNListModuleItem *moduleItem; // @synthesize moduleItem=_moduleItem;
@property(retain, nonatomic) QNMyNewsCellSpecialInfo *myNewsCellInfo; // @synthesize myNewsCellInfo=_myNewsCellInfo;
@property(copy, nonatomic) NSArray *circleItems; // @synthesize circleItems=_circleItems;
@property(nonatomic) unsigned long long verticalCellType; // @synthesize verticalCellType=_verticalCellType;
@property(copy, nonatomic) NSString *worldCupExt; // @synthesize worldCupExt=_worldCupExt;
@property(copy, nonatomic) NSString *sportsExt; // @synthesize sportsExt=_sportsExt;
@property(copy, nonatomic) NSString *sportsTargetId; // @synthesize sportsTargetId=_sportsTargetId;
@property(copy, nonatomic) NSArray *matchList; // @synthesize matchList=_matchList;
@property(copy, nonatomic) NSArray *expertList; // @synthesize expertList=_expertList;
@property(copy, nonatomic) NSString *expertWording; // @synthesize expertWording=_expertWording;
@property(retain, nonatomic) QNCommentItem *firstComment; // @synthesize firstComment=_firstComment;
@property(retain, nonatomic) QNCommentItem *answerItem; // @synthesize answerItem=_answerItem;
@property(nonatomic) long long specialCount; // @synthesize specialCount=_specialCount;
@property(copy, nonatomic) NSString *origSpecialID; // @synthesize origSpecialID=_origSpecialID;
@property(copy, nonatomic) NSString *specialID; // @synthesize specialID=_specialID;
@property(retain, nonatomic) QNWeiboRelationItem *relationItem; // @synthesize relationItem=_relationItem;
@property(retain, nonatomic) QNListWeiboItem *weiboItem; // @synthesize weiboItem=_weiboItem;
@property(copy, nonatomic) NSArray *topicList; // @synthesize topicList=_topicList;
@property(copy, nonatomic) NSString *topicTitle; // @synthesize topicTitle=_topicTitle;
@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(retain, nonatomic) QNRadioInfoItem *radioInfoItem; // @synthesize radioInfoItem=_radioInfoItem;
@property(retain, nonatomic) QNAudioInfoItem *audioInfo; // @synthesize audioInfo=_audioInfo;
@property(nonatomic) _Bool hasAudio; // @synthesize hasAudio=_hasAudio;
@property(nonatomic) _Bool isPay; // @synthesize isPay=_isPay;
@property(nonatomic) _Bool roseRoomWebTabexist; // @synthesize roseRoomWebTabexist=_roseRoomWebTabexist;
@property(nonatomic) long long roseBannerType; // @synthesize roseBannerType=_roseBannerType;
@property(copy, nonatomic) NSString *roseLiveVideoID; // @synthesize roseLiveVideoID=_roseLiveVideoID;
@property(copy, nonatomic) NSString *roseLiveType; // @synthesize roseLiveType=_roseLiveType;
@property(copy, nonatomic) NSString *roseLiveID; // @synthesize roseLiveID=_roseLiveID;
@property(copy, nonatomic) NSArray *videoCommentItems; // @synthesize videoCommentItems=_videoCommentItems;
@property(nonatomic) _Bool showCommentView; // @synthesize showCommentView=_showCommentView;
@property(retain, nonatomic) QNLiveVideoSpecialEntranceItem *liveVideoSpecialEntranceItem; // @synthesize liveVideoSpecialEntranceItem=_liveVideoSpecialEntranceItem;
@property(retain, nonatomic) QNLiveVideoItem *liveVideoItem; // @synthesize liveVideoItem=_liveVideoItem;
@property(retain, nonatomic) QNModuleDocumentaryList *documentary; // @synthesize documentary=_documentary;
@property(retain, nonatomic) QNNowLiveItem *nowLiveItem; // @synthesize nowLiveItem=_nowLiveItem;
@property(retain, nonatomic) QNVideoItem *videoItem; // @synthesize videoItem=_videoItem;
@property(copy, nonatomic) NSString *titleHeadWords; // @synthesize titleHeadWords=_titleHeadWords;
@property(copy, nonatomic) NSString *graphicLiveID; // @synthesize graphicLiveID=_graphicLiveID;
@property(copy, nonatomic) NSString *demoVideoName; // @synthesize demoVideoName=_demoVideoName;
@property(copy, nonatomic) NSString *videoCategory; // @synthesize videoCategory=_videoCategory;
@property(copy, nonatomic) NSString *fadcid; // @synthesize fadcid=_fadcid;
@property(copy, nonatomic) NSString *videoTime; // @synthesize videoTime=_videoTime;
@property(copy, nonatomic) NSString *albumTitle; // @synthesize albumTitle=_albumTitle;
@property(nonatomic) long long videoNumOfAlbum; // @synthesize videoNumOfAlbum=_videoNumOfAlbum;
@property(nonatomic) _Bool isSupportVR; // @synthesize isSupportVR=_isSupportVR;
@property(nonatomic) _Bool hasVideo; // @synthesize hasVideo=_hasVideo;
@property(nonatomic) _Bool isLive; // @synthesize isLive=_isLive;
@property(nonatomic) _Bool firstPage; // @synthesize firstPage=_firstPage;
@property(copy, nonatomic) NSString *topicArticleDesc; // @synthesize topicArticleDesc=_topicArticleDesc;
@property(nonatomic) unsigned long long ballotOpinionCount; // @synthesize ballotOpinionCount=_ballotOpinionCount;
@property(nonatomic) unsigned long long ballotId; // @synthesize ballotId=_ballotId;
@property(copy, nonatomic) NSString *hideWording; // @synthesize hideWording=_hideWording;
@property(copy, nonatomic) NSString *focusNewsId; // @synthesize focusNewsId=_focusNewsId;
@property(copy, nonatomic) NSString *groupId; // @synthesize groupId=_groupId;
@property(copy, nonatomic) NSString *linkDesc; // @synthesize linkDesc=_linkDesc;
@property(copy, nonatomic) NSString *adTitle; // @synthesize adTitle=_adTitle;
@property(copy, nonatomic) NSArray *tag; // @synthesize tag=_tag;
@property(nonatomic) _Bool listCellHtmlUseJson; // @synthesize listCellHtmlUseJson=_listCellHtmlUseJson;
@property(copy, nonatomic) NSString *listCellHtmlUrl; // @synthesize listCellHtmlUrl=_listCellHtmlUrl;
@property(copy, nonatomic) NSString *listCellHtmlStr; // @synthesize listCellHtmlStr=_listCellHtmlStr;
@property(nonatomic) double listCellHeight; // @synthesize listCellHeight=_listCellHeight;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (id)audioDataUrlForShare;
- (id)miniProgramPathForShare;
- (long long)newsShareStyle:(long long)arg1;
- (id)defaultThumbnailImageForShare;
- (id)thumbnailUrlForShare;
- (id)descriptionForShare;
- (id)webpageUrlForShare;
- (id)titleForShare:(long long)arg1;
@property(copy, nonatomic) NSString *shareVid;
- (void)mergeFromParentNewsItem:(id)arg1;
- (void)mergeFromWeiboModel:(id)arg1;
- (void)mergeFromSelfCommentInfo;
- (void)mergeFromWeiboNewsItem:(id)arg1;
- (void)mergeFromIndexItem:(id)arg1;
- (long long)bossLiveTrailerType;
- (id)bossLiveVideoTypeString;
- (long long)moduleArticleType;
- (long long)moduleTypeForReport;
- (_Bool)shouldShowMultiPhotosCell;
- (_Bool)shouldShowBigPhotosCell;
- (_Bool)shouldShowByPicViewCell;
- (_Bool)isLiveRoseRoomPreciousItem;
- (_Bool)isSubscribeItem;
- (_Bool)isDepthItem;
- (id)realListItemTypeForWebCell;
- (_Bool)isPlaceHolerListItem;
- (_Bool)isModulePalceHolderItem;
- (_Bool)isModuleOpenPalceHolderItem;
- (_Bool)isFinanceEntrance;
- (_Bool)isAdItem;
- (_Bool)isWebViewCell;
- (_Bool)isVerticalizationCell;
- (_Bool)isWebDetailArticle;
- (_Bool)isExclusiveArticle;
- (id)getLableImageUrlString;
- (_Bool)enableMiniProgramShare;
- (_Bool)enableRelatedExpressionGif;
- (_Bool)enableCommentGIF;
- (_Bool)enableRelatedEmoji;
- (_Bool)enableEmoji;
- (id)shareUrl;
- (id)p_webUrlStringWithInterfaceName:(id)arg1;
- (id)detailUrlStringForSubscribeWeb;
- (id)detailUrl;
- (_Bool)hasLikeWeibo;
- (_Bool)isValidRelationItem;
- (_Bool)isWeiboItem;
- (_Bool)shouldShowOriginalLink;
- (id)hotTopicList;
- (id)recommendTopicList;
- (id)nickNameForTopicModule;
- (id)getConnectedListItem;
- (id)getTopicItemForTopicModule;
- (_Bool)shouldEnterToWeiboDetail;
- (id)articleTitleForTopicModule;
- (id)firstNewsItemInTopicModule;
- (_Bool)isTopicModuleValid;
- (_Bool)userIsMySelf;
- (id)userDesc;
- (id)userNickName;
- (id)userVipIconUrl;
- (_Bool)isVipPlaceRight;
- (id)userRightVipIconUrl;
- (long long)userVipType;
- (id)userAvatar;
- (id)authorMediaId;
- (id)mediaID;
- (id)gifImageUrlWithChannelId:(id)arg1 shouldBigGif:(_Bool)arg2 isInVideoRelateChannel:(_Bool)arg3;
- (id)getCoverImageUrlExceptKKInfo;
- (id)getCoverImageUrl;
- (long long)screenTypeValue;
- (_Bool)isWithVideo;
- (_Bool)isLiveVideoPalyEnd;
- (id)itemVideoInfo;
- (void)updateLatestCommentCount:(long long)arg1;
- (long long)latestCommentCount;
@property(copy, nonatomic) NSString *roseLiveStatus; // @dynamic roseLiveStatus;
@property(nonatomic) _Bool hasUnfold; // @dynamic hasUnfold;
- (id)modelId;
- (_Bool)isCommentValid;
- (_Bool)isSubInfoValid;
- (_Bool)isBasicInfoValid;
- (_Bool)isValid;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
