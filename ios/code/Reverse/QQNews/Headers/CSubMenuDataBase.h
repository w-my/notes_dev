//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface CSubMenuDataBase : NSObject
{
    NSMutableDictionary *_menuListDictionary;
}

+ (id)getDataFilePathWithChannel:(id)arg1;
+ (id)sharedInstance;
@property(retain, nonatomic, getter=getMenuListDictionary) NSMutableDictionary *menuListDictionary; // @synthesize menuListDictionary=_menuListDictionary;
- (void).cxx_destruct;
- (void)cleanDiskDataWithChannel:(id)arg1;
- (id)getSubMenuList:(id)arg1;
- (id)getFirstChannelIDWithChannel:(id)arg1;
- (id)subMenuItemWithChannel:(id)arg1 andSubChannelID:(id)arg2;
- (id)getFirstSubMenuItem:(id)arg1;
- (id)getSubMenuItemAtIndex:(long long)arg1 channel:(id)arg2;
- (void)writeToDisk:(id)arg1 channel:(id)arg2;
- (void)updateMenuListDictionary:(id)arg1 channel:(id)arg2;
- (id)init;

@end
