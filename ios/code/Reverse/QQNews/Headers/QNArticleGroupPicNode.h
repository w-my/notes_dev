//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CArticleContentNodeType.h"

#import "QNDetailComponentModelProtocol.h"

@class NSString;

@interface QNArticleGroupPicNode : CArticleContentNodeType <QNDetailComponentModelProtocol>
{
    _Bool _isInTextMode;
    NSString *_articleID;
    NSString *_channel;
    NSString *_urlString;
    NSString *_cid;
    NSString *_desc;
    NSString *_title;
    long long _num;
    NSString *_bigPicURLString;
    long long _bigPicWidth;
    long long _bigPicHeight;
    NSString *_smallPicURLString;
    long long _smallPicWidth;
    long long _smallPicHeight;
}

@property(nonatomic) _Bool isInTextMode; // @synthesize isInTextMode=_isInTextMode;
@property(nonatomic) long long smallPicHeight; // @synthesize smallPicHeight=_smallPicHeight;
@property(nonatomic) long long smallPicWidth; // @synthesize smallPicWidth=_smallPicWidth;
@property(copy, nonatomic) NSString *smallPicURLString; // @synthesize smallPicURLString=_smallPicURLString;
@property(nonatomic) long long bigPicHeight; // @synthesize bigPicHeight=_bigPicHeight;
@property(nonatomic) long long bigPicWidth; // @synthesize bigPicWidth=_bigPicWidth;
@property(copy, nonatomic) NSString *bigPicURLString; // @synthesize bigPicURLString=_bigPicURLString;
@property(nonatomic) long long num; // @synthesize num=_num;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *desc; // @synthesize desc=_desc;
@property(copy, nonatomic) NSString *cid; // @synthesize cid=_cid;
@property(copy, nonatomic) NSString *urlString; // @synthesize urlString=_urlString;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
@property(copy, nonatomic) NSString *articleID; // @synthesize articleID=_articleID;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfo:(id)arg1;
- (Class)componentViewClass;
- (void)setComponentFrame:(struct CGRect)arg1;
- (struct CGRect)componentFrame;
- (id)uniqueId;

@end

