//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "PBCoding.h"

@class NSString;

@interface ChatRoomRemindMsg : NSObject <PBCoding>
{
    unsigned int createTime;
    unsigned int msgSvrID;
    NSString *desc;
    NSString *chatRoomName;
    unsigned int actionType;
    NSString *actionName;
    NSString *actionUrl;
    unsigned int expireTime;
}

+ (void)initialize;
@property(nonatomic) unsigned int expireTime; // @synthesize expireTime;
@property(retain, nonatomic) NSString *actionUrl; // @synthesize actionUrl;
@property(retain, nonatomic) NSString *actionName; // @synthesize actionName;
@property(nonatomic) unsigned int actionType; // @synthesize actionType;
@property(retain, nonatomic) NSString *chatRoomName; // @synthesize chatRoomName;
@property(retain, nonatomic) NSString *desc; // @synthesize desc;
@property(nonatomic) unsigned int msgSvrID; // @synthesize msgSvrID;
@property(nonatomic) unsigned int createTime; // @synthesize createTime;
- (void).cxx_destruct;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

