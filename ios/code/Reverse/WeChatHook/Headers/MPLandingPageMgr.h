//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IExptServiceExt.h"
#import "MMService.h"

@class NSMutableDictionary, NSString;

@interface MPLandingPageMgr : MMService <IExptServiceExt, MMService>
{
    _Bool _isOpenVideoNativePageExpt;
    NSMutableDictionary *_dicVideoPageUrl2Progress;
}

@property(retain, nonatomic) NSMutableDictionary *dicVideoPageUrl2Progress; // @synthesize dicVideoPageUrl2Progress=_dicVideoPageUrl2Progress;
@property(nonatomic) _Bool isOpenVideoNativePageExpt; // @synthesize isOpenVideoNativePageExpt=_isOpenVideoNativePageExpt;
- (void).cxx_destruct;
- (void)saveVideoProgress:(double)arg1 url:(id)arg2;
- (double)getVideoProgressByUrl:(id)arg1;
- (void)onExptItemListChange;
- (_Bool)isOpenVideoLandingPageSwitch;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

