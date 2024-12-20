//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QZLiveStatistic : NSObject
{
    long long _videoScores[6];
    long long _audioScores[6];
    double _enterLiveControllerTime;
    double _exitLiveControllerTime;
    double _fetchRoomInfoStartTime;
    double _fetchRoomInfoEndTime;
    double _startConnectionTime;
    double _startRenderingTime;
    double _startResolveHostTime;
    double _endResolveHostTime;
    double _finishConnectionTime;
    double _receivePackageTime;
    double _receiveFirstAudioPackageTime;
    double _receiveFirstVideoPackageTime;
    double _finishPackageBufferTime;
    double _finishAudioPackageBufferTime;
    double _viewDidAppearTime;
    NSString *_videoErrors;
    NSString *_audioErrors;
    NSString *_allPlayErrors;
    NSString *_currentPlayError;
    NSString *_videoIntervalErrors;
    NSString *_audioIntervalErrors;
    NSString *_playIntervalErrors;
    unsigned long long _status;
    double _downloadRate;
    float _cpuUsagePencent;
    float _memoryUsage;
    _Bool _isLauncherNormalBeforePlay;
    unsigned long long _launcherStatus;
    unsigned long long _cameraStatusWhenEnter;
    unsigned long long _fps;
    long long _bufferingCount;
    long long _connectCount;
    _Bool _isHasLoadSuccess;
    NSString *_ipStr;
    NSString *_launcherUin;
    unsigned int _firstVideoPackageSize;
    unsigned int _firstAudioPackageSize;
    unsigned long long _costStandardWhenBadNet;
    unsigned int _lastBufferedDuration;
    unsigned int _firstAudioPlayDelaySeconds;
    unsigned int _ka_duration_0_2;
    unsigned int _ka_duration_3_6;
    unsigned int _ka_duration_7_10;
    unsigned int _ka_duration_more_than_10;
    unsigned int _ka_fps_duration;
    unsigned int _ka_fps_0_5;
    unsigned int _ka_fps_6_10;
    unsigned int _ka_fps_11_15;
    unsigned int _ka_fps_16_20;
    unsigned int _ka_fps_20_25;
    unsigned int _ka_fps_more_than_25;
    unsigned int _videoPacket_gap_0_50;
    unsigned int _videoPacket_gap_50_100;
    unsigned int _videoPacket_gap_100_150;
    unsigned int _videoPacket_gap_150_200;
    unsigned int _videoPacket_gap_200_300;
    unsigned int _videoPacket_gap_300_400;
    unsigned int _videoPacket_gap_400_500;
    unsigned int _videoPacket_gap_500_1000;
    unsigned int _videoPacket_gap_more_than_1000;
    unsigned int _audioPacket_gap_0_50;
    unsigned int _audioPacket_gap_50_100;
    unsigned int _audioPacket_gap_100_150;
    unsigned int _audioPacket_gap_150_200;
    unsigned int _audioPacket_gap_200_300;
    unsigned int _audioPacket_gap_more_than_300;
    int _avinterless_n2000;
    int _avinter_n2000_n1000;
    int _avinter_n1000_n600;
    int _avinter_n600_n300;
    int _avinter_n300_300;
    int _avinter_300_600;
    int _avinter_600_1000;
    int _avinter_1000_2000;
    int _avintermore_2000;
    unsigned long long _AVstartConnectCDNTime;
    unsigned long long _AVgetFirstPacketTime;
    unsigned long long _secondPacketTime;
    unsigned int watcher_exit_without_firstPacket_come;
    unsigned long long watcher_exit_without_firstPacket_come_time;
    unsigned int cdn_connection_success;
    unsigned long long down_video_showfirstPacket_time;
    unsigned long long down_video_batteryLevel_time;
    unsigned long long down_video_batteryLevel;
    unsigned long long down_first_audio_packet_time;
    unsigned long long down_first_packet_time;
    unsigned long long down_video_close_time;
    unsigned long long down_video_duration_time;
    unsigned long long down_battery_duration_time;
    float _down_battery_level_duration;
    float _startbatteryLevel;
    long long _liveID;
    long long _roomID;
    NSString *_url;
    long long _lag1Count;
    long long _lag2Count;
}

