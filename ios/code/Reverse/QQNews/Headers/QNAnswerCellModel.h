//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommentCellBaseUnitModel.h"

@class NSString, QNAnswerCellContentUnitModel, QNAnswerCellFooterUnitModel, QNAnswerCellHeaderUnitModel, QNAnswerCellPictureUnitModel;

@interface QNAnswerCellModel : QNCommentCellBaseUnitModel
{
    QNAnswerCellHeaderUnitModel *_headerUnitModel;
    QNAnswerCellContentUnitModel *_contentUnitModel;
    QNAnswerCellFooterUnitModel *_footerUnitModel;
    QNAnswerCellPictureUnitModel *_pictureUnitModel;
    NSString *_replyId;
}

@property(copy, nonatomic) NSString *replyId; // @synthesize replyId=_replyId;
@property(retain, nonatomic) QNAnswerCellPictureUnitModel *pictureUnitModel; // @synthesize pictureUnitModel=_pictureUnitModel;
@property(retain, nonatomic) QNAnswerCellFooterUnitModel *footerUnitModel; // @synthesize footerUnitModel=_footerUnitModel;
@property(retain, nonatomic) QNAnswerCellContentUnitModel *contentUnitModel; // @synthesize contentUnitModel=_contentUnitModel;
@property(retain, nonatomic) QNAnswerCellHeaderUnitModel *headerUnitModel; // @synthesize headerUnitModel=_headerUnitModel;
- (void).cxx_destruct;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;
- (id)init;

@end

