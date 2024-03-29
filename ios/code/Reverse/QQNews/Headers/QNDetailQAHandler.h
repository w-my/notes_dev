//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNDetailBaseHandler.h"

#import "QNDetailHandlerDelegate.h"

@class CArticleContentType, QNComment, QNDetailComponentImage, QNDetailComponentQAComponents, QNListNewsItem, QNLoadingShimmerView, QNQACommentView, QNQADetailCommnModel, QNQADetailModel, QNQADetailReplyInfoParams, UIView;

@interface QNDetailQAHandler : QNDetailBaseHandler <QNDetailHandlerDelegate>
{
    _Bool _isDeleted;
    _Bool _isHadLoad;
    QNDetailComponentQAComponents *_qaComponent;
    QNDetailComponentImage *_imageComponent;
    QNListNewsItem *_listItem;
    CArticleContentType *_articleContent;
    id <QNQADetailHTMLNewsViewProtocol> _qADetailHTMLNewsViewDelegate;
    QNQACommentView *_htmlsCommentView;
    QNComment *_rootComment;
    QNQADetailReplyInfoParams *_params;
    unsigned long long _qQHtmlsViewType;
    QNQADetailModel *_qADetailModel;
    QNQADetailCommnModel *_contentTypeModel;
    UIView *_splitline;
    QNLoadingShimmerView *_qaloadingView;
}

@property(retain, nonatomic) QNLoadingShimmerView *qaloadingView; // @synthesize qaloadingView=_qaloadingView;
@property(retain, nonatomic) UIView *splitline; // @synthesize splitline=_splitline;
@property(nonatomic) _Bool isHadLoad; // @synthesize isHadLoad=_isHadLoad;
@property(nonatomic) _Bool isDeleted; // @synthesize isDeleted=_isDeleted;
@property(retain, nonatomic) QNQADetailCommnModel *contentTypeModel; // @synthesize contentTypeModel=_contentTypeModel;
@property(retain, nonatomic) QNQADetailModel *qADetailModel; // @synthesize qADetailModel=_qADetailModel;
@property(nonatomic) unsigned long long qQHtmlsViewType; // @synthesize qQHtmlsViewType=_qQHtmlsViewType;
@property(retain, nonatomic) QNQADetailReplyInfoParams *params; // @synthesize params=_params;
@property(retain, nonatomic) QNComment *rootComment; // @synthesize rootComment=_rootComment;
@property(readonly, nonatomic) QNQACommentView *htmlsCommentView; // @synthesize htmlsCommentView=_htmlsCommentView;
@property(nonatomic) __weak id <QNQADetailHTMLNewsViewProtocol> qADetailHTMLNewsViewDelegate; // @synthesize qADetailHTMLNewsViewDelegate=_qADetailHTMLNewsViewDelegate;
@property(retain, nonatomic) CArticleContentType *articleContent; // @synthesize articleContent=_articleContent;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(readonly, nonatomic) QNDetailComponentImage *imageComponent; // @synthesize imageComponent=_imageComponent;
@property(readonly, nonatomic) QNDetailComponentQAComponents *qaComponent; // @synthesize qaComponent=_qaComponent;
- (void).cxx_destruct;
- (void)loadingFailed;
- (void)removeLoadingView;
- (void)showLoadingView;
- (void)prepareImageWithInfo:(id)arg1;
- (void)clearContentContainerTop;
- (void)p_doLayoutContent;
- (void)loadContents:(id)arg1 contentTypeModel:(id)arg2 rootComment:(id)arg3;
- (void)initSubClassViews;
- (id)componentControlsArray;
- (void)webviewDidShow;
- (double)webViewHasFinishNavigationWithLastReadPositionY;
- (void)dealloc;
- (id)initWithController:(id)arg1 controllerContainerView:(id)arg2 contentViewFrame:(struct CGRect)arg3;
- (void)webViewWebContentProcessDidTerminate:(id)arg1;

@end

