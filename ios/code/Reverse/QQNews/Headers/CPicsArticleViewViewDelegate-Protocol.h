//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSNumber;

@protocol CPicsArticleViewViewDelegate <NSObject>
- (void)failLoadContent;
- (void)picsContentHasShow:(NSNumber *)arg1;
- (void)picsClicked;
- (void)picChangeToNumber:(NSNumber *)arg1;

@optional
- (void)picOffsetXChanged:(double)arg1;
@end
