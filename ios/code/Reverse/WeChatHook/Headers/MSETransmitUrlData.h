//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MSETransmitData.h"

#import "PBCoding.h"

@class NSString;

@interface MSETransmitUrlData : MSETransmitData <PBCoding>
{
    NSString *title;
    NSString *thumUrl;
    NSString *contentUrl;
    NSString *thumPath;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *thumPath; // @synthesize thumPath;
@property(retain, nonatomic) NSString *contentUrl; // @synthesize contentUrl;
@property(retain, nonatomic) NSString *thumUrl; // @synthesize thumUrl;
@property(retain, nonatomic) NSString *title; // @synthesize title;
- (void).cxx_destruct;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
