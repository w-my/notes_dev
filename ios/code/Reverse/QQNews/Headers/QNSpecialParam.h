//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSDictionary, NSString;

@interface QNSpecialParam : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _isNoPicMode;
    NSString *_introTextKey;
    NSString *_introTextNameKey;
    NSDictionary *_introImageKey;
    NSArray *_headerViewKeywords;
    NSString *_introTextTitle;
    NSArray *_headerActItems;
    NSString *_fromPage;
    NSArray *_headerViewTopicList;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSArray *headerViewTopicList; // @synthesize headerViewTopicList=_headerViewTopicList;
@property(nonatomic) _Bool isNoPicMode; // @synthesize isNoPicMode=_isNoPicMode;
@property(copy, nonatomic) NSString *fromPage; // @synthesize fromPage=_fromPage;
@property(copy, nonatomic) NSArray *headerActItems; // @synthesize headerActItems=_headerActItems;
@property(copy, nonatomic) NSString *introTextTitle; // @synthesize introTextTitle=_introTextTitle;
@property(copy, nonatomic) NSArray *headerViewKeywords; // @synthesize headerViewKeywords=_headerViewKeywords;
@property(copy, nonatomic) NSDictionary *introImageKey; // @synthesize introImageKey=_introImageKey;
@property(copy, nonatomic) NSString *introTextNameKey; // @synthesize introTextNameKey=_introTextNameKey;
@property(copy, nonatomic) NSString *introTextKey; // @synthesize introTextKey=_introTextKey;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
