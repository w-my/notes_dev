//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSMutableArray;

@interface CCarHomeEntryModel : NSObject <NSCoding>
{
    long long _version;
    NSMutableArray *_list;
}

@property(retain, nonatomic) NSMutableArray *list; // @synthesize list=_list;
@property(nonatomic) long long version; // @synthesize version=_version;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfoDic:(id)arg1;

@end

