//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "PBCoding.h"
#import "WCTColumnCoding.h"

@class NSString;

@interface DBContactRemark : NSObject <PBCoding, WCTColumnCoding>
{
    NSString *nickName;
    NSString *aliasName;
    NSString *remark;
    NSString *remarkPYFull;
    NSString *remarkShortPinYin;
    NSString *fullPinYin;
    NSString *descriptions;
    NSString *labelIDList;
}

+ (int)columnTypeForWCDB;
+ (id)unarchiveWithWCTValue:(struct NSObject *)arg1;
+ (void)initialize;
@property(retain, nonatomic) NSString *labelIDList; // @synthesize labelIDList;
@property(retain, nonatomic) NSString *descriptions; // @synthesize descriptions;
@property(retain, nonatomic) NSString *fullPinYin; // @synthesize fullPinYin;
@property(retain, nonatomic) NSString *remarkShortPinYin; // @synthesize remarkShortPinYin;
@property(retain, nonatomic) NSString *remarkPYFull; // @synthesize remarkPYFull;
@property(retain, nonatomic) NSString *remark; // @synthesize remark;
@property(retain, nonatomic) NSString *aliasName; // @synthesize aliasName;
@property(retain, nonatomic) NSString *nickName; // @synthesize nickName;
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

