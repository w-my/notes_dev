//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class MVAudioItem, MVMusicMaterial;

@interface MVMusicItem : NSObject <NSCoding, NSCopying>
{
    _Bool _showLyrics;
    MVMusicMaterial *_material;
    CDStruct_e83c9415 _timeRange;
}

@property(nonatomic) _Bool showLyrics; // @synthesize showLyrics=_showLyrics;
@property(nonatomic) CDStruct_e83c9415 timeRange; // @synthesize timeRange=_timeRange;
@property(retain, nonatomic) MVMusicMaterial *material; // @synthesize material=_material;
- (void).cxx_destruct;
@property(readonly, nonatomic) MVAudioItem *audioItem;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithMaterial:(id)arg1;

@end
