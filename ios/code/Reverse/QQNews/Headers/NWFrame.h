//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData;

@interface NWFrame : NSObject
{
    NSData *_content;
    _Bool bDelete;
    int type;
    unsigned int timestamp;
    unsigned int seq;
}

@property(readonly, nonatomic) NSData *content; // @synthesize content=_content;
@property(nonatomic) _Bool bDelete; // @synthesize bDelete;
@property(nonatomic) unsigned int seq; // @synthesize seq;
@property(nonatomic) unsigned int timestamp; // @synthesize timestamp;
@property(nonatomic) int type; // @synthesize type;
- (void).cxx_destruct;
- (void)dealloc;
- (void)setContent:(const void *)arg1 length:(unsigned long long)arg2;
- (id)initWithContent:(const void *)arg1 length:(unsigned long long)arg2;
- (id)init;

@end

