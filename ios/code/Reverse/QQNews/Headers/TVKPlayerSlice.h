//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class NSURL;

@interface TVKPlayerSlice : NSObject <NSCopying>
{
    NSURL *_url;
    long long _duration;
}

@property(nonatomic) long long duration; // @synthesize duration=_duration;
@property(retain, nonatomic) NSURL *url; // @synthesize url=_url;
- (void).cxx_destruct;
- (id)description;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithUrl:(id)arg1 duration:(long long)arg2;
- (id)initWithUrl:(id)arg1;

@end
