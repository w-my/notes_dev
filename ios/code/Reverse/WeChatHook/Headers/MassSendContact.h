//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCTTableCoding.h"

@class NSString;

@interface MassSendContact : NSObject <WCTTableCoding>
{
    NSString *m_nsUsrName;
    NSString *m_nsDetail;
    unsigned int m_uiToListCount;
    unsigned int ConIntRes2;
    NSString *ConStrRes1;
    NSString *ConStrRes2;
}

+ (void)additionalObjectRelationalMapping:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_8:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_7:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_6:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_5:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConStrRes2;
+ (const struct WCTProperty *)__wcdb_synthesize_4:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConStrRes1;
+ (const struct WCTProperty *)__wcdb_synthesize_3:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConIntRes2;
+ (const struct WCTProperty *)__wcdb_synthesize_2:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)m_uiToListCount;
+ (const struct WCTProperty *)__wcdb_synthesize_1:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)m_nsDetail;
+ (const struct WCTProperty *)__wcdb_synthesize_0:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)m_nsUsrName;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(retain, nonatomic) NSString *ConStrRes2; // @synthesize ConStrRes2;
@property(retain, nonatomic) NSString *ConStrRes1; // @synthesize ConStrRes1;
@property(nonatomic) unsigned int ConIntRes2; // @synthesize ConIntRes2;
@property(nonatomic) unsigned int m_uiToListCount; // @synthesize m_uiToListCount;
@property(retain, nonatomic) NSString *m_nsDetail; // @synthesize m_nsDetail;
@property(retain, nonatomic) NSString *m_nsUsrName; // @synthesize m_nsUsrName;
- (void).cxx_destruct;
- (id)description;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(nonatomic) _Bool isAutoIncrement;
@property(nonatomic) long long lastInsertedRowID;

@end

