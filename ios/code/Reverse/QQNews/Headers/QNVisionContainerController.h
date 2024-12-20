//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListContainerController.h"

@class QNVisionHotListController, QNVisionSubMenuManager;

@interface QNVisionContainerController : QNListContainerController
{
    QNVisionSubMenuManager *_visionMenuManager;
    long long _subMenuType;
    QNVisionHotListController *_hotController;
}

@property(retain, nonatomic) QNVisionHotListController *hotController; // @synthesize hotController=_hotController;
@property(nonatomic) long long subMenuType; // @synthesize subMenuType=_subMenuType;
@property(retain, nonatomic) QNVisionSubMenuManager *visionMenuManager; // @synthesize visionMenuManager=_visionMenuManager;
- (void).cxx_destruct;
- (void)scrollViewDidScroll:(id)arg1;
- (id)pageViewPlaceholderViewClassWithChannel:(id)arg1;
- (_Bool)pageViewShouldPreload;
- (void)switchActiveChannelFrom:(id)arg1 to:(id)arg2;
- (id)contentViewControllerWithSubMenuItem:(id)arg1;
- (id)subMenuContainerChannel;
- (id)subMenuDataSource;
- (_Bool)haveSubMenu;
- (_Bool)qnNavigationController:(id)arg1 shouldInteractiveGestureRecognizerBegin:(id)arg2;
- (id)init;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidLoad;

@end

