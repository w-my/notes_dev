//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, QLCoverRelatedModel;

@protocol QLCoverRelatedModelDelegate <NSObject>

@optional
- (void)requestModel:(QLCoverRelatedModel *)arg1 didFailedLoadWithError:(NSError *)arg2;
- (void)requestModelDidFinishLoad:(QLCoverRelatedModel *)arg1;
@end
