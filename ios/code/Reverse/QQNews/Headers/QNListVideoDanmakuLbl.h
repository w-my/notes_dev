//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNAvatarView, UILabel;

@interface QNListVideoDanmakuLbl : QNThemableView
{
    QNAvatarView *_imageView;
    UILabel *_textLbl;
}

@property(retain, nonatomic) UILabel *textLbl; // @synthesize textLbl=_textLbl;
@property(retain, nonatomic) QNAvatarView *imageView; // @synthesize imageView=_imageView;
- (void).cxx_destruct;
- (void)layoutWithHeadIconUrl:(id)arg1 text:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
