//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NWInputStream.h"

@class NSString;

@interface NWByteArrayInputStream : NSObject <NWInputStream>
{
    char *buf;
    int count;
    int pos;
    int mark;
    _Bool freeWhenDone;
}

- (int)skip:(unsigned long long)arg1;
- (int)readDataTo:(id)arg1 length:(unsigned long long)arg2;
- (int)readData:(void *)arg1 length:(unsigned long long)arg2;
- (int)read;
- (void)reset;
- (void)mark;
- (int)available;
- (void)dealloc;
- (id)initWithData:(const void *)arg1 length:(unsigned long long)arg2 freeWhenDone:(_Bool)arg3;
- (id)initWithData:(id)arg1;
- (id)initWithData:(const void *)arg1 length:(unsigned long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
