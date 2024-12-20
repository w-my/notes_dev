//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommentCellBaseUnitModel.h"

@class QNBaseViewModel, QNCommentCellContentUnitModel, QNCommentCellPictureUnitModel, QNCommentCellRelevantRefNewsUnitModel;

@interface QNCommentCellRefCommentUnitModel : QNCommentCellBaseUnitModel
{
    QNCommentCellContentUnitModel *_replyUnit;
    QNCommentCellPictureUnitModel *_pictureUnit;
    QNBaseViewModel *_separatorUnit;
    QNCommentCellRelevantRefNewsUnitModel *_refNewsUnit;
}

@property(retain, nonatomic) QNCommentCellRelevantRefNewsUnitModel *refNewsUnit; // @synthesize refNewsUnit=_refNewsUnit;
@property(retain, nonatomic) QNBaseViewModel *separatorUnit; // @synthesize separatorUnit=_separatorUnit;
@property(retain, nonatomic) QNCommentCellPictureUnitModel *pictureUnit; // @synthesize pictureUnit=_pictureUnit;
@property(retain, nonatomic) QNCommentCellContentUnitModel *replyUnit; // @synthesize replyUnit=_replyUnit;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

@end

