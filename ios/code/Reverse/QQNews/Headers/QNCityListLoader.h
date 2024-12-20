//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableArray, NSString, QNCityApi;

@interface QNCityListLoader : NSObject
{
    QNCityApi *_api;
    NSMutableArray *_innerCityData;
    NSString *_localVersion;
}

@property(retain, nonatomic) NSString *localVersion; // @synthesize localVersion=_localVersion;
@property(retain, nonatomic) NSMutableArray *innerCityData; // @synthesize innerCityData=_innerCityData;
- (void).cxx_destruct;
- (id)p_cityListDataFolder;
- (void)p_asyncWriteCityDataToDisk;
- (_Bool)p_loadCityDataFromDisk;
@property(readonly, nonatomic) NSArray *cityListData;
- (id)p_parseJson:(id)arg1;
- (void)loadCityListDataCompletion:(CDUnknownBlockType)arg1;

@end

