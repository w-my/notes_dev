//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UINavigationController.h"

@interface PtNavigationController : UINavigationController
{
    _Bool _bIsAutoRotate;
    long long _statusBarStyle;
}

@property long long statusBarStyle; // @synthesize statusBarStyle=_statusBarStyle;
@property _Bool bIsAutoRotate; // @synthesize bIsAutoRotate=_bIsAutoRotate;
- (void)setAutoRotate:(_Bool)arg1;
- (id)init;
- (_Bool)shouldAutorotate;
- (long long)preferredStatusBarStyle;

@end

