//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommentCellBaseUnitView.h"

@class QNCommentCellMyMentionContentUnitView, QNCommentCellMyMentionPictureUnitView, QNCommentItem;

@interface QNCommentCellMyMentionRefCommentUnitView : QNCommentCellBaseUnitView
{
    CDUnknownBlockType _viewWholeCommentBlock;
    QNCommentCellMyMentionContentUnitView *_replyView;
    QNCommentCellMyMentionPictureUnitView *_picView;
    QNCommentItem *_commentItem;
}

@property(retain, nonatomic) QNCommentItem *commentItem; // @synthesize commentItem=_commentItem;
@property(retain, nonatomic) QNCommentCellMyMentionPictureUnitView *picView; // @synthesize picView=_picView;
@property(retain, nonatomic) QNCommentCellMyMentionContentUnitView *replyView; // @synthesize replyView=_replyView;
@property(copy, nonatomic) CDUnknownBlockType viewWholeCommentBlock; // @synthesize viewWholeCommentBlock=_viewWholeCommentBlock;
- (void).cxx_destruct;
- (void)p_handleTap:(id)arg1;
- (struct _NSRange)realDisplayRange;
- (void)prepareForEnqueue;
- (void)prepareForReuse;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
