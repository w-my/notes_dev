//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class EditImageAttr, EditVideoBGMSelectedMusicInfo, NSString;

@interface EditVideoAttr : MMObject
{
    _Bool _isSelectFromAlbum;
    _Bool _isOriginSoundOff;
    _Bool _isCropped;
    unsigned int _audioChannelsPerFrame;
    NSString *_assetURL;
    NSString *_originVideoArgs;
    EditVideoBGMSelectedMusicInfo *_musicInfo;
    EditImageAttr *_editImageAttr;
    CDStruct_1b6d18a9 _originDuration;
    CDStruct_e83c9415 _editedTimeRange;
}

@property(retain, nonatomic) EditImageAttr *editImageAttr; // @synthesize editImageAttr=_editImageAttr;
@property(nonatomic) _Bool isCropped; // @synthesize isCropped=_isCropped;
@property(nonatomic) _Bool isOriginSoundOff; // @synthesize isOriginSoundOff=_isOriginSoundOff;
@property(retain, nonatomic) EditVideoBGMSelectedMusicInfo *musicInfo; // @synthesize musicInfo=_musicInfo;
@property(nonatomic) CDStruct_e83c9415 editedTimeRange; // @synthesize editedTimeRange=_editedTimeRange;
@property(nonatomic) CDStruct_1b6d18a9 originDuration; // @synthesize originDuration=_originDuration;
@property(nonatomic) _Bool isSelectFromAlbum; // @synthesize isSelectFromAlbum=_isSelectFromAlbum;
@property(nonatomic) unsigned int audioChannelsPerFrame; // @synthesize audioChannelsPerFrame=_audioChannelsPerFrame;
@property(retain, nonatomic) NSString *originVideoArgs; // @synthesize originVideoArgs=_originVideoArgs;
@property(retain, nonatomic) NSString *assetURL; // @synthesize assetURL=_assetURL;
- (void).cxx_destruct;
- (_Bool)isEdited;
- (void)fillVideoAttrWithOriginPath:(id)arg1;
- (id)getVideoFileSize;
- (id)getImageBySize:(struct CGSize)arg1;
- (id)init;

@end

