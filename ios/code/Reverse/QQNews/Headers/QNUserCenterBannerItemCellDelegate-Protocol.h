//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNUserCenterBannerItemCell, QNUserCenterCellEntity, QNWebView;

@protocol QNUserCenterBannerItemCellDelegate <NSObject>

@optional
- (void)bannerItemCell:(QNUserCenterBannerItemCell *)arg1 webviewDidLoadSuccess:(QNWebView *)arg2 contentHeight:(double)arg3 withEntity:(QNUserCenterCellEntity *)arg4;
@end

