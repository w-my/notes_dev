//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "WAOrientationSuggestionViewControllerDelegate.h"

@class MMUIWindow, NSString, WAOrientationSuggestionViewController;

@interface WAIpadAdaptLogic : MMObject <WAOrientationSuggestionViewControllerDelegate>
{
    MMUIWindow *_suggestionWindow;
    WAOrientationSuggestionViewController *_suggestionViewController;
    id <WAOrientationSuggestionWindowDelegate> _delegate;
}

+ (_Bool)needIpadCustomTransition:(_Bool)arg1;
+ (id)IsPresentedByAnotherWeApp:(id)arg1;
+ (_Bool)IsPresentedByMainViewControllerInIpad:(id)arg1;
+ (_Bool)currentNavigationControllerHasPrevWeAppVC:(id)arg1;
+ (_Bool)checkIfNeedIpadSpecialPresentLogic:(id)arg1 PresentingVC:(id *)arg2;
@property(nonatomic) __weak id <WAOrientationSuggestionWindowDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) __weak WAOrientationSuggestionViewController *suggestionViewController; // @synthesize suggestionViewController=_suggestionViewController;
@property(retain, nonatomic) MMUIWindow *suggestionWindow; // @synthesize suggestionWindow=_suggestionWindow;
- (void).cxx_destruct;
- (void)onQuitButtonClicked;
- (_Bool)tryAddOrRemoveMaskView:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
