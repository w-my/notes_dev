//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAutoCodingCopyingObject.h"

@class NSArray, NSDate;

@interface QNSubmenuRecoverKeyChainsData : QNAutoCodingCopyingObject
{
    NSArray *_submenuIDsArray;
    NSArray *_submenuItemList;
    NSDate *_saveDate;
}

+ (id)loadFromKeyChains;
@property(retain, nonatomic) NSDate *saveDate; // @synthesize saveDate=_saveDate;
@property(retain, nonatomic) NSArray *submenuItemList; // @synthesize submenuItemList=_submenuItemList;
@property(retain, nonatomic) NSArray *submenuIDsArray; // @synthesize submenuIDsArray=_submenuIDsArray;
- (void).cxx_destruct;
- (id)description;
- (void)saveToKeyChains;

@end
