//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCTTableCoding.h"

@class NSString;

@interface WCStoryPlayRecord : NSObject <WCTTableCoding>
{
    unsigned int _playCount;
    unsigned int _lastPlayTime;
    unsigned int _lastPlaySecne;
    unsigned int _bHitPreload;
    NSString *_tid;
    NSString *_userName;
}

+ (void)__wcdb_index_15:(struct WCTBinding *)arg1;
+ (void)__wcdb_index_14:(struct WCTBinding *)arg1;
+ (void)__wcdb_column_constraint_13:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)__wcdb_synthesize_12:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)lastPlaySecne;
+ (const struct WCTProperty *)__wcdb_synthesize_11:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)bHitPreload;
+ (const struct WCTProperty *)__wcdb_synthesize_10:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)lastPlayTime;
+ (const struct WCTProperty *)__wcdb_synthesize_9:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)playCount;
+ (const struct WCTProperty *)__wcdb_synthesize_8:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)userName;
+ (const struct WCTProperty *)__wcdb_synthesize_7:(struct WCTBinding *)arg1;
+ (const struct WCTProperty *)tid;
+ (id)__wcdbtyper;
+ (const SyntaxList_7f15fe8c *)allProperties;
+ (const struct WCTBinding *)objectRelationalMapping;
@property(nonatomic) unsigned int bHitPreload; // @synthesize bHitPreload=_bHitPreload;
@property(nonatomic) unsigned int lastPlaySecne; // @synthesize lastPlaySecne=_lastPlaySecne;
@property(nonatomic) unsigned int lastPlayTime; // @synthesize lastPlayTime=_lastPlayTime;
@property(nonatomic) unsigned int playCount; // @synthesize playCount=_playCount;
@property(retain, nonatomic) NSString *userName; // @synthesize userName=_userName;
@property(retain, nonatomic) NSString *tid; // @synthesize tid=_tid;
- (void).cxx_destruct;
- (id)description;

// Remaining properties
@property(nonatomic) _Bool isAutoIncrement;
@property(nonatomic) long long lastInsertedRowID;

@end
