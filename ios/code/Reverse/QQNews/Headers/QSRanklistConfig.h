//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSDictionary, NSString;

@interface QSRanklistConfig : QSModel
{
    _Bool _displaySwitch;
    NSString *_desc;
    NSString *_imageUrl;
    NSDictionary *_jumpData;
}

+ (id)propertyNameFromParsedKey:(id)arg1;
@property(nonatomic) _Bool displaySwitch; // @synthesize displaySwitch=_displaySwitch;
@property(retain, nonatomic) NSDictionary *jumpData; // @synthesize jumpData=_jumpData;
@property(retain, nonatomic) NSString *imageUrl; // @synthesize imageUrl=_imageUrl;
@property(retain, nonatomic) NSString *desc; // @synthesize desc=_desc;
- (void).cxx_destruct;

@end

