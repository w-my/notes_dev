//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListContainerController.h"

@class QNControllerParam;

@interface QNMyPublishViewController : QNListContainerController
{
    QNControllerParam *_param;
}

@property(retain, nonatomic) QNControllerParam *param; // @synthesize param=_param;
- (void).cxx_destruct;
- (id)pageViewPlaceholderViewClassWithChannel:(id)arg1;
- (_Bool)pageViewShouldPreload;
- (void)switchActiveChannelFrom:(id)arg1 to:(id)arg2;
- (id)contentViewControllerWithSubMenuItem:(id)arg1;
- (id)subMenuDataSource;
- (long long)subMenuType;
- (_Bool)haveSubMenu;
- (_Bool)qnNavigationController:(id)arg1 shouldInteractiveGestureRecognizerBegin:(id)arg2;
- (void)onBack:(id)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

@end
