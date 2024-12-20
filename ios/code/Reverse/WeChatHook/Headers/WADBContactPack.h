//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "PBCoding.h"
#import "WCTColumnCoding.h"

@class NSString;

@interface WADBContactPack : NSObject <PBCoding, WCTColumnCoding>
{
    unsigned int uiLastUpdateAppVersionInfoTime;
    NSString *aliasName;
    NSString *nickName;
    NSString *fullPinYin;
    NSString *headHDImageURL;
    NSString *headImageURL;
    NSString *signature;
}

+ (int)columnTypeForWCDB;
+ (id)unarchiveWithWCTValue:(struct NSObject *)arg1;
+ (void)initialize;
@property(nonatomic) unsigned int uiLastUpdateAppVersionInfoTime; // @synthesize uiLastUpdateAppVersionInfoTime;
@property(retain, nonatomic) NSString *signature; // @synthesize signature;
@property(retain, nonatomic) NSString *headImageURL; // @synthesize headImageURL;
@property(retain, nonatomic) NSString *headHDImageURL; // @synthesize headHDImageURL;
@property(retain, nonatomic) NSString *fullPinYin; // @synthesize fullPinYin;
@property(retain, nonatomic) NSString *nickName; // @synthesize nickName;
@property(retain, nonatomic) NSString *aliasName; // @synthesize aliasName;
- (void).cxx_destruct;
- (struct NSObject *)archivedWCTValue;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

