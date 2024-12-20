//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSDictionary, NSMutableArray, NSMutableString, NSNumber, NSString;

@interface QLMovieItem : NSObject <NSCoding, NSCopying>
{
    _Bool _currentMovieItemOnTop;
    _Bool _noSubTitle;
    _Bool _isLiveVideo;
    _Bool _appPlay;
    _Bool _webPlay;
    _Bool _canDownload;
    _Bool _isCover;
    _Bool _isColumn;
    _Bool _isTop;
    _Bool _isTrailer;
    _Bool _isDrm;
    _Bool _blooperON;
    _Bool _isPotraitHome;
    _Bool _isShowUpdateNotify;
    _Bool _isListStyle;
    _Bool _isPosterVertical;
    _Bool _hotspot;
    _Bool _wxHots;
    _Bool _isOuterVideo;
    _Bool _fullTag;
    _Bool _isBarrageSwitch;
    _Bool _isBarrageAutoPlay;
    _Bool _interactiveFlag;
    _Bool _isJump;
    float _programVersion;
    int _copyrightFrom;
    NSString *_updateTime;
    NSString *_title;
    NSString *_imageurl;
    NSString *_imageurl2;
    NSString *_desc;
    NSString *_summaryText;
    long long _videoIndex;
    NSString *_style;
    NSMutableString *_director;
    NSMutableString *_actor;
    NSMutableString *_year;
    NSMutableString *_area;
    double _rating;
    NSString *_ratingCaption;
    NSString *_titleType;
    long long _length;
    unsigned long long _playCount;
    NSDictionary *_dicFamous;
    NSArray *_aryActor;
    NSArray *_aryDirector;
    long long _typeID;
    long long _varietySubType;
    long long _columnid;
    NSString *_columnname;
    NSString *_source;
    NSString *_subType;
    NSString *_destinationUrl;
    long long _updatedEpisodeNumber;
    long long _totalEpisodeCount;
    NSString *_belongedCoverID;
    double _priceVIP;
    double _priceNormal;
    double _priceDiscount;
    double _scoreIMDB;
    NSString *_rawTitle;
    NSString *_rawActor;
    NSString *_rawDirector;
    NSString *_rawArea;
    NSString *_rawYear;
    NSString *_rawSubtype;
    NSString *_selectedCommentID;
    NSString *_exclusiveTag;
    long long _videoSize;
    NSString *_screenshotUrl;
    NSString *_videoID;
    NSString *_coverID;
    NSString *_commentID;
    NSString *_jumpPageID;
    unsigned long long _programType;
    unsigned long long _liveType;
    NSString *_specialTopicID;
    long long _rank;
    NSString *_zbID;
    NSString *_zbURL;
    NSArray *_aryImgTagItems;
    NSString *_channelID;
    long long _numChapter;
    long long _isVarietyExtra;
    unsigned long long _openTo;
    NSMutableArray *_thumbExtendedTempletItemIDs;
    long long _modeIndex;
    NSString *_URL;
    NSString *_pID;
    NSString *_matchId;
    NSString *_competitionId;
    NSString *_openSource;
    NSString *_songTitle;
    NSString *_songUrl;
    NSString *_aunTitle;
    NSString *_aunUrl;
    NSString *_qid;
    NSString *_searchQuery;
    NSString *_language;
    NSNumber *_play_increment;
    NSString *_vidForLocateInWorldCup;
    NSString *_voteId;
    double _voteEffectStartPoint;
    NSString *_dmTargetIdAndType;
    NSString *_pageEntry;
    NSString *_weiXinPublicAccountID;
    NSString *_weiXinPublicAccountName;
    NSString *_weiXinPublicAccountCode;
    NSString *_weiXinPublicAccountImgURL;
    NSString *_attentionDatakey;
    NSString *_algID;
    NSString *_tplID;
    NSString *_tplName;
    NSString *_linkType;
    NSDictionary *_linkTypes;
    long long _updateflag;
    unsigned long long _sourceFrom;
    NSString *_report_params;
    NSString *_definition;
    long long _position;
    long long _newRank;
}

