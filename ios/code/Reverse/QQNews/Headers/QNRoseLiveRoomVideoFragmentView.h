//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomBaseFragmentView.h"

@class CSimpleImageView, UIButton;

@interface QNRoseLiveRoomVideoFragmentView : QNRoseLiveRoomBaseFragmentView
{
    CSimpleImageView *_videoCoverView;
    UIButton *_playBtn;
}

+ (double)expectFragmentViewHeight:(id)arg1 level:(long long)arg2 width:(double)arg3 context:(id)arg4;
+ (unsigned long long)dataType;
@property(retain, nonatomic) UIButton *playBtn; // @synthesize playBtn=_playBtn;
@property(retain, nonatomic) CSimpleImageView *videoCoverView; // @synthesize videoCoverView=_videoCoverView;
- (void).cxx_destruct;
- (void)p_startPlayVideo:(id)arg1;
- (void)layoutSubviewsImmediately;
- (id)initWithFrame:(struct CGRect)arg1;

@end

