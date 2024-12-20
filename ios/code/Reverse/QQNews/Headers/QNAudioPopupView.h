//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNAudioPopupViewButton, UIImageView;

@interface QNAudioPopupView : QNThemableView
{
    CDUnknownBlockType _playNewestBlock;
    CDUnknownBlockType _downloadBlock;
    UIImageView *_backGroundView;
    QNAudioPopupViewButton *_playNewestButton;
    QNAudioPopupViewButton *_downloadButton;
}

@property(retain, nonatomic) QNAudioPopupViewButton *downloadButton; // @synthesize downloadButton=_downloadButton;
@property(retain, nonatomic) QNAudioPopupViewButton *playNewestButton; // @synthesize playNewestButton=_playNewestButton;
@property(retain, nonatomic) UIImageView *backGroundView; // @synthesize backGroundView=_backGroundView;
@property(copy, nonatomic) CDUnknownBlockType downloadBlock; // @synthesize downloadBlock=_downloadBlock;
@property(copy, nonatomic) CDUnknownBlockType playNewestBlock; // @synthesize playNewestBlock=_playNewestBlock;
- (void).cxx_destruct;
- (void)p_downloadClick:(id)arg1;
- (void)p_playNewestClick:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)layoutSubviews;
- (id)init;

@end

