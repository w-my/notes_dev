//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNPoiSearchResult : NSObject
{
    unsigned long long _errorCode;
    id _data;
    NSString *_cityName;
    NSString *_keyWord;
}

@property(retain, nonatomic) NSString *keyWord; // @synthesize keyWord=_keyWord;
@property(retain, nonatomic) NSString *cityName; // @synthesize cityName=_cityName;
@property(retain, nonatomic) id data; // @synthesize data=_data;
@property(nonatomic) unsigned long long errorCode; // @synthesize errorCode=_errorCode;
- (void).cxx_destruct;
- (id)init;

@end

