//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QSMatchLivePropsMessageDisplayView, UIView<QSMatchLivePropsMessageViewProtocol>;

@protocol QSMatchLivePropsMessageDisplayViewDataSource <NSObject>
- (double)displayView:(QSMatchLivePropsMessageDisplayView *)arg1 heightForRowAtIndex:(long long)arg2;
- (UIView<QSMatchLivePropsMessageViewProtocol> *)displayView:(QSMatchLivePropsMessageDisplayView *)arg1 viewForRowAtIndex:(long long)arg2;
- (long long)numberOfRowsInDisplayView:(QSMatchLivePropsMessageDisplayView *)arg1;
@end
