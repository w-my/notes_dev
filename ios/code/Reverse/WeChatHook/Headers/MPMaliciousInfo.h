//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSString;

@interface MPMaliciousInfo : MMObject
{
    NSString *_title;
    NSString *_digest;
    NSString *_cover;
    NSString *_titleWarning;
}

@property(copy, nonatomic) NSString *titleWarning; // @synthesize titleWarning=_titleWarning;
@property(copy, nonatomic) NSString *cover; // @synthesize cover=_cover;
@property(copy, nonatomic) NSString *digest; // @synthesize digest=_digest;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (id)description;

@end

