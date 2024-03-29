//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@interface QNEditorRemoteConfig : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _disableEdit;
    unsigned long long _minTextCount;
    unsigned long long _maxTextCount;
    unsigned long long _maxImageCount;
    unsigned long long _minVideoTitleLength;
    unsigned long long _maxVideoTitleLength;
    unsigned long long _maxVideoRecordingDuration;
    unsigned long long _minVideoRecordingDuration;
    long long _videoExpirationDuration;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) long long videoExpirationDuration; // @synthesize videoExpirationDuration=_videoExpirationDuration;
@property(nonatomic) unsigned long long minVideoRecordingDuration; // @synthesize minVideoRecordingDuration=_minVideoRecordingDuration;
@property(nonatomic) unsigned long long maxVideoRecordingDuration; // @synthesize maxVideoRecordingDuration=_maxVideoRecordingDuration;
@property(nonatomic) unsigned long long maxVideoTitleLength; // @synthesize maxVideoTitleLength=_maxVideoTitleLength;
@property(nonatomic) unsigned long long minVideoTitleLength; // @synthesize minVideoTitleLength=_minVideoTitleLength;
@property(nonatomic) _Bool disableEdit; // @synthesize disableEdit=_disableEdit;
@property(nonatomic) unsigned long long maxImageCount; // @synthesize maxImageCount=_maxImageCount;
@property(nonatomic) unsigned long long maxTextCount; // @synthesize maxTextCount=_maxTextCount;
@property(nonatomic) unsigned long long minTextCount; // @synthesize minTextCount=_minTextCount;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

