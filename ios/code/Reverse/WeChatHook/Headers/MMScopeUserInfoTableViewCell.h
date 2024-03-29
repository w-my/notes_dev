//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMMultiMenuTableViewCell.h"

@class CALayer, MMUILabel, MMWebImageView, OauthAvatarInfo, UIImageView;

@interface MMScopeUserInfoTableViewCell : MMMultiMenuTableViewCell
{
    _Bool _isSelect;
    _Bool _isBottom;
    OauthAvatarInfo *_avatarInfo;
    MMWebImageView *_avatarImageView;
    MMUILabel *_nickNameLabel;
    MMUILabel *_descLabel;
    UIImageView *_selectImageView;
    CALayer *_topSeparateLine;
    CALayer *_bottomSeparateLine;
}

+ (double)viewHeight;
@property(retain, nonatomic) CALayer *bottomSeparateLine; // @synthesize bottomSeparateLine=_bottomSeparateLine;
@property(retain, nonatomic) CALayer *topSeparateLine; // @synthesize topSeparateLine=_topSeparateLine;
@property(retain, nonatomic) UIImageView *selectImageView; // @synthesize selectImageView=_selectImageView;
@property(retain, nonatomic) MMUILabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) MMUILabel *nickNameLabel; // @synthesize nickNameLabel=_nickNameLabel;
@property(retain, nonatomic) MMWebImageView *avatarImageView; // @synthesize avatarImageView=_avatarImageView;
@property(nonatomic) _Bool isBottom; // @synthesize isBottom=_isBottom;
@property(nonatomic) _Bool isSelect; // @synthesize isSelect=_isSelect;
@property(retain, nonatomic) OauthAvatarInfo *avatarInfo; // @synthesize avatarInfo=_avatarInfo;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (void)updateView;

@end

