//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionViewCell.h"

@class MMHeadImageView, MMUIButton, MMUILabel, NSMutableArray, UIImageView, WCStoryTimelineCellModel;

@interface WCStoryFriendsCollectionViewCell : UICollectionViewCell
{
    WCStoryTimelineCellModel *_friendsCollectionViewCellModel;
    MMHeadImageView *_headerImageView;
    MMUILabel *_usernameLabel;
    UIImageView *_favourImageView;
    MMUIButton *_unreadCountButton;
    NSMutableArray *_storyHeadImageViewArray;
}

@property(retain, nonatomic) NSMutableArray *storyHeadImageViewArray; // @synthesize storyHeadImageViewArray=_storyHeadImageViewArray;
@property(retain, nonatomic) MMUIButton *unreadCountButton; // @synthesize unreadCountButton=_unreadCountButton;
@property(retain, nonatomic) UIImageView *favourImageView; // @synthesize favourImageView=_favourImageView;
@property(retain, nonatomic) MMUILabel *usernameLabel; // @synthesize usernameLabel=_usernameLabel;
@property(retain, nonatomic) MMHeadImageView *headerImageView; // @synthesize headerImageView=_headerImageView;
@property(retain, nonatomic) WCStoryTimelineCellModel *friendsCollectionViewCellModel; // @synthesize friendsCollectionViewCellModel=_friendsCollectionViewCellModel;
- (void).cxx_destruct;
- (id)createUnreadStoryHeadImageView;
- (void)updateUnreadStoryHeadImageView:(id)arg1;
- (void)prepareForReuse;
- (void)setupUI;
- (id)initWithFrame:(struct CGRect)arg1;

@end

