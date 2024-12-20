//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class CArticleDetailEntryInfo, NSArray, NSDictionary, NSMutableDictionary, NSString, QNArticleContentNodeTagLinkNode, QNArticleContentSportSubHtmlNode, QNCommentUser;

@interface CArticleContentType : NSObject <NSCoding>
{
    _Bool _downloadError;
    _Bool _hasAudioText;
    _Bool _channelEntryJump;
    _Bool _hasSearchWord;
    _Bool _smartPush;
    _Bool _foldSwitch;
    _Bool _showGuessLikeViewInDetail;
    _Bool _isGetRelateVideo;
    NSString *_fadcid;
    NSString *_idStr;
    NSString *_newsChannelID;
    NSString *_articleSource;
    NSString *_topic;
    NSString *_htmlString;
    NSString *_templateString;
    NSString *_customerTemplate;
    NSString *_intro;
    NSString *_remarks;
    NSString *_introName;
    NSString *_remarksName;
    NSString *_topicTagName;
    NSString *_topicTagDefaultBannerUrl;
    NSString *_topicTagNightBannerUrl;
    NSDictionary *_truthInfo;
    QNCommentUser *_author;
    NSString *_originalTitle;
    NSString *_cmsEditor;
    NSDictionary *_liveReservationInfo;
    NSString *_addChannelId;
    NSString *_typeFlagUrl;
    NSString *_nightTypeFlagUrl;
    long long _appPromptionPosition;
    NSString *_copyrightTitle;
    NSString *_copyright;
    NSString *_articleTopPic;
    long long _relateBucket;
    long long _guessLikeJump;
    CArticleDetailEntryInfo *_detailEntryInfo;
    unsigned long long _customGenKeyIndex;
    NSString *_mustacheTemplateString;
    QNArticleContentNodeTagLinkNode *_h5TagItem;
    QNArticleContentSportSubHtmlNode *_htmlAndTagItem;
    long long _relateNewsTotalCount;
    long long _relateNewsExposeCount;
    NSString *_fartForCatalog;
    NSString *_detailScheme;
    NSArray *_guesslikeList;
    NSArray *_moduleSequence;
    unsigned long long _showRelateNewsNum;
    NSMutableDictionary *_contentsDic;
}

