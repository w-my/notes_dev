//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNNewsSubMenuView, QNPushRemindAlertView, QNTopicExtendInfoView, QNTopicItem;

@interface QNTopicMiddleContentView : UIView
{
    _Bool _showRemindView;
    _Bool _darkStyle;
    QNTopicExtendInfoView *_infoView;
    QNPushRemindAlertView *_remindView;
    QNNewsSubMenuView *_subMenu;
    QNTopicItem *_topicItem;
}

@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(nonatomic) _Bool darkStyle; // @synthesize darkStyle=_darkStyle;
@property(nonatomic) _Bool showRemindView; // @synthesize showRemindView=_showRemindView;
@property(retain, nonatomic) QNNewsSubMenuView *subMenu; // @synthesize subMenu=_subMenu;
@property(retain, nonatomic) QNPushRemindAlertView *remindView; // @synthesize remindView=_remindView;
@property(retain, nonatomic) QNTopicExtendInfoView *infoView; // @synthesize infoView=_infoView;
- (void).cxx_destruct;
- (void)updateTopicInfoAlpha:(double)arg1 contentOffset:(double)arg2;
- (void)updateDarkStyle:(_Bool)arg1;
- (double)maxTopOffset;
- (void)checkContentViewFrame;
- (void)updateRemindViewWithShow:(_Bool)arg1;
- (void)updateRemindViewWithTopicItem:(id)arg1;
- (void)layoutWithTopicItem:(id)arg1 openDesc:(_Bool)arg2 animation:(_Bool)arg3;
- (id)initWithFrame:(struct CGRect)arg1;

@end