+ (id)itemWithVID:(id)arg1 title:(id)arg2 imageURL:(id)arg3 screenShot:(id)arg4 noSubTitle:(_Bool)arg5 index:(long long)arg6;
@property(nonatomic) _Bool isJump; // @synthesize isJump=_isJump;
@property long long newRank; // @synthesize newRank=_newRank;
@property(nonatomic) long long position; // @synthesize position=_position;
@property(copy, nonatomic) NSString *definition; // @synthesize definition=_definition;
@property(copy, nonatomic) NSString *report_params; // @synthesize report_params=_report_params;
@property(nonatomic) unsigned long long sourceFrom; // @synthesize sourceFrom=_sourceFrom;
@property(nonatomic) long long updateflag; // @synthesize updateflag=_updateflag;
@property(nonatomic) _Bool interactiveFlag; // @synthesize interactiveFlag=_interactiveFlag;
@property(retain) NSDictionary *linkTypes; // @synthesize linkTypes=_linkTypes;
@property(copy, nonatomic) NSString *linkType; // @synthesize linkType=_linkType;
@property(copy, nonatomic) NSString *tplName; // @synthesize tplName=_tplName;
@property(copy, nonatomic) NSString *tplID; // @synthesize tplID=_tplID;
@property(copy, nonatomic) NSString *algID; // @synthesize algID=_algID;
@property(copy, nonatomic) NSString *attentionDatakey; // @synthesize attentionDatakey=_attentionDatakey;
@property(copy, nonatomic) NSString *weiXinPublicAccountImgURL; // @synthesize weiXinPublicAccountImgURL=_weiXinPublicAccountImgURL;
@property(copy, nonatomic) NSString *weiXinPublicAccountCode; // @synthesize weiXinPublicAccountCode=_weiXinPublicAccountCode;
@property(copy, nonatomic) NSString *weiXinPublicAccountName; // @synthesize weiXinPublicAccountName=_weiXinPublicAccountName;
@property(copy, nonatomic) NSString *weiXinPublicAccountID; // @synthesize weiXinPublicAccountID=_weiXinPublicAccountID;
@property(copy, nonatomic) NSString *pageEntry; // @synthesize pageEntry=_pageEntry;
@property(copy, nonatomic) NSString *dmTargetIdAndType; // @synthesize dmTargetIdAndType=_dmTargetIdAndType;
@property(nonatomic) _Bool isBarrageAutoPlay; // @synthesize isBarrageAutoPlay=_isBarrageAutoPlay;
@property(nonatomic) _Bool isBarrageSwitch; // @synthesize isBarrageSwitch=_isBarrageSwitch;
@property(nonatomic) double voteEffectStartPoint; // @synthesize voteEffectStartPoint=_voteEffectStartPoint;
@property(copy, nonatomic) NSString *voteId; // @synthesize voteId=_voteId;
@property(retain, nonatomic) NSString *vidForLocateInWorldCup; // @synthesize vidForLocateInWorldCup=_vidForLocateInWorldCup;
@property(retain, nonatomic) NSNumber *play_increment; // @synthesize play_increment=_play_increment;
@property(nonatomic) int copyrightFrom; // @synthesize copyrightFrom=_copyrightFrom;
@property(retain, nonatomic) NSString *language; // @synthesize language=_language;
@property(nonatomic) _Bool fullTag; // @synthesize fullTag=_fullTag;
@property(retain, nonatomic) NSString *searchQuery; // @synthesize searchQuery=_searchQuery;
@property(retain, nonatomic) NSString *qid; // @synthesize qid=_qid;
@property(nonatomic) _Bool isOuterVideo; // @synthesize isOuterVideo=_isOuterVideo;
@property(nonatomic) _Bool wxHots; // @synthesize wxHots=_wxHots;
@property(nonatomic) _Bool hotspot; // @synthesize hotspot=_hotspot;
@property(copy, nonatomic) NSString *aunUrl; // @synthesize aunUrl=_aunUrl;
@property(copy, nonatomic) NSString *aunTitle; // @synthesize aunTitle=_aunTitle;
@property(copy, nonatomic) NSString *songUrl; // @synthesize songUrl=_songUrl;
@property(copy, nonatomic) NSString *songTitle; // @synthesize songTitle=_songTitle;
@property(copy, nonatomic) NSString *openSource; // @synthesize openSource=_openSource;
@property(copy, nonatomic) NSString *competitionId; // @synthesize competitionId=_competitionId;
@property(copy, nonatomic) NSString *matchId; // @synthesize matchId=_matchId;
@property(copy, nonatomic) NSString *pID; // @synthesize pID=_pID;
@property(copy, nonatomic) NSString *URL; // @synthesize URL=_URL;
@property _Bool isPosterVertical; // @synthesize isPosterVertical=_isPosterVertical;
@property _Bool isListStyle; // @synthesize isListStyle=_isListStyle;
@property long long modeIndex; // @synthesize modeIndex=_modeIndex;
@property(retain) NSMutableArray *thumbExtendedTempletItemIDs; // @synthesize thumbExtendedTempletItemIDs=_thumbExtendedTempletItemIDs;
@property unsigned long long openTo; // @synthesize openTo=_openTo;
@property(nonatomic) _Bool isShowUpdateNotify; // @synthesize isShowUpdateNotify=_isShowUpdateNotify;
@property long long isVarietyExtra; // @synthesize isVarietyExtra=_isVarietyExtra;
@property long long numChapter; // @synthesize numChapter=_numChapter;
@property(copy) NSString *channelID; // @synthesize channelID=_channelID;
@property(retain) NSArray *aryImgTagItems; // @synthesize aryImgTagItems=_aryImgTagItems;
@property _Bool isPotraitHome; // @synthesize isPotraitHome=_isPotraitHome;
@property _Bool blooperON; // @synthesize blooperON=_blooperON;
@property(copy) NSString *zbURL; // @synthesize zbURL=_zbURL;
@property(copy) NSString *zbID; // @synthesize zbID=_zbID;
@property long long rank; // @synthesize rank=_rank;
@property(copy) NSString *specialTopicID; // @synthesize specialTopicID=_specialTopicID;
@property float programVersion; // @synthesize programVersion=_programVersion;
@property unsigned long long liveType; // @synthesize liveType=_liveType;
@property unsigned long long programType; // @synthesize programType=_programType;
@property(copy, nonatomic) NSString *jumpPageID; // @synthesize jumpPageID=_jumpPageID;
@property(copy, nonatomic) NSString *commentID; // @synthesize commentID=_commentID;
@property(copy, nonatomic) NSString *coverID; // @synthesize coverID=_coverID;
@property(copy, nonatomic) NSString *videoID; // @synthesize videoID=_videoID;
@property(copy, nonatomic) NSString *screenshotUrl; // @synthesize screenshotUrl=_screenshotUrl;
@property(nonatomic) long long videoSize; // @synthesize videoSize=_videoSize;
@property(copy, nonatomic) NSString *exclusiveTag; // @synthesize exclusiveTag=_exclusiveTag;
@property(copy, nonatomic) NSString *selectedCommentID; // @synthesize selectedCommentID=_selectedCommentID;
@property(copy, nonatomic) NSString *rawSubtype; // @synthesize rawSubtype=_rawSubtype;
@property(copy, nonatomic) NSString *rawYear; // @synthesize rawYear=_rawYear;
@property(copy, nonatomic) NSString *rawArea; // @synthesize rawArea=_rawArea;
@property(copy, nonatomic) NSString *rawDirector; // @synthesize rawDirector=_rawDirector;
@property(copy, nonatomic) NSString *rawActor; // @synthesize rawActor=_rawActor;
@property(copy, nonatomic) NSString *rawTitle; // @synthesize rawTitle=_rawTitle;
@property(nonatomic) double scoreIMDB; // @synthesize scoreIMDB=_scoreIMDB;
@property(nonatomic) double priceDiscount; // @synthesize priceDiscount=_priceDiscount;
@property(nonatomic) double priceNormal; // @synthesize priceNormal=_priceNormal;
@property(nonatomic) double priceVIP; // @synthesize priceVIP=_priceVIP;
@property(nonatomic) _Bool isDrm; // @synthesize isDrm=_isDrm;
@property(copy, nonatomic) NSString *belongedCoverID; // @synthesize belongedCoverID=_belongedCoverID;
@property(nonatomic) long long totalEpisodeCount; // @synthesize totalEpisodeCount=_totalEpisodeCount;
@property(nonatomic) long long updatedEpisodeNumber; // @synthesize updatedEpisodeNumber=_updatedEpisodeNumber;
@property(copy, nonatomic) NSString *destinationUrl; // @synthesize destinationUrl=_destinationUrl;
@property(nonatomic) _Bool isTrailer; // @synthesize isTrailer=_isTrailer;
@property(copy, nonatomic) NSString *subType; // @synthesize subType=_subType;
@property(nonatomic) _Bool isTop; // @synthesize isTop=_isTop;
@property(nonatomic) _Bool isColumn; // @synthesize isColumn=_isColumn;
@property(nonatomic) _Bool isCover; // @synthesize isCover=_isCover;
@property(copy, nonatomic) NSString *source; // @synthesize source=_source;
@property(copy, nonatomic) NSString *columnname; // @synthesize columnname=_columnname;
@property(nonatomic) long long columnid; // @synthesize columnid=_columnid;
@property(nonatomic) long long varietySubType; // @synthesize varietySubType=_varietySubType;
@property(nonatomic) long long typeID; // @synthesize typeID=_typeID;
@property(nonatomic) _Bool canDownload; // @synthesize canDownload=_canDownload;
@property(nonatomic) _Bool webPlay; // @synthesize webPlay=_webPlay;
@property(nonatomic) _Bool appPlay; // @synthesize appPlay=_appPlay;
@property(retain) NSArray *aryDirector; // @synthesize aryDirector=_aryDirector;
@property(retain) NSArray *aryActor; // @synthesize aryActor=_aryActor;
@property(retain) NSDictionary *dicFamous; // @synthesize dicFamous=_dicFamous;
@property(nonatomic) unsigned long long playCount; // @synthesize playCount=_playCount;
@property(nonatomic) long long length; // @synthesize length=_length;
@property(copy, nonatomic) NSString *titleType; // @synthesize titleType=_titleType;
@property(copy, nonatomic) NSString *ratingCaption; // @synthesize ratingCaption=_ratingCaption;
@property(nonatomic) double rating; // @synthesize rating=_rating;
@property(retain, nonatomic) NSMutableString *area; // @synthesize area=_area;
@property(retain, nonatomic) NSMutableString *year; // @synthesize year=_year;
@property(retain, nonatomic) NSMutableString *actor; // @synthesize actor=_actor;
@property(retain, nonatomic) NSMutableString *director; // @synthesize director=_director;
@property(copy, nonatomic) NSString *style; // @synthesize style=_style;
@property(nonatomic) long long videoIndex; // @synthesize videoIndex=_videoIndex;
@property(nonatomic) _Bool isLiveVideo; // @synthesize isLiveVideo=_isLiveVideo;
@property(nonatomic) _Bool noSubTitle; // @synthesize noSubTitle=_noSubTitle;
@property(copy, nonatomic) NSString *summaryText; // @synthesize summaryText=_summaryText;
@property(copy, nonatomic) NSString *desc; // @synthesize desc=_desc;
@property(copy, nonatomic) NSString *imageurl2; // @synthesize imageurl2=_imageurl2;
@property(copy, nonatomic) NSString *imageurl; // @synthesize imageurl=_imageurl;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(nonatomic) _Bool currentMovieItemOnTop; // @synthesize currentMovieItemOnTop=_currentMovieItemOnTop;
@property(retain, nonatomic, getter=getUpdateTimeFromCache, setter=setUpdateTimeToCache:) NSString *updateTime; // @synthesize updateTime=_updateTime;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)setBarrageSwitchOnItem:(_Bool)arg1 withBarrageAutoPlay:(_Bool)arg2;
@property(readonly, nonatomic) NSString *movieId;
- (id)getMovieId;
- (_Bool)isPayed;
- (id)init;

@end

