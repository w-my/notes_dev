//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSString;

@interface QNAMRSoundItem : QNAutoCodingCopyingObject
{
    NSString *_soundUrl;
    double _duration;
    NSString *_containerIdentifier;
    NSString *_localId;
    NSString *_localFilePath;
}

+ (id)itemWithData:(id)arg1;
@property(copy, nonatomic) NSString *localFilePath; // @synthesize localFilePath=_localFilePath;
@property(copy, nonatomic) NSString *localId; // @synthesize localId=_localId;
@property(copy, nonatomic) NSString *containerIdentifier; // @synthesize containerIdentifier=_containerIdentifier;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(copy, nonatomic) NSString *soundUrl; // @synthesize soundUrl=_soundUrl;
- (void).cxx_destruct;
- (_Bool)isEqual:(id)arg1;
- (id)description;

@end
