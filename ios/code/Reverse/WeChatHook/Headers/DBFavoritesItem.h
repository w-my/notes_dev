//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCTTableCoding.h"

@class NSString;

@interface DBFavoritesItem : NSObject <WCTTableCoding>
{
    _Bool isAutoIncrement;
    unsigned int _localId;
    unsigned int _favId;
    unsigned int _type;
    unsigned int _time;
    unsigned int _status;
    unsigned int _updateSeq;
    unsigned int _localUpdateSeq;
    unsigned int _sourceType;
    unsigned int _localStatus;
    unsigned int _dataTotalSize;
    unsigned int _IntRes2;
    unsigned int _IntRes3;
    long long lastInsertedRowID;
    NSString *_fromUser;
    NSString *_toUser;
    NSString *_realChatName;
    NSString *_sourceId;
    NSString *_xml;
    NSString *_StrRes1;
    NSString *_StrRes2;
    NSString *_StrRes3;
}

+ (void)__wcdb_column_constraint_39:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_38:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_37:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_36:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_35:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_34:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_33:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_32:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_31:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_30:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_29:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_28:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_27:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_26:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_25:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_24:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_23:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_22:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_21:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_20:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_19:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)StrRes3;
+ (const struct WCTProperty *)__wcdb_synthesize_18:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)StrRes2;
+ (const struct WCTProperty *)__wcdb_synthesize_17:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)StrRes1;
+ (const struct WCTProperty *)__wcdb_synthesize_16:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)IntRes3;
+ (const struct WCTProperty *)__wcdb_synthesize_15:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)IntRes2;
+ (const struct WCTProperty *)__wcdb_synthesize_14:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)dataTotalSize;
+ (const struct WCTProperty *)__wcdb_synthesize_13:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)xml;
+ (const struct WCTProperty *)__wcdb_synthesize_12:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)sourceId;
+ (const struct WCTProperty *)__wcdb_synthesize_11:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)localStatus;
+ (const struct WCTProperty *)__wcdb_synthesize_10:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)sourceType;
+ (const struct WCTProperty *)__wcdb_synthesize_9:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)realChatName;
+ (const struct WCTProperty *)__wcdb_synthesize_8:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)toUser;
+ (const struct WCTProperty *)__wcdb_synthesize_7:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)fromUser;
+ (const struct WCTProperty *)__wcdb_synthesize_6:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)localUpdateSeq;
+ (const struct WCTProperty *)__wcdb_synthesize_5:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)updateSeq;
+ (const struct WCTProperty *)__wcdb_synthesize_4:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)status;
+ (const struct WCTProperty *)__wcdb_synthesize_3:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)time;
+ (const struct WCTProperty *)__wcdb_synthesize_2:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)type;
+ (const struct WCTProperty *)__wcdb_synthesize_1:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)favId;
+ (const struct WCTProperty *)__wcdb_synthesize_0:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)localId;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(retain, nonatomic) NSString *StrRes3; // @synthesize StrRes3=_StrRes3;
@property(retain, nonatomic) NSString *StrRes2; // @synthesize StrRes2=_StrRes2;
@property(retain, nonatomic) NSString *StrRes1; // @synthesize StrRes1=_StrRes1;
@property(nonatomic) unsigned int IntRes3; // @synthesize IntRes3=_IntRes3;
@property(nonatomic) unsigned int IntRes2; // @synthesize IntRes2=_IntRes2;
@property(nonatomic) unsigned int dataTotalSize; // @synthesize dataTotalSize=_dataTotalSize;
@property(retain, nonatomic) NSString *xml; // @synthesize xml=_xml;
@property(retain, nonatomic) NSString *sourceId; // @synthesize sourceId=_sourceId;
@property(nonatomic) unsigned int localStatus; // @synthesize localStatus=_localStatus;
@property(nonatomic) unsigned int sourceType; // @synthesize sourceType=_sourceType;
@property(retain, nonatomic) NSString *realChatName; // @synthesize realChatName=_realChatName;
@property(retain, nonatomic) NSString *toUser; // @synthesize toUser=_toUser;
@property(retain, nonatomic) NSString *fromUser; // @synthesize fromUser=_fromUser;
@property(nonatomic) unsigned int localUpdateSeq; // @synthesize localUpdateSeq=_localUpdateSeq;
@property(nonatomic) unsigned int updateSeq; // @synthesize updateSeq=_updateSeq;
@property(nonatomic) unsigned int status; // @synthesize status=_status;
@property(nonatomic) unsigned int time; // @synthesize time=_time;
@property(nonatomic) unsigned int type; // @synthesize type=_type;
@property(nonatomic) unsigned int favId; // @synthesize favId=_favId;
@property(nonatomic) unsigned int localId; // @synthesize localId=_localId;
@property(nonatomic) long long lastInsertedRowID; // @synthesize lastInsertedRowID;
@property(nonatomic) _Bool isAutoIncrement; // @synthesize isAutoIncrement;
- (void).cxx_destruct;

@end

