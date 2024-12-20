//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNTableViewCell.h"

#import "QNListCellProtocol.h"

@class NSString, QNTopicProgressHeaderUnit, QNTopicProgressMultiEntryCellModel, QNTopicProgressMultiEntryUnit, UIView;

@interface QNTopicProgressMultiEntryCell : QNTableViewCell <QNListCellProtocol>
{
    CDUnknownBlockType _openBlock;
    CDUnknownBlockType _topicProgressEntryClickBlock;
    UIView *_containerBgView;
    QNTopicProgressHeaderUnit *_headerUnit;
    QNTopicProgressMultiEntryUnit *_multiEntryUnit;
    QNTopicProgressMultiEntryCellModel *_progressMultiEntryModel;
}

@property(retain, nonatomic) QNTopicProgressMultiEntryCellModel *progressMultiEntryModel; // @synthesize progressMultiEntryModel=_progressMultiEntryModel;
@property(retain, nonatomic) QNTopicProgressMultiEntryUnit *multiEntryUnit; // @synthesize multiEntryUnit=_multiEntryUnit;
@property(retain, nonatomic) QNTopicProgressHeaderUnit *headerUnit; // @synthesize headerUnit=_headerUnit;
@property(retain, nonatomic) UIView *containerBgView; // @synthesize containerBgView=_containerBgView;
@property(copy, nonatomic) CDUnknownBlockType topicProgressEntryClickBlock; // @synthesize topicProgressEntryClickBlock=_topicProgressEntryClickBlock;
@property(copy, nonatomic) CDUnknownBlockType openBlock; // @synthesize openBlock=_openBlock;
- (void).cxx_destruct;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

