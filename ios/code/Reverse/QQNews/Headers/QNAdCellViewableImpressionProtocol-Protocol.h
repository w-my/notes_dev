//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNAdItem, TADReportManager;

@protocol QNAdCellViewableImpressionProtocol <NSObject>
@property(retain, nonatomic) QNAdItem *adItem;
@property(nonatomic) __weak TADReportManager *adReportManager;
- (void)adCellDidAppear;
@end
