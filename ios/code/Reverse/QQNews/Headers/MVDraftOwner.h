//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSDictionary, NSString;

@interface MVDraftOwner : NSObject
{
    NSString *_identifier;
    NSDictionary *_draftTable;
}

+ (id)ownerWithIdentifier:(id)arg1;
+ (id)ownerWithFile:(id)arg1;
@property(retain, nonatomic) NSDictionary *draftTable; // @synthesize draftTable=_draftTable;
@property(retain, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
- (void).cxx_destruct;
- (id)description;
- (_Bool)saveToFile:(id)arg1;
@property(readonly, nonatomic) NSArray *draftsInDraftBox;
@property(readonly, nonatomic) NSString *latestEditingDraft;
- (void)reloadDraftTableWithDrafts:(id)arg1;
- (id)loadDraftsFromDirectory:(id)arg1;

@end

