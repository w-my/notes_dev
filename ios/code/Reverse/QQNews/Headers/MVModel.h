//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class MVAudioModel, MVBusinessModel, MVCoverModel, MVEffectModel, MVUserModel, MVVideoModel, NSString;

@interface MVModel : NSObject <NSCoding, NSCopying>
{
    NSString *_identifier;
    long long _mediaType;
    long long _source;
    MVVideoModel *_video;
    MVAudioModel *_audio;
    MVEffectModel *_effect;
    MVCoverModel *_cover;
    MVUserModel *_user;
    MVBusinessModel *_business;
}

+ (long long)preferredContentModeForDisplayingWithMeidaSize:(struct CGSize)arg1;
+ (void)unarchieveFromFile:(id)arg1 completion:(CDUnknownBlockType)arg2;
+ (id)modelWithVideoAtPath:(id)arg1;
+ (id)modelWithVideoItems:(id)arg1;
+ (id)modelWithMediaType:(long long)arg1;
@property(retain, nonatomic) MVBusinessModel *business; // @synthesize business=_business;
@property(retain, nonatomic) MVUserModel *user; // @synthesize user=_user;
@property(retain, nonatomic) MVCoverModel *cover; // @synthesize cover=_cover;
@property(retain, nonatomic) MVEffectModel *effect; // @synthesize effect=_effect;
@property(retain, nonatomic) MVAudioModel *audio; // @synthesize audio=_audio;
@property(retain, nonatomic) MVVideoModel *video; // @synthesize video=_video;
@property(nonatomic) long long source; // @synthesize source=_source;
@property(nonatomic) long long mediaType; // @synthesize mediaType=_mediaType;
@property(retain, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
- (void).cxx_destruct;
- (void)resetIdentifier;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (void)removeAllFiles;
- (_Bool)archieveToFile:(id)arg1;
- (id)stringOfMetadata;
- (id)cloneAVContentsWithReplacingVideoItems:(id)arg1;
- (void)clearEditingEffects;
@property(readonly, nonatomic) _Bool containsEditingContents;
- (void)enumerateVideoItemsWithBlock:(CDUnknownBlockType)arg1;
- (void)enumerateVideoItemsByApplyingVideoClipWithBlock:(CDUnknownBlockType)arg1;
- (void)enumerateVideoItemsByApplyingVideoClipModel:(id)arg1 block:(CDUnknownBlockType)arg2;
- (id)videoItemsByApplyingVideoClipModel:(id)arg1 usingNewIdentifier:(_Bool)arg2;
- (id)accessableVideoItemsByApplyingVideoClip;
- (id)makeVideoItemsByApplyingVideoClipModel:(id)arg1;
- (id)makeVideoItemsByApplyingVideoClip;
- (id)videoAccessableTimeRanges;
- (id)tmpDirectory;
- (id)outputDirectory;
- (id)createSubWorkDirectoryIfNeeded:(long long)arg1;
- (id)subWorkDirectory:(long long)arg1;
- (id)workDirectory;

@end
