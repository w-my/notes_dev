//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString, UIColor;

@interface QNCommentSectionHeaderModel : QNBaseModelObject <NSCopying, NSCoding>
{
    UIColor *_textColor;
    UIColor *_night_textColor;
    UIColor *_backgroundColor;
    UIColor *_night_backgroundColor;
    NSString *_title;
    NSString *_icon;
    NSString *_night_icon;
    NSString *_name;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(copy, nonatomic) NSString *night_icon; // @synthesize night_icon=_night_icon;
@property(copy, nonatomic) NSString *icon; // @synthesize icon=_icon;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) UIColor *night_backgroundColor; // @synthesize night_backgroundColor=_night_backgroundColor;
@property(retain, nonatomic) UIColor *backgroundColor; // @synthesize backgroundColor=_backgroundColor;
@property(retain, nonatomic) UIColor *night_textColor; // @synthesize night_textColor=_night_textColor;
@property(retain, nonatomic) UIColor *textColor; // @synthesize textColor=_textColor;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
