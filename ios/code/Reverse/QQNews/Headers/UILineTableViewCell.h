//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

@class QNRemindBadge, QNRemindPoint, UIColor, UIView;

@interface UILineTableViewCell : QNThemableTableViewCell
{
    _Bool _showRemindBadge;
    _Bool _showRemindPoint;
    long long _topLineStyle;
    long long _botLineStyle;
    UIColor *_seperateLineColor;
    QNRemindBadge *_remindBadge;
    QNRemindPoint *_remindPoint;
    UIView *_separatorLineTopView;
    UIView *_separatorLineBotView;
    struct CGPoint _remindBadgeOrigin;
    struct CGPoint _remindPointOrigin;
    struct CGPoint _remindPointCenter;
}

@property(retain, nonatomic) UIView *separatorLineBotView; // @synthesize separatorLineBotView=_separatorLineBotView;
@property(retain, nonatomic) UIView *separatorLineTopView; // @synthesize separatorLineTopView=_separatorLineTopView;
@property(nonatomic) _Bool showRemindPoint; // @synthesize showRemindPoint=_showRemindPoint;
@property(nonatomic) struct CGPoint remindPointCenter; // @synthesize remindPointCenter=_remindPointCenter;
@property(nonatomic) struct CGPoint remindPointOrigin; // @synthesize remindPointOrigin=_remindPointOrigin;
@property(nonatomic) struct CGPoint remindBadgeOrigin; // @synthesize remindBadgeOrigin=_remindBadgeOrigin;
@property(nonatomic) _Bool showRemindBadge; // @synthesize showRemindBadge=_showRemindBadge;
@property(retain, nonatomic) QNRemindPoint *remindPoint; // @synthesize remindPoint=_remindPoint;
@property(retain, nonatomic) QNRemindBadge *remindBadge; // @synthesize remindBadge=_remindBadge;
@property(retain, nonatomic) UIColor *seperateLineColor; // @synthesize seperateLineColor=_seperateLineColor;
@property(nonatomic) long long botLineStyle; // @synthesize botLineStyle=_botLineStyle;
@property(nonatomic) long long topLineStyle; // @synthesize topLineStyle=_topLineStyle;
- (void).cxx_destruct;
- (double)qn_mineTableViewCellLineCustomLineWidth;
- (double)qn_mineTableViewCellLineCustomLineOffsetX;
- (void)p_initRemindPoint;
- (struct CGRect)getRemindPointFrame;
- (struct CGRect)getRemindBadgeFrame;
- (void)showRemindBadgeWithCount:(long long)arg1;
- (void)p_initRemindBadge;
- (void)showPreviousBotLine:(_Bool)arg1;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (double)separatorLineHeight;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

