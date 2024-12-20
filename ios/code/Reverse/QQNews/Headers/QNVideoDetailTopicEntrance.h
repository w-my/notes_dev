//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNAttributedLabel, QNListNewsItem, QNReportParam, QNTopicItem, UIView;

@interface QNVideoDetailTopicEntrance : QNThemableView
{
    QNListNewsItem *_listItem;
    QNReportParam *_reportParam;
    QNTopicItem *_topicItem;
    UIView *_bgView;
    QNAttributedLabel *_topicLabel;
}

@property(retain, nonatomic) QNAttributedLabel *topicLabel; // @synthesize topicLabel=_topicLabel;
@property(retain, nonatomic) UIView *bgView; // @synthesize bgView=_bgView;
@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)p_tapOnTopic:(id)arg1;
- (void)reloadWithTopicItem:(id)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

