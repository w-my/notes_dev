//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNListUnitProtocol.h"

@class NSArray, NSString, QNTopicProgressMultiEntryUnitModel, UIImageView;

@interface QNTopicProgressMultiEntryUnit : UIView <QNListUnitProtocol>
{
    CDUnknownBlockType _openBlock;
    CDUnknownBlockType _topicProgressEntryClickBlock;
    NSArray *_topicProgressEntryArray;
    QNTopicProgressMultiEntryUnitModel *_multiEntryUnitModel;
    UIView *_arrowDownView;
    UIImageView *_arrowImageView;
}

@property(retain, nonatomic) UIImageView *arrowImageView; // @synthesize arrowImageView=_arrowImageView;
@property(retain, nonatomic) UIView *arrowDownView; // @synthesize arrowDownView=_arrowDownView;
@property(retain, nonatomic) QNTopicProgressMultiEntryUnitModel *multiEntryUnitModel; // @synthesize multiEntryUnitModel=_multiEntryUnitModel;
@property(copy, nonatomic) NSArray *topicProgressEntryArray; // @synthesize topicProgressEntryArray=_topicProgressEntryArray;
@property(copy, nonatomic) CDUnknownBlockType topicProgressEntryClickBlock; // @synthesize topicProgressEntryClickBlock=_topicProgressEntryClickBlock;
@property(copy, nonatomic) CDUnknownBlockType openBlock; // @synthesize openBlock=_openBlock;
- (void).cxx_destruct;
- (void)p_arrowDownClicked;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
