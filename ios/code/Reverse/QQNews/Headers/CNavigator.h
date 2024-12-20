//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CPushManager;

@interface CNavigator : NSObject
{
    _Bool _bAlert;
    CPushManager *_pushManager;
}

+ (id)p_supportedNewsDetailTypes;
+ (Class)p_controllerClassWithArticleType:(long long)arg1 listItem:(id)arg2;
+ (Class)p_controllerClassWithPageJumpType:(unsigned long long)arg1;
+ (Class)p_controllerClassWithArticleType:(long long)arg1 pageJumpType:(unsigned long long)arg2 listItem:(id)arg3;
+ (id)p_listItemForCommonParam:(id)arg1;
+ (id)sharedInstance;
@property(retain, nonatomic) CPushManager *pushManager; // @synthesize pushManager=_pushManager;
@property(nonatomic) _Bool bAlert; // @synthesize bAlert=_bAlert;
- (void).cxx_destruct;
- (void)p_doShowAd:(id)arg1 from:(id)arg2;
- (void)p_enterToChannel:(id)arg1;
- (void)navigateToTopicItem:(id)arg1 reportParam:(id)arg2;
- (void)p_enterToRandomChannel:(id)arg1;
- (void)navigateRandomPositionToChannel:(id)arg1 preview:(_Bool)arg2;
- (void)navigateToChannel:(id)arg1 preview:(_Bool)arg2;
- (void)showUserDetailWithListItem:(id)arg1;
- (_Bool)tryShowPersonalPageForUser:(id)arg1 animated:(_Bool)arg2 animationType:(long long)arg3;
- (_Bool)tryShowPersonalPageForUser:(id)arg1 animated:(_Bool)arg2;
- (void)navigateToController:(id)arg1 animated:(_Bool)arg2;
- (void)cancelAsyncPush;
- (void)navigateFromNavigator:(id)arg1 toNews:(id)arg2 fromType:(id)arg3 viewComment:(id)arg4 channel:(id)arg5;
- (void)navigateFromNavigator:(id)arg1 toNews:(id)arg2 fromType:(id)arg3 viewComment:(id)arg4;
- (void)showAd:(id)arg1 from:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)showAd:(id)arg1 from:(id)arg2;
- (void)showCommentAd:(id)arg1 from:(id)arg2;
- (id)p_validateControllerParam:(id)arg1 toType:(long long)arg2 param:(id)arg3;
- (void)p_navigateFrom:(id)arg1 toType:(long long)arg2 pageJumpType:(unsigned long long)arg3 withParam:(id)arg4 animated:(_Bool)arg5 animationType:(long long)arg6 tapToLoadText:(id)arg7 allowUseTopNav:(_Bool)arg8;
- (void)navigateFrom:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4 animationType:(long long)arg5 tapToLoadText:(id)arg6 allowUseTopNav:(_Bool)arg7;
- (void)navigateFrom:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4 animationType:(long long)arg5 tapToLoadText:(id)arg6;
- (void)navigateFrom:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4 animationType:(long long)arg5;
- (void)navigateFrom:(id)arg1 listItem:(id)arg2 withParam:(id)arg3 animated:(_Bool)arg4;
- (void)navigateFrom:(id)arg1 toType:(long long)arg2 withParamBlock:(CDUnknownBlockType)arg3 animated:(_Bool)arg4;
- (void)navigateFrom:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4;
- (void)clearControllerDelegate:(id)arg1;
- (void)popToRootTabRootViewController;
- (id)p_controllerWithType:(long long)arg1 pageJumpType:(unsigned long long)arg2 andParam:(id)arg3;
- (id)controllerWithType:(long long)arg1 andParam:(id)arg2;
- (_Bool)checkNavigationFull:(id)arg1 withControllerType:(long long)arg2;
- (_Bool)shouldAlertWithController:(long long)arg1;
- (void)navigateFromNavigator:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4 animationType:(long long)arg5 tapToLoadText:(id)arg6;
- (void)navigateFromNavigator:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4 animationType:(long long)arg5;
- (void)navigateFromNavigator:(id)arg1 toType:(long long)arg2 withParamBlock:(CDUnknownBlockType)arg3 animated:(_Bool)arg4;
- (void)navigateFromNavigator:(id)arg1 toType:(long long)arg2 withParam:(id)arg3 animated:(_Bool)arg4;
- (id)init;

@end

