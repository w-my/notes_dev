//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNativeWidgetView.h"

#import "QNCommentCellActionDelegate.h"

@class NSString, QNCommentCell, QNCommentViewModel, QNWidgetNodeArticleComment, UILabel;

@interface QNNativeWidgetArticleComment : QNNativeWidgetView <QNCommentCellActionDelegate>
{
    _Bool _widgetNeedLayout;
    QNCommentCell *_commentView;
    UILabel *_fromLabel;
    QNCommentViewModel *_viewModel;
    QNWidgetNodeArticleComment *_commentNode;
}

+ (id)p_commentCellLayoutContext;
+ (struct CGSize)sizeForViewWithData:(id)arg1 width:(double)arg2 isNoPicMode:(_Bool)arg3;
@property(retain, nonatomic) QNWidgetNodeArticleComment *commentNode; // @synthesize commentNode=_commentNode;
@property(nonatomic) _Bool widgetNeedLayout; // @synthesize widgetNeedLayout=_widgetNeedLayout;
@property(retain, nonatomic) QNCommentViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(retain, nonatomic) UILabel *fromLabel; // @synthesize fromLabel=_fromLabel;
@property(retain, nonatomic) QNCommentCell *commentView; // @synthesize commentView=_commentView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_validateTheme;
- (void)commentCellActionReport:(id)arg1;
- (void)commentCellActionReplyComment:(id)arg1;
- (void)commentCellActionDeclare:(id)arg1 state:(long long)arg2;
- (_Bool)canPerformCommentCellAction:(SEL)arg1 commentItem:(id)arg2 category:(id)arg3;
- (void)p_handleKeyboardWillHideNotify:(id)arg1;
- (id)p_listItemForComment:(id)arg1;
- (long long)widgetViewType;
- (void)layoutViewWithData:(id)arg1;
- (void)layoutSubviews;
- (void)setFrame:(struct CGRect)arg1;
- (id)initWidget;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

