//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface CLiveDataSummaryNode : NSObject <NSCoding>
{
    int _version;
    NSString *_cnt;
}

@property(nonatomic) int version; // @synthesize version=_version;
@property(copy, nonatomic) NSString *cnt; // @synthesize cnt=_cnt;
- (void).cxx_destruct;
- (void)dealloc;
- (void)reset;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithInfo:(id)arg1;
- (id)init;

@end
