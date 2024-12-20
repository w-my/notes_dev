//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNListNewsItem, UIButton, UILabel;

@interface QNVideoCellReplayView : UIView
{
    UIButton *_buttonReplay;
    UIButton *_buttonWX;
    UIButton *_buttonPYQ;
    UILabel *_labelReplay;
    UILabel *_labelWX;
    UILabel *_labelPYQ;
    UIView *_line1;
    UIView *_line2;
    UIButton *_buttonMore;
    UILabel *_labelMore;
    QNListNewsItem *_listItem;
    CDUnknownBlockType _replayAction;
}

@property(copy, nonatomic) CDUnknownBlockType replayAction; // @synthesize replayAction=_replayAction;
@property(nonatomic) __weak QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (struct CGRect)touchFrame;
- (void)actionTapContentGesture:(id)arg1;
- (void)actionButton:(id)arg1;
- (id)labelWithText:(id)arg1;
- (id)buttonWithImage:(id)arg1 tag:(long long)arg2;
- (void)layoutWithShare:(_Bool)arg1;
- (_Bool)canShare;
- (void)didMoveToSuperview;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

