//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSString, QSVideoListByColumnIdAdInfo;

@interface QSVideoListByColumnIdInfo : QSModel
{
    NSString *_title;
    QSVideoListByColumnIdAdInfo *_adInfo;
    NSArray *_videoList;
}

+ (id)classNameForObjectInArrayProperty:(id)arg1;
@property(retain, nonatomic) NSArray *videoList; // @synthesize videoList=_videoList;
@property(retain, nonatomic) QSVideoListByColumnIdAdInfo *adInfo; // @synthesize adInfo=_adInfo;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
- (void).cxx_destruct;

@end

