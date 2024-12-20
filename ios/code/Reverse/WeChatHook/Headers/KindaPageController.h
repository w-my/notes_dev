//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "KindaTinyAppUIPageDelegate.h"
#import "KindaViewControllerControlDelegate.h"
#import "MMIUIPageController.h"

@class KindaTinyAppUIPage, NSString;

@interface KindaPageController : NSObject <KindaViewControllerControlDelegate, KindaTinyAppUIPageDelegate, MMIUIPageController>
{
    KindaTinyAppUIPage *_tinyAppPage;
}

@property(retain, nonatomic) KindaTinyAppUIPage *tinyAppPage; // @synthesize tinyAppPage=_tinyAppPage;
- (void).cxx_destruct;
- (void)tinyAppDidClose:(id)arg1;
- (void)onCloseUI:(id)arg1;
- (void)startModalPageUI:(id)arg1 transitionStyle:(long long)arg2 extraData:(id)arg3;
- (void)startPageUI:(id)arg1 extraData:(id)arg2;
- (void)presentVC:(id)arg1;
- (void)pushVC:(id)arg1;
- (void)openTinyApp:(id)arg1 extraData:(id)arg2;
- (void)presentWebView:(id)arg1 extraData:(id)arg2;
- (void)pushWebView:(id)arg1 extraData:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

