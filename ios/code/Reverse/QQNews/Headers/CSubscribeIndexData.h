//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListModel.h"

@class NSMutableArray, NSString;

@interface CSubscribeIndexData : QNListModel
{
    long long _ret;
    NSMutableArray *_ids;
    NSString *_channel;
    NSMutableArray *_recomm;
    NSString *_version;
}

@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
@property(retain, nonatomic) NSMutableArray *recomm; // @synthesize recomm=_recomm;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
@property(retain, nonatomic) NSMutableArray *ids; // @synthesize ids=_ids;
@property(nonatomic) long long ret; // @synthesize ret=_ret;
- (void).cxx_destruct;
- (void)dealloc;
- (id)generateIdsFromListItems;
- (void)popReadFlag;
- (void)writeReadFlagToDisk;
- (void)pushReadFlag:(id)arg1;
- (id)listDataFilePath;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

