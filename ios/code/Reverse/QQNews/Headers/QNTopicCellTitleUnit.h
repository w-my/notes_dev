//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNListUnitProtocol.h"
#import "UIGestureRecognizerDelegate.h"

@class NSString, QNAttributedLabel, QNEnlargeHitTestButton, QNListNewsItem, QNReportParam, QNTopicCellTitleUnitModel;

@interface QNTopicCellTitleUnit : UIView <UIGestureRecognizerDelegate, QNListUnitProtocol>
{
    QNReportParam *_reportParam;
    QNListNewsItem *_listItem;
    QNTopicCellTitleUnitModel *_titleUnitModel;
    QNAttributedLabel *_contentLabel;
    QNEnlargeHitTestButton *_openArticleBtn;
}

@property(retain, nonatomic) QNEnlargeHitTestButton *openArticleBtn; // @synthesize openArticleBtn=_openArticleBtn;
@property(retain, nonatomic) QNAttributedLabel *contentLabel; // @synthesize contentLabel=_contentLabel;
@property(retain, nonatomic) QNTopicCellTitleUnitModel *titleUnitModel; // @synthesize titleUnitModel=_titleUnitModel;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
- (void).cxx_destruct;
- (void)p_handleTapGesture:(id)arg1;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)p_openArticle;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
