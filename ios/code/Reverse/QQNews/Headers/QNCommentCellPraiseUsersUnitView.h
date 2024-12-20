//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommentCellBaseUnitView.h"

@class NSArray, NSMutableArray, QNMoreMaskViewButton;

@interface QNCommentCellPraiseUsersUnitView : QNCommentCellBaseUnitView
{
    CDUnknownBlockType _moreButtonClickedBlock;
    CDUnknownBlockType _avatarClickedBlock;
    NSArray *_praiseUsersAvatarList;
    NSArray *_praiseUserMaskButtonList;
    NSMutableArray *_praiseUserItemList;
    QNMoreMaskViewButton *_moreMaskViewButton;
}

@property(retain, nonatomic) QNMoreMaskViewButton *moreMaskViewButton; // @synthesize moreMaskViewButton=_moreMaskViewButton;
@property(retain, nonatomic) NSMutableArray *praiseUserItemList; // @synthesize praiseUserItemList=_praiseUserItemList;
@property(copy, nonatomic) NSArray *praiseUserMaskButtonList; // @synthesize praiseUserMaskButtonList=_praiseUserMaskButtonList;
@property(copy, nonatomic) NSArray *praiseUsersAvatarList; // @synthesize praiseUsersAvatarList=_praiseUsersAvatarList;
@property(copy, nonatomic) CDUnknownBlockType avatarClickedBlock; // @synthesize avatarClickedBlock=_avatarClickedBlock;
@property(copy, nonatomic) CDUnknownBlockType moreButtonClickedBlock; // @synthesize moreButtonClickedBlock=_moreButtonClickedBlock;
- (void).cxx_destruct;
- (void)p_tapOnMoreView:(id)arg1;
- (void)p_tapOnAvatarView:(id)arg1;
- (void)p_resetUserAvatarList;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end

