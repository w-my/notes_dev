//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class MVMusicItem, NSArray;

@interface MVAudioModel : NSObject <NSCoding, NSCopying>
{
    _Bool _discardsOriginalAudio;
    float _originalAudioVolume;
    float _BGMVolume;
    NSArray *_audioItems;
    MVMusicItem *_musicItem;
}

@property(nonatomic) _Bool discardsOriginalAudio; // @synthesize discardsOriginalAudio=_discardsOriginalAudio;
@property(nonatomic) float BGMVolume; // @synthesize BGMVolume=_BGMVolume;
@property(nonatomic) float originalAudioVolume; // @synthesize originalAudioVolume=_originalAudioVolume;
@property(retain, nonatomic) MVMusicItem *musicItem; // @synthesize musicItem=_musicItem;
@property(retain, nonatomic) NSArray *audioItems; // @synthesize audioItems=_audioItems;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

