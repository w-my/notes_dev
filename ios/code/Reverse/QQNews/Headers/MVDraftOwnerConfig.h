//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface MVDraftOwnerConfig : NSObject <NSCoding>
{
    NSString *_latestEditingMedia;
}

+ (id)ownerConfigWithFile:(id)arg1;
@property(retain, nonatomic) NSString *latestEditingMedia; // @synthesize latestEditingMedia=_latestEditingMedia;
- (void).cxx_destruct;
- (_Bool)saveToFile:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end
