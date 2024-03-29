//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCTTableCoding.h"

@class NSString;

@interface DBEmoticon : NSObject <WCTTableCoding>
{
    unsigned int _type;
    unsigned int _createTime;
    unsigned int _length;
    unsigned int _status;
    unsigned int _catalogId;
    unsigned int _lastUsedTime;
    unsigned int _extFlag;
    unsigned int _indexInPack;
    NSString *_md5;
    NSString *_message;
    NSString *_catalog;
    NSString *_draft;
    NSString *_extInfo;
    NSString *_packageId;
    NSString *_ConStrRes3;
}

+ (void)__wcdb_column_constraint_162:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_161:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_160:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_159:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_158:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_157:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_156:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_155:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_154:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)ConStrRes3;
+ (const struct WCTProperty *)__wcdb_synthesize_153:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)packageId;
+ (const struct WCTProperty *)__wcdb_synthesize_152:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)extInfo;
+ (const struct WCTProperty *)__wcdb_synthesize_151:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)indexInPack;
+ (const struct WCTProperty *)__wcdb_synthesize_150:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)extFlag;
+ (const struct WCTProperty *)__wcdb_synthesize_149:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)lastUsedTime;
+ (const struct WCTProperty *)__wcdb_synthesize_148:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)draft;
+ (const struct WCTProperty *)__wcdb_synthesize_147:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)catalogId;
+ (const struct WCTProperty *)__wcdb_synthesize_146:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)catalog;
+ (const struct WCTProperty *)__wcdb_synthesize_145:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)status;
+ (const struct WCTProperty *)__wcdb_synthesize_144:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)length;
+ (const struct WCTProperty *)__wcdb_synthesize_143:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)createTime;
+ (const struct WCTProperty *)__wcdb_synthesize_142:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)type;
+ (const struct WCTProperty *)__wcdb_synthesize_141:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)message;
+ (const struct WCTProperty *)__wcdb_synthesize_140:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)md5;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(retain, nonatomic) NSString *ConStrRes3; // @synthesize ConStrRes3=_ConStrRes3;
@property(retain, nonatomic) NSString *packageId; // @synthesize packageId=_packageId;
@property(retain, nonatomic) NSString *extInfo; // @synthesize extInfo=_extInfo;
@property(nonatomic) unsigned int indexInPack; // @synthesize indexInPack=_indexInPack;
@property(nonatomic) unsigned int extFlag; // @synthesize extFlag=_extFlag;
@property(nonatomic) unsigned int lastUsedTime; // @synthesize lastUsedTime=_lastUsedTime;
@property(retain, nonatomic) NSString *draft; // @synthesize draft=_draft;
@property(nonatomic) unsigned int catalogId; // @synthesize catalogId=_catalogId;
@property(retain, nonatomic) NSString *catalog; // @synthesize catalog=_catalog;
@property(nonatomic) unsigned int status; // @synthesize status=_status;
@property(nonatomic) unsigned int length; // @synthesize length=_length;
@property(nonatomic) unsigned int createTime; // @synthesize createTime=_createTime;
@property(nonatomic) unsigned int type; // @synthesize type=_type;
@property(retain, nonatomic) NSString *message; // @synthesize message=_message;
@property(retain, nonatomic) NSString *md5; // @synthesize md5=_md5;
- (void).cxx_destruct;

// Remaining properties
@property(nonatomic) _Bool isAutoIncrement;
@property(nonatomic) long long lastInsertedRowID;

@end

