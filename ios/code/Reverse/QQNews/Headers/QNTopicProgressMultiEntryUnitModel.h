//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListUnitModelProtocol.h"

@class NSArray, NSString, UIColor;

@interface QNTopicProgressMultiEntryUnitModel : NSObject <QNListUnitModelProtocol>
{
    _Bool _isUnfold;
    id <QNListModelProtocol> _data;
    UIColor *_bgColor;
    NSArray *_entryModelList;
    struct CGRect _rect;
    struct CGRect _arrowDownRect;
}

@property(readonly, nonatomic) _Bool isUnfold; // @synthesize isUnfold=_isUnfold;
@property(readonly, nonatomic) struct CGRect arrowDownRect; // @synthesize arrowDownRect=_arrowDownRect;
@property(readonly, copy, nonatomic) NSArray *entryModelList; // @synthesize entryModelList=_entryModelList;
@property(readonly, nonatomic) UIColor *bgColor; // @synthesize bgColor=_bgColor;
@property(readonly, nonatomic) struct CGRect rect; // @synthesize rect=_rect;
@property(readonly, nonatomic) id <QNListModelProtocol> data; // @synthesize data=_data;
- (void).cxx_destruct;
- (void)p_createEntryModelList:(id)arg1;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
