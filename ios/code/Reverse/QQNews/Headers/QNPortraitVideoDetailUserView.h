//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNAdIcon, QNAttributedLabel, QNAvatarView, QNBaseLabel, QNListNewsItem, QNReportParam, QNSubscribeButton;

@interface QNPortraitVideoDetailUserView : UIView
{
    _Bool _titleTruncated;
    CDUnknownBlockType _unfoldBlock;
    CDUnknownBlockType _openAdViewBlock;
    QNReportParam *_reportParam;
    QNListNewsItem *_listItem;
    QNAvatarView *_avatarView;
    QNBaseLabel *_nameLabel;
    QNSubscribeButton *_subButton;
    QNAttributedLabel *_titleLabel;
    QNBaseLabel *_adLinkLabel;
    QNAdIcon *_adIcon;
}

@property(nonatomic) _Bool titleTruncated; // @synthesize titleTruncated=_titleTruncated;
@property(retain, nonatomic) QNAdIcon *adIcon; // @synthesize adIcon=_adIcon;
@property(retain, nonatomic) QNBaseLabel *adLinkLabel; // @synthesize adLinkLabel=_adLinkLabel;
@property(retain, nonatomic) QNAttributedLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) QNSubscribeButton *subButton; // @synthesize subButton=_subButton;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) QNAvatarView *avatarView; // @synthesize avatarView=_avatarView;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(copy, nonatomic) CDUnknownBlockType openAdViewBlock; // @synthesize openAdViewBlock=_openAdViewBlock;
@property(copy, nonatomic) CDUnknownBlockType unfoldBlock; // @synthesize unfoldBlock=_unfoldBlock;
- (void).cxx_destruct;
- (void)p_tapped:(id)arg1;
- (void)setBackgroundColor:(id)arg1;
- (void)layoutWithListItem:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end
