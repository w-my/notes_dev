//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNAvatarView, QNBaseLabel;

@interface QNAccountQACellResponderView : QNThemableView
{
    QNAvatarView *_responderHeadView;
    QNBaseLabel *_wordingLabel;
}

+ (double)viewHeight;
@property(retain, nonatomic) QNBaseLabel *wordingLabel; // @synthesize wordingLabel=_wordingLabel;
@property(retain, nonatomic) QNAvatarView *responderHeadView; // @synthesize responderHeadView=_responderHeadView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (id)p_generateExpertWordingWithUserItem:(id)arg1;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
