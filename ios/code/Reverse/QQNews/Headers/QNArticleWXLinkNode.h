//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CArticleContentNodeType.h"

@class NSString;

@interface QNArticleWXLinkNode : CArticleContentNodeType
{
    NSString *_title;
    NSString *_urlString;
    NSString *_wxHeaderUrl;
    NSString *_wxNick;
    NSString *_content;
}

@property(copy, nonatomic) NSString *content; // @synthesize content=_content;
@property(copy, nonatomic) NSString *wxNick; // @synthesize wxNick=_wxNick;
@property(copy, nonatomic) NSString *wxHeaderUrl; // @synthesize wxHeaderUrl=_wxHeaderUrl;
@property(copy, nonatomic) NSString *urlString; // @synthesize urlString=_urlString;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfo:(id)arg1;

@end

