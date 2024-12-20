//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSString;

@interface QSMatchDetailNewsItem : QSModel
{
    _Bool _hasVideo;
    _Bool _exist;
    _Bool _hideThumbnail;
    NSString *_newsId;
    NSString *_title;
    NSString *_time;
    double _timestamp;
    NSString *_source;
    long long _articletype;
    NSArray *_thumbnails_qqnews;
    NSString *_uinnick;
    NSString *_uinname;
    long long _commentCount;
}

+ (id)propertyNameFromParsedKey:(id)arg1;
@property(nonatomic) _Bool hideThumbnail; // @synthesize hideThumbnail=_hideThumbnail;
@property(nonatomic) long long commentCount; // @synthesize commentCount=_commentCount;
@property(nonatomic) _Bool exist; // @synthesize exist=_exist;
@property(copy, nonatomic) NSString *uinname; // @synthesize uinname=_uinname;
@property(copy, nonatomic) NSString *uinnick; // @synthesize uinnick=_uinnick;
@property(retain, nonatomic) NSArray *thumbnails_qqnews; // @synthesize thumbnails_qqnews=_thumbnails_qqnews;
@property(nonatomic) _Bool hasVideo; // @synthesize hasVideo=_hasVideo;
@property(nonatomic) long long articletype; // @synthesize articletype=_articletype;
@property(copy, nonatomic) NSString *source; // @synthesize source=_source;
@property(nonatomic) double timestamp; // @synthesize timestamp=_timestamp;
@property(copy, nonatomic) NSString *time; // @synthesize time=_time;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *newsId; // @synthesize newsId=_newsId;
- (void).cxx_destruct;

@end

