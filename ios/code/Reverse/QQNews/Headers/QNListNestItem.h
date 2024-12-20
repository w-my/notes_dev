//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString, QNListNewsItem;

@interface QNListNestItem : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_name;
    NSString *_icon;
    NSString *_nightIcon;
    NSString *_title1;
    NSString *_title2;
    NSString *_titleDes1;
    NSString *_titleDes2;
    long long _topTileColor;
    long long _filmTitleDayColor;
    long long _filmTitleNightColor;
    long long _descColor;
    long long _iconWidth;
    long long _iconHeight;
    NSString *_cellID;
    long long _cellVer;
    QNListNewsItem *_newsItem;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(retain, nonatomic) QNListNewsItem *newsItem; // @synthesize newsItem=_newsItem;
@property(nonatomic) long long cellVer; // @synthesize cellVer=_cellVer;
@property(copy, nonatomic) NSString *cellID; // @synthesize cellID=_cellID;
@property(nonatomic) long long iconHeight; // @synthesize iconHeight=_iconHeight;
@property(nonatomic) long long iconWidth; // @synthesize iconWidth=_iconWidth;
@property(nonatomic) long long descColor; // @synthesize descColor=_descColor;
@property(nonatomic) long long filmTitleNightColor; // @synthesize filmTitleNightColor=_filmTitleNightColor;
@property(nonatomic) long long filmTitleDayColor; // @synthesize filmTitleDayColor=_filmTitleDayColor;
@property(nonatomic) long long topTileColor; // @synthesize topTileColor=_topTileColor;
@property(copy, nonatomic) NSString *titleDes2; // @synthesize titleDes2=_titleDes2;
@property(copy, nonatomic) NSString *titleDes1; // @synthesize titleDes1=_titleDes1;
@property(copy, nonatomic) NSString *title2; // @synthesize title2=_title2;
@property(copy, nonatomic) NSString *title1; // @synthesize title1=_title1;
@property(copy, nonatomic) NSString *nightIcon; // @synthesize nightIcon=_nightIcon;
@property(copy, nonatomic) NSString *icon; // @synthesize icon=_icon;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (long long)filmTitleColor;

@end

