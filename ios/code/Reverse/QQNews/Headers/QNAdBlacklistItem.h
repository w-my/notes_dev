//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSArray, NSString;

@interface QNAdBlacklistItem : NSObject <NSCoding>
{
    NSString *_includeKeywords;
    NSString *_position;
    NSArray *_excludeKeywords;
}

@property(readonly, nonatomic) NSArray *excludeKeywords; // @synthesize excludeKeywords=_excludeKeywords;
@property(readonly, nonatomic) NSString *position; // @synthesize position=_position;
@property(readonly, nonatomic) NSString *includeKeywords; // @synthesize includeKeywords=_includeKeywords;
- (void).cxx_destruct;
- (_Bool)isUrlStringValid:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithInfo:(id)arg1;

@end
