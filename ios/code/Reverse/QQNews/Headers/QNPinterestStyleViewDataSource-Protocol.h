//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNPinterestStyleView, QNPinterestStyleViewCell;

@protocol QNPinterestStyleViewDataSource <NSObject>
- (long long)numberOfRows:(QNPinterestStyleView *)arg1;
- (QNPinterestStyleViewCell *)collectionView:(QNPinterestStyleView *)arg1 cellForRowAtIndex:(long long)arg2;

@optional
- (long long)numberOfColumns:(QNPinterestStyleView *)arg1;
@end
