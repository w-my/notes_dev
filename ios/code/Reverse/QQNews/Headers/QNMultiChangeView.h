//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CArticleContentVideoBroadcastNode, QNMultiChangeTitleView, UIImageView;

@interface QNMultiChangeView : UIView
{
    CArticleContentVideoBroadcastNode *_streamInfo;
    UIImageView *_thumbnail;
    QNMultiChangeTitleView *_titleView;
    UIImageView *_shadowView;
}

@property(retain, nonatomic) UIImageView *shadowView; // @synthesize shadowView=_shadowView;
@property(retain, nonatomic) QNMultiChangeTitleView *titleView; // @synthesize titleView=_titleView;
@property(retain, nonatomic) UIImageView *thumbnail; // @synthesize thumbnail=_thumbnail;
@property(retain, nonatomic) CArticleContentVideoBroadcastNode *streamInfo; // @synthesize streamInfo=_streamInfo;
- (void).cxx_destruct;
- (void)setImageViewHidden:(_Bool)arg1;
- (void)layoutWithStreamInfo:(id)arg1 broadcastArray:(id)arg2;
- (id)getCurrentImage;
- (id)initWithFrame:(struct CGRect)arg1;

@end

