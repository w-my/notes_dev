//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSDate, QNNetworkResponse;

@interface __QNNetworkStateData : QNAutoCodingCopyingObject
{
    _Bool _isNetworkOK;
    NSDate *_updateTime;
    QNNetworkResponse *_originalResponseData;
}

@property(retain, nonatomic) QNNetworkResponse *originalResponseData; // @synthesize originalResponseData=_originalResponseData;
@property(retain, nonatomic) NSDate *updateTime; // @synthesize updateTime=_updateTime;
@property(nonatomic) _Bool isNetworkOK; // @synthesize isNetworkOK=_isNetworkOK;
- (void).cxx_destruct;

@end
