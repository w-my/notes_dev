//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

@interface QNPickCityDataApi : QNNetworkJSONDictionaryApi
{
}

- (id)_parseCityItemList:(id)arg1 cityLevel:(long long)arg2 parentID:(id)arg3;
- (id)_parseHotCityItemList:(id)arg1;
- (id)_parseSubList:(id)arg1;
- (id)_parseCurrentCity:(id)arg1 hotList:(id)arg2 subList:(id)arg3;
- (id)_parseData:(id)arg1;
- (id)initWithChannels:(id)arg1;

@end
