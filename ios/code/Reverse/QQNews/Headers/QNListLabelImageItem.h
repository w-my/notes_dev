//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNListLabelImageItem : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_url2x;
    NSString *_url3x;
    NSString *_urlNight2x;
    NSString *_urlNight3x;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *urlNight3x; // @synthesize urlNight3x=_urlNight3x;
@property(copy, nonatomic) NSString *urlNight2x; // @synthesize urlNight2x=_urlNight2x;
@property(copy, nonatomic) NSString *url3x; // @synthesize url3x=_url3x;
@property(copy, nonatomic) NSString *url2x; // @synthesize url2x=_url2x;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
