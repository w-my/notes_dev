//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSTextLiveMatchAdItem : QSModel
{
    long long _picWidth;
    long long _picHeight;
    NSString *_linkUrl;
    NSString *_imgUrl;
    NSString *_title;
}

@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) NSString *imgUrl; // @synthesize imgUrl=_imgUrl;
@property(retain, nonatomic) NSString *linkUrl; // @synthesize linkUrl=_linkUrl;
@property(nonatomic) long long picHeight; // @synthesize picHeight=_picHeight;
@property(nonatomic) long long picWidth; // @synthesize picWidth=_picWidth;
- (void).cxx_destruct;

@end