@property long long lag2Count; // @synthesize lag2Count=_lag2Count;
@property long long lag1Count; // @synthesize lag1Count=_lag1Count;
@property(readonly) unsigned long long fps; // @synthesize fps=_fps;
@property(retain, nonatomic) NSString *url; // @synthesize url=_url;
@property(nonatomic) long long roomID; // @synthesize roomID=_roomID;
@property(nonatomic) long long liveID; // @synthesize liveID=_liveID;
- (void).cxx_destruct;
- (int)avintermore_2000;
- (int)avinterless_1000_2000;
- (int)avinterless_600_1000;
- (int)avinterless_300_600;
- (int)avinterless_n300_300;
- (int)avinterless_n600_n300;
- (int)avinterless_n1000_n600;
- (int)avinter_n2000_n1000;
- (int)avinterless_n2000;
- (float)startbatteryLevel;
- (float)down_battery_level_duration;
- (unsigned long long)down_battery_duration_time;
- (unsigned long long)down_video_duration_time;
- (unsigned long long)down_video_close_time;
- (unsigned long long)down_first_packet_time;
- (unsigned long long)down_first_audio_packet_time;
- (unsigned long long)down_video_batteryLevel;
- (unsigned long long)down_video_batteryLevel_time;
- (unsigned long long)down_video_showfirstPacket_time;
- (unsigned long long)cnd_connection_time;
- (unsigned int)cdn_connection_success;
- (unsigned long long)watcher_exit_without_firstPacket_come_time;
- (unsigned int)watcher_exit_without_firstPacket_come;
- (unsigned int)audioPacket_gap_more_than_300;
- (unsigned int)audioPacket_gap_200_300;
- (unsigned int)audioPacket_gap_150_200;
- (unsigned int)audioPacket_gap_100_150;
- (unsigned int)audioPacket_gap_50_100;
- (unsigned int)audioPacket_gap_0_50;
- (unsigned int)videoPacket_gap_more_than_1000;
- (unsigned int)videoPacket_gap_500_1000;
- (unsigned int)videoPacket_gap_400_500;
- (unsigned int)videoPacket_gap_300_400;
- (unsigned int)videoPacket_gap_200_300;
- (unsigned int)videoPacket_gap_150_200;
- (unsigned int)videoPacket_gap_100_150;
- (unsigned int)videoPacket_gap_50_100;
- (unsigned int)videoPacket_gap_0_50;
- (unsigned int)ka_fps_more_than_25;
- (unsigned int)ka_fps_20_25;
- (unsigned int)ka_fps_16_20;
- (unsigned int)ka_fps_11_15;
- (unsigned int)ka_fps_6_10;
- (unsigned int)ka_fps_0_5;
- (unsigned int)ka_fps_duration;
- (unsigned int)ka_duration_more_than_10;
- (unsigned int)ka_duration_7_10;
- (unsigned int)ka_duration_3_6;
- (unsigned int)ka_duration_0_2;
- (void)calculate_battery_level;
- (void)set_start_battery_level;
- (void)set_player_end_time:(unsigned long long)arg1;
- (void)set_show_first_packet_time:(unsigned long long)arg1;
- (void)set_player_first_packet_time:(unsigned long long)arg1;
- (void)setCdn_connection_success:(unsigned int)arg1;
- (void)set_first_audio_packet_time:(unsigned long long)arg1;
- (void)setWatcherExitWithoutFirstPacketcomeTime:(unsigned long long)arg1;
- (void)setWatcherExitWithoutFirstPacketcome;
- (unsigned long long)firstFrameCost;
- (void)setStartCDNConnectionTime:(unsigned long long)arg1;
- (void)setGetFirstPacketTime:(unsigned long long)arg1;
- (void)statisticAudioPacketGap:(int)arg1;
- (void)statisticVideoPacketGap:(int)arg1;
- (void)countKaFps:(int)arg1 curFps:(int)arg2 ifClose:(_Bool)arg3;
- (void)countAVSynchronize:(int)arg1;
- (void)recordVideoDecodeFailed:(int)arg1;
- (void)recordVideoFrameRendering;
- (void)recordFirstAudioPlayDelaySeconds:(unsigned int)arg1;
- (void)updateBufferedDuration:(unsigned int)arg1;
@property(readonly) unsigned int firstAudioPlayDelaySeconds;
@property(readonly) unsigned int lastBufferedDuration;
@property(readonly) unsigned int firstAudioPackageSize;
@property(readonly) unsigned int firstVideoPackageSize;
- (void)recordLauncherUin:(id)arg1;
@property(readonly, nonatomic) NSString *launcherUin;
- (void)recordIP:(id)arg1;
@property(readonly, nonatomic) NSString *ipStr;
@property(readonly) unsigned long long launcerStatusWhenEnter;
@property(readonly) _Bool isPlaySucess;
@property(readonly) _Bool isHasLoadSuccess;
- (void)connect;
@property(readonly) long long retryCount;
@property(readonly) long long bufferingCount;
- (void)buffering;
- (void)lag2;
- (void)lag;
- (void)recordCameraStatusWhenEnter:(unsigned long long)arg1;
- (void)updateLaucherStatus:(unsigned long long)arg1;
- (void)recordFps:(unsigned long long)arg1;
- (void)recordMemoryUsage:(float)arg1;
- (void)recordCpuUsagePercent:(float)arg1;
- (void)recordStatus:(unsigned long long)arg1;
- (void)recordDownloadRate:(double)arg1;
@property(readonly) unsigned long long launcherStatus;
@property(readonly) float memoryUsage;
@property(readonly) float cpuUsagePencent;
@property(readonly) unsigned long long status;
@property(readonly) double downloadRate;
- (void)clearPlayIntervalErrors;
- (void)clearAudioIntervalErrors;
- (void)clearVideoIntervalErrors;
@property(readonly) NSString *playIntervalErrors;
@property(readonly) NSString *audioIntervalErrors;
@property(readonly) NSString *videoIntervalErrors;
@property(readonly) NSString *currentPlayError;
@property(readonly) NSString *allPlayErrors;
@property(readonly) NSString *audioErrors;
@property(readonly) NSString *videoErrors;
- (void)addPlayError:(int)arg1;
- (void)addVideoError:(int)arg1;
- (void)addAudioError:(int)arg1;
@property(readonly) NSString *firstPlayTimeCostResolution;
@property(readonly) double viewAppearCost;
@property(readonly) double loadRenderCost;
@property(readonly) double audioBufferCost;
@property(readonly) double packageBufferCost;
@property(readonly) double receiveVideoPackageCost;
@property(readonly) double receiveAudioPackageCost;
@property(readonly) double receivePackageCost;
@property(readonly) double connectCost;
@property(readonly) double stayInLiveControllerCost;
@property(readonly) double firstLoadCost;
@property(readonly) double fetchRoomInfoCost;
@property(readonly, nonatomic) double resolveHostCost;
- (void)recordViewDidAppear;
- (void)finishAudioPackageBuffer;
- (void)finishPackageBuffer;
- (void)receiveFirstVideoPackageWithSize:(unsigned int)arg1;
- (void)receiveFirstAudioPackageWithSize:(unsigned int)arg1;
- (void)receivePackage;
- (void)finishConnection;
- (void)startConnection;
- (void)endResolveHost;
- (void)startResolveHost;
- (void)startRendering;
- (void)endFetchRoomInfo;
- (void)startFetchRoomInfo;
- (void)exitLiveController;
- (void)enterLiveController;
- (id)init;

@end

