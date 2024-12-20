//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class NSArray, NSString, QNDetailContentContainer, QNDetailRelateOneTopicView, QNListModuleItem, QNListNewsItem, QNReportParam, UIView;

@interface QNDetailRelateTopicView : QNThemableView <QNDetailContentElementProtocol>
{
    _Bool _exposured;
    QNDetailContentContainer *_contentContainer;
    NSArray *_topicList;
    QNListNewsItem *_listItem;
    QNReportParam *_reportParam;
    UIView *_titleView;
    QNDetailRelateOneTopicView *_oneTopicView;
    QNListModuleItem *_currentModuleItem;
}

@property(retain, nonatomic) QNListModuleItem *currentModuleItem; // @synthesize currentModuleItem=_currentModuleItem;
@property(retain, nonatomic) QNDetailRelateOneTopicView *oneTopicView; // @synthesize oneTopicView=_oneTopicView;
@property(nonatomic) _Bool exposured; // @synthesize exposured=_exposured;
@property(retain, nonatomic) UIView *titleView; // @synthesize titleView=_titleView;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) NSArray *topicList; // @synthesize topicList=_topicList;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
- (void).cxx_destruct;
- (void)p_onTopicItemClick:(id)arg1;
- (void)reloadRelateTopicView;
- (void)layoutWithTopicItems:(id)arg1;
- (void)contentContainer:(id)arg1 ScrolledToPosition:(struct CGPoint)arg2;
- (double)heightOfElementView;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

