//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVEdition.h"

@class MVMusicItem;

@interface MVMusicEdition : MVEdition
{
    _Bool _hasMusicItem;
    _Bool _showLyrics;
    float _recordedAudioVolume;
    float _bgmVolume;
    MVMusicItem *_musicItem;
    CDStruct_e83c9415 _musicTimeRange;
}

+ (id)editionFromMedia:(id)arg1;
@property(nonatomic) CDStruct_e83c9415 musicTimeRange; // @synthesize musicTimeRange=_musicTimeRange;
@property(nonatomic) _Bool showLyrics; // @synthesize showLyrics=_showLyrics;
@property(nonatomic) _Bool hasMusicItem; // @synthesize hasMusicItem=_hasMusicItem;
@property(nonatomic) float bgmVolume; // @synthesize bgmVolume=_bgmVolume;
@property(nonatomic) float recordedAudioVolume; // @synthesize recordedAudioVolume=_recordedAudioVolume;
@property(retain, nonatomic) MVMusicItem *musicItem; // @synthesize musicItem=_musicItem;
- (void).cxx_destruct;
- (void)applyEditionToMedia:(id)arg1;

@end
