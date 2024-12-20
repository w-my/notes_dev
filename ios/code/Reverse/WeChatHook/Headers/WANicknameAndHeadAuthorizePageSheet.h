//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WAAuthorizePageSheet.h"

@class NSString, UIImage, UIImageView, UILabel, UIView;

@interface WANicknameAndHeadAuthorizePageSheet : WAAuthorizePageSheet
{
    UIImageView *_headView;
    UILabel *_nickNameLabel;
    UILabel *_nickNameFooterLabel;
    UIView *_topSplitView;
    UIView *_bottomSplitView;
    UIImage *_headImage;
    NSString *_nickName;
}

@property(retain, nonatomic) NSString *nickName; // @synthesize nickName=_nickName;
@property(retain, nonatomic) UIImage *headImage; // @synthesize headImage=_headImage;
@property(retain, nonatomic) UIView *bottomSplitView; // @synthesize bottomSplitView=_bottomSplitView;
@property(retain, nonatomic) UIView *topSplitView; // @synthesize topSplitView=_topSplitView;
@property(retain, nonatomic) UILabel *nickNameFooterLabel; // @synthesize nickNameFooterLabel=_nickNameFooterLabel;
@property(retain, nonatomic) UILabel *nickNameLabel; // @synthesize nickNameLabel=_nickNameLabel;
@property(retain, nonatomic) UIImageView *headView; // @synthesize headView=_headView;
- (void).cxx_destruct;
- (void)layoutSubViews;
- (void)loadExtraSubviewsWithInfo;
- (double)contentHeight;
- (id)initWithInfo:(id)arg1;

@end

