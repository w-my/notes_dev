//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "CSimpleImageViewDelegate.h"

@class CSimpleImageViewEx, KBListItem, KBTableViewCellLayoutContext, NSString, QNAttributedLabel, QNEnlargeHitTestButton, UIImageView;

@interface QNModuleHeaderCell : KBTableViewCell <CSimpleImageViewDelegate>
{
    CDUnknownBlockType _clickBlock;
    CSimpleImageViewEx *_headImageView;
    QNAttributedLabel *_titleLbl;
    UIImageView *_hotIconView;
    QNEnlargeHitTestButton *_dislikeButton;
    QNEnlargeHitTestButton *_arrowBtn;
    KBListItem *_kbListItem;
    KBTableViewCellLayoutContext *_context;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (struct UIEdgeInsets)cellInsetsWithContext:(id)arg1;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
@property(retain, nonatomic) QNEnlargeHitTestButton *arrowBtn; // @synthesize arrowBtn=_arrowBtn;
@property(retain, nonatomic) QNEnlargeHitTestButton *dislikeButton; // @synthesize dislikeButton=_dislikeButton;
@property(retain, nonatomic) UIImageView *hotIconView; // @synthesize hotIconView=_hotIconView;
@property(retain, nonatomic) QNAttributedLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) CSimpleImageViewEx *headImageView; // @synthesize headImageView=_headImageView;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
- (void).cxx_destruct;
- (void)_resetViewsColor;
- (void)_dislikeButtonClicked:(id)arg1;
- (void)setImageCompletedWithImageView:(id)arg1 image:(id)arg2;
- (void)p_arrowClicked;
- (id)p_titleAttributeString:(id)arg1 size:(double)arg2;
- (void)themeChanged:(long long)arg1;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
