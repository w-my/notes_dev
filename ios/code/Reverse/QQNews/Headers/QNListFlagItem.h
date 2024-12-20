//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"
#import "QNListDiffable.h"
#import "QNListModelProtocol.h"

@class NSString, UIColor, UIImage;

@interface QNListFlagItem : QNBaseModelObject <QNListDiffable, QNListModelProtocol, NSCopying, NSCoding>
{
    _Bool _hasBorder;
    _Bool _required;
    _Bool _calculated;
    _Bool _hasShadow;
    long long _type;
    NSString *_word;
    NSString *_textColorStr;
    NSString *_textNightColorStr;
    NSString *_backgroundColorStr;
    NSString *_backgroundNightColorStr;
    UIColor *_textColor;
    UIColor *_textNightColor;
    UIColor *_backgroundColor;
    UIColor *_backgroundNightColor;
    NSString *_imageUrl;
    NSString *_imageNightUrl;
    long long _imageWidth;
    long long _imageHeight;
    long long _radius;
    long long _displayMode;
    long long _focusDisplayMode;
    UIImage *_image;
    UIImage *_imageNight;
    long long _width;
    long long _height;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool hasShadow; // @synthesize hasShadow=_hasShadow;
@property(nonatomic) _Bool calculated; // @synthesize calculated=_calculated;
@property(nonatomic) _Bool required; // @synthesize required=_required;
@property(nonatomic) long long height; // @synthesize height=_height;
@property(nonatomic) long long width; // @synthesize width=_width;
@property(retain, nonatomic) UIImage *imageNight; // @synthesize imageNight=_imageNight;
@property(retain, nonatomic) UIImage *image; // @synthesize image=_image;
@property(nonatomic) long long focusDisplayMode; // @synthesize focusDisplayMode=_focusDisplayMode;
@property(nonatomic) long long displayMode; // @synthesize displayMode=_displayMode;
@property(nonatomic) long long radius; // @synthesize radius=_radius;
@property(nonatomic) long long imageHeight; // @synthesize imageHeight=_imageHeight;
@property(nonatomic) long long imageWidth; // @synthesize imageWidth=_imageWidth;
@property(copy, nonatomic) NSString *imageNightUrl; // @synthesize imageNightUrl=_imageNightUrl;
@property(copy, nonatomic) NSString *imageUrl; // @synthesize imageUrl=_imageUrl;
@property(nonatomic) _Bool hasBorder; // @synthesize hasBorder=_hasBorder;
@property(retain, nonatomic) UIColor *backgroundNightColor; // @synthesize backgroundNightColor=_backgroundNightColor;
@property(retain, nonatomic) UIColor *backgroundColor; // @synthesize backgroundColor=_backgroundColor;
@property(retain, nonatomic) UIColor *textNightColor; // @synthesize textNightColor=_textNightColor;
@property(retain, nonatomic) UIColor *textColor; // @synthesize textColor=_textColor;
@property(copy, nonatomic) NSString *backgroundNightColorStr; // @synthesize backgroundNightColorStr=_backgroundNightColorStr;
@property(copy, nonatomic) NSString *backgroundColorStr; // @synthesize backgroundColorStr=_backgroundColorStr;
@property(copy, nonatomic) NSString *textNightColorStr; // @synthesize textNightColorStr=_textNightColorStr;
@property(copy, nonatomic) NSString *textColorStr; // @synthesize textColorStr=_textColorStr;
@property(copy, nonatomic) NSString *word; // @synthesize word=_word;
@property(nonatomic) long long type; // @synthesize type=_type;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)isEqualToDiffableObject:(id)arg1;
- (id)uniqueIdentifier;
- (_Bool)hasCustomBackgroundColor;
- (_Bool)shouldShowFlagWithTextMode:(_Bool)arg1;
- (id)getBackgroundColor;
- (id)getFlagTextColor;
- (_Bool)isValid;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

