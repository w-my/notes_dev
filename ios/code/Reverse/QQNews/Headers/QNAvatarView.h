//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class UIImage, UIImageView;

@interface QNAvatarView : QNThemableView
{
    double _flagOffset;
    UIImageView *_avatarView;
    UIImageView *_flagView;
}

@property(retain, nonatomic) UIImageView *flagView; // @synthesize flagView=_flagView;
@property(retain, nonatomic) UIImageView *avatarView; // @synthesize avatarView=_avatarView;
@property(nonatomic) double flagOffset; // @synthesize flagOffset=_flagOffset;
- (void).cxx_destruct;
@property(retain, nonatomic) UIImage *avatarImage; // @dynamic avatarImage;
- (void)setAvatarImage:(id)arg1 avatarSize:(struct CGSize)arg2 flagIconURL:(id)arg3 flagIconSize:(struct CGSize)arg4;
- (void)setAvatarImage:(id)arg1 avatarSize:(struct CGSize)arg2 flagIcon:(id)arg3 flagIconSize:(struct CGSize)arg4;
- (void)setAvatarImage:(id)arg1 avatarSize:(struct CGSize)arg2 flagIcon:(id)arg3;
- (void)setAvatarImage:(id)arg1 flagIcon:(id)arg2;
- (void)setAvatarImage:(id)arg1 avatarSize:(struct CGSize)arg2;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 avatarProcessConfig:(id)arg4 flagIconURL:(id)arg5 flagIconSize:(struct CGSize)arg6 processCategory:(id)arg7 success:(CDUnknownBlockType)arg8 failure:(CDUnknownBlockType)arg9;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 avatarProcessConfig:(id)arg4 flagIcon:(id)arg5 flagIconSize:(struct CGSize)arg6 processCategory:(id)arg7 success:(CDUnknownBlockType)arg8 failure:(CDUnknownBlockType)arg9;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 flagIconURLPicker:(CDUnknownBlockType)arg4 flagIconSize:(struct CGSize)arg5;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 avatarProcessConfig:(id)arg4 flagIconURL:(id)arg5 flagIconSize:(struct CGSize)arg6;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 avatarProcessConfig:(id)arg4 flagIcon:(id)arg5 flagIconSize:(struct CGSize)arg6;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 flagIconURL:(id)arg4 flagIconSize:(struct CGSize)arg5;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 flagIcon:(id)arg4 flagIconSize:(struct CGSize)arg5;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3 flagIcon:(id)arg4;
- (void)setAvatarImageWithURL:(id)arg1 placeholderImage:(id)arg2 avatarSize:(struct CGSize)arg3;
- (void)setAvatarImageWithURL:(id)arg1 avatarSize:(struct CGSize)arg2;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
