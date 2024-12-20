//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CommonMessageCellView.h"

@class AppUrlMessageViewModel, UIImageView, UILabel;

@interface AppUrlMessageCellView : CommonMessageCellView
{
    UILabel *m_titleLabel;
    UILabel *m_detailLabel;
    UIImageView *m_thumbImageView;
}

- (void).cxx_destruct;
- (id)viewControllerToPreviewWithFromController:(id)arg1 forLocation:(struct CGPoint)arg2 inCoordinateView:(id)arg3;
- (id)viewControllerForPreview:(id)arg1;
- (id)urlForPreView:(id)arg1;
- (_Bool)canPeek;
- (void)onForward:(id)arg1;
- (void)doFavorite;
- (id)operationMenuItems;
- (void)onTouchUpInside;
- (void)onTouchDown;
- (id)thumbImageView;
- (id)thumbImage;
- (void)updateThumbImage;
- (void)addVideoIcon;
- (void)addThumbImageView;
- (void)addDetailLabel;
- (void)addTitleLabel;
- (id)defaultThumbImage;
- (void)onAppear;
- (id)displayViewForImageBrowser;
- (void)layoutContentView;
- (_Bool)canBeReused;

// Remaining properties
@property(readonly, nonatomic) AppUrlMessageViewModel *viewModel; // @dynamic viewModel;

@end

