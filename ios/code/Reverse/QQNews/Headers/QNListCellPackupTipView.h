//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRecommendUnlikeTipViewBase.h"

@class QNListNewsItem, UIView;

@interface QNListCellPackupTipView : QNRecommendUnlikeTipViewBase
{
    UIView *_backgroundContainer;
    QNListNewsItem *_listItem;
}

@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) UIView *backgroundContainer; // @synthesize backgroundContainer=_backgroundContainer;
- (void).cxx_destruct;
- (void)p_receivedNotification:(id)arg1;
- (void)p_disappearWithUnlikeOperation:(long long)arg1;
- (void)p_packup:(id)arg1;
- (void)showUnlikeTipsInTableViewCell:(id)arg1 position:(struct CGPoint)arg2 listItem:(id)arg3 completion:(CDUnknownBlockType)arg4;
- (void)dealloc;
- (id)init;
- (id)initWithFrame:(struct CGRect)arg1;

@end
