//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSString, UIButton, UILabel;

@interface QNAddChannelTipsView : QNThemableView
{
    _Bool _isAnimating;
    NSString *_channelId;
    CDUnknownBlockType _callBack;
    UILabel *_descLbl;
    UIButton *_addBtn;
    UIButton *_hasAddBtn;
}

@property(nonatomic) _Bool isAnimating; // @synthesize isAnimating=_isAnimating;
@property(retain, nonatomic) UIButton *hasAddBtn; // @synthesize hasAddBtn=_hasAddBtn;
@property(retain, nonatomic) UIButton *addBtn; // @synthesize addBtn=_addBtn;
@property(retain, nonatomic) UILabel *descLbl; // @synthesize descLbl=_descLbl;
@property(copy, nonatomic) CDUnknownBlockType callBack; // @synthesize callBack=_callBack;
@property(copy, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
- (void).cxx_destruct;
- (void)_handleChannelListChanged;
- (void)_hideSelf;
- (void)_onAddChannelBtnClick;
- (void)hideTipsView;
- (void)showTipsViewInView:(id)arg1 frame:(struct CGRect)arg2 channelId:(id)arg3 callback:(CDUnknownBlockType)arg4;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end
