//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNPinterestStyleView, QNPinterestStyleViewCell;

@protocol QNPinterestStyleViewDelegate <NSObject>
- (double)collectionView:(QNPinterestStyleView *)arg1 heightForRowAtIndex:(long long)arg2 width:(double)arg3;

@optional
- (void)collectionView:(QNPinterestStyleView *)arg1 action:(long long)arg2 atIndex:(unsigned long long)arg3;
- (void)collectionView:(QNPinterestStyleView *)arg1 didSelectRowAtIndex:(long long)arg2;
- (void)collectionView:(QNPinterestStyleView *)arg1 willDisplayCell:(QNPinterestStyleViewCell *)arg2 forRowAtIndex:(long long)arg3;
@end