+ (id)ArticleContent;
@property(retain, nonatomic) NSMutableDictionary *contentsDic; // @synthesize contentsDic=_contentsDic;
@property(nonatomic) unsigned long long showRelateNewsNum; // @synthesize showRelateNewsNum=_showRelateNewsNum;
@property(nonatomic) _Bool isGetRelateVideo; // @synthesize isGetRelateVideo=_isGetRelateVideo;
@property(copy, nonatomic) NSArray *moduleSequence; // @synthesize moduleSequence=_moduleSequence;
@property(copy, nonatomic) NSArray *guesslikeList; // @synthesize guesslikeList=_guesslikeList;
@property(nonatomic) _Bool showGuessLikeViewInDetail; // @synthesize showGuessLikeViewInDetail=_showGuessLikeViewInDetail;
@property(copy, nonatomic) NSString *detailScheme; // @synthesize detailScheme=_detailScheme;
@property(nonatomic) _Bool foldSwitch; // @synthesize foldSwitch=_foldSwitch;
@property(nonatomic, getter=isSmartPush) _Bool smartPush; // @synthesize smartPush=_smartPush;
@property(copy, nonatomic) NSString *fartForCatalog; // @synthesize fartForCatalog=_fartForCatalog;
@property(nonatomic) long long relateNewsExposeCount; // @synthesize relateNewsExposeCount=_relateNewsExposeCount;
@property(nonatomic) long long relateNewsTotalCount; // @synthesize relateNewsTotalCount=_relateNewsTotalCount;
@property(nonatomic) _Bool hasSearchWord; // @synthesize hasSearchWord=_hasSearchWord;
@property(retain, nonatomic) QNArticleContentSportSubHtmlNode *htmlAndTagItem; // @synthesize htmlAndTagItem=_htmlAndTagItem;
@property(retain, nonatomic) QNArticleContentNodeTagLinkNode *h5TagItem; // @synthesize h5TagItem=_h5TagItem;
@property(copy, nonatomic) NSString *mustacheTemplateString; // @synthesize mustacheTemplateString=_mustacheTemplateString;
@property(nonatomic) unsigned long long customGenKeyIndex; // @synthesize customGenKeyIndex=_customGenKeyIndex;
@property(retain, nonatomic) CArticleDetailEntryInfo *detailEntryInfo; // @synthesize detailEntryInfo=_detailEntryInfo;
@property(nonatomic) long long guessLikeJump; // @synthesize guessLikeJump=_guessLikeJump;
@property(nonatomic) long long relateBucket; // @synthesize relateBucket=_relateBucket;
@property(copy, nonatomic) NSString *articleTopPic; // @synthesize articleTopPic=_articleTopPic;
@property(copy, nonatomic) NSString *copyright; // @synthesize copyright=_copyright;
@property(copy, nonatomic) NSString *copyrightTitle; // @synthesize copyrightTitle=_copyrightTitle;
@property(nonatomic) long long appPromptionPosition; // @synthesize appPromptionPosition=_appPromptionPosition;
@property(copy, nonatomic) NSString *nightTypeFlagUrl; // @synthesize nightTypeFlagUrl=_nightTypeFlagUrl;
@property(copy, nonatomic) NSString *typeFlagUrl; // @synthesize typeFlagUrl=_typeFlagUrl;
@property(copy, nonatomic) NSString *addChannelId; // @synthesize addChannelId=_addChannelId;
@property(retain, nonatomic) NSDictionary *liveReservationInfo; // @synthesize liveReservationInfo=_liveReservationInfo;
@property(copy, nonatomic) NSString *cmsEditor; // @synthesize cmsEditor=_cmsEditor;
@property(copy, nonatomic) NSString *originalTitle; // @synthesize originalTitle=_originalTitle;
@property(retain, nonatomic) QNCommentUser *author; // @synthesize author=_author;
@property(retain, nonatomic) NSDictionary *truthInfo; // @synthesize truthInfo=_truthInfo;
@property(copy, nonatomic) NSString *topicTagNightBannerUrl; // @synthesize topicTagNightBannerUrl=_topicTagNightBannerUrl;
@property(copy, nonatomic) NSString *topicTagDefaultBannerUrl; // @synthesize topicTagDefaultBannerUrl=_topicTagDefaultBannerUrl;
@property(copy, nonatomic) NSString *topicTagName; // @synthesize topicTagName=_topicTagName;
@property(copy, nonatomic) NSString *remarksName; // @synthesize remarksName=_remarksName;
@property(nonatomic) _Bool channelEntryJump; // @synthesize channelEntryJump=_channelEntryJump;
@property(copy, nonatomic) NSString *introName; // @synthesize introName=_introName;
@property(copy, nonatomic) NSString *remarks; // @synthesize remarks=_remarks;
@property(copy, nonatomic) NSString *intro; // @synthesize intro=_intro;
@property(nonatomic) _Bool hasAudioText; // @synthesize hasAudioText=_hasAudioText;
@property(copy, nonatomic) NSString *customerTemplate; // @synthesize customerTemplate=_customerTemplate;
@property(copy, nonatomic) NSString *templateString; // @synthesize templateString=_templateString;
@property(copy, nonatomic) NSString *htmlString; // @synthesize htmlString=_htmlString;
@property _Bool downloadError; // @synthesize downloadError=_downloadError;
@property(copy, nonatomic) NSString *topic; // @synthesize topic=_topic;
@property(copy) NSString *articleSource; // @synthesize articleSource=_articleSource;
@property(copy, nonatomic) NSString *newsChannelID; // @synthesize newsChannelID=_newsChannelID;
@property(copy) NSString *idStr; // @synthesize idStr=_idStr;
@property(copy, nonatomic) NSString *fadcid; // @synthesize fadcid=_fadcid;
- (void).cxx_destruct;
- (id)description;
- (_Bool)isSpecialListValid;
- (void)dealloc;
- (id)getAllComponentModels;
- (id)allCustomJSLinks;
- (id)allCustomCssLinksForThemeType:(long long)arg1;
- (id)allImageNodes;
- (id)getAllTextNodes;
- (id)getAllSearchWords;
- (id)getAllPicNodes;
- (void)readFromDisk:(id)arg1;
- (_Bool)write2Disk:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)reset;
- (id)init;
- (void)loadNodesFromDict:(id)arg1;
- (id)allNodes;
- (id)allNodeKeys;
- (void)setNode:(id)arg1 forKey:(id)arg2;
- (id)nodeForKey:(id)arg1;

@end

