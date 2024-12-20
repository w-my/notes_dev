//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "CModelLoaderDelegate.h"

@class CModelLoader, NSArray, NSString, NSTimer, QNListNewsItem, QNLiveVideoLikeItem, QNRoseLiveRoomBannerModel, QNRoseLiveRoomLiveViewModel, QNRoseLiveRoomPreciousHotViewModel, QNRoseLiveRoomPreciousTalkViewModel, QNRoseLiveRoomPreciousViewModel, QNRoseLiveRoomResource, QNRoseLiveRoomSportRaceInfoModel, QNRoseLiveRoomTalkViewModel;

@interface QNRoseLiveRoomViewModel : NSObject <CModelLoaderDelegate>
{
    _Bool _supportAudio;
    _Bool _supportVideo;
    _Bool _isSportsPay;
    _Bool _isSportsRoseLive;
    _Bool _showSportGiftEntry;
    _Bool _showSportRankEntry;
    QNListNewsItem *_listItem;
    QNLiveVideoLikeItem *_likeItem;
    QNRoseLiveRoomResource *_resources;
    NSString *_title;
    long long _viewCount;
    long long _liveRoomType;
    long long _liveStatus;
    QNRoseLiveRoomBannerModel *_headerInfo;
    NSArray *_webPageInfos;
    QNRoseLiveRoomSportRaceInfoModel *_raceInfo;
    long long _showType;
    CDUnknownBlockType _loadFinishedBlock;
    CDUnknownBlockType _autoUpdateFinishedBlock;
    CModelLoader *_loader;
    NSTimer *_autoUpdateTimer;
    CModelLoader *_autoUpdateLoader;
    long long _autoUpdateInterval;
    QNRoseLiveRoomLiveViewModel *_liveViewModel;
    QNRoseLiveRoomTalkViewModel *_talkViewModel;
    QNRoseLiveRoomPreciousViewModel *_preciousViewModel;
    QNRoseLiveRoomPreciousHotViewModel *_preciousHotViewModel;
    QNRoseLiveRoomPreciousTalkViewModel *_preciousTalkViewModel;
    NSArray *_sportPageInfos;
}

@property(copy, nonatomic) NSArray *sportPageInfos; // @synthesize sportPageInfos=_sportPageInfos;
@property(retain, nonatomic) QNRoseLiveRoomPreciousTalkViewModel *preciousTalkViewModel; // @synthesize preciousTalkViewModel=_preciousTalkViewModel;
@property(retain, nonatomic) QNRoseLiveRoomPreciousHotViewModel *preciousHotViewModel; // @synthesize preciousHotViewModel=_preciousHotViewModel;
@property(retain, nonatomic) QNRoseLiveRoomPreciousViewModel *preciousViewModel; // @synthesize preciousViewModel=_preciousViewModel;
@property(retain, nonatomic) QNRoseLiveRoomTalkViewModel *talkViewModel; // @synthesize talkViewModel=_talkViewModel;
@property(retain, nonatomic) QNRoseLiveRoomLiveViewModel *liveViewModel; // @synthesize liveViewModel=_liveViewModel;
@property(nonatomic) long long autoUpdateInterval; // @synthesize autoUpdateInterval=_autoUpdateInterval;
@property(retain, nonatomic) CModelLoader *autoUpdateLoader; // @synthesize autoUpdateLoader=_autoUpdateLoader;
@property(retain, nonatomic) NSTimer *autoUpdateTimer; // @synthesize autoUpdateTimer=_autoUpdateTimer;
@property(retain, nonatomic) CModelLoader *loader; // @synthesize loader=_loader;
@property(copy, nonatomic) CDUnknownBlockType autoUpdateFinishedBlock; // @synthesize autoUpdateFinishedBlock=_autoUpdateFinishedBlock;
@property(copy, nonatomic) CDUnknownBlockType loadFinishedBlock; // @synthesize loadFinishedBlock=_loadFinishedBlock;
@property(nonatomic) _Bool showSportRankEntry; // @synthesize showSportRankEntry=_showSportRankEntry;
@property(nonatomic) _Bool showSportGiftEntry; // @synthesize showSportGiftEntry=_showSportGiftEntry;
@property(nonatomic) _Bool isSportsRoseLive; // @synthesize isSportsRoseLive=_isSportsRoseLive;
@property(nonatomic) long long showType; // @synthesize showType=_showType;
@property(retain, nonatomic) QNRoseLiveRoomSportRaceInfoModel *raceInfo; // @synthesize raceInfo=_raceInfo;
@property(copy, nonatomic) NSArray *webPageInfos; // @synthesize webPageInfos=_webPageInfos;
@property(retain, nonatomic) QNRoseLiveRoomBannerModel *headerInfo; // @synthesize headerInfo=_headerInfo;
@property(nonatomic) _Bool isSportsPay; // @synthesize isSportsPay=_isSportsPay;
@property(nonatomic) long long liveStatus; // @synthesize liveStatus=_liveStatus;
@property(nonatomic) long long liveRoomType; // @synthesize liveRoomType=_liveRoomType;
@property(nonatomic) _Bool supportVideo; // @synthesize supportVideo=_supportVideo;
@property(nonatomic) _Bool supportAudio; // @synthesize supportAudio=_supportAudio;
@property(nonatomic) long long viewCount; // @synthesize viewCount=_viewCount;
@property(nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) QNRoseLiveRoomResource *resources; // @synthesize resources=_resources;
@property(retain, nonatomic) QNLiveVideoLikeItem *likeItem; // @synthesize likeItem=_likeItem;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)modelDidFailed:(id)arg1;
- (void)modelDidFinish:(id)arg1;
- (void)p_updateLiveData;
- (void)p_stopAutoUpdateData;
- (void)p_startAutoUpdateData;
- (void)p_resetAutoUpdateInterval:(long long)arg1;
- (void)p_updateLiveRoomStatus:(id)arg1;
- (void)p_updatePlaybackAndVideoInfo;
- (void)p_parseUpdateResponseData:(id)arg1;
- (void)p_parseArticleContentWithData:(id)arg1;
- (unsigned long long)sportLivePageConfig;
- (_Bool)shouldShowLiveForecast;
- (id)viewModelForController:(id)arg1;
- (void)updateRoseLiveType:(id)arg1;
- (void)loadData;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

