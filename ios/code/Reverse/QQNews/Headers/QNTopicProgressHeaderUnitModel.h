//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListUnitModelProtocol.h"

@class NSString, UIColor;

@interface QNTopicProgressHeaderUnitModel : NSObject <QNListUnitModelProtocol>
{
    id <QNListModelProtocol> _data;
    UIColor *_bgColor;
    UIColor *_titleColor;
    NSString *_title;
    struct CGRect _rect;
    struct CGRect _titleRect;
}

@property(readonly, nonatomic) struct CGRect titleRect; // @synthesize titleRect=_titleRect;
@property(readonly, copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(readonly, nonatomic) UIColor *titleColor; // @synthesize titleColor=_titleColor;
@property(readonly, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(readonly, nonatomic) struct CGRect rect; // @synthesize rect=_rect;
@property(readonly, nonatomic) id <QNListModelProtocol> data; // @synthesize data=_data;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

