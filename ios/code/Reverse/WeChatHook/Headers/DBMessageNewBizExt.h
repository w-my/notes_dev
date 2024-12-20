//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCTTableCoding.h"

@class NSString;

@interface DBMessageNewBizExt : NSObject <WCTTableCoding>
{
    unsigned int _msgLocalId;
    unsigned int _msgType;
    unsigned int _msgInnerType;
    unsigned int _status;
    unsigned int _invalidTime;
    unsigned int _msgExtColInt1;
    unsigned int _msgExtColInt2;
    NSString *_chatUsername;
    NSString *_bizId;
    NSString *_msgExtColString1;
    NSString *_msgExtColString2;
}

+ (void)__wcdb_index_109:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_108:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_107:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgExtColString2;
+ (const struct WCTProperty *)__wcdb_synthesize_106:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgExtColString1;
+ (const struct WCTProperty *)__wcdb_synthesize_105:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgExtColInt2;
+ (const struct WCTProperty *)__wcdb_synthesize_104:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgExtColInt1;
+ (const struct WCTProperty *)__wcdb_synthesize_103:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)invalidTime;
+ (const struct WCTProperty *)__wcdb_synthesize_102:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)status;
+ (const struct WCTProperty *)__wcdb_synthesize_101:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)bizId;
+ (const struct WCTProperty *)__wcdb_synthesize_100:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgInnerType;
+ (const struct WCTProperty *)__wcdb_synthesize_99:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgType;
+ (const struct WCTProperty *)__wcdb_synthesize_98:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)msgLocalId;
+ (const struct WCTProperty *)__wcdb_synthesize_97:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)chatUsername;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(retain, nonatomic) NSString *msgExtColString2; // @synthesize msgExtColString2=_msgExtColString2;
@property(retain, nonatomic) NSString *msgExtColString1; // @synthesize msgExtColString1=_msgExtColString1;
@property(nonatomic) unsigned int msgExtColInt2; // @synthesize msgExtColInt2=_msgExtColInt2;
@property(nonatomic) unsigned int msgExtColInt1; // @synthesize msgExtColInt1=_msgExtColInt1;
@property(nonatomic) unsigned int invalidTime; // @synthesize invalidTime=_invalidTime;
@property(nonatomic) unsigned int status; // @synthesize status=_status;
@property(retain, nonatomic) NSString *bizId; // @synthesize bizId=_bizId;
@property(nonatomic) unsigned int msgInnerType; // @synthesize msgInnerType=_msgInnerType;
@property(nonatomic) unsigned int msgType; // @synthesize msgType=_msgType;
@property(nonatomic) unsigned int msgLocalId; // @synthesize msgLocalId=_msgLocalId;
@property(retain, nonatomic) NSString *chatUsername; // @synthesize chatUsername=_chatUsername;
- (void).cxx_destruct;

// Remaining properties
@property(nonatomic) _Bool isAutoIncrement;
@property(nonatomic) long long lastInsertedRowID;

@end

