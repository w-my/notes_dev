//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface CArticleContentMusicInfo : NSObject <NSCoding>
{
    NSString *_songId;
    NSString *_songName;
    NSString *_songer;
    NSString *_coverPicUrl;
    NSString *_songUrl;
    long long _duration;
    NSString *_songAlbum;
    NSString *_webPlayUrl;
}

@property(copy, nonatomic) NSString *webPlayUrl; // @synthesize webPlayUrl=_webPlayUrl;
@property(copy, nonatomic) NSString *songAlbum; // @synthesize songAlbum=_songAlbum;
@property(nonatomic) long long duration; // @synthesize duration=_duration;
@property(copy, nonatomic) NSString *songUrl; // @synthesize songUrl=_songUrl;
@property(copy, nonatomic) NSString *coverPicUrl; // @synthesize coverPicUrl=_coverPicUrl;
@property(copy, nonatomic) NSString *songer; // @synthesize songer=_songer;
@property(copy, nonatomic) NSString *songName; // @synthesize songName=_songName;
@property(copy, nonatomic) NSString *songId; // @synthesize songId=_songId;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfo:(id)arg1;
- (id)init;

@end

