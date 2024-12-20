//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSString;

@interface QSNewsListItem : QSModel
{
    _Bool _hasCopyRight;
    _Bool _isExist;
    _Bool _hasRead;
    int _picCount;
    int _commentsNum;
    int _newsTypeColor;
    NSString *_newsId;
    NSString *_title;
    NSString *_source;
    NSString *_summary;
    NSString *_smallPicUrl;
    NSString *_bigPicUrl;
    NSString *_articleSourceUrl;
    NSString *_pubTime;
    long long _type;
    NSString *_videoTime;
    NSString *_livingId;
    NSString *_livingStartTime;
    NSString *_livingEndTime;
    NSString *_cc_cid;
    NSString *_tagIcon;
    NSString *_tagName;
    NSString *_newsTypeName;
    NSString *_targetId;
    NSString *_cid;
    NSString *_vid;
    NSArray *_thumbnails;
    NSString *_newsType;
    NSString *_tagKey;
    double _width;
    double _height;
}

+ (id)parseNewsListItemsFromDict:(id)arg1;
+ (id)propertyNameFromParsedKey:(id)arg1;
@property(nonatomic) double height; // @synthesize height=_height;
@property(nonatomic) double width; // @synthesize width=_width;
@property(copy, nonatomic) NSString *tagKey; // @synthesize tagKey=_tagKey;
@property(nonatomic) int newsTypeColor; // @synthesize newsTypeColor=_newsTypeColor;
@property(copy, nonatomic) NSString *newsType; // @synthesize newsType=_newsType;
@property(nonatomic) int commentsNum; // @synthesize commentsNum=_commentsNum;
@property(copy, nonatomic) NSArray *thumbnails; // @synthesize thumbnails=_thumbnails;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(copy, nonatomic) NSString *cid; // @synthesize cid=_cid;
@property(copy, nonatomic) NSString *targetId; // @synthesize targetId=_targetId;
@property(copy, nonatomic) NSString *newsTypeName; // @synthesize newsTypeName=_newsTypeName;
@property(copy, nonatomic) NSString *tagName; // @synthesize tagName=_tagName;
@property(copy, nonatomic) NSString *tagIcon; // @synthesize tagIcon=_tagIcon;
@property(copy, nonatomic) NSString *cc_cid; // @synthesize cc_cid=_cc_cid;
@property(nonatomic) _Bool hasRead; // @synthesize hasRead=_hasRead;
@property(nonatomic) _Bool isExist; // @synthesize isExist=_isExist;
@property(nonatomic) int picCount; // @synthesize picCount=_picCount;
@property(nonatomic) _Bool hasCopyRight; // @synthesize hasCopyRight=_hasCopyRight;
@property(copy, nonatomic) NSString *livingEndTime; // @synthesize livingEndTime=_livingEndTime;
@property(copy, nonatomic) NSString *livingStartTime; // @synthesize livingStartTime=_livingStartTime;
@property(copy, nonatomic) NSString *livingId; // @synthesize livingId=_livingId;
@property(copy, nonatomic) NSString *videoTime; // @synthesize videoTime=_videoTime;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(copy, nonatomic) NSString *pubTime; // @synthesize pubTime=_pubTime;
@property(copy, nonatomic) NSString *articleSourceUrl; // @synthesize articleSourceUrl=_articleSourceUrl;
@property(copy, nonatomic) NSString *bigPicUrl; // @synthesize bigPicUrl=_bigPicUrl;
@property(copy, nonatomic) NSString *smallPicUrl; // @synthesize smallPicUrl=_smallPicUrl;
@property(copy, nonatomic) NSString *summary; // @synthesize summary=_summary;
@property(copy, nonatomic) NSString *source; // @synthesize source=_source;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *newsId; // @synthesize newsId=_newsId;
- (void).cxx_destruct;
- (void)manualResetWithInfo:(id)arg1;

@end

