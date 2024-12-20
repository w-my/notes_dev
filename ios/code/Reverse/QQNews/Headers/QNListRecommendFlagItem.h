//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNListRecommendFlagItem : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_type;
    NSString *_sicon;
    NSString *_siconNight;
    NSString *_textColor;
    NSString *_textColorNight;
    NSString *_words;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *words; // @synthesize words=_words;
@property(copy, nonatomic) NSString *textColorNight; // @synthesize textColorNight=_textColorNight;
@property(copy, nonatomic) NSString *textColor; // @synthesize textColor=_textColor;
@property(copy, nonatomic) NSString *siconNight; // @synthesize siconNight=_siconNight;
@property(copy, nonatomic) NSString *sicon; // @synthesize sicon=_sicon;
@property(copy, nonatomic) NSString *type; // @synthesize type=_type;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

