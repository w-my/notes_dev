//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListUnitModelProtocol.h"

@class NSAttributedString;

@protocol QNListTextUnitModel <QNListUnitModelProtocol>
@property(readonly, nonatomic) _Bool showUnfoldLabel;
@property(readonly, nonatomic) struct CGRect textRect;
@property(readonly, copy, nonatomic) NSAttributedString *attributedText;

@optional
@property(readonly, nonatomic) unsigned long long lineBoundsOption;
@property(readonly, nonatomic) struct CGRect unfoldLabelRect;
@property(readonly, copy, nonatomic) NSAttributedString *unfoldText;
@property(readonly, nonatomic) _Bool enableTapGesture;
@end

