//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMTabBarController.h"

#import "MMTabBarControllerDelegate.h"
#import "WCLazyInitObjectProtocol.h"

@class ContactsViewController, FindFriendEntryViewController, MMTabbarItem, MoreViewController, NSMutableArray, NSString, NewMainFrameViewController;

@interface MainTabBarViewController : MMTabBarController <MMTabBarControllerDelegate, WCLazyInitObjectProtocol>
{
    unsigned int m_whatHasInit;
    NewMainFrameViewController *m_mainFrameViewController;
    MMTabbarItem *m_mainFrameTabItem;
    ContactsViewController *m_contactsViewController;
    MMTabbarItem *m_contacsTabItem;
    FindFriendEntryViewController *m_findFriendEntryViewController;
    MMTabbarItem *m_findFrientTabItem;
    MoreViewController *m_moreViewController;
    MMTabbarItem *m_moreTabItem;
    NSMutableArray *m_arrViewController;
    _Bool haveLazyInit;
    id <MainTabBarControllerDelegate> _mainDelegate;
}

@property(nonatomic) __weak id <MainTabBarControllerDelegate> mainDelegate; // @synthesize mainDelegate=_mainDelegate;
@property(nonatomic) _Bool haveLazyInit; // @synthesize haveLazyInit;
- (void).cxx_destruct;
- (void)recreateFindFriendViewController;
- (void)p_createMoreViewController;
- (id)p_getMoreViewController;
- (void)p_createFindFriendViewController;
- (id)p_getFindFriendEntryViewController;
- (void)p_createContactsViewController;
- (id)p_getContactsViewController;
- (void)p_createNewMainFrameViewController;
- (id)p_getNewMainFrameViewController;
- (void)p_createSlimViewControllers;
- (void)p_createTabBarItems;
- (void)p_tryToInitAllControllers;
@property(nonatomic) unsigned long long selectedIndex;
- (id)init;
- (void)tabBarController:(id)arg1 didSelectViewController:(id)arg2;
- (_Bool)tabBarController:(id)arg1 shouldSelectViewController:(id)arg2;
- (void)OnMainFrameDoubleClicked:(id)arg1;
- (id)getAllNavigationControllers;
- (id)getNavigationContollerAtIndex:(unsigned long long)arg1;
- (id)getAllTabBaseViewControllers;
- (id)getTabBarBaseViewController:(unsigned long long)arg1;
- (id)getNewMainFrameViewController;
- (void)goToLazyInitObject;
- (double)timeToLazyInitAfterOpenFirstView;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
