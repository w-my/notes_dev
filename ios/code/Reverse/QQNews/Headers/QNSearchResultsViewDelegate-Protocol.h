//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, QNSearchResultsView;

@protocol QNSearchResultsViewDelegate <NSObject>

@optional
- (void)switchTabWithSecType:(unsigned long long)arg1;
- (void)searchResultView:(QNSearchResultsView *)arg1 showKeyboard:(_Bool)arg2;
- (void)createResultControllerWithSearchKeyword:(NSString *)arg1;
@end
