//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "CSubMenuProtocol.h"

@class NSArray, NSString;

@interface CSubMenuManager : NSObject <CSubMenuProtocol>
{
    NSArray *_menuList;
}

@property(retain, nonatomic) NSArray *menuList; // @synthesize menuList=_menuList;
- (void).cxx_destruct;
- (void)changeSubMenuList:(id)arg1;
- (id)getSubMenuList;
- (unsigned long long)getIndexInCurrentByChannelID:(id)arg1;
- (id)getFirstSubMenuItem;
- (id)getSubMenuItemAtIndex:(long long)arg1;
- (void)createSubMenuList;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
