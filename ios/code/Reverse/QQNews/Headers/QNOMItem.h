//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"
#import "QNListModelProtocol.h"

@class NSArray, NSString;

@interface QNOMItem : QNBaseModelObject <QNListModelProtocol, NSCopying, NSCoding>
{
    _Bool _calculated;
    NSArray *_omList;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool calculated; // @synthesize calculated=_calculated;
@property(copy, nonatomic) NSArray *omList; // @synthesize omList=_omList;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)isEqualToDiffableObject:(id)arg1;
- (id)uniqueIdentifier;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
