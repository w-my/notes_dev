//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListCellModelProtocol.h"

@class NSString, UIColor;

@interface QNTopicScrollIndexCellModel : NSObject <QNListCellModelProtocol>
{
    id <QNListModelProtocol> _data;
    UIColor *_bgColor;
    struct CGRect _rect;
}

@property(retain, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct CGRect rect; // @synthesize rect=_rect;
@property(retain, nonatomic) id <QNListModelProtocol> data; // @synthesize data=_data;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
