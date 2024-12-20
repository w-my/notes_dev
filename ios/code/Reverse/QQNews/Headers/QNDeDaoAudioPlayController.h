//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "QNDeDaoPlayListViewDelegate.h"
#import "QNDeDaoPlayerViewProtocol.h"
#import "QNShareActivityControllerDelegate.h"
#import "UIScrollViewDelegate.h"

@class NSString, QNBaseLabel, QNDeDaoAudioPlayViewModel, QNDeDaoPlayListView, QNEnlargeHitTestButton, QNInteractiveProgressView, QNSDWebGIFImageView, UIScrollView;

@interface QNDeDaoAudioPlayController : UIViewController <QNDeDaoPlayListViewDelegate, QNShareActivityControllerDelegate, UIScrollViewDelegate, QNDeDaoPlayerViewProtocol>
{
    _Bool _hasAppeared;
    QNDeDaoAudioPlayViewModel *_viewModel;
    UIScrollView *_containerView;
    QNBaseLabel *_lessonNameLabel;
    QNInteractiveProgressView *_progressView;
    QNBaseLabel *_timeLabel;
    QNBaseLabel *_remainTimeLabel;
    QNDeDaoPlayListView *_playListView;
    QNEnlargeHitTestButton *_preButton;
    QNEnlargeHitTestButton *_nextButton;
    QNEnlargeHitTestButton *_playButton;
    QNSDWebGIFImageView *_loadingView;
}

@property(retain, nonatomic) QNSDWebGIFImageView *loadingView; // @synthesize loadingView=_loadingView;
@property(retain, nonatomic) QNEnlargeHitTestButton *playButton; // @synthesize playButton=_playButton;
@property(retain, nonatomic) QNEnlargeHitTestButton *nextButton; // @synthesize nextButton=_nextButton;
@property(retain, nonatomic) QNEnlargeHitTestButton *preButton; // @synthesize preButton=_preButton;
@property(retain, nonatomic) QNDeDaoPlayListView *playListView; // @synthesize playListView=_playListView;
@property(retain, nonatomic) QNBaseLabel *remainTimeLabel; // @synthesize remainTimeLabel=_remainTimeLabel;
@property(retain, nonatomic) QNBaseLabel *timeLabel; // @synthesize timeLabel=_timeLabel;
@property(retain, nonatomic) QNInteractiveProgressView *progressView; // @synthesize progressView=_progressView;
@property(retain, nonatomic) QNBaseLabel *lessonNameLabel; // @synthesize lessonNameLabel=_lessonNameLabel;
@property(retain, nonatomic) UIScrollView *containerView; // @synthesize containerView=_containerView;
@property(retain, nonatomic) QNDeDaoAudioPlayViewModel *viewModel; // @synthesize viewModel=_viewModel;
- (void).cxx_destruct;
- (void)scrollViewDidScroll:(id)arg1;
- (_Bool)shouldAutorotate;
- (unsigned long long)supportedInterfaceOrientations;
- (id)getShareToEmailInfo;
- (void)p_handleTap:(id)arg1;
- (void)p_share;
- (void)p_dismiss;
- (void)p_viewArticle;
- (void)p_showPlayList;
- (void)p_playAtProgress:(double)arg1;
- (void)p_playNextLesson;
- (void)p_playPreLesson;
- (void)p_togglePlay;
- (void)p_viewCourseDetail;
- (void)playListView:(id)arg1 didClickArticle:(id)arg2;
- (void)playListView:(id)arg1 didSelectedLessonAtIndex:(long long)arg2;
- (void)p_updateWithPlayerStatus:(unsigned long long)arg1;
- (void)playerStatusDidChange:(unsigned long long)arg1;
- (void)updateWithLesson:(id)arg1 status:(unsigned long long)arg2;
- (void)updateProgress:(double)arg1 animated:(_Bool)arg2;
- (void)p_buildBottomToolView;
- (void)p_buildPlayView;
- (void)p_buildCourceInfoView;
- (void)p_buildNavButton;
- (void)dealloc;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithCoder:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initWithViewModel:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

