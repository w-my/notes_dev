//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

@class CSimpleImageView, KBListItem, KBTableViewCellLayoutContext, QNBaseLabel, QNEnlargeHitTestButton, UIImageView;

@interface QNChannelGuideKuaiShouCell : KBTableViewCell
{
    _Bool _isAnimating;
    CSimpleImageView *_simpleImageView;
    UIImageView *_blackBGView;
    QNBaseLabel *_titleLbl;
    QNBaseLabel *_descLbl;
    QNEnlargeHitTestButton *_addCHannelBtn;
    UIImageView *_arrowImageView;
    KBListItem *_kbListItem;
    KBTableViewCellLayoutContext *_context;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (id)reuseIdentifierForData:(id)arg1;
+ (double)imageHeight;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
@property(nonatomic) _Bool isAnimating; // @synthesize isAnimating=_isAnimating;
@property(retain, nonatomic) UIImageView *arrowImageView; // @synthesize arrowImageView=_arrowImageView;
@property(retain, nonatomic) QNEnlargeHitTestButton *addCHannelBtn; // @synthesize addCHannelBtn=_addCHannelBtn;
@property(retain, nonatomic) QNBaseLabel *descLbl; // @synthesize descLbl=_descLbl;
@property(retain, nonatomic) QNBaseLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) UIImageView *blackBGView; // @synthesize blackBGView=_blackBGView;
@property(retain, nonatomic) CSimpleImageView *simpleImageView; // @synthesize simpleImageView=_simpleImageView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)_channelStateChanged;
- (void)_onAddChannelBtnClick;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
