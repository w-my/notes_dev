//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CSimpleImageViewEx.h"

@class NSString, QNBaseLabel, QNPlayButtonOnCell, UIImageView;

@interface QNPlayerCoverView : CSimpleImageViewEx
{
    _Bool _isShowVRView;
    QNPlayButtonOnCell *_playButton;
    QNBaseLabel *_errorLabel;
    NSString *_vid;
    UIImageView *_vrImageView;
}

@property(nonatomic) _Bool isShowVRView; // @synthesize isShowVRView=_isShowVRView;
@property(retain, nonatomic) UIImageView *vrImageView; // @synthesize vrImageView=_vrImageView;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(retain, nonatomic) QNBaseLabel *errorLabel; // @synthesize errorLabel=_errorLabel;
@property(readonly, nonatomic) QNPlayButtonOnCell *playButton; // @synthesize playButton=_playButton;
- (void).cxx_destruct;
- (void)showVRView:(_Bool)arg1;
- (void)showStartImmediatelyViewWithBlock:(CDUnknownBlockType)arg1;
- (void)hideAllViewExceptsBackgraoundImageView:(_Bool)arg1;
- (void)setPlayEnabled:(_Bool)arg1;
- (void)setErrorLabelEnabled:(_Bool)arg1 videoId:(id)arg2;
- (void)removeErrorLabel;
- (void)setVideoCoverUrlString:(id)arg1 placeholder:(id)arg2;
- (void)onTapped;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end
