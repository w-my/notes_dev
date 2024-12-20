//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNCommentCellUnitProtocol.h"
#import "QNListUnitProtocol.h"

@class NSString, QNCommentCellBaseUnitModel;

@interface QNCommentCellBaseUnitView : QNThemableView <QNListUnitProtocol, QNCommentCellUnitProtocol>
{
    QNCommentCellBaseUnitModel *_unitModel;
}

@property(retain, nonatomic) QNCommentCellBaseUnitModel *unitModel; // @synthesize unitModel=_unitModel;
- (void).cxx_destruct;
- (void)prepareForReuse;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

