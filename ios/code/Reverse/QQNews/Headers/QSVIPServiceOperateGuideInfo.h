//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSString;

@interface QSVIPServiceOperateGuideInfo : QSModel
{
    _Bool _canOperate;
    long long _type;
    NSString *_title;
    NSArray *_serviceList;
}

+ (id)classNameForObjectInArrayProperty:(id)arg1;
@property(retain, nonatomic) NSArray *serviceList; // @synthesize serviceList=_serviceList;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(nonatomic) _Bool canOperate; // @synthesize canOperate=_canOperate;
@property(nonatomic) long long type; // @synthesize type=_type;
- (void).cxx_destruct;

@end

