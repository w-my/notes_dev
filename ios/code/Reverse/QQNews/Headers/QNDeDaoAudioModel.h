//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNDeDaoAudioModel : QNBaseModelObject <NSCopying, NSCoding>
{
    double _duration;
    NSString *_decodeKey;
    NSString *_url;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
@property(copy, nonatomic) NSString *decodeKey; // @synthesize decodeKey=_decodeKey;
@property(nonatomic) double duration; // @synthesize duration=_duration;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

