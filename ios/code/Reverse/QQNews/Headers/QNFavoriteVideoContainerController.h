//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListContainerController.h"

@class CSubMenuManager, QNBarButton, QNMyFavoriteCommonVideoContrller, QNMyFavoriteVideoViewController;

@interface QNFavoriteVideoContainerController : QNListContainerController
{
    QNBarButton *_closeButton;
    CSubMenuManager *_menuManager;
    QNMyFavoriteCommonVideoContrller *_commonVideoContrller;
    QNMyFavoriteVideoViewController *_xiaoshipinVideoContrller;
}

@property(retain, nonatomic) QNMyFavoriteVideoViewController *xiaoshipinVideoContrller; // @synthesize xiaoshipinVideoContrller=_xiaoshipinVideoContrller;
@property(retain, nonatomic) QNMyFavoriteCommonVideoContrller *commonVideoContrller; // @synthesize commonVideoContrller=_commonVideoContrller;
@property(retain, nonatomic) CSubMenuManager *menuManager; // @synthesize menuManager=_menuManager;
@property(retain, nonatomic) QNBarButton *closeButton; // @synthesize closeButton=_closeButton;
- (void).cxx_destruct;
- (void)switchActiveChannelFrom:(id)arg1 to:(id)arg2;
- (id)pageViewPlaceholderViewClassWithChannel:(id)arg1;
- (_Bool)pageViewShouldPreload;
- (id)contentViewControllerWithSubMenuItem:(id)arg1;
- (id)subMenuDataSource;
- (long long)subMenuType;
- (_Bool)haveSubMenu;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

@end
