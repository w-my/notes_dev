//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNExclusiveListViewController.h"

@class UIButton;

@interface QNChannelExclusivePreviewViewController : QNExclusiveListViewController
{
    UIButton *_addChannelBtn;
}

+ (double)p_textWidth:(id)arg1;
@property(retain, nonatomic) UIButton *addChannelBtn; // @synthesize addChannelBtn=_addChannelBtn;
- (void).cxx_destruct;
- (void)p_enterNewsChannel;
- (void)p_channelBtnClick;
- (void)p_resetChannelBtnState;
- (void)configCollectionView;
- (id)customViewModel;
- (void)scroll2Top;
- (void)configBarButtons;
- (void)viewDidLoad;
- (id)initWithID:(id)arg1;

@end
