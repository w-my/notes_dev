//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListContainerController.h"

@class CFavoritesController, QNBarButton, QNFavoriteHistorySubMenuManager, QNPushHistoryViewController, QNReadHistoryViewController;

@interface QNFavoriteHistoryRoomController : QNListContainerController
{
    QNFavoriteHistorySubMenuManager *_menuManager;
    CFavoritesController *_favoritesCtl;
    QNReadHistoryViewController *_historyCtl;
    QNPushHistoryViewController *_pushCtl;
    QNBarButton *_closeButton;
    QNBarButton *_editBtn;
}

@property(retain, nonatomic) QNBarButton *editBtn; // @synthesize editBtn=_editBtn;
@property(retain, nonatomic) QNBarButton *closeButton; // @synthesize closeButton=_closeButton;
@property(retain, nonatomic) QNPushHistoryViewController *pushCtl; // @synthesize pushCtl=_pushCtl;
@property(retain, nonatomic) QNReadHistoryViewController *historyCtl; // @synthesize historyCtl=_historyCtl;
@property(retain, nonatomic) CFavoritesController *favoritesCtl; // @synthesize favoritesCtl=_favoritesCtl;
@property(retain, nonatomic) QNFavoriteHistorySubMenuManager *menuManager; // @synthesize menuManager=_menuManager;
- (void).cxx_destruct;
- (id)pageViewPlaceholderViewClassWithChannel:(id)arg1;
- (_Bool)pageViewShouldPreload;
- (void)switchActiveChannelFrom:(id)arg1 to:(id)arg2;
- (id)contentViewControllerWithSubMenuItem:(id)arg1;
- (id)subMenuContainerChannel;
- (id)subMenuDataSource;
- (long long)subMenuType;
- (_Bool)haveSubMenu;
- (void)onEdit:(id)arg1;
- (void)updateEditButton;
- (void)onBack:(id)arg1;
- (id)getCurrentCtr;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

@end
