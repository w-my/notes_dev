//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomBaseFragmentView.h"

#import "CContextMenuDelegate.h"

@class NSMutableDictionary, NSString, QNRoseLiveRoomBubble;

@interface QNRoseLiveRoomContainerFragmentView : QNRoseLiveRoomBaseFragmentView <CContextMenuDelegate>
{
    id <QNRoseLiveRoomContainerFragmentViewContextDelegate> _delegate;
    QNRoseLiveRoomBubble *_bubbleBackgroundView;
    long long _viewInScence;
    NSMutableDictionary *_fragments;
}

+ (long long)fragmentContainerLevel;
+ (id)fragmentConfigs;
+ (double)expectFragmentViewHeight:(id)arg1 level:(long long)arg2 width:(double)arg3 context:(id)arg4;
+ (void)initialize;
@property(retain, nonatomic) NSMutableDictionary *fragments; // @synthesize fragments=_fragments;
@property(nonatomic) long long viewInScence; // @synthesize viewInScence=_viewInScence;
@property(retain, nonatomic) QNRoseLiveRoomBubble *bubbleBackgroundView; // @synthesize bubbleBackgroundView=_bubbleBackgroundView;
@property(nonatomic) __weak id <QNRoseLiveRoomContainerFragmentViewContextDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)layoutAllFragmentViews:(id)arg1 superView:(id)arg2 maxContentWidth:(double)arg3 insets:(struct UIEdgeInsets)arg4;
- (void)resetMenuViewDataSource;
- (id)removeFragmentView:(long long)arg1;
- (id)findFragmentView:(long long)arg1 createIfMiss:(_Bool)arg2;
- (_Bool)containsFragmentView:(long long)arg1;
- (void)setBubbleViewStyle:(long long)arg1;
- (id)findImageViewByDataNode:(id)arg1;
- (id)_findImageView:(Class)arg1 view:(id)arg2 node:(id)arg3;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

