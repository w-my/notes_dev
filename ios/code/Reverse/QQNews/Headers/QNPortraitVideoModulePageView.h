//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNPageViewContentBase.h"

@class QNAttributedLabel, QNAvatarView, QNBaseLabel, QNCommonGIFImageView, QNListNewsItem, QNPlayButtonOnCell;

@interface QNPortraitVideoModulePageView : QNPageViewContentBase
{
    QNCommonGIFImageView *_coverView;
    QNAvatarView *_avatarView;
    QNBaseLabel *_nameLabel;
    QNAttributedLabel *_titleLabel;
    QNBaseLabel *_supportCountLabel;
    QNPlayButtonOnCell *_playButton;
    QNListNewsItem *_newsItem;
}

+ (_Bool)do_isFullWidthMode;
+ (struct CGSize)viewSize;
@property(retain, nonatomic) QNListNewsItem *newsItem; // @synthesize newsItem=_newsItem;
@property(retain, nonatomic) QNPlayButtonOnCell *playButton; // @synthesize playButton=_playButton;
@property(retain, nonatomic) QNBaseLabel *supportCountLabel; // @synthesize supportCountLabel=_supportCountLabel;
@property(retain, nonatomic) QNAttributedLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) QNAvatarView *avatarView; // @synthesize avatarView=_avatarView;
@property(retain, nonatomic) QNCommonGIFImageView *coverView; // @synthesize coverView=_coverView;
- (void).cxx_destruct;
- (void)p_handleTapUser:(id)arg1;
- (id)imageCoverView;
- (void)updateSupportCount;
- (void)layoutWithItem:(id)arg1 userInfo:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
