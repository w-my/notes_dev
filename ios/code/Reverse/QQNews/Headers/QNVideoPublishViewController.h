//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVBaseViewController.h"

@class MVEditEngine, MVModel, MVVideoMediaView, QZEVContext, UIButton, UILabel;

@interface QNVideoPublishViewController : MVBaseViewController
{
    MVModel *_media;
    QZEVContext *_context;
    UIButton *_backButton;
    MVEditEngine *_editEngine;
    id <MVPlayControl> _player;
    MVVideoMediaView *_mediaView;
    UIButton *_publishVideoButton;
    UIButton *_saveToAlbumButton;
    UIButton *_changeVideoCoverImageButton;
    UILabel *_titleLabel;
}

@property(nonatomic) __weak UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) UIButton *changeVideoCoverImageButton; // @synthesize changeVideoCoverImageButton=_changeVideoCoverImageButton;
@property(retain, nonatomic) UIButton *saveToAlbumButton; // @synthesize saveToAlbumButton=_saveToAlbumButton;
@property(retain, nonatomic) UIButton *publishVideoButton; // @synthesize publishVideoButton=_publishVideoButton;
@property(nonatomic) __weak MVVideoMediaView *mediaView; // @synthesize mediaView=_mediaView;
@property(retain, nonatomic) id <MVPlayControl> player; // @synthesize player=_player;
@property(retain, nonatomic) MVEditEngine *editEngine; // @synthesize editEngine=_editEngine;
@property(nonatomic) __weak UIButton *backButton; // @synthesize backButton=_backButton;
@property(retain, nonatomic) QZEVContext *context; // @synthesize context=_context;
@property(retain, nonatomic) MVModel *media; // @synthesize media=_media;
- (void).cxx_destruct;
- (void)p_updateStatusBarStyle;
- (void)p_showInfo:(id)arg1 message:(id)arg2;
- (void)p_finishWithAction:(long long)arg1;
- (void)p_updateMediaCover;
- (void)presentChangeCoverController;
- (void)p_chooseCover;
- (id)addVideoPlayerView;
- (void)p_showPhotoLibraryAuthorizationForbiddenAlert;
- (void)p_saveAlbumClick:(id)arg1;
- (_Bool)canHandleSaveToAlbumAction;
- (void)handleSaveToAlbumAction;
- (void)p_publishBtnClick:(id)arg1;
- (void)setPublishButtonEnable:(_Bool)arg1;
- (void)publishSuccess;
- (void)handlePublishAction;
- (void)dismissMicrovision;
- (void)p_backMicrovisionClick:(id)arg1;
- (void)setTitle:(id)arg1;
- (void)setupNaviBackButton;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;

@end
