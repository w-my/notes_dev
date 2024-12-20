//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCTTableCoding.h"

@class NSString;

@interface DBMessageExt : NSObject <WCTTableCoding>
{
    unsigned int _msgLocalId;
    unsigned int _msgFlag;
    unsigned int _ConIntRes1;
    unsigned int _ConIntRes2;
    unsigned int _ConIntRes3;
    NSString *_msgSource;
    NSString *_msgIdentify;
    NSString *_ConStrRes1;
    NSString *_ConStrRes2;
    NSString *_ConStrRes3;
}

+ (void)__wcdb_column_constraint_87:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_86:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_85:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_84:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_83:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_82:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_81:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConIntRes1;
+ (const struct WCTProperty *)__wcdb_synthesize_80:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConStrRes3;
+ (const struct WCTProperty *)__wcdb_synthesize_79:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConStrRes2;
+ (const struct WCTProperty *)__wcdb_synthesize_78:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConStrRes1;
+ (const struct WCTProperty *)__wcdb_synthesize_77:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgIdentify;
+ (const struct WCTProperty *)__wcdb_synthesize_76:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgSource;
+ (const struct WCTProperty *)__wcdb_synthesize_75:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConIntRes3;
+ (const struct WCTProperty *)__wcdb_synthesize_74:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConIntRes2;
+ (const struct WCTProperty *)__wcdb_synthesize_73:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgFlag;
+ (const struct WCTProperty *)__wcdb_synthesize_72:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgLocalId;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(retain, nonatomic) NSString *ConStrRes3; // @synthesize ConStrRes3=_ConStrRes3;
@property(retain, nonatomic) NSString *ConStrRes2; // @synthesize ConStrRes2=_ConStrRes2;
@property(retain, nonatomic) NSString *ConStrRes1; // @synthesize ConStrRes1=_ConStrRes1;
@property(nonatomic) unsigned int ConIntRes3; // @synthesize ConIntRes3=_ConIntRes3;
@property(nonatomic) unsigned int ConIntRes2; // @synthesize ConIntRes2=_ConIntRes2;
@property(nonatomic) unsigned int ConIntRes1; // @synthesize ConIntRes1=_ConIntRes1;
@property(retain, nonatomic) NSString *msgIdentify; // @synthesize msgIdentify=_msgIdentify;
@property(retain, nonatomic) NSString *msgSource; // @synthesize msgSource=_msgSource;
@property(nonatomic) unsigned int msgFlag; // @synthesize msgFlag=_msgFlag;
@property(nonatomic) unsigned int msgLocalId; // @synthesize msgLocalId=_msgLocalId;
- (void).cxx_destruct;

// Remaining properties
@property(nonatomic) _Bool isAutoIncrement;
@property(nonatomic) long long lastInsertedRowID;

@end

