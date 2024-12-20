//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

@class KBListItem, KBTableViewCellLayoutContext, QNHotEventSpecialNewsBackgroundView, QNReportParam;

@interface QNHotEventSpecialNewsCell : KBTableViewCell
{
    CDUnknownBlockType _focusClickBlock;
    CDUnknownBlockType _normalClickBlock;
    CDUnknownBlockType _footerClickBlock;
    QNHotEventSpecialNewsBackgroundView *_hotEventSpecialNewsBgView;
    KBListItem *_item;
    KBTableViewCellLayoutContext *_context;
    QNReportParam *_reportParam;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *item; // @synthesize item=_item;
@property(retain, nonatomic) QNHotEventSpecialNewsBackgroundView *hotEventSpecialNewsBgView; // @synthesize hotEventSpecialNewsBgView=_hotEventSpecialNewsBgView;
@property(copy, nonatomic) CDUnknownBlockType footerClickBlock; // @synthesize footerClickBlock=_footerClickBlock;
@property(copy, nonatomic) CDUnknownBlockType normalClickBlock; // @synthesize normalClickBlock=_normalClickBlock;
@property(copy, nonatomic) CDUnknownBlockType focusClickBlock; // @synthesize focusClickBlock=_focusClickBlock;
- (void).cxx_destruct;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)themeChanged:(long long)arg1;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end

