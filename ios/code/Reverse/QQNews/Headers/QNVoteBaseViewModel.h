//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNListUnitModelProtocol.h"

@class NSArray, NSString, QNVoteBaseViewSubmitUnitModel, QNVoteBaseViewTwoChoiceUnitModel, UIColor;

@interface QNVoteBaseViewModel : NSObject <QNListUnitModelProtocol>
{
    _Bool _isTwoChoice;
    _Bool _isUnfold;
    id <QNListModelProtocol> _data;
    UIColor *_bgColor;
    NSArray *_questionChoiceUnitModelList;
    QNVoteBaseViewTwoChoiceUnitModel *_twoChoiceUnitModel;
    QNVoteBaseViewSubmitUnitModel *_submitUnitModel;
    struct CGRect _rect;
}

@property(readonly, nonatomic) _Bool isUnfold; // @synthesize isUnfold=_isUnfold;
@property(readonly, nonatomic) _Bool isTwoChoice; // @synthesize isTwoChoice=_isTwoChoice;
@property(readonly, nonatomic) QNVoteBaseViewSubmitUnitModel *submitUnitModel; // @synthesize submitUnitModel=_submitUnitModel;
@property(readonly, nonatomic) QNVoteBaseViewTwoChoiceUnitModel *twoChoiceUnitModel; // @synthesize twoChoiceUnitModel=_twoChoiceUnitModel;
@property(readonly, copy, nonatomic) NSArray *questionChoiceUnitModelList; // @synthesize questionChoiceUnitModelList=_questionChoiceUnitModelList;
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

