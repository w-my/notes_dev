//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface CCarHomeEntryItem : NSObject <NSCoding>
{
    NSString *_name;
    NSString *_ename;
    NSString *_iconUrl;
    NSString *_nightlyIconUrl;
    NSString *_title;
    NSString *_url;
    NSString *_sharePic;
    NSString *_shareContent;
}

@property(copy, nonatomic) NSString *shareContent; // @synthesize shareContent=_shareContent;
@property(copy, nonatomic) NSString *sharePic; // @synthesize sharePic=_sharePic;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *nightlyIconUrl; // @synthesize nightlyIconUrl=_nightlyIconUrl;
@property(copy, nonatomic) NSString *iconUrl; // @synthesize iconUrl=_iconUrl;
@property(copy, nonatomic) NSString *ename; // @synthesize ename=_ename;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfoDic:(id)arg1;

@end
