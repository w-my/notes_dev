//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KindaView.h"

#import "MMKViewLayout.h"

@class NSString;

@interface KindaLayout : KindaView <MMKViewLayout>
{
    long long flexDirection;
    long long justifyContent;
    long long flexWrap;
    long long alignItems;
    long long alignContent;
}

- (void)removeAllViews;
- (void)removeView:(id)arg1;
- (void)addView:(id)arg1 position:(int)arg2;
- (void)addView:(id)arg1;
- (long long)getAlignContent;
- (void)setAlignContent:(long long)arg1;
- (long long)getAlignItems;
- (void)setAlignItems:(long long)arg1;
- (long long)getFlexWrap;
- (void)setFlexWrap:(long long)arg1;
- (long long)getJustifyContent;
- (void)setJustifyContent:(long long)arg1;
- (long long)getFlexDirection;
- (void)setFlexDirection:(long long)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

