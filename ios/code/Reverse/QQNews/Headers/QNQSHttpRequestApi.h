//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkBaseApi.h"

#import "NSCopying.h"

@class NSString;

@interface QNQSHttpRequestApi : QNNetworkBaseApi <NSCopying>
{
    NSString *_version;
    CDUnknownBlockType _parserBlock;
}

@property(copy, nonatomic) CDUnknownBlockType parserBlock; // @synthesize parserBlock=_parserBlock;
@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
- (void).cxx_destruct;
- (id)p_parserResponse:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithURL:(id)arg1 parserBlock:(CDUnknownBlockType)arg2;

@end

