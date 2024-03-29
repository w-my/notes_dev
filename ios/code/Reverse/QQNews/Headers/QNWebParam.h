//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString, QNListNewsItem;

@interface QNWebParam : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _isShowOriginalTitle;
    _Bool _disableGesture;
    _Bool _isFullScreen;
    NSString *_url;
    QNListNewsItem *_webListItem;
    QNListNewsItem *_listItemForWebView;
    NSString *_fromChannel;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool isFullScreen; // @synthesize isFullScreen=_isFullScreen;
@property(copy, nonatomic) NSString *fromChannel; // @synthesize fromChannel=_fromChannel;
@property(retain, nonatomic) QNListNewsItem *listItemForWebView; // @synthesize listItemForWebView=_listItemForWebView;
@property(nonatomic) _Bool disableGesture; // @synthesize disableGesture=_disableGesture;
@property(retain, nonatomic) QNListNewsItem *webListItem; // @synthesize webListItem=_webListItem;
@property(nonatomic) _Bool isShowOriginalTitle; // @synthesize isShowOriginalTitle=_isShowOriginalTitle;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

